// LibraryTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "Multiply.h"
#include "Subtract.h"
#include "Tensor.h"
typedef std::vector<double> tens;
int main()
{
    Graph::Tensor<int, 3, 4, 2, 7> tenz;
    tenz[0] = 2;
    auto dims = tenz.getDimensions();
    for (auto x : dims)std::cout << x << " ";
    std::cout << tenz.size();
    tens t1{ 1,.14,3.23,51,52 };
    tens t2{ 12,353.14,32.3223,551,523 };
    tens t3{ 1,23.14,33.223,5431,522 };
    tens t4{ 5,3,3.3,1,2 };
    tens t5{ 11,.4,32.63,123,12 };
    Graph::Graph<tens> g;
    g.addNode(t1);
    g.addNode(t2);
    g.addNode(t3);
    g.addNode(t4); 
    g.addNode(t5);
    Graph::Multiply<tens> mul;
    g.addNode(std::make_shared<decltype(mul)>(mul));
    g.addPath(0, 5);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
