/************************************************************************
*  CMPSC 122                                                            *
*  Startup code for HW 2                                                *
*  September 29, 2016                                                   *
*  Hyuntae Na, hzn17@psu.edu                                            *
*                                                                       *
*  Description:                                                         *
*                                                                       *
*  This is a test program for class Vector.                             *
*  Do not delete provided test cases.                                   *
*                                                                       *
*  Please report any bug to htna@psu.edu                                *
*************************************************************************/

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <string>
#include "vector.h"

using namespace std;

template<typename T>
void check(int& num_tests, int& num_failed, T value, T expect, string testname)
{
    // num_tests  : total number of tests
    // num_failed : number of tests failed
    // value      : computed value
    // expect     : expected result
    // testname   : test title

    num_tests++;
    cout << endl << testname << endl;
    cout << "  result: " << value  << endl;
    cout << "  expect: " << expect << endl;
    if (value == expect)
    {
        cout << "  test success" << endl;
    }
    else
    {
        num_failed++;
        cout << "  test failed !!!!!" << endl;
    }
}

int main()
{
    cout << "Testing Vector" << endl;

    string str;         // output
    string est;         // expected string
    int num_tests = 0;  // total number of tests
    int num_failed = 0; // number of tests failed

    // test constructors
    Vector v1;          check<string>(num_tests, num_failed, v1.ToString(), "(0,0)", "test 01 - default constructor");
    Vector v2(2,3);     check<string>(num_tests, num_failed, v2.ToString(), "(2,3)", "test 02 - memberwise-copy constructor");
    Vector v3(v2);      check<string>(num_tests, num_failed, v3.ToString(), "(2,3)", "test 03 - copy constructor");

    // test getters and setters
    Vector v4;
    v4.SetX(10);
    check<string>(num_tests, num_failed, v4.ToString(), "(10,0)", "test 04a - SetX()");
    check<int   >(num_tests, num_failed, v4.GetX()    , 10      , "test 04b - GetX()");

    Vector v5;
    v5.SetY(10);
    check<string>(num_tests, num_failed, v5.ToString(), "(0,10)", "test 05a - SetY()");
    check<int   >(num_tests, num_failed, v5.GetY()    , 10      , "test 05b - GetY()");

    // test operators
    Vector v6 ;         v6   = v2;  check<string>(num_tests, num_failed, v6 .ToString(), "(2,3)"  , "test 06 - operator =");
    Vector v7 (1,2);    v7  += v2;  check<string>(num_tests, num_failed, v7 .ToString(), "(3,5)"  , "test 07 - operator +=");
    Vector v8 (1,2);    v8  -= v2;  check<string>(num_tests, num_failed, v8 .ToString(), "(-1,-1)", "test 08 - operator -=");
    Vector v9 (1,2);    v9  *= 2;   check<string>(num_tests, num_failed, v9 .ToString(), "(2,4)"  , "test 09 - operator *=");
    Vector v10(1,2);    v10 /= 2;   check<string>(num_tests, num_failed, v10.ToString(), "(0,1)"  , "test 10 - operator /=");
    Vector v11 = (v7 + v2);         check<string>(num_tests, num_failed, v11.ToString(), "(5,8)"  , "test 11 - operator +");
    Vector v12 = (v7 - v2);         check<string>(num_tests, num_failed, v12.ToString(), "(1,2)"  , "test 12 - operator -");
    Vector v13 = (v7 * 2);          check<string>(num_tests, num_failed, v13.ToString(), "(6,10)" , "test 13 - operator *");
    Vector v14 = (v7 / 2);          check<string>(num_tests, num_failed, v14.ToString(), "(1,2)"  , "test 14 - operator /");

    Vector v15(3,5);
    check<bool>(num_tests, num_failed, (v7 == v15), true , "test 15 - operator ==");
    check<bool>(num_tests, num_failed, (v7 != v15), false, "test 16 - operator !=");

    // print test results
    if (num_failed == 0)
        cout << endl << "passed all " << num_tests << " test cases" << endl;
    else
        cout << endl << "failed " << num_failed << " cases out of " << num_tests << " cases" << endl;
    cout << endl;

    return 0;
}
