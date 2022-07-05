#include "sudoku.h"
#include <iostream>
#define N 4         //defining 4 as constant
using namespace std;


void sudoku::print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

//row, column, matrix check all in one
bool sudoku::canPlaceNum(int grid[N][N], int row, int col, int num)
{

    for (int x = 0; x < N; x++)  //if there is the same number in the row, then return false
        if (grid[row][x] == num)
            return false;

    
    for (int x = 0; x < N; x++)  //if there is the same number in col, then false
        if (grid[x][col] == num)
            return false;

    // Check if we find the same num in 
    // the particular 3*3 matrix,
    // we return false
    int startRow = row - row % 3,  
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}


bool sudoku::solveSudoku(int grid[N][N], int row, int col)
{

    if (row == N - 1 && col == N) //if we reached to the end of the cell, we return true to avoid 
        return true;               //exceeding of backtracking


    if (col == N) //if col becomes 9, then move onto the next row, with col becomes zero
    {
        row++;
        col = 0;
    }

 
    if (grid[row][col] > 0)    //if the current grid already has a number bigger than 0, then we move to next col
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {

  
        if (canPlaceNum(grid, row, col, num)) 
        {


            grid[row][col] = num; //if the condition is true, then place the num in the current grid

            if (solveSudoku(grid, row, col + 1)) //check the same condition for next col
                return true;
        }


        grid[row][col] = 0;
    }
    return false;
}
