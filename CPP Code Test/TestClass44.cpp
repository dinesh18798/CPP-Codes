#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    if (A.size() == 0)
        return 1;

    int maxNum = *std::max_element(A.begin(), A.end());

    if (maxNum <= 0)
        return 1;

    vector<int> tracker(maxNum, 0);

    for (int i = 0; i < (int)A.size(); ++i)
    {
        if (A[i] > 0)
            ++tracker[A[i] - 1];
    }

    for (int j = 0; j < maxNum; ++j)
    {
        if (tracker[j] == 0)
            return j + 1;
    }

    return maxNum + 1;
}

int main()
{
    vector<int> A = {-1000000, 1000000};
    solution(A);
    return 1;
}