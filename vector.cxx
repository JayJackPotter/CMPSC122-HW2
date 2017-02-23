//---------------------------------------------------------------------
// How to compile
//   g++ -ansi -pedantic -Wall vector.cxx main.cxx -o main
//
// - to run the program, use the following command
//
//   ./main
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
//friend std::ostream& operator<< (std::ostream& os, const TVector<T>& vec)//
// Which lines professor wrote it.
// Donglin Xu help me out of it
//---------------------------------------------------------------------
/************************************************************************
*  CMPSC 122                                                            *
*  Startup code for HW 2                                                *
*  September 29, 2016                                                   *
*  Hyuntae Na, hzn17@psu.edu                                            *
*                                                                       *
*  Description:                                                         *
*                                                                       *
*  This is a source file for Vector class.                              *
*                                                                       *
*  Please report any bug to htna@psu.edu                                *
*************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include "vector.h"

double Vector::GetLength() const
{
    double leng = sqrt(x*x + y*y);
    return leng;
}

std::string Vector::ToString() const
{
    std::stringstream os;
    os << *this;
    string str = os.str();
    return str;
}

void Vector::Rotate(double angle, const Vector& center)
{
    int c_x = x - center.x;
    int c_y = y - center.y;
    double sin_angle = sin(angle);
    double cos_angle = cos(angle);
    x = (int)(c_x * cos_angle - c_y * sin_angle + center.x);
    y = (int)(c_x * sin_angle + c_y * cos_angle + center.y);
}
Vector::Vector()
{
	this->x = 0;
	this->y = 0;

}
Vector::Vector(int x, int y) 
{
	this->x = x;
	this->y = y;
}
Vector::Vector(const Vector& vec)
{
	this->x = vec.x;
	this->y = vec.y;
}

Vector::~Vector()
{

}
int Vector::GetX() const
{
	return this->x;
}
int Vector::GetY() const
{
	return this->y;
}
void Vector::SetX(int value)
{
	this->x = value;
}
void Vector::SetY(int value)
{
	this->y = value;
}
// assignment operator
Vector& Vector::operator= (const Vector& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

// arithmatic operators
Vector& Vector::operator+=(const Vector& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;

}
Vector& Vector::operator-=(const Vector& rhs)
{
	this->x = this->x - rhs.x;
	this->y = this->y - rhs.y;
	return *this;
}
Vector& Vector::operator*=(const int     rhs)
{
	this->x = this->x*rhs;
	this->y = this->y*rhs;
	return *this;
}
Vector& Vector::operator/=(const int     rhs)
{
	this->x = this->x/rhs;
	this->y = this->y/rhs;
	return *this;
}

Vector  Vector::operator+ (const Vector& rhs) const
{
	Vector tv;
	tv.x=(this->x + rhs.x);
	tv.y=(this->y + rhs.y);
	return tv;

}
Vector  Vector::operator- (const Vector& rhs) const
{
	Vector tv;
	tv.x = (this->x - rhs.x);
	tv.y = (this->y - rhs.y);
	return tv;

}
Vector  Vector::operator* (const int     rhs) const
{
	Vector tv;
	tv.x = (this->x * rhs);
	tv.y = (this->y * rhs);
	return tv;

}
Vector  Vector::operator/ (const int     rhs) const
{
	Vector tv;
	tv.x = (this->x / rhs);
	tv.y = (this->y / rhs);
	return tv;

}

// equality/inequality operators
bool Vector::operator==(const Vector& rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y);
}
bool Vector::operator!=(const Vector& rhs) const
{
	return (this->x != rhs.x && this->y != rhs.y);
}

// stream insertion/extraction operators as friend
std::ostream& operator<< (std::ostream& os, const Vector& vec)
{
	os << "(" << vec.x << "," << vec.y << ")";
	return os;

}
/////////////////////////////////////////////////////////////////////////
// Implement member functions of Vector class



