#pragma once
#include <iostream>
using namespace std;
#define N 4
class sudoku
{
public:    
	void print(int arr[N][N]);
	bool canPlaceNum(int grid[N][N], int row, int col, int num);
	bool solveSudoku(int grid[N][N], int row, int col);
	

private:
	int grid[N][N];


};

