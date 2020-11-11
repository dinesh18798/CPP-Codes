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

ListNode<int> *reverse(ListNode<int> *list)
{
    ListNode<int> *currentHead = list;
    ListNode<int> *prev = nullptr;
    ListNode<int> *next = nullptr;

    while (currentHead)
    {
        next = currentHead->next;
        currentHead->next = prev;
        prev = currentHead;
        currentHead = next;
    }

    return prev;
}

bool isListPalindrome(ListNode<int> *l)
{
    ListNode<int> *forwardList = l;
    ListNode<int> *reverseList = l;

    while (forwardList && forwardList->next)
    {
        reverseList = reverseList->next;
        forwardList = forwardList->next->next;
    }

    forwardList = l;
    reverseList = reverse(reverseList);

    while (reverseList)
    {
        if (forwardList->value != reverseList->value)
        {
            return false;
        }
        forwardList = forwardList->next;
        reverseList = reverseList->next;
    }

    return true;
}

/*bool isListPalindrome(ListNode<int> *l)
{
    string forwardStr = "";
    string reverseStr = "";
    ListNode<int> *currentHead = l;

    while (currentHead)
    {
        forwardStr += currentHead->value + '0';
        reverseStr = (char)(currentHead->value + '0') + reverseStr;
        currentHead = currentHead->next;
    }

    return forwardStr == reverseStr;
}*/

int main(void)
{
    ListNode<int> *node = new ListNode<int>(1);
    node->next = new ListNode<int>(2);
    node->next->next = new ListNode<int>(2);
    node->next->next->next = new ListNode<int>(3);

    cout << isListPalindrome(node) << endl;
    return 1;
}
