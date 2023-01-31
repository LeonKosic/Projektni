#pragma once
#include "Operation.h"
#include <functional>
namespace Graph {
	template<typename T> class Custom :Operation<T> {
	private:
		std::function<T(const T&)> f;
	public:
		T calculate() const override {
			if (Operation<T>::empty())throw std::exception("Nema validnih operanada za izvrsavanje operacije");
			try {
				return f(Operation<T>::operands[0]->getResult());
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
		}
	};
}