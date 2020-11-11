#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> numbers;
    for (int i = 0; i < size; ++i)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    int queries;
    cin >> queries;

    for (int q = 0; q < queries; ++q)
    {
        int currentQuery;
        cin >> currentQuery;

        vector<int>::iterator lower = lower_bound(numbers.begin(), numbers.end(), currentQuery);

        if (numbers[lower - numbers.begin()] == currentQuery)
            printf("Yes %d\n", lower - numbers.begin() + 1);
        else
            printf("No %d\n", lower - numbers.begin() + 1);
    }

    return 0;
}