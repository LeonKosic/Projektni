#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<utility>
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
		std::vector<std::pair<size_t, size_t> > paths;
	public:
		std::vector<std::vector<T>> Jacobian() {
			std::vector< std::vector<T> > jacobMat;
			std::vector<bool> isTensor(nodes.size(), false);
			for (int i = 0; i < nodes.size(); i++) {
				if (typeid(*nodes[i]).raw_name() == typeid(Leaf<T>).raw_name())isTensor[i] = true;
			}
			for (int i = 0; i < nodes.size(); i++) {
				if (!isTensor[i])continue;
				jacobMat.push_back(std::vector<T>());
				for (int j = 0; j < nodes.size(); j++) {
					if (isTensor[j])continue;
					//jacobMat[i].push_back(nodes[j]->getResult());
					jacobMat[i].push_back(nodes[j]->derivative(nodes[i]));
				}
			}
			return jacobMat;
		}
		void printJacobian() {
			auto arr = Jacobian();
			for (int i = 0; i < arr.size(); i++) {
				std::cout << i + 1 << " : \n";
				for (int j = 0; j < arr[i].size(); j++) {
					for (int k = 0; k < arr[i][j].size(); k++) {
						std::cout << arr[i][j][k] << ' ';
					}
					std::cout << std::endl;
				}
			}
		}
		void print() {
			for (int i = 0; i < nodes.size(); i++)std::cout << typeid(*nodes[i]).name() << std::endl;
		}
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
			paths.push_back({ to,from });
			/*
			* pretpostavlja se da korisnik povezuje vezu OD tensora DO operacije, tj od operacije do operacije koja zavisi od te operacije, 
			* u klasi sam obrnuto implementirao zbog laksih operacija izracunavanja
			* ako hocu da cuvam i vezu do i vezu od kao dva odvojena vektora
			* moram slati this pointer kao std::shared_ptr pa mi mora Node<T> inherit std::enable_shared_from_this<Node<T>>
			* klasu a i rizikujem circular dependency? samo mi je lakse ovako
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
			for (int i = 0; i < a.nodes.size(); i++) {
				ofs << *(a.nodes[i]);
			}
			ofs << "addPaths#\n";//razdvaja nodes i paths
			for (const auto& x : a.paths) {
				ofs << x.first << ' ' << x.second << '\n';
			}
			return ofs;
		}
		friend std::ostream& operator<<(std::ostream& os, const Graph<T>& a) {
			for (int i = 0; i < a.nodes.size(); i++) {
				os << *(a.nodes[i]);
			}
			for (const auto& x : a.paths) {
				os << x.first << ' ' << x.second << std::endl;
			}
			return os;
		}
		friend std::istream& operator>>(std::ifstream& ifs, Graph<T>& a) {
			char delim = '#';
			std::string type;
			while (std::getline(ifs, type, delim)&&type!="addPaths") {
			//	std::cout << type << std::endl;
				ptr<Node<T>> temp;
				if (type == typeid(Addition<T>).raw_name()) {
					temp =std::make_shared<Addition<T>>();
				}else if (type == typeid(Multiply<T>).raw_name()) {
					temp =std::make_shared<Multiply<T>>();
				}else if (type == typeid(Subtract<T>).raw_name()) {
					temp =std::make_shared<Subtract<T>>();
				}else if (type == typeid(MultiplyScalar<T>).raw_name()) {
					temp =std::make_shared<MultiplyScalar<T>>();
				}else if (type == typeid(AddScalar<T>).raw_name()) {
					temp =std::make_shared<AddScalar<T>>();
				}else if (type == typeid(Inverse<T>).raw_name()) {
					temp =std::make_shared<Inverse<T>>();
				}else if (type == typeid(BinaryOperation<T>).raw_name()) {
					temp = std::make_shared<BinaryOperation<T>>([](const T& a, const T& b) {
						T res(a);
					for (int i = 0; i < res.size(); i++) {
						res[i] = a[i] + b[i];
					}
					return res;
						});
				}else if (type == typeid(UnaryOperation<T>).raw_name()) {
					temp =std::make_shared<UnaryOperation<T>>([](const T& tenz) {
						T res(tenz);
					for (int i = 0; i < tenz.size(); i++) {
						res[i] = -tenz[i];
					}
					return res;
						});
				}else if (type == typeid(ScalarOperation<T>).raw_name()) {
					temp =std::make_shared<ScalarOperation<T>>([](const T& a, const double b) {
						T res(a);
					for (int i = 0; i < res.size(); i++) {
						res[i] = a[i] + b;
					}
					return res;
						});
				}else if (type == typeid(Leaf<T>).raw_name()) {
					temp = std::make_shared<Leaf<T>>();
					//std::string str;
				//	std::getline(ifs, str, delim);
				//	std::stringstream ss(str);
					temp->deserialize(ifs);
				}else if(type.length()>3){
					//std::cout << type;
					throw std::exception("Invalid Node Type");
					//std::cout << "AAAAA";
				}
				else {
					continue;
				}
			//	std::cout << "A";
				a.addNode(temp);
			}
			//std::cout << "TYPE: "<<type << std::endl;
			size_t b, c;
			while (ifs >> b >> c) {
				a.addPath(b, c);
			}
			return ifs;
		}
	};
}
