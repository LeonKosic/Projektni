#pragma once
#include "Node.h"

namespace Graph {
	template<typename T> class Leaf :Node<T> {
	public:
		virtual T getResult() const {
			if (empty()) throw std::exception("Tensor operanda nije definisan");
			return operands[0];
		}
	};

}