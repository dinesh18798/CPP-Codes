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

Tree<int> *restoreBinaryTree(vector<int> inorder, vector<int> preorder)
{
    if (inorder.size() == 0)
        return nullptr;

    Tree<int> *tree = new Tree<int>(preorder[0]);
    int leftLength = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

    tree->left = restoreBinaryTree(vector<int>(inorder.begin(), inorder.begin() + leftLength),
                                   vector<int>(preorder.begin() + 1, preorder.begin() + leftLength + 1));

    tree->right = restoreBinaryTree(vector<int>(inorder.begin() + leftLength + 1, inorder.end()),
                                    vector<int>(preorder.begin() + leftLength + 1, preorder.end()));
    return tree;
}

int main()
{
    Tree<int> *tree = restoreBinaryTree(vector<int>{4, 2, 1, 5, 3, 6}, vector<int>{1, 2, 4, 3, 5, 6});
    return 1;
}