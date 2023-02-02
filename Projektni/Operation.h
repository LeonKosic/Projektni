#pragma once
#include "Node.h"
namespace Graph {
	template<typename T> class Operation : public Node<T> {
	protected:
		std::vector<ptr<Node<T>>> operands; // iz cega se racuna
	public:
		virtual T calculate() const = 0;
		virtual void addOperand(const ptr<Node<T>>& el) {
			operands.push_back(el);
		}
		size_t size() const {
			return operands.size();
		}
		bool empty() const{
			return operands.size() == 0;
		}
		virtual void add(ptr<Node<T>>& el) override {
			addOperand(el);
			//el->addOperator(Node<T>::getPtr());
		}
		virtual T getResult() const override {
			return calculate();
		}
		virtual void serialize(std::ofstream& ofs) const override {

		}
		virtual void deserialize(std::ifstream& ifs) override {

		}
	};

}