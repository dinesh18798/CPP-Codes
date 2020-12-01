#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main()
{
    vector<int> v;
    fstream myfile("E:\\data.txt", std::ios_base::in);
    int a;
    while (myfile >> a)
    {
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int front = 0;
    int back = v.size() - 1;

    while (front < back)
    {
        int t = v[front] + v[back];

        if (t == 2020)
        {
            cout << v[front] << " " << v[back] << endl;
            cout << "Addition : " << v[front] + v[back] << endl;
            cout << "Multiplication : " << v[front] * v[back] << endl;
        }
        if (t > 2020)
            --back;
        else
            ++front;
    }

    return 0;
}