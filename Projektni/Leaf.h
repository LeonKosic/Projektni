#pragma once
#include "Node.h"

namespace Graph {
	template<typename T> class Leaf :public Node<T> {
	private:
		T value;
	public:
		Leaf(const T& val) :value(val){}
		virtual T getResult() const {
			return value;
		}
		void setValue(const T& val) {
			value = val;
		}
		virtual void serialize(std::ofstream& ofs) const override {
			
		}
		virtual void deserialize(std::ifstream& ifs) override {

		}
	};

}