#pragma once
#include "Operation.h"
namespace Graph {
	template<typename T> class Subtract :Operation<T> {
	public:
		T calculate() const override {
			try {
				T res(operands[0]);
				for (int i = 1; i < operands.size(); i++) {
					for (int j = 0; j < res.size(); j++) {
						res[j] -= operands[i][j];
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