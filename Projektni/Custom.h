#pragma once
#include "Operation.h"
#include <functional>
namespace Graph {
	template<typename T> class Custom :Operation<T> {
	private:
		std::function<T(const T&, const T&)> f;
	public:
		T calculate() const override {
			if (Operation<T>::empty())throw std::exception("Nema validnih operanada za izvrsavanje operacije");
			try {
				T res(Operation<T>::operands[0]);
				for (int i = 1; i < Operation<T>::size(); i++) {
					res = f(res,Operation<T>::operands[i]);
				}
				return res;
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
		}
	};
}