#pragma once
#include <type_traits>
#include <concepts>
#include<iostream>
namespace Graph {
    template <typename T> concept Printable = requires(std::ostream & os, const T & t){
        { os << t } -> std::convertible_to<decltype(os)>;
    };
    template <typename T> concept Invertable = requires(decltype(T()[0]) t) {
        {t = -t}->std::convertible_to<decltype(T()[0])>;
    };
    template<typename T> concept Addable = requires(decltype(T()[0]) & a, const decltype(a) & b) {
        {a += b}->std::convertible_to<decltype(a)&>;
        {a + b}->std::convertible_to<decltype(a)>;
    };
    template <typename T>
    concept Collection = requires(const T & b,decltype(T()[0]) a) {
        b[0];
    };

    template <typename T>
    concept Assignable = requires(T & a, const T & b) {
        {a = b}-> std::convertible_to<T>;
    };
}