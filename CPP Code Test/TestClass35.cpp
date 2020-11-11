#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <chrono>
using namespace std;

vector<string> allLongestStrings(vector<string> inputArray)
{
    int currentLongest = inputArray[0].length();
    vector<string> result;

    for (int i = 0; i < inputArray.size(); ++i)
    {
        string currentString = inputArray[i];

        if (currentString.length() == currentLongest)
        {
            result.push_back(currentString);
        }
        else if (currentString.length() > currentLongest)
        {
            currentLongest = currentString.length();
            result = vector<string>{currentString};
        }
    }

    return result;
}

int main()
{
    vector<string> strings{"young ", "yooooooung", "hot", "or", "not", "come", "on", "fire", "water", "watermelon"};
    strings.push_back("aba");
    strings.push_back("aa");
    strings.push_back("ad");
    strings.push_back("vcd");
    strings.push_back("aba");

    auto start = chrono::high_resolution_clock::now();

    vector<string> result = allLongestStrings(strings);

    // Get ending timepoint
    auto stop = chrono::high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method

    for (auto str : result)
    {
        cout << str << endl;
    }

    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}
