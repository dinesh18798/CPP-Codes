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

bool hasPathWithGivenSum(Tree<int> *t, int s)
{
    if (t == nullptr)
        return false;

    int diff = s - t->value;
    bool result = false;

    if (diff == 0 && !t->left && !t->right)
        return true;

    if (t->left)
        result = result || hasPathWithGivenSum(t->left, diff);

    if (t->right)
        result = result || hasPathWithGivenSum(t->right, diff);

    return result;
}
