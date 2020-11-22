#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <chrono>
using namespace std;

class Solution
{

public:
    int longestPath(vector<int> T)
    {
        int n = T.size();
        vector<vector<int>> citiesNetwork(n, vector<int>{});
        //we do this to denote that there is an edge between u and T[u] and vice-versa
        for (int u = 0; u < n; u++)
        {
            if (u != T[u])
            {
                citiesNetwork[u].push_back(T[u]);
                citiesNetwork[T[u]].push_back(u);
            }
        }
        return recurse(citiesNetwork, 0, -1, false);
    }

    int recurse(vector<vector<int>> citiesNetwork, int node, int parent, bool usedTicket)
    {
        //if we enter an odd numbered node and we have already
        //visited another odd-valued one, then we cannot proceed and just return 0
        if (usedTicket && node % 2 == 1)
            return 0;

        //find out how deep can we go, given the restriction
        //we can visit at most one odd-valued node
        int maxCities = 0;
        for (int next : citiesNetwork[node])
        {
            if (next != parent)
            {
                maxCities = max(maxCities, recurse(citiesNetwork, next, node, usedTicket | (node % 2 == 1)));
            }
        }

        //we add 1 to the answer, because we should
        //also count the node we are currently at
        return 1 + maxCities;
    }
};

int main()
{

    vector<int> connection{0, 9, 0, 2, 6, 8, 0, 8, 3, 0};

    Solution sol;
    cout << sol.longestPath(connection) << endl;
    cout << sol.longestPath(vector<int>{0, 0, 0, 1, 6, 1, 0, 0}) << endl;

    // Console.WriteLine($ "Path : {longest.longestPath(new int[] { 0, 0, 0, 1, 6, 1, 0, 0 })}");
    return 1;
}