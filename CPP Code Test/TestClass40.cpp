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

bool isMirror(Tree<int> *root1, Tree<int> *root2)
{
    if (!root1 && !root2)
        return true;

    if (root1 && root2 && (root1->value == root2->value))
    {
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
    return false;
}

bool isTreeSymmetric(Tree<int> *t)
{
    return isMirror(t, t);
}

int main()
{
    Tree<int> *t = new Tree<int>(3);
}