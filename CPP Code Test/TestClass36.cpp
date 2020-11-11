#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <chrono>
using namespace std;

int commonCharacterCount(string s1, string s2)
{
    int r = 0;
    for (auto a : s1)
    {
        for (auto b : s2)
            if (a == b && a != ' ')
            {
                r++;
                a = ' ';
                b = ' ';
            }
    }
    return r;
}

int main()
{
    cout << commonCharacterCount("aabcc", "adcaa") << endl;
}
