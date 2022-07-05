#include "airlinenetwork.h"
#include <iostream>
#include <list>
#include <vector>
#include <queue> 
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;


string Digraph::data(int k) const ///***this is the name of the city
{
    return myAdjacencyLists[k].data;
}



void Digraph::read(ifstream& inStream)
{
    VertexInfo vi;
    int n, vertex;
    myAdjacencyLists.push_back(vi);
    while (inStream >> vi.data)
    {


 inStream >> n;

        list<int> adjList;

        for (int i = 1; i <= n; i++)//
        {

            inStream >> vertex;


            adjList.push_back(vertex);



        }
        vi.adjacencyList = adjList;
        myAdjacencyLists.push_back(vi);

    }

}


void Digraph::display(ostream& out)
{
    out << "The Digraph's Adjacency-List Representation: \n";
    for (unsigned i = 1; i < myAdjacencyLists.size(); i++)
    {
        out << " " << i << ": " << setw(14) << myAdjacencyLists[i].data << " --> ";
        for (list<int>::iterator it = myAdjacencyLists[i].adjacencyList.begin();
            it != myAdjacencyLists[i].adjacencyList.end(); it++)
            out << *it << " ";
        out << endl;
    }
}




void Digraph::depthFirstSearch(int start)
{
    vector<bool> unvisited(myAdjacencyLists.size(), true);   // myAdjacencyLists.size() returns # of total of vertices    depthFirstSearchAux(start, unvisited);
}



void Digraph::depthFirstSearchAux(int start, vector<bool>& unvisited)
{
    
    cout << myAdjacencyLists[start].data << endl;

    unvisited[start] = false;
    
    for (list<int>::iterator it = myAdjacencyLists[start].adjacencyList.begin();
        it != myAdjacencyLists[start].adjacencyList.end(); it++)
        if (unvisited[*it])    
            depthFirstSearchAux(*it, unvisited); // start DFS from new node
}


vector<int> Digraph::shortestPath(int start, int destination)
{
    int n = myAdjacencyLists.size();   // n: total number of vertices
    vector<int> distLabel(n, -1),   
        predLabel(n);       
    
    distLabel[start] = 0;  
    int distance = 0,       
        vertex;          
    queue<int> vertexQueue;    
    vertexQueue.push(start);
    while (distLabel[destination] < 0 && !vertexQueue.empty()) 
    {                                             
        vertex = vertexQueue.front();
        vertexQueue.pop();
        if (distLabel[vertex] > distance)
            distance++;
        for (list<int>::iterator it = myAdjacencyLists[vertex].adjacencyList.begin();
            it != myAdjacencyLists[vertex].adjacencyList.end(); it++)
            if (distLabel[*it] < 0)
            {
                distLabel[*it] = distance + 1;
                predLabel[*it] = vertex;
                vertexQueue.push(*it);
            }
    }
    distance++;

   
    vector<int> path(distance + 1);   
    if (distLabel[destination] < 0)   
        cout << "Destination not reachable from start vertex\n";
    else
    {
        path[distance] = destination;
        for (int k = distance - 1; k >= 0; k--)
            path[k] = predLabel[path[k + 1]];
    }

    return path;
}



