#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int depositProfit(int deposit, int rate, int threshold)
{
    int year = 0;
    double r = (double)rate / 100;
    double dep = (double)deposit;

    while (dep < threshold)
    {
        dep += r * dep;
        ++year;
    }
    return year;
}

int main()
{
    depositProfit(100, 20, 170);
    return 1;
}
