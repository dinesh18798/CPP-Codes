#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        long long reverse = 0;
        int original = x;

        while (original)
        {
            reverse = reverse * 10 + (original % 10);
            original = original / 10;
        }

        return reverse == x;
    }
};

struct Base
{
public:
    virtual void show() { cout << "In Base \n"; }
};

struct Derived : Base
{
public:
    void show()
    {
        Base::show();
        cout << "In Derived \n";
    }
};

int main()
{
    Base *bp = new Derived;
    bp->show(); // <- Runtime Polymorphism in Action*/
    Solution s;
    //cout << s.reverse(1534236469);

    cout << s.isPalindrome(2) << endl;

    string *test = new string;

    cout << test << "\t" << &test;

    int firstvalue = 5, secondvalue = 15;
    int *p1, *p2;
    int intTest;

    p1 = &firstvalue;  // p1 = address of firstvalue
    p2 = &secondvalue; // p2 = address of secondvalue
    *p1 = 10;          // value pointed to by p1 = 10
    *p2 = *p1;         // value pointed to by p2 = value pointed to by p1 (pointer dereference assigning the value)
    p1 = p2;           // p1 = p2 (value of pointer is copied)
    *p1 = 20;          // value pointed to by p1 = 20

    intTest = *p1;

    cout << "firstvalue is " << firstvalue << '\n';
    cout << "secondvalue is " << secondvalue << '\n';
    return 0;

    return 0;
}