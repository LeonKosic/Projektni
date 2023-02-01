#pragma once
#include "BinaryOperation.h"
namespace Graph {
	template<typename T> class Multiply :BinaryOperation<T> {
	private:
	public:
		Multiply() :BinaryOperation<T>([](const T& a,const T& b) {
			T res(a);
		for (int i = 0; i < res.size(); i++) {
			res[i] =a[i]* b[i];
		}
		return res;
			}
			) {}
	};
}