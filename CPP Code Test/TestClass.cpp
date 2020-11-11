#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Question 4 (10 points)
//
// Implement a C function which converts a character string into a signed
// integer without using any library functions.  Assume that the string
// contains a valid integer, and no white space.
//
///////////////////////////////////////////////////////////////////////////////
int StringToInt(const char *szString)
{
    // write your implementation here
    int number = 0;
    int i = 0;
    bool isNegative = false;

    //check negative or positve number

    char p = szString[i];
    while (p != '\0')
    {
        if (p == '-')
            isNegative = true;
        else if (p == '+')
        {
            p = szString[++i];
            continue;
        }
        else
            number = (number * 10) + (p - '0');
        p = szString[++i];
    }
    if (isNegative)
        number *= -1;
    return number;
}

void TestStringToInt()
{
    int iValue = StringToInt("-640");
    cout << iValue << endl;
    int testZero = StringToInt("0000111111");
    cout << testZero << endl;
    int testZeroNegative = StringToInt("0000-7452");
    cout << testZeroNegative << endl;
    int testPositiveSign = StringToInt("+6325151");
    cout << testPositiveSign << endl;
}

int main()
{
    TestStringToInt();
}