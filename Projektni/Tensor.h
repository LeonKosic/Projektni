#pragma once
#include<iostream>
#include<fstream>
#include<array>
namespace Graph {

	template<typename T,size_t ... args> class Tensor {
	private:
		static constexpr size_t size = (args * ...);
		std::array<T, size> arr;
	public:
	
		T& operator[](size_t index) {
			return arr[index];
		}
		const T& operator[](size_t index) const {
			return arr[index];
		}
		auto begin() {
			return arr.begin();
		}
		auto cbegin() const {
			return arr.cbegin();
		}
		auto end() {
			return arr.end();
		}
		auto cend() const {
			return arr.cend();
		}
	};
}