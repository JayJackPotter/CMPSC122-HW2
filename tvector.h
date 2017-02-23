//---------------------------------------------------------------------
// How to compile
//   g++ -ansi -pedantic -Wall tvector.h testmain.cxx -o testmain
//
// - to run the program, use the following command
//
//   ./testmain
//---------------------------------------------------------------------
//---------------------------------------------------------------------
// Name: Yixuan Zhang
// Email: yuz313@psu.edu
// Class: CMPSC 122
// Homework 2
// Due Date: February 22, 2017
//
// Description: A vector class with checking program.
//
// Acknowledgement:
// My testmain.cxx orginally cannot work.
// I do not know why
// My compiler told me the error is from tvector.h
// Which is from 
// friend std::ostream& operator<< (std::ostream& os, const TVector<T>& vec)//
// Which lines professor wrote it.
// Donglin Xu help me out of it.
//---------------------------------------------------------------------
/************************************************************************
*  CMPSC 122                                                            *
*  Startup code for HW 2                                                *
*  September 29, 2016                                                   *
*  Hyuntae Na, hzn17@psu.edu                                            *
*                                                                       *
*  Description:                                                         *
*                                                                       *
*  This is a header file for template class TVector<T>.                 *
*                                                                       *
*  Please report any bug to htna@psu.edu                                *
*************************************************************************/


#ifndef __TVector__
#define __TVector__

#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>
#include <math.h>

using namespace std;

template<typename T>
class TVector
{
private:
    T x;
    T y;

public:
    TVector();
    TVector(T x, T y);
    TVector(const TVector<T>& vec);

    ~TVector();

    T GetX() const;
    T GetY() const;
    void SetX(T value);
    void SetY(T value);

    double GetLength() const;
    void Rotate(double angle, const TVector<T>& center);
    std::string ToString() const;

    // operator []
    T& operator[] (int index)
    {
        if (index == 0) return x;
        if (index == 1) return y;
        assert(false);
    }

    // assignment operator
    TVector<T>& operator= (const TVector<T>& rhs);

    // arithmatic operators
    TVector<T>& operator+=(const TVector<T>& rhs);
    TVector<T>& operator-=(const TVector<T>& rhs);
    TVector<T>& operator*=(const T       rhs);
    TVector<T>& operator/=(const T       rhs);

    TVector<T>  operator+ (const TVector<T>& rhs) const;
    TVector<T>  operator- (const TVector<T>& rhs) const;
    TVector<T>  operator* (const T       rhs) const;
    TVector<T>  operator/ (const T       rhs) const;

    // equality/inequality operators
    bool operator==(const TVector<T>& rhs) const;
    bool operator!=(const TVector<T>& rhs) const;

    // stream insertion/extraction operators as friend
    friend std::ostream& operator<< (std::ostream& os, const TVector<T>& vec)
    {
        os << "(" << vec.x << "," << vec.y << ")";
        return os;
    }
};

template<typename T>
inline std::string TVector<T>::ToString() const
{
    std::stringstream os;
    os << *this;
    string str = os.str();
    return str;
}

template<typename T>
inline void TVector<T>::Rotate(double angle, const TVector<T>& center)
{
    T c_x = x - center.x;
    T c_y = y - center.y;
    double sin_angle = sin(angle);
    double cos_angle = cos(angle);
    x = (T)(c_x * cos_angle - c_y * sin_angle + center.x);
    y = (T)(c_x * sin_angle + c_y * cos_angle + center.y);
}

/////////////////////////////////////////////////////////////////////////
// Implement member functions of Vector class
template<typename T>
TVector<T>::TVector()
{
	this->x = 0;
	this->y = 0;
}
template<typename T>
TVector<T>::TVector(T x, T y)
{
	this->x = x;
	this->y = y;
}
template<typename T>
TVector<T>::TVector(const TVector<T>& vec)
{
	this->x = vec.x;
	this->y = vec.y;
}
template<typename T>
TVector<T>::~TVector()
{
}

template<typename T>
T TVector<T>::GetX() const
{
	return this->x;
}

template<typename T>
T TVector<T>::GetY() const
{
	return this->y;
}
template<typename T>
void TVector<T>::SetX(T value)
{
	this->x = value;
}
template<typename T>
void TVector<T>::SetY(T value)
{
	this->y = value;
}
template<typename T>
double TVector<T>::GetLength() const
{
	double leng = sqrt(x*x + y*y);
	return leng;
}
template<typename T>
TVector<T>& TVector<T>::operator= (const TVector<T>& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

// arithmatic operators
template<typename T>
TVector<T>& TVector<T>::operator+=(const TVector<T>& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}
template<typename T>
TVector<T>& TVector<T>::operator-=(const TVector<T>& rhs)
{
	this->x = this->x - rhs.x;
	this->y = this->y - rhs.y;
	return *this;
}
template<typename T>
TVector<T>& TVector<T>::operator*=(const T       rhs)
{
	this->x = this->x*rhs;
	this->y = this->y*rhs;
	return *this;

}
template<typename T>
TVector<T>& TVector<T>::operator/=(const T       rhs)
{
	this->x = this->x / rhs;
	this->y = this->y / rhs;
	return *this;

}
template<typename T>
TVector<T>  TVector<T>::operator+ (const TVector<T>& rhs) const
{
	TVector<T> tv;
	tv.x = (this->x + rhs.x);
	tv.y = (this->y + rhs.y);
	return tv;

}
template<typename T>
TVector<T>  TVector<T>::operator- (const TVector<T>& rhs) const
{
	TVector<T> tv;
	tv.x = (this->x - rhs.x);
	tv.y = (this->y - rhs.y);
	return tv;

}
template<typename T>
TVector<T>  TVector<T>::operator* (const T       rhs) const
{
	TVector<T> tv;
	tv.x = (this->x * rhs);
	tv.y = (this->y * rhs);
	return tv;

}
template<typename T>
TVector<T>  TVector<T>::operator/ (const T       rhs) const
{
	TVector<T> tv;
	tv.x = (this->x / rhs);
	tv.y = (this->y / rhs);
	return tv;

}
template<typename T>
bool TVector<T>::operator==(const TVector<T>& rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y);

}
template<typename T>
bool TVector<T>::operator!=(const TVector<T>& rhs) const
{
	return (this->x != rhs.x && this->y != rhs.y);

}

// Implement member functions of Vector class
/////////////////////////////////////////////////////////////////////////

#endif
