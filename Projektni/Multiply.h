#pragma once
#include "BinaryOperation.h"
namespace Graph {
	template<typename T> class Multiply : public BinaryOperation<T> {
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
		
		virtual T derValue(size_t size, size_t opInd)  override {
			T res = Operation<T>::operands[0]->getResult();
			for (auto& x : res) {
				x = 1;
			}
			
			for (size_t i = 0; i < Operation<T>::size(); i++) {
				if (i == opInd)continue;
				auto val = Operation<T>::operands[i]->getResult();
				for (size_t j = 0; j < val.size(); j++) {
					res[j] *= val[j];
				}
			}
			return res;
		}
	};
}