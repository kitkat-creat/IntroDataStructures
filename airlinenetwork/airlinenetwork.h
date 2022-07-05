#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <queue> 
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;




class Digraph
{
public:
    /***** Member Functions *****/
    string data(int k) const;


    void read(ifstream& inStream);


    void display(ostream& out);


    void depthFirstSearch(int start);


    void depthFirstSearchAux(int start, vector<bool>& unvisited);


    vector<int> shortestPath(int start, int destination);




    class VertexInfo
    {
    public:
        string data;
        list<int> adjacencyList;           ////***number adj to city
    };

    vector<VertexInfo> myAdjacencyLists;  ////** name of city
};


	


