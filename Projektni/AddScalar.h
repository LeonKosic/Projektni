#pragma once
#include "ScalarOperation.h"
namespace Graph {
	template<typename T> class AddScalar : public ScalarOperation<T> {
	private:
	public:
		AddScalar() :AddOperation<T>([](const T& a, const double& b) {
			T res(a);
		for (int i = 0; i < res.size(); i++) {
			res[i] = a[i] + b[i];
		}
		return res;
			}
			) {}
	};
}