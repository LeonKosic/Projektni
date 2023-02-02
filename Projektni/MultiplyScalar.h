#pragma once
#include "ScalarOperation.h"
namespace Graph {
	template<typename T> class MultiplyScalar : public ScalarOperation<T> {
	private:
	public:
		MultiplyScalar(double scalar = 0) :ScalarOperation<T>([](const T& a, const double b) {
			T res(a);
		for (int i = 0; i < res.size(); i++) {
			res[i] = a[i] * b;
		}
		return res;
			}
			, scalar) {}
	};
}