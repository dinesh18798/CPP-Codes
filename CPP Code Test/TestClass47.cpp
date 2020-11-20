#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <chrono>
using namespace std;

bool isExist(int nums[], int size, int k)
{
    int lower = 0;
    int upper = size - 1;

    if (nums[lower] == k)
        return true;
    if (nums[upper] == k)
        return true;

    if (k < nums[lower] || k > nums[upper])
        return false;

    while (lower <= upper)
    {
        int middle = (upper + lower) / 2;

        if (nums[middle] == k)
        {
            return true;
        }

        if (nums[middle] < k)
        {
            lower = middle + 1;
        }
        else
        {
            upper = middle - 1;
        }
    }
    return false;
}

int main()
{
    int nums[]{1, 2, 3, 4, 5, 6, 7};
    cout << isExist(nums, 7, 5) << endl;
    return 1;
}