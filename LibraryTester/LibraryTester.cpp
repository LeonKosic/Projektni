
#include <iostream>
#include "Graph.h"
#include "Multiply.h"
#include "Subtract.h"
#include "Tensor.h"
using tens = std::vector<double>;
void fillGraph(Graph::Graph<tens>& g){
    tens t1{ 1,.14,3.23,51,52 };
    tens t2{ 12,353.14,32.3223,551,523 };
    tens t3{ 1,23.14,33.223,5431,522 };
    tens t4{ 5.12,1.232,33.3,51,24 };
    tens t5{ 11,.4,32.63,123,12 };
    //dodajemo cvorove koji sadrze samo tenzore
    g.addNode(t1);//0
    g.addNode(t2);//1
    g.addNode(t3);//2
    g.addNode(t4);//3
    g.addNode(t5);//4
    //dodajemo operaciju sabiranja
    Graph::Addition<tens> add;
    g.addNode(std::make_shared<decltype(add)>(add));//5
    g.addPath(0, 5);
    g.addPath(1, 5);
    // dodajemo operaciju mnozenja
    Graph::Multiply<tens> mul;
    g.addNode(std::make_shared<decltype(mul)>(mul));//6
    g.addPath(2, 6);
    g.addPath(3, 6);
    //dodajemo operaciju invertovanja
    Graph::Inverse<tens> inv;
    g.addNode(std::make_shared<decltype(inv)>(inv));//7
    g.addPath(4, 7);
    //dodajemo operaciju oduzimanja
    Graph::Subtract<tens> sub;
    g.addNode(std::make_shared<decltype(sub)>(sub));//8
    g.addPath(6, 8);
    g.addPath(5, 8);
    //dodajemo operaciju sabiranja skalarom
    Graph::AddScalar<tens> addS(2.25);
    g.addNode(std::make_shared<decltype(addS)>(addS));//9
    g.addPath(7, 9);
    //dodajemo operaciju mnozenja skalarom
    Graph::MultiplyScalar<tens> mulS(1.25);
    g.addNode(std::make_shared<decltype(mulS)>(mulS));//10
    g.addPath(8, 10);
    //dodajemo sabiranje zadnja dva cvora
    Graph::Addition<tens> addF;
    g.addNode(std::make_shared<decltype(addF)>(addF));//11
    g.addPath(9, 11);
    g.addPath(10, 11);
}
void printNodeResult(Graph::Graph<tens>& g,int ind) {
    auto a = g[ind]->getResult();
    for (const auto& x : a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
void testGraphSerialization(const Graph::Graph<tens>& g,std::string name)
{
    std::ofstream ofs = std::ofstream(name);
    ofs << g;
    ofs.close();
}
void testGraphDeserialization(std::string name) {
    Graph::Graph<tens> g;
    std::ifstream ifs = std::ifstream(name);
    ifs >> g;
    ifs.close();
    std::cout << g;
}
int main()
{
    Graph::Graph<tens> g;
    fillGraph(g);
    //printNodeResult(g, 11);
    std::string file = "graph.txt";
    testGraphSerialization(g,file);
    testGraphDeserialization(file);
   // std::cout << g;
    //g.printJacobian();
}


