///////////////////////////////////////////////////////////////////////////////
//
// Question 2 (5 points)
//
// Given the following BinaryTreeElement class write the implementation of the
// Search() function for a sorted binary tree.
//
// For extra credit, you should consider efficiency with large data sets under
// the assumption that the compiler will not perform "clever" optimisations.
//
///////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

class BinaryTreeElement
{
public:
    // assume the class has a full implementation for element creation and
    // and tree manipulation. You only have to implement the Search() function

    BinaryTreeElement *Search(char cData);

private:
    char m_cData;
    BinaryTreeElement *m_pxLeftSubtree;
    BinaryTreeElement *m_pxRightSubtree;
};

// Replace this with your implementation of the Search() function:
BinaryTreeElement *BinaryTreeElement::Search(char cData)
{
    // -- Assign the head of the binary tree as the current element
    BinaryTreeElement *currentElement; // = head;

    while (currentElement != nullptr)
    {
        if (currentElement->m_cData == cData)
            break;

        if (currentElement->m_cData > cData)
            currentElement = currentElement->m_pxLeftSubtree;
        else if (currentElement->m_cData < cData)
            currentElement = currentElement->m_pxRightSubtree;
    }

    return currentElement;
}