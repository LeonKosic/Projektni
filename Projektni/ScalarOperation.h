#pragma once
#include "Operation.h"
#include <functional>
namespace Graph {
	template<typename T> class ScalarOperation : public Operation<T> {
	private:
		std::function<T(const T&, const double)> f;
		double scalar;
	public:
		ScalarOperation(decltype(f) val, double scal = 0) :f(val), scalar(scal) {}
		T calculate() const override {
			if (Operation<T>::empty())throw std::exception("Nema validnih operanada za izvrsavanje operacije");
			try {
				return f(Operation<T>::operands[0]->getResult(), scalar);
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
		}
		void setScalar(const double& scal) {
			scalar = scal;
		}
	};
}