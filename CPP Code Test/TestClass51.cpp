#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

char findMiddle(string str)
{
    int total = 0;
    for (char c : str)
    {
        total += toupper(c);
    }
    return (char)(total / str.length());
}

int main()
{
    cout << findMiddle("ToavX") << endl;
    return 1;
}