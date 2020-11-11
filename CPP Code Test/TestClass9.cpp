#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;
};

struct DoublyLinkedListNode
{
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;
};

SinglyLinkedListNode *reverse(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *currentHead = head;
    SinglyLinkedListNode *next = nullptr, *prev = nullptr;

    while (currentHead)
    {
        next = currentHead->next;
        currentHead->next = prev;
        prev = currentHead;
        currentHead = next;
    }

    return prev;
}

DoublyLinkedListNode *reverseDouble(DoublyLinkedListNode *head)
{

    DoublyLinkedListNode *temp = nullptr;
    DoublyLinkedListNode *newHead = head;
    DoublyLinkedListNode *currentHead = head;

    while (currentHead)
    {
        temp = currentHead->prev;
        currentHead->prev = currentHead->next;
        currentHead->next = temp;
        newHead = currentHead;
        currentHead = currentHead->prev;
    }

    return newHead;
}
