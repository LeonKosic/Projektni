#pragma once
#include "Node.h"

namespace Graph {
	template<typename T> class Leaf :Node<T> {
	private:
		T value;
	public:
		Leaf(T val) :val(T);
		virtual T getResult() const {
			return value;
		}
	};

}