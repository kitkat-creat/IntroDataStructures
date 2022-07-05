// sodukuDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "sudoku.h"
#define N 4
using namespace std;
int main()
{
    sudoku s;
    int grid[N][N];
   
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];

        }
    }
    if (s.solveSudoku(grid, 0, 0))
    {
        cout << endl;
        cout << "---------- Solution ----------" << endl;
        s.print(grid);
    }
    else
        cout << "no solution  exists " << endl;
    
    return 0;
}


