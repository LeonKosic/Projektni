#pragma once
#include "Node.h"
namespace Graph {
	template<typename T> class Operation : public Node<T> {
	protected:
		std::vector<ptr<Node>> operands; // iz cega se racuna
	public:
		virtual T calculate() const = 0;
		virtual void addOperand(const ptr<Node>& el) {
			operands.push_back(el);
		}
		
		virtual void add(ptr<Node>& el) override {
			addOperand(el);
			el->add(getPtr());
		}
	};

}