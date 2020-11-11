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

ListNode<int> *rearrangeLastN(ListNode<int> *l, int n)
{
    if (l == nullptr)
        return l;

    ListNode<int> *rearrangeList = l;
    ListNode<int> *tail = l;

    int count = 1;
    while (tail->next)
    {
        ++count;
        tail = tail->next;
    }

    int diff = count - n;

    if (diff == 0 || diff == count)
        return l;

    ListNode<int> *prev = nullptr;

    while (rearrangeList->next)
    {
        if (diff-- == 0)
        {
            break;
        }

        prev = rearrangeList;
        rearrangeList = rearrangeList->next;
    }

    tail->next = l;

    if (prev->next)
        prev->next = nullptr;

    return rearrangeList;
}

/*ListNode<int> *rearrangeLastN(ListNode<int> *l, int n)
{

    if (l == nullptr)
        return l;

    ListNode<int> *rearrangeList = l;

    while (n--)
    {
        ListNode<int> *prev = rearrangeList;
        ListNode<int> *tail = rearrangeList;
        while (tail->next)
        {
            prev = tail;
            tail = tail->next;
        }

        prev->next = nullptr;
        tail->next = rearrangeList;
        rearrangeList = tail;
    }

    return rearrangeList;
}*/

int main()
{
    ListNode<int> *node1 = new ListNode<int>(1);
    node1->next = new ListNode<int>(2);
    node1->next->next = new ListNode<int>(3);
    node1->next->next->next = new ListNode<int>(4);
    node1->next->next->next->next = new ListNode<int>(5);
    // node1->next->next->next->next->next = new ListNode<int>(9999);

    //ListNode<int> *node2 = new ListNode<int>(1);
    //node2->next = new ListNode<int>(8001);

    rearrangeLastN(node1, 1);
}
