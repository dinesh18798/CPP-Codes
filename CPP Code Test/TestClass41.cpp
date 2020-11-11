#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

vector<vector<int>> boxBlur(vector<vector<int>> image)
{
    int rows = image.size() - 2;
    int columns = image[0].size() - 2;

    int row = 0, column = 0;

    vector<vector<int>> blurImage;
    while (row < rows)
    {
        vector<int> blur;
        while (column < columns)
        {

            int totalSum = 0;
            for (int i = row; i < row + 3; ++i)
            {
                for (int j = column; j < column + 3; ++j)
                {
                    totalSum += image[i][j];
                }
            }
            blur.push_back(totalSum / 9);
            ++column;
        }
        blurImage.push_back(blur);
        column = 0;
        ++row;
    }
    return blurImage;
}

int main()
{
    vector<vector<int>> image;

    image.push_back(vector<int>{7, 4, 0, 1});
    image.push_back(vector<int>{5, 6, 2, 2});
    image.push_back(vector<int>{6, 10, 7, 8});
    image.push_back(vector<int>{1, 4, 2, 0});

    boxBlur(image);
}
