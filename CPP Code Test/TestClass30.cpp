#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int makeArrayConsecutive2(vector<int> statues)
{
    vector<int> needed;
    sort(statues.begin(), statues.end());

    for (int i = statues[0] + 1; i < statues[statues.size() - 1]; ++i)
    {
        if (find(statues.begin(), statues.end(), i) == statues.end())
        {
            needed.push_back(i);
        }
    }
    return needed.size();
}

int main(void)
{
    vector<int> numbers = {6, 2, 3, 8};
    makeArrayConsecutive2(numbers);
    return 1;
}
