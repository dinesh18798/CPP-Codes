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

void treeAsString(Tree<int> *t, string &str)
{
    if (t == nullptr)
    {
        str += 'a';
        return;
    }

    treeAsString(t->left, str);
    str += t->value + '0';
    treeAsString(t->right, str);
}

bool areIdentical(Tree<int> *t1, Tree<int> *t2)
{
    if (t1 == nullptr && t2 == nullptr)
        return true;

    if (t1 == nullptr || t2 == nullptr)
        return false;

    return (t1->value == t2->value && areIdentical(t1->left, t2->left) && areIdentical(t1->right, t2->right));
}

bool isSubtree(Tree<int> *t1, Tree<int> *t2)
{
    if (t2 == nullptr)
        return true;

    if (t1 == nullptr)
        return false;

    if (areIdentical(t1, t2))
        return true;

    return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

int main()
{
    Tree<int> *t1 = new Tree<int>(5);
    t1->left = new Tree<int>(10);
    t1->left->left = new Tree<int>(4);
    t1->left->left->left = new Tree<int>(1);
    t1->left->left->right = new Tree<int>(2);
    t1->left->right = new Tree<int>(6);
    t1->left->right->right = new Tree<int>(-1);
    t1->right = new Tree<int>(7);

    Tree<int> *t2 = new Tree<int>(10);
    t2->left = new Tree<int>(4);
    t1->left->left = new Tree<int>(1);
    t1->left->right = new Tree<int>(2);
    t1->right = new Tree<int>(6);
    t1->right->right = new Tree<int>(-1);

    cout << isSubtree(t1, t2) << endl;

    return 1;
}
