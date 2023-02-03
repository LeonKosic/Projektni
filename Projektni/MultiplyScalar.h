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
		virtual T derValue(size_t size, size_t opInd) override {
			/*double scale = ScalarOperation<T>::getScalar();
			auto val = Operation<T>::operands[0];
			for (auto& x : val)x = scale;*/
			return T(size, ScalarOperation<T>::getScalar());
		}
	};
}