#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set<int> numbers;
    int queries;
    cin >> queries;

    for (int i = 0; i < queries; ++i)
    {
        int query, number;
        cin >> query >> number;
        set<int>::iterator itr;

        switch (query)
        {
        case 1:
            numbers.insert(number);
            break;
        case 2:
            numbers.erase(number);
            break;
        case 3:
            itr = numbers.find(number);
            if (itr != numbers.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}
