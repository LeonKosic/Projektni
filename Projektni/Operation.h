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
		size_t size() const override{
			return operands.size();
		}
		bool empty() const{
			return operands.size() == 0;
		}
		virtual bool findDerivative(const ptr<Node<T>>& a) const override{
			for (size_t i = 0; i < size(); i++) {
				if ((a==operands[i])||(findDerivative(operands[i])))return true;
			}
			return false;
		}

		virtual T derivative(const ptr<Node<T>>& a) override {
			T res=operands[0]->getResult();
			for (auto& x : res)x = 0;
			for (size_t i = 0; i < size(); i++) {
				if (!findDerivative(a))continue;
				T tempRes1=derValue(res.size(), i);
				T tempRes2 = operands[i]->derivative(a);
				for (size_t j = 0; j < res.size(); j++) {
					res[j] += tempRes1[j] * tempRes2[j];
				}
			}
			return res;
		}
		virtual T derValue(size_t size, size_t opInd) {
			return T(size, 1); //default ponasanje je kao kod sabiranja
		}
		virtual void add(ptr<Node<T>>& el) override {
			addOperand(el);
			//el->addOperator(Node<T>::getPtr());
		}
		virtual T getResult() const override {
			return calculate();
		}
		virtual void serialize(std::ofstream& ofs) const override {
			return;
		}
		virtual void deserialize(std::ifstream& ifs) override {
			return;
		}
	};

}