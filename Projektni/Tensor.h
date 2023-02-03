#pragma once
#include<iostream>
#include<fstream>
#include<typeinfo>
#include<vector>
namespace Graph {

	template<typename T,size_t ... args> class Tensor {
	private:
		static constexpr std::vector<size_t> val{ {args...} };
		static constexpr size_t num = (args * ...);
		std::vector<T> arr;
	public:
		template<typename ...sizeT>
		T& get(sizeT ... argsF) {
			std::vector<int> el{ {argsF...} };
			size_t index = 0;
			size_t multiplier = size / args[0];
			if (val.size() != el.size())throw std::exception("Nema tacan broj dimenzija");
			for (size_t i = 0; i < val.size() - 1; i++) {
				if (el[i] > val[i])throw std::exception("Out of bounds");
				index += multiplier * el[i];
				multiplier /= val[i + 1];
			}
			index += el[el.size() - 1];
			return arr[index];
		}
		template<typename ...sizeT>
		const T& get(sizeT ... argsF) const{
			std::vector<int> el{ {argsF...} };
			size_t index = 0;
			size_t multiplier = size / args[0];
			if (val.size() != el.size())throw std::exception("Nema tacan broj dimenzija");
			for (size_t i = 0; i < val.size() - 1; i++) {
				if (el[i] > val[i])throw std::exception("Out of bounds");
				index += multiplier * el[i];
				multiplier /= val[i + 1];
			}
			index += el[el.size() - 1];
			return arr[index];
		}
		static inline auto value_type = std::vector<T>::value_type;
		size_t capacity() const {
			return num;
		}
		size_t size() const {
			return arr.size();
		}
		T& operator[](size_t index) {
			if (index > num)throw std::exception("Out of tensor range");
			if (index > size())throw std::exception("Value not set");
			return arr[index];
		}
		std::vector<size_t> getDimensions() const {
			return val;
		}
		const T& operator[](size_t index) const {
			if (index > num)throw std::exception("Out of tensor range");
			if (index > size())throw std::exception("Value not set");
			return arr[index];
		}
		auto begin() {
			return arr.begin();
		}
		auto cbegin() const {
			return arr.cbegin();
		}
		void push_back(const T& el) {
			if (arr.size() == num)throw std::exception("Array dimensions full, possible if trying to deserialize a tensor with a different format");
			arr.push_back(el);
		}
		auto end() {
			return arr.end();
		}
		auto cend() const {
			return arr.cend();
		}
	};
}