
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            //map the key to the node in the linked list
    int cp;                         //capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0;       //get function
};

class LRUCache : public Cache
{
public:
    LRUCache(int capacity)
    {
        cp = capacity;
        tail = NULL;
        head = NULL;
    }

    void set(int, int) override;
    int get(int) override;
};

void LRUCache::set(int key, int value)
{
    Node *node;

    if (mp.empty())
    {
        node = new Node(key, value);
        head = tail = node;
        mp[key] = node;
        return;
    }

    if (mp.find(key) != mp.end())
    {
        mp[key]->value = value;

        if (head == mp[key])
            return;

        mp[key]->prev->next = mp[key]->next;

        if (mp[key] == tail)
        {
            tail->prev->next = tail->next;
            tail = tail->prev;
        }
        else
        {
            mp[key]->next->prev = mp[key]->prev;
        }

        head->prev = mp[key];
        mp[key]->next = head;
        mp[key]->prev = NULL;
        head = mp[key];
    }
    else
    {
        node = new Node(NULL, head, key, value);
        if (head)
            head->prev = node;
        head = node;
        mp[key] = node;

        if (mp.size() > cp)
        {
            tail = tail->prev;
            mp.erase(tail->next->key);
            delete tail->next;
            tail->next = NULL;
        }
    }
}

int LRUCache::get(int key)
{
    if (mp.find(key) != mp.end())
    {
        return mp[key]->value;
    }
    else
        return -1;
}