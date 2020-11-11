#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Singly-linked lists are already defined with this interface:
template <typename T>
struct ListNode
{
    ListNode(const T &v) : value(v), next(nullptr) {}
    T value;
    ListNode *next;
};

ListNode<int> *removeKFromList(ListNode<int> *l, int k)
{
    if (l == nullptr)
        return l;

    ListNode<int> *currentHead = l;
    ListNode<int> *prev = nullptr;
    ListNode<int> *temp = nullptr;

    while (currentHead && currentHead->value == k)
    {
        temp = currentHead;
        currentHead = currentHead->next;
    }

    ListNode<int> *newHead;
    if (currentHead != nullptr)
        newHead = currentHead;
    else
        return l;

    while (currentHead)
    {
        if (currentHead->value == k)
        {
            prev->next = currentHead->next;
        }
        prev = currentHead;
        currentHead = currentHead->next;
    }

    return l;
}

int main(void)
{
    ListNode<int> *node = new ListNode<int>(1000);
    node->next = new ListNode<int>(1000);
    removeKFromList(node, 1000);
    return 1;
}
