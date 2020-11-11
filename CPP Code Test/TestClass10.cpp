#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> numberArrays;
    int n, queries, size, number, arr, index;
    cin >> n >> queries;
    for (int i = 0; i < n; ++i)
    {
        cin >> size;
        vector<int> tempVector;
        for (int j = 0; j < size; ++j)
        {
            cin >> number;
            tempVector.push_back(number);
        }
        numberArrays.push_back(tempVector);
    }

    for (int q = 0; q < queries; ++q)
    {
        cin >> arr >> index;
        cout << numberArrays[arr][index] << endl;
    }

    return 0;
}

//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
    int l, b, h;

public:
    Box() : l(0), b(0), h(0) {}
    Box(int length, int breadth, int height) : l(length), b(breadth), h(height) {}
    Box(const Box &);

    int getLength();
    int getBreadth();
    int getHeight();
    long long CalculateVolume();

    bool operator<(Box &);
};

Box::Box(const Box &boxB)
{
    l = boxB.l;
    b = boxB.b;
    h = boxB.h;
}

int Box::getLength()
{
    return l;
}

int Box::getBreadth()
{
    return b;
}

int Box::getHeight()
{
    return h;
}

long long Box::CalculateVolume()
{
    return (long long)l * b * h;
}

bool Box::operator<(Box &boxB)
{
    if ((l < boxB.l) ||
        ((b < boxB.b) && (l == boxB.l)) ||
        ((h < boxB.h) && (b == boxB.b) && (l == boxB.l)))
        return true;
    else
        return false;
}

ostream &operator<<(ostream &out, Box &B)
{

    return out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
}
