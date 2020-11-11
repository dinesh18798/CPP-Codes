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
// Question 5 (5 parts, 20 points in total)
//
// Given the following Vector3 class, write the implementation for the three
// functions. You may use basic trigonometry functions by #including <math.h>.
// You may also use sqrtf(). You should avoid using functions that involve
// double precision types. You should attempt to minimise the use of expensive
// arithmetic operations.
//
// Part (a)
// GetMagnitude() should return a float representing the magnitude of the vector.
//
// Part (b)
// Normalise() should modify the vector so that is has unit length.
//
// Part (c)
// GetAngleBetween() should return a float representing the angle between the
// two input vectors.
//
// Part (d)
// GetPerpVector() should return a third vector which is perpendicular to the
// two input vectors. Some credit will be given for mentioning the name of the
// operation even if you cannot remember or derive the formula.
//
// Part (e)
// What does the use of 'const' mean in the declaration of GetAngleBetween()?
// What does the use of 'const' mean in the declation of GetMagnitude()?
//
///////////////////////////////////////////////////////////////////////////////
class Vector3
{
public:
    Vector3()
    {
    }

    Vector3(float fX, float fY, float fZ)
        : m_fX(fX), m_fY(fY), m_fZ(fZ)
    {
    }

    float GetMagnitude() const;
    void Normalise();
    static float GetAngleBetween(const Vector3 &xVec1, const Vector3 &xVec2);
    static Vector3 GetPerpVector(const Vector3 &xVec1, const Vector3 &xVec2);

private:
    float m_fX;
    float m_fY;
    float m_fZ;
};

// Part (a) - write your implementation here:
float Vector3::GetMagnitude() const
{
    return sqrtf((m_fX * m_fX) + (m_fY * m_fY) + (m_fZ * m_fZ));
}

// Part (b) - write your implementation here:
void Vector3::Normalise()
{
    float magnitude = GetMagnitude();
    m_fX /= magnitude;
    m_fY /= magnitude;
    m_fZ /= magnitude;
}

// Part (c) - write your implementation here:
float Vector3::GetAngleBetween(const Vector3 &xVec1, const Vector3 &xVec2)
{
    float dotProduct = (xVec1.m_fX * xVec2.m_fX) + (xVec1.m_fY * xVec2.m_fY) + (xVec1.m_fZ * xVec2.m_fZ);
    float magnitudes = xVec1.GetMagnitude() * xVec2.GetMagnitude();
    float radian = acos(dotProduct / magnitudes);
    return radian * 180 / PI;
}

// Part (d) - write your implementation here:
Vector3 Vector3::GetPerpVector(const Vector3 &xVec1, const Vector3 &xVec2)
{
    Vector3 xResult;
    //cross product
    xResult.m_fX = (xVec1.m_fY * xVec2.m_fZ) - (xVec1.m_fZ * xVec2.m_fY);
    xResult.m_fY = (xVec1.m_fZ * xVec2.m_fX) - (xVec1.m_fX * xVec2.m_fZ);
    xResult.m_fZ = (xVec1.m_fX * xVec2.m_fY) - (xVec1.m_fY * xVec2.m_fX);
    return xResult;
}

// Part (e): add comments with your answers to these 2 questions:
// Q: What does the use of 'const' mean in the declaration of GetAngleBetween()?
// A: When passing the parameter as 'const' type, it is not modifiable throughout the function which allows to perform the operation without any errors or mistakes.
//    If the passed variables don't declare as const, its values can be modified which also altered the reference variable and result in the wrong angle calculation.
//    In GetAngleBetween() function, the Vector xVec1 and xVec2 parameter passed as const to use the values to calculate the angle without modifying it.
//
// Q: What does the use of 'const' mean in the declation of GetMagnitude()?
// A: Simillar to previous statement, when passing the parameter as 'const' type, it is not modifiable throughout the function which allows to perform the operation
//    without any errors or mistakes. In GetMagnitude() function, the Vector xVec1 and xVec2 parameter passed as const to use the values to calculate the perpendicular vector
//    without modifying it. If the values changed during the operation, the return result might be wrong and also the reference values modified which will not give desired
//    output when passing to any functions in further operations.