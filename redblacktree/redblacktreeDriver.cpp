// redBlackTreeDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "redBlacktree.h"

using namespace std;

int main()
{
    int num;
    redBlacktree rbt;

    cout << "Enter value to be inserted: ";
    while (true)
    {

        cin >> num;
        if (num < 0)
        {
            cout << "Balanced Red Black Tree:" << endl;
            rbt.printTree();
            return false;
        }
        else
            rbt.insert(num);
    }
    
    return 0;
}
