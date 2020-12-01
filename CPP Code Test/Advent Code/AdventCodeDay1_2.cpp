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

    for (int i = 0; i < v.size() - 2; ++i)
    {
        int front = i + 1;
        int back = v.size() - 1;

        while (front < back)
        {
            int t = v[i] + v[front] + v[back];

            if (t == 2020)
            {
                cout << v[i] << " " << v[front] << " " << v[back] << endl;
                cout << "Addition : " << v[i] + v[front] + v[back] << endl;
                cout << "Multiplication : " << v[i] * v[front] * v[back] << endl;
            }
            if (t > 2020)
                --back;
            else
                ++front;
        }
    }

    return 0;
}