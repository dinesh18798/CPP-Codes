#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    //! This method returns a pointer to the node with the given​​​​​​‌​​​‌‌‌‌​​‌​‌​‌‌​‌​‌​‌​‌‌ value.
    Node *find(int v)
    {
        if (value == v)
            return this;
        if (value > v)
        {
            if (this->left)
                return this->left->find(v);
        }
        else if (value < v)
        {
            if (this->right)
                return this->right->find(v);
        }
        Node *r = new Node();
        r->value = 0;
        return r;
    }
};

int main(void)
{
    Node *n = new Node();
    n->value = 9;
    n->left = new Node();
    n->left->value = 7;
    n->left->right = new Node();
    n->left->right->value = 8;

    Node *a = n->find(0);
    cout << a->value << endl;
}
