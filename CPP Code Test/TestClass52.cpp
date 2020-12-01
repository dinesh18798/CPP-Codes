#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

string LexicographicalMaxString(string str)
{
    char maxchar = 'a';
    vector<int> index;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] > maxchar)
            index.clear();

        if (str[i] >= maxchar)
        {
            maxchar = str[i];
            index.push_back(i);
        }
    }
    string maxstring = "";

    for (int i = 0; i < index.size(); i++)
    {
        string temp = str.substr(index[i], str.length());
        if (temp > maxstring)
        {
            maxstring = str.substr(index[i], str.length());
        }
    }
    return maxstring;
}

int main()
{
    int d = 5;
    int *p = &d;
    cout << p;
}