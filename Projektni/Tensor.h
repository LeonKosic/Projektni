#pragma once
#include<iostream>
#include<fstream>
#include<array>
namespace Graph {

	template<typename T,size_t ... args> class Tensor {
	private:
		static constexpr size_t num = (args * ...);
		static constexpr std::vector<size_t> val{ {args...} };
		std::array<T, num> arr;
	public:
		/*T& operator()(size_t ... argsF) {
			std::vector<size_t> el{ {argsF...} };
			size_t index = 0;
			size_t multiplier = size / args[0];
			if (val.size() != el.size())throw std::exception("Nema tacan broj dimenzija");
			for (size_t i = 0; i < val.size()-1; i++) {
				if (el[i] > val[i])throw std::exception("Out of bounds");
				index += multiplier * el[i];
				multiplier /= val[i + 1];
			}
			index += el[el.size() - 1];
			return arr[index];
		}*/
		size_t size() const {
			return num;
		}
		T& operator[](size_t index) {
			return arr[index];
		}
		std::vector<size_t> getDimensions() const {
			return val;
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