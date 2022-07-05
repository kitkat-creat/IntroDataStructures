// airlineNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "airlinenetwork.h"
#include <iostream>
#include <list>
#include <vector>
#include <queue> 
#include <fstream>
#include <iomanip>
#include <string>




using namespace std;

int main()
{
    string line;
    cout << "Enter name of network file: ";
    string networkFile;
    cin >> networkFile;
    ifstream inFile(networkFile);
    if (!inFile.is_open())
    {
        cout << "*** Cannot open " << networkFile << " ***\n";
        return false;
    }
    
    
    Digraph d;
    d.read(inFile);
    
    d.display(cout);
    cout << endl;

    int start, destination;
    char response;
    do
    {
        cout << " Number of start city? ";
        cin >> start;
        cout << "Number of destination? ";
        cin >> destination;

        vector<int> path = d.shortestPath(start, destination);
        cout << "Shortest path is:\n";

        for (unsigned k = 0; k < path.size() - 1; k++)
        {
            cout << setw(3) << path[k] << ' ' << d.data(path[k]) << endl;
            cout << " |\n"
                " v\n";
        }
        cout << setw(3) << destination << ' ' << d.data(destination) << endl;
        cout << "\nMore (Y or N)?";
        cin >> response;
    } while (response == 'y' || response == 'Y');
    return 0;
}


