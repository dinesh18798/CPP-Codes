#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int matrixElementsSum(vector<vector<int>> matrix)
{
    int col = matrix[0].size();
    int row = matrix.size();

    int sum = 0;

    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            if (!matrix[j][i])
                break;
            sum += matrix[j][i];
        }
    }

    return sum;
}

int main()
{
    vector<vector<int>> matrix(3);

    matrix[0] = vector<int>{1, 1, 1, 0};
    matrix[1] = vector<int>{0, 5, 0, 1};
    matrix[2] = vector<int>{2, 1, 3, 10};

    matrixElementsSum(matrix);
    return 1;
}
