#pragma once
#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
private:
    vector<pair<int, edge> > G;  // graph
    vector<pair<int, edge> > T;  // minimum span tree
    int* parent;
    int V;  // number of vertices/nodes in graph
public:
    Graph(int V);
    void AddWeightedEdge(int source, int dest, int weight);
    int find_set(int i);
    void union_set(int source, int weight);
    void kruskal();
    void print();
};


