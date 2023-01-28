#pragma once
#include<iostream>
#include<fstream>
#include "Node.h"
namespace Graph {
	template<typename T> class Graph {
	private:
		std::vector<ptr<Node<T>> > nodes;
	public:

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