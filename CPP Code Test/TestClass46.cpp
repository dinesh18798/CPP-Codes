#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <chrono>
using namespace std;

int main()
{
    string str(2000000, 'a');

    int count = 0;
    auto t1 = chrono::high_resolution_clock::now();

    /*for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == 'a')
            ++count;
    }*/
    count = std::count(str.begin(), str.end(), 'a');
    auto t2 = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "For Loop: " << duration << " microseconds" << endl;
    cout << count << endl;
    return 1;
}