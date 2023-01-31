#pragma once
#include "Node.h"

namespace Graph {
	template<typename T> class Leaf :Node<T> {
	private:
		T value;
	public:
		Leaf(T val) :value(val){}
		virtual T getResult() const {
			return value;
		}
	};

}