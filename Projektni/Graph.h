#pragma once
#include<iostream>
#include<fstream>
#include "Node.h"
#include "Addition.h"
#include "Subtract.h"
#include "Inverse.h"
#include "Multiply.h"
#include "AddScalar.h"
#include "MultiplyScalar.h"
#include "Leaf.h"
namespace Graph  {
	template<Collection T> class Graph {
	private:
		std::vector<ptr<Node<T>> > nodes;
	public:
		ptr<Node<T>> operator[](const size_t& index) {
			if (index >= size())throw std::exception("Index out of bounds");
			return nodes[index];
		}
		size_t size() const {
			return nodes.size();
		}
		ptr<const Node<T>> operator[](const size_t& index) const {
			if (index >= size())throw std::exception("Index out of bounds");
			return nodes[index];
		}
		void addNode(ptr<Node<T>> el) {
			nodes.push_back(el);
		}
		void addNode(const Operation<T>& el) {
			ptr<Node<T>> val = std::make_shared<Operation<T> >(el);
			addNode(val);
		}
		void addNode(const T& el) {
			ptr<Node<T>> val=std::make_shared<Leaf<T>>(el);
			addNode(val);
		}
		size_t find(const ptr<Node<T>>& el) const{
			for (size_t i = 0; i < size(); i++) {
				if (el == nodes[i])return i;//inshallah je dobar equality operator za shared_ptr
			}
		}
		void addPath(size_t from, size_t to) {
			nodes[to]->add(nodes[from]);
			/*
			* pretpostavlja se da korisnik povezuje vezu OD tensora DO operacije, 
			* u klasi sam obrnuto implementirao zbog laksih operacija
			*/
		}
		void addPath(ptr<Node<T>> from, ptr<Node<T>> to) {
			addPath(find(from), find(to));
		}
		T getResult(size_t from) {
			return nodes[from]->getResult();
		}
		T getResult(ptr<Node<T>> start) const {
			return getResult(find(start));
		}
		friend std::ostream& operator<<(std::ofstream& ofs, const Graph<T>& a) {

		}
		friend std::istream& operator>>(std::ifstream& ifs, Graph<T>& a) {

		}
	};
	template<typename T> std::ostream& operator<<(std::ostream& os, const T& el) {
		for (int i = 0; i < el.size(); i++) {
			os << (*el[i]) << ' ';
		}
	}
	
}