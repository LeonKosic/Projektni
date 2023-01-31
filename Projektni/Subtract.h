#pragma once
#include "Operation.h"
namespace Graph {
	template<typename T> class Subtract :Operation<T> {
	public:
		T calculate() const override {

			if (Operation<T>::empty())throw std::exception("Nema validnih operanada za izvrsavanje operacije");
			try {
				T res(Operation<T>::operands[0]);
				for (int i = 1; i < Operation<T>::size(); i++) {
					for (int j = 0; j < res.size(); j++) {
						res[j] -= Operation<T>::operands[i][j];
					}
				}
				return res;
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
		}
	};
}