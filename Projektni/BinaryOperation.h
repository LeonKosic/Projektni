#pragma once
#include "Operation.h"
#include <functional>
namespace Graph {
	template<typename T> class BinaryOperation : public Operation<T> {
	private:
		std::function<T(const T&, const T&)> f;
	public:
		BinaryOperation(decltype(f) val) :f(val){}
		T calculate() const override {
			if (Operation<T>::empty())throw std::exception("Nema validnih operanada za izvrsavanje operacije");
			try {
				T res(Operation<T>::operands[0]->getResult());
				for (int i = 1; i < Operation<T>::size(); i++) {
					res = f(res,Operation<T>::operands[i]->getResult());
				}
				return res;
			}
			catch (std::exception& e) {
				throw(e);
			}
		}
	};
}