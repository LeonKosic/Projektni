#pragma once
#include <type_traits>
#include <concepts>
#include<iostream>
namespace Graph {
    template <typename T>
    concept Printable = requires(std::ostream & os, const T & t)​ {
        { os << t } -> std::convertible_to<decltype(os)>;
    };

    template <typename T>
    concept Collection = requires(const T & T,decltype(T()[0]) a) {
        T[0];
    };
}