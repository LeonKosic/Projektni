#pragma once
#include "UnaryOperation.h"
namespace Graph {
	template<Invertable T> class Inverse :public UnaryOperation<T> {
	public:
		Inverse() :UnaryOperation<T>([](const T& tenz) {
			T res(tenz);
			for (int i = 0; i < tenz.size(); i++) {
				res[i] = -tenz[i];
			}
			return res; 
			}
		){}

	};
}