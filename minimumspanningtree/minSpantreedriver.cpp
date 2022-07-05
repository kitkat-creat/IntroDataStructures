// MinSpanTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include "MinspanTree.h"
using namespace std;




// Driver code
int main()
{

    Graph g(8);
    g.AddWeightedEdge(1, 2, 6);
    g.AddWeightedEdge(1, 6, 5);
    g.AddWeightedEdge(2, 1, 6);
    g.AddWeightedEdge(2, 6, 8);
    g.AddWeightedEdge(2, 7, 7);
    g.AddWeightedEdge(2, 3, 10);
    g.AddWeightedEdge(3, 2, 10);
     g.AddWeightedEdge(3,7, 5);
     g.AddWeightedEdge(3, 5, 10);
     g.AddWeightedEdge(3, 4, 8);
    g.AddWeightedEdge(4, 3, 8);
    g.AddWeightedEdge(4, 5, 8);
    g.AddWeightedEdge(5, 6, 12);
    g.AddWeightedEdge(5, 7, 7);
    g.AddWeightedEdge(5, 3, 10);
    g.AddWeightedEdge(5, 4, 8);
    g.AddWeightedEdge(6, 1, 5);
    g.AddWeightedEdge(6, 2, 8);
    g.AddWeightedEdge(6, 7, 7);
    g.AddWeightedEdge(6, 5, 12);
    g.AddWeightedEdge(7, 2, 7);
 g.AddWeightedEdge(7, 3, 5);
 g.AddWeightedEdge(7, 5, 7);
    g.AddWeightedEdge(7, 6, 7);
   
   
   
   
    g.kruskal();
    g.print();
    return 0;
}
