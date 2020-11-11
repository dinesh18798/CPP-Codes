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

unsigned long long getNumbers(ListNode<int> *listNode)
{
    unsigned long long result = 0;
    ListNode<int> *currentHead = listNode;

    while (currentHead)
    {
        result = (result * 10000) + currentHead->value;
        currentHead = currentHead->next;
    }

    return result;
}

/*ListNode<int> *addTwoHugeNumbers(ListNode<int> *a, ListNode<int> *b)
{
    unsigned long long aNum = getNumbers(a);
    unsigned long long bNum = getNumbers(b);

    long long sum = aNum + bNum;

    ListNode<int> *resList = nullptr;
    ListNode<int> *currentList = nullptr;

    while (sum > 0)
    {
        currentList = new ListNode<int>(sum % 10000);
        sum /= 10000;
        currentList->next = resList;
        resList = currentList;
    }

    return resList;
}*/

ListNode<int> *addTwoHugeNumbers(ListNode<int> *a, ListNode<int> *b)
{
    ListNode<int> *aNum = reverse(a);
    ListNode<int> *bNum = reverse(b);

    ListNode<int> *resList = nullptr;
    ListNode<int> *currentList = nullptr;

    int carry = 0;
    while (aNum || bNum || carry)
    {
        int sum = carry;
        carry = 0;
        if (aNum)
        {
            sum += aNum->value;
            aNum = aNum->next;
        }

        if (bNum)
        {
            sum += bNum->value;
            bNum = bNum->next;
        }
        if (sum > 9999)
        {
            sum = 10000 - sum;
            carry = 1;
        }

        currentList = new ListNode<int>(sum);
        currentList->next = resList;
        resList = currentList;
    }

    return resList;
}

int main()
{
    ListNode<int> *node1 = new ListNode<int>(9998);
    node1->next = new ListNode<int>(9999);
    node1->next->next = new ListNode<int>(9999);
    node1->next->next->next = new ListNode<int>(9999);
    node1->next->next->next->next = new ListNode<int>(9999);
    node1->next->next->next->next->next = new ListNode<int>(9999);

    ListNode<int> *node2 = new ListNode<int>(1);
    //node2->next = new ListNode<int>(8001);

    addTwoHugeNumbers(node1, node2);
}
