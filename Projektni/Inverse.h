#pragma once
#include "Operation.h"
namespace Graph {
	template<typename T> class Inverse :public Operation<T> {
	public:
		T calculate() const override {
			if (Operation<T>::empty())throw std::exception("Nema validnih operanada za izvrsavanje operacije");
			try {
				T res(Operation<T>::operands[0]);
				for (int i = 0; i < res.size(); i++) {
					res[j] = -res[j];
				}
				return res;
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
		}

	};
}