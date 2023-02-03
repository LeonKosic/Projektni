#pragma once
#include "Node.h"

namespace Graph {
	template<typename T> class Leaf :public Node<T> {
	private:
		T value;
	public:
		Leaf(){}
		Leaf(const T& val) :value(val){}
		virtual T getResult() const {
			return value;
		}
		void setValue(const T& val) {
			value = val;
		}
		size_t size() const override { return 1; }
		virtual void serialize(std::ofstream& ofs) const override {
			//ofs << "# ";
			for (const auto& x : value) {
				ofs << x<< ' ';
			}
		}
		virtual void serialize(std::ostream& ofs) const override {
			for (const auto& x : value) {
				ofs << x << ' ';
			}
		}
		virtual void deserialize(std::ifstream& ifs) override {
			typename T::value_type t;
			std::string str;
			std::getline(ifs, str, '#');
			std::stringstream ss(str);
			while (ss >> t) {
				//std::cout << "-"<<t << "\n";
				value.push_back(t);
			}
			//std::cout <<"Type: "<<typeid(T::value_type).name()<<" Val:"<< t << ' ';
			
		}
		bool findDerivative(const ptr<Node<T>>& a) const override {
			return this == a.get();
		}
		virtual T derivative(const ptr<Node<T>>& a) override {
			T res;
			if (findDerivative(a)) {
				res = T(value.size(), 1);
			}
			else {
				res = T(value.size(),0);
			}
			return res;
		}
		
		friend std::ostream& operator<<(std::ofstream& ofs,const Leaf<T>& a) {
			a.serialize(ofs);
		}
		friend std::istream& operator>>(std::ifstream& ifs,Leaf<T>& a) {
			a.deserialize(ifs);
		}
	};

}