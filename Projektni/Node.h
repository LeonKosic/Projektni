#pragma once
#include<vector>
#include<exception>
#include "Concepts.h"
#include<string>
#include<sstream>
#include "Pointer.h"
namespace Graph {
	template<typename T> class Node  {
	protected:
		std::vector<ptr<Node>> operators; // u sta se racuna
	public:
		virtual T getResult() const = 0;
		virtual void add(ptr<Node>& el) {
			addOperator(el);
		}
		virtual size_t size() const = 0;
		virtual void addOperator(const ptr<Node>& el) {
			operators.push_back(el);
		}
		virtual bool findDerivative(const ptr<Node<T>>& a) const = 0;
		virtual T derivative(const ptr<Node<T>>& a) //const = 0;
		{
			return getResult();
		}
		virtual void serialize(std::ofstream& ofs) const { return; }
		virtual void serialize(std::ostream& ofs) const { return; }
		virtual void deserialize(std::ifstream& ifs) = 0;
		friend std::ostream& operator<<(std::ofstream& ofs, const Node<T>& a) {
			ofs << typeid(a).raw_name()<<'#';
			a.serialize(ofs);
			ofs << '#';
			return ofs;
		}
		friend std::ostream& operator<<(std::ostream& os, const Node<T>& a) {
			os << typeid(a).name() << '\n';
			a.serialize(os);
			os<< '\n';
			return os;
		}

	};
}