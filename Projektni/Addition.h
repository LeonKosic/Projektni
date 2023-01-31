#pragma once
#include "Operation.h"
namespace Graph {
	template<typename T> class Addition :Operation<T> {
	private:
	public:
		T calculate() const override {
			if (Operation<T>::empty())throw std::exception("Nema validnih operanada za izvrsavanje operacije");
			try {
				T res(Operation<T>::operands[0]->getResult());
				for (int i = 1; i < Operation<T>::operands.size(); i++) {
					T temp = Operation<T>::operands[i]->getResult();
					for (int j = 0; j < res.size(); j++) {
						res[j] += temp[j];
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