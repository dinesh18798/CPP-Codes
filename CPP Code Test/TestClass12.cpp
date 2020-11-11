#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, int> studentMarks;

    int queries;
    cin >> queries;

    for (int q = 0; q < queries; ++q)
    {
        int query, marks;
        string name;

        cin >> query >> name;
        if (query == 1)
        {
            cin >> marks;
            studentMarks[name] += marks;
        }
        else if (query == 2)
        {
            studentMarks.erase(name);
        }
        else if (query == 3)
        {
            cout << studentMarks[name] << endl;
        }
    }

    return 0;
}
