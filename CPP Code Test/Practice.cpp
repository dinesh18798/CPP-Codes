#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define SQUARE(x) (x * x)

///////////////////////////////////////////////////////////////////////////////
//
// Question 1 (5 points)
//
// Given the following ListElement class write the implementation of the
// Insert() function.
//
// You should consider what happens if you insert to the start, middle or the
// end of the list.
//
///////////////////////////////////////////////////////////////////////////////

class ListElement
{
public:
    ListElement(char cData)
        : m_cData(cData), m_pxPrev(0), m_pxNext(0)
    {
    }

    static void Insert(ListElement *pxElementToInsert,
                       ListElement *pxInsertionPosition);

private:
    char m_cData;
    ListElement *m_pxPrev;
    ListElement *m_pxNext;
};

void ListElement::Insert(ListElement *pxElementToInsert,
                         ListElement *pxInsertionPosition)
{
    // At start
    if (pxInsertionPosition->m_pxPrev == nullptr)
    {
        pxInsertionPosition->m_pxPrev = pxElementToInsert;
        pxElementToInsert->m_pxNext = pxInsertionPosition;
        pxElementToInsert->m_pxPrev = nullptr;
    }
    //At end
    else if (pxInsertionPosition->m_pxNext == nullptr)
    {
        pxInsertionPosition->m_pxNext = pxElementToInsert;
        pxElementToInsert->m_pxPrev = pxInsertionPosition;
        pxElementToInsert->m_pxNext = nullptr;
    }
    //At middle
    else if (pxInsertionPosition->m_pxPrev != nullptr && pxInsertionPosition->m_pxNext != nullptr)
    {
        pxElementToInsert->m_pxNext = pxInsertionPosition->m_pxNext;
        pxInsertionPosition->m_pxNext = pxElementToInsert;
        pxElementToInsert->m_pxPrev = pxInsertionPosition;
        pxInsertionPosition->m_pxNext->m_pxPrev = pxElementToInsert;
    }
}

int main()
{
    int sq = SQUARE(2 / 3);

    cout << sq;
}