#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename T>
struct Tree
{
    Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
    T value;
    Tree *left;
    Tree *right;
};

int kthSmallestInBST(Tree<int> *t, int k)
{
    if (!t)
        return 0;

    Tree<int> *prev = nullptr, *curr = t;
    vector<int> datas;

    while (curr)
    {
        if (!curr->left)
        {
            datas.push_back(curr->value);
            curr = curr->right;
        }
        else
        {
            prev = curr->left;
            while (prev->right != nullptr && prev->right != curr)
                prev = prev->right;

            if (!prev->right)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = nullptr;
                datas.push_back(curr->value);
                curr = curr->right;
            }
        }

        if (datas.size() >= k)
            break;
    }

    return datas.size() >= k ? datas[k - 1] : 0;
}

int main()
{
    Tree<int> *t = new Tree<int>(3);
    t->left = new Tree<int>(1);
    t->right = new Tree<int>(5);
    t->right->left = new Tree<int>(4);
    t->right->right = new Tree<int>(6);

    kthSmallestInBST(t, 4);
    return 1;
}
