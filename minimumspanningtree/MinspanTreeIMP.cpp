#include "MinspanTree.h"
#include <iostream>
using namespace std;

Graph::Graph(int V) {
    parent = new int[V];     //parent as pointer


    for (int i = 0; i < V; i++) //store data in parent
        parent[i] = i;

    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int source, int dest, int weight) {
    G.push_back(make_pair(weight, edge(source, dest)));
} //push data into graph 
int Graph::find_set(int i) {
    
    if (i == parent[i])
        return i;
    else
       
        return find_set(parent[i]);
}

void Graph::union_set(int source, int dest) {
    parent[source] = parent[dest];
}
void Graph::kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end());  // increasing weight
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {
            T.push_back(G[i]);  // add to tree
            union_set(uRep, vRep);
        }
    }
}
void Graph::print() {
    int total=0;
    cout << "Edges of MST are: " << endl;
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " - " << T[i].second.second << " = "
            << T[i].first;
        cout << endl;
        total += T[i].first;
    }
    cout << "Weight of MST is:" << total;
}