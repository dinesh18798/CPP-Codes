#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
//
// Question 3 (5 points)
//
// Compare the following function and macro definitions.
// Give 3 different use cases where the macro produces a result that may be
// unexpected.
//
///////////////////////////////////////////////////////////////////////////////
int Square(int iVal)
{
    return iVal * iVal;
}

#define SQUARE(x) (x * x)

// write your 3 use cases in the following function with comments explaining
// what the possible pitfalls are:
void SquareTest()
{
    // If float value passed, the SQUARE macro accept and return the value as float type,
    // but Square function accept the value as int and return as int too
    cout << "SQUARE: " << SQUARE(2.1) << " Square: " << Square(2.1) << endl;

    // If pass 3 + 4 as parameter, the SQUARE macro function evaluates as (3 + 4 * 3 + 4)
    // which return as 19 instead of 49, but the Square function evaluates the operation
    // in parameter and the square the number
    cout << "SQUARE: " << SQUARE(3 + 4) << " Square: " << Square(3 + 4) << endl;
    // For the below case, the SQUARE macro return negative number, where the Square function
    // return postive evethough the parameter is negative
    cout << "SQUARE: " << SQUARE(6 - 8) << " Square: " << Square(6 - 8) << endl;

    int mac = 5;
    int fun = 5;
    // When there is pre increment value passed as parameter, the SQUARE macro perform the pre increment twice,
    // whereas in Square fucntion only once.
    // SQUARE - mac variable becomes 7
    // Square - fun variable becomes 6
    cout << "SQUARE: " << SQUARE(++mac) << " Square: " << Square(++fun) << endl;
}

int main()
{
    SquareTest();
}