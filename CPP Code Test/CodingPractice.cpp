#include <iostream>
#include <iterator>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *prev;

    ListNode() : data(0),
                 next(NULL),
                 prev(NULL)
    {
    }
};

ListNode *reverseList(ListNode *head)
{
    ListNode *newHead = head;

    // *** TODO: add code here to reverse the linked list passed in
    ListNode *tempPrev = NULL, *tempNext = NULL;

    while (newHead != NULL)
    {
        tempNext = newHead->next;
        newHead->next = tempPrev;
        tempPrev = newHead;
        newHead = tempNext;
    }

    newHead = tempPrev;
    return newHead;
}

ListNode *reverseList(ListNode *head, int k)
{
    ListNode *newHead = head;

    // *** TODO: add code here to reverse the linked list passed in
    ListNode *tempPrev = NULL, *tempNext = NULL;
    int count = 0;

    while (newHead != NULL && count < k)
    {
        tempNext = newHead->next;
        newHead->next = tempPrev;
        tempPrev = newHead;
        newHead = tempNext;
        count++;
    }

    if (tempNext != NULL)
    {
        head->next = reverseList(tempNext, k);
    }

    newHead = tempPrev;
    return newHead;
}

// Example function that calls reverseList.
void doSomeWork()
{
    ListNode *listHead = new ListNode[5];
    for (int i = 0; i < 5; i++)
    {
        listHead[i].data = i;
        listHead[i].next = (i < 4) ? listHead + i + 1 : NULL;
        listHead[i].prev = (i > 0) ? listHead + i - 1 : NULL;
    }

    cout << "Print Before" << endl;
    ListNode *newList = listHead;
    while (newList != NULL)
    {
        int value = newList->data;
        cout << value << endl;
        newList = newList->next;
    }

    listHead = reverseList(listHead, 2);

    cout << "Print After" << endl;
    for (int i = 0; i < 5; i++)
    {
        int value = listHead->data;
        cout << value << endl;
        listHead = listHead->next;
    }
}

int main()
{
    doSomeWork();
    return 0;
}