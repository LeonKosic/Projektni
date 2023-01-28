#pragma once
#include<vector>
#include<exception>
#include "Pointer.h"
namespace Graph {
	template<typename T> class Node : std::enable_shared_from_this<Node<T>> {
	protected:
		std::vector<ptr<Node>> operators; // u sta se racuna
	public:
		ptr<Node> getPtr() {
			return shared_from_this(); //NOTE mzd moram derivirati
		}
		virtual T getResult() const = 0;
		virtual void add(ptr<Node>& el) {
			addOperator(el);
		}
		virtual void addOperator(const ptr<Node>& el) {
			operators.push_back(el);
		}
	};
	template<typename T> std::ostream& operator<<(std::ofstream& ofs, const T& a) {
		for (int i = 0; i < a.size(); i++) {
			ofs << a[i] << ' ';
		}
	}
	template<typename T> std::istream& operator>>(std::ifstream& ofs, T& a) {
		for (int i = 0; i < a.size(); i++) {
			ofs >> a[i]; //TODO : concepts da bi radilo
		}
	}
}