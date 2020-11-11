#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int size = nums.size();
        int result = nums[0] + nums[1] + nums[size - 1];

        sort(nums.begin(), nums.end());

        for (int a = 0; a < size - 2; ++a)
        {
            if (a >= 1 && nums[a] == nums[a - 1])
                continue;
            int b = a + 1, c = size - 1;
            while (b < c)
            {
                int sum = nums[a] + nums[b] + nums[c];
                if (sum == target)
                    return sum;
                if (abs(target - sum) < abs(target - result))
                    result = sum;
                if (sum < target)
                    ++b;
                else
                    --c;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> strings = {0, 0, 0};

    cout << s.threeSumClosest(strings, 1) << endl;

    string test = string(3, 'M');

    cout << test << endl;
}