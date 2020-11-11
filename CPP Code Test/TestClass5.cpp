#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <math.h>

#define PI 3.14159265
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Question 6 (20 points)
//
// The following string wrapper class does not work as intended in the
// use cases contained in the TestStringClass() function.
// Without modifying the existing code in the class, make any required
// additions changes to the class so that the code executes correctly.
// You may add new functions to the class
//
///////////////////////////////////////////////////////////////////////////////
class StringWrapper
{
public:
    StringWrapper(const char *const szString)
    {
        // assume szString is not NULL
        const char *szTemp = szString;
        unsigned int uLength = 0;
        while (*szTemp++)
        {
            ++uLength;
        }

        m_pcString = new char[uLength + 1];

        for (unsigned int u = 0; u <= uLength; ++u)
        {
            m_pcString[u] = szString[u];
        }
    }

    ~StringWrapper()
    {
        delete[] m_pcString;
    }

    StringWrapper &operator=(const StringWrapper &);

private:
    char *m_pcString;
};

StringWrapper &StringWrapper::operator=(const StringWrapper &wrapper)
{
    if (this != &wrapper)
    {
        //m_pcString = std::move(wrapper.m_pcString);
        //this->m_pcString = wrapper.m_pcString; // this is not possible because the wrapper of GetMeAString function destroy after it function life end
        int stringLength = 0;
        /*char p = wrapper.m_pcString[stringLength];
        while (p != '\0')
        {
            p = wrapper.m_pcString[++stringLength];
        }*/

        char *p = wrapper.m_pcString;
        while (*p)
        {
            cout << p << endl;
            ++stringLength;
            ++p;
        }
        //delete[] m_pcString;
        m_pcString = (char *)realloc(m_pcString, stringLength + 1);

        for (int i = 0; i <= stringLength; i++)
        {
            m_pcString[i] = wrapper.m_pcString[i];
        }
    }
    return *this;
}

// GetMeAString() - helper function for the test code below.
// DO NOT MODIFY THIS FUNCTION
StringWrapper GetMeAString()
{
    return StringWrapper("another string");
}

// TestStringClass() - helper function for the test code below.
// DO NOT MODIFY THIS FUNCTION
void TestStringClass()
{
    // try and construct a new string containing "test"
    StringWrapper xTestString("test");
    // try and construct a new blank string
    StringWrapper xBlankString("");
    // try and assign the first string to the second one.
    xBlankString = xTestString;
    // assign the first string to itself - this should leave the string with the same contents
    xTestString = xTestString;
    // assign the string via a function call that returns a string
    xTestString = GetMeAString();
}

// main() - this calls the TestStringClass().
// You may add extra function calls to help you test code form other parts of the test.
int main(void)
{
    TestStringClass();
}