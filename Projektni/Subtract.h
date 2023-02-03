#pragma once
#include "BinaryOperation.h"
namespace Graph {
	template<typename T> class Subtract : public BinaryOperation<T> {
	public:
		Subtract() :BinaryOperation<T>([](const T& a,const T& b) {
			T res(a);
		for (int i = 0; i < res.size(); i++) {
			res[i] = a[i] - b[i];
		}
		return res;
			}
			) {}
		virtual T derValue(size_t size, size_t opInd) override {
			return T(size, opInd==0?1:-1); 
		}
	};
}