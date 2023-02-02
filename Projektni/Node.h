#pragma once
#include<vector>
#include<exception>
#include "Concepts.h"
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
		virtual void addOperator(const ptr<Node>& el) {
			operators.push_back(el);
		}
		virtual void serialize(std::ofstream& ofs) const{
		};
		virtual void deserialize(std::ifstream& ifs) = 0;
		friend std::ostream& operator<<(std::ofstream& ofs, const Node<T>& a) {
			ofs << typeid(a).raw_name();
			return ofs;
		}
		friend std::ostream& operator<<(std::ostream& os, const Node<T>& a) {
			os << typeid(a).name() << '\n';
			return os;
		}
	};
}