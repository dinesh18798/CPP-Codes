#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int getValue(int row, int column, vector<vector<bool>> matrix)
{
    int count = 0;
    int rowBegin = row - 1 < 0 ? 0 : row - 1;
    int rowEnd = row + 1 < matrix.size() ? row + 1 : matrix.size();

    int colBegin = column - 1 < 0 ? 0 : column - 1;
    int colEnd = column + 1 < matrix[0].size() ? column + 1 : matrix[0].size();

    for (int i = rowBegin; i <= rowEnd; ++i)
    {
        for (int j = colBegin; j <= colEnd; ++j)
        {
            if (i == row && j == column)
                continue;
            count += matrix[i][j];
        }
    }
    return count;
}

vector<vector<int>> minesweeper(vector<vector<bool>> matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    vector<vector<int>> result(rows, vector<int>(columns));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            result[i][j] = getValue(i, j, matrix);
        }
    }
    return result;
}

int main()
{
    vector<vector<bool>> matrix;

    matrix.push_back(vector<bool>{true, false, false});
    matrix.push_back(vector<bool>{false, true, false});
    matrix.push_back(vector<bool>{false, false, false});

    minesweeper(matrix);
    return 1;
}

/*
bool getValue(int row, int column, vector<vector<bool>> matrix)
{
    if ((row >= 0 && row < matrix.size()) && (column >= 0 && column < matrix[0].size()))
    {
        return matrix[row][column];
    }
    return false;
}

vector<vector<int>> minesweeper(vector<vector<bool>> matrix)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    vector<vector<int>> result(rows, vector<int>(columns));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            int count = 0;
            int currentRow = i;
            int currentColumn = j;

            //North
            count += getValue(currentRow - 1, currentColumn, matrix);
            //NorthEast
            count += getValue(currentRow - 1, currentColumn + 1, matrix);
            //East
            count += getValue(currentRow, currentColumn + 1, matrix);
            //SouthEast
            count += getValue(currentRow + 1, currentColumn + 1, matrix);
            //South
            count += getValue(currentRow + 1, currentColumn, matrix);
            //SouthWest
            count += getValue(currentRow + 1, currentColumn - 1, matrix);
            //West
            count += getValue(currentRow, currentColumn - 1, matrix);
            //NorthWest
            count += getValue(currentRow - 1, currentColumn - 1, matrix);

            result[currentRow][currentColumn] = count;
        }
    }
    return result;
}
*/