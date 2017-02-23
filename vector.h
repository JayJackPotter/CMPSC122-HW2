/************************************************************************
*  CMPSC 122                                                            *
*  Startup code for HW 2                                                *
*  September 29, 2016                                                   *
*  Hyuntae Na, hzn17@psu.edu                                            *
*                                                                       *
*  Description:                                                         *
*                                                                       *
*  This is a header file for Vector class.                              *
*  Do not modify this file and implement each methods defined here in   *
*     Vector.cxx                                                        *
*                                                                       *
*  Please report any bug to htna@psu.edu                                *
*************************************************************************/

#ifndef __Vector_1_H__
#define __Vector_1_H__

#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>

using namespace std;

class Vector
{
private:
    int x;
    int y;

public:
    Vector();
    Vector(int x, int y);
    Vector(const Vector& vec);

    ~Vector();

    int GetX() const;
    int GetY() const;
    void SetX(int value);
    void SetY(int value);

    double GetLength() const;
    void Rotate(double angle, const Vector& center);
    std::string ToString() const;

    // operator []
    int& operator[] (int index)
    {
        if (index == 0) return x;
        if (index == 1) return y;
        throw "out of index";
    }

    // assignment operator
    Vector& operator= (const Vector& rhs);

    // arithmatic operators
    Vector& operator+=(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);
    Vector& operator*=(const int     rhs);
    Vector& operator/=(const int     rhs);

    Vector  operator+ (const Vector& rhs) const;
    Vector  operator- (const Vector& rhs) const;
    Vector  operator* (const int     rhs) const;
    Vector  operator/ (const int     rhs) const;

    // equality/inequality operators
    bool operator==(const Vector& rhs) const;
    bool operator!=(const Vector& rhs) const;

    // stream insertion/extraction operators as friend
    friend std::ostream& operator<< (std::ostream& os, const Vector& vec);
};

#endif
