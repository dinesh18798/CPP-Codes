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

ListNode<int> *reverseNodesInKGroups(ListNode<int> *l, int k)
{
    if (k == 1)
        return l;

    ListNode<int> *reverseList = new ListNode<int>(0);
    ListNode<int> *currentHead = reverseList;

    int count = 0;
    ListNode<int> *dummyHead = l;
    ListNode<int> *dummyTail = l;

    while (dummyTail)
    {
        ++count;
        dummyTail = dummyTail->next;
        if (count == k)
        {
            //do reverse
            ListNode<int> *prev = nullptr;
            ListNode<int> *next = nullptr;
            ListNode<int> *start = dummyHead;

            while (dummyHead != dummyTail)
            {
                next = dummyHead->next;
                dummyHead->next = prev;
                prev = dummyHead;
                dummyHead = next;
            }

            currentHead->next = prev;
            currentHead = start;

            count = 0;
        }
    }

    if (count != k && dummyHead)
    {
        currentHead->next = dummyHead;
    }

    return reverseList->next;
}

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

    reverseNodesInKGroups(node1, 2);
}
