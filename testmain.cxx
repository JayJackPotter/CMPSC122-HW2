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
// My compiler told me the error is from tvector.hz
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
*  This is a new test program for template class TVector<T>.            *
*  Write your own test program here.                                    *
*                                                                       *
*  Please report any bug to htna@psu.edu                                *
*************************************************************************/

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "tvector.h"

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
	cout << "  result: " << value << endl;
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
	string str;         // output
	string est;         // expected string
	int num_tests = 0;  // total number of tests
	int num_failed = 0; // number of tests failed

	//initialize random number function
	int seed = static_cast <int> (time(0));							 //Get system time
	srand(seed);													//Seed the random number generator
	
	cout << "Testing TVector<double>" << endl;
	for (int i = 0; i < 2; i++)
	{
		//Double test
		// test constructors
		TVector<double> vd1;             check<string>(num_tests, num_failed, vd1.ToString(), "(0,0)", "double test 01 - default constructor");
		TVector<double> vd2(11.18, 18.11);   check<string>(num_tests, num_failed, vd2.ToString(), "(11.18,18.11)", "double test 02 - memberwise-copy constructor");
		TVector<double> vd3(vd2);         check<string>(num_tests, num_failed, vd3.ToString(), "(11.18,18.11)", "double test 03 - copy constructor");

		// test getters and setters
		TVector<double> vd4;
		vd4.SetX(11.18);
		check<string>(num_tests, num_failed, vd4.ToString(), "(11.18,0)", "double test 04a - SetX()");
		check<int   >(num_tests, num_failed, vd4.GetX(), 11, "double test 04b - GetX()");

		TVector<double> vd5;
		vd5.SetY(18.11);
		check<string>(num_tests, num_failed, vd5.ToString(), "(0,18.11)", "double test 05a - SetY()");
		check<int   >(num_tests, num_failed, vd5.GetY(), 18, "double test 05b - GetY()");

		// test operators
		TVector<double> vd6;            vd6 = vd2; check<string>(num_tests, num_failed, vd6.ToString(), "(11.18,18.11)", "double test 06 - operator =");
		TVector<double> vd7(18.11, 11.18);   vd7 += vd2; check<string>(num_tests, num_failed, vd7.ToString(), "(29.29,29.29)", "double test 07 - operator +=");
		TVector<double> vd8(18.11, 11.18);   vd8 -= vd2; check<string>(num_tests, num_failed, vd8.ToString(), "(6.93,-6.93)", "double test 08 - operator -=");
		TVector<double> vd9(18.11, 11.18);   vd9 *= 2;  check<string>(num_tests, num_failed, vd9.ToString(), "(36.22,22.36)", "double test 09 - operator *=");
		TVector<double> vd10(18.11, 11.18);   vd10 /= 2;  check<string>(num_tests, num_failed, vd10.ToString(), "(9.055,5.59)", "double test 10 - operator /=");
		TVector<double> vd11 = (vd7 + vd2);           check<string>(num_tests, num_failed, vd11.ToString(), "(40.47,47.4)", "double test 11 - operator +");
		TVector<double> vd12 = (vd7 - vd2);           check<string>(num_tests, num_failed, vd12.ToString(), "(18.11,11.18)", "double test 12 - operator -");
		TVector<double> vd13 = (vd7 * 2);            check<string>(num_tests, num_failed, vd13.ToString(), "(58.58,58.58)", "double test 13 - operator *");
		TVector<double> vd14 = (vd7 / 2);            check<string>(num_tests, num_failed, vd14.ToString(), "(14.645,14.645)", "double test 14 - operator /");

		TVector<double> vd15(1, 1);
		check<bool>(num_tests, num_failed, (vd7 == vd15), false, "double test 15 - operator ==");
		check<bool>(num_tests, num_failed, (vd7 != vd15), true, "double test 16 - operator !=");
	}
	for (int i = 0; i < 2; i++)
	{
		//float test
		// test constructors
		TVector<float> vf1;             check<string>(num_tests, num_failed, vf1.ToString(), "(0,0)", "float test 01 - default constructor");
		TVector<float> vf2(12.01, 1.12);   check<string>(num_tests, num_failed, vf2.ToString(), "(12.01,1.12)", "float test 02 - memberwise-copy constructor");
		TVector<float> vf3(vf2);         check<string>(num_tests, num_failed, vf3.ToString(), "(12.01,1.12)", "float test 03 - copy constructor");

		// test getters and setters
		TVector<float> vf4;
		vf4.SetX(12.01);
		check<string>(num_tests, num_failed, vf4.ToString(), "(12.01,0)", "float test 04a - SetX()");
		check<int   >(num_tests, num_failed, vf4.GetX(), 12, "float test 04b - GetX()");

		TVector<float> vf5;
		vf5.SetY(1.12);
		check<string>(num_tests, num_failed, vf5.ToString(), "(0,1.12)", "float test 05a - SetY()");
		check<int   >(num_tests, num_failed, vf5.GetY(), 1, "float test 05b - GetY()");

		// test operators
		TVector<float> vf6;            vf6 = vf2; check<string>(num_tests, num_failed, vf6.ToString(), "(12.01,1.12)", "float test 06 - operator =");
		TVector<float> vf7(1.12, 12.01);   vf7 += vf2; check<string>(num_tests, num_failed, vf7.ToString(), "(13.13,13.13)", "float test 07 - operator +=");
		TVector<float> vf8(1.12, 12.01);   vf8 -= vf2; check<string>(num_tests, num_failed, vf8.ToString(), "(-10.89,10.89)", "float test 08 - operator -=");
		TVector<float> vf9(1.12, 12.01);   vf9 *= 2;  check<string>(num_tests, num_failed, vf9.ToString(), "(2.24,24.02)", "float test 09 - operator *=");
		TVector<float> vf10(1.12, 12.01);   vf10 /= 2;  check<string>(num_tests, num_failed, vf10.ToString(), "(0.56,6.005)", "float test 10 - operator /=");
		TVector<float> vf11 = (vf7 + vf2);           check<string>(num_tests, num_failed, vf11.ToString(), "(25.14,14.25)", "float test 11 - operator +");
		TVector<float> vf12 = (vf7 - vf2);           check<string>(num_tests, num_failed, vf12.ToString(), "(1.12,12.01)", "float test 12 - operator -");
		TVector<float> vf13 = (vf7 * 2);            check<string>(num_tests, num_failed, vf13.ToString(), "(26.26,26.26)", "float test 13 - operator *");
		TVector<float> vf14 = (vf7 / 2);            check<string>(num_tests, num_failed, vf14.ToString(), "(6.565,6.565)", "float test 14 - operator /");

		TVector<float> vf15(3, 5);
		check<bool>(num_tests, num_failed, (vf7 == vf15), false, "float  test 15 - operator ==");
		check<bool>(num_tests, num_failed, (vf7 != vf15), true, "float test 16 - operator !=");
	}
	/*
	//Int test
	// test constructors
	TVector<int> vi1;             check<string>(num_tests, num_failed, vi1.ToString(), "(0,0)", "int test 01 - default constructor");
	TVector<int> vi2(9,7);   check<string>(num_tests, num_failed, vi2.ToString(), "(9,7)", "int test 02 - memberwise-copy constructor");
	TVector<int> vi3(vi2);         check<string>(num_tests, num_failed, vi3.ToString(), "(9,7)", "int test 03 - copy constructor");

	// test getters and setters
	TVector<int> vi4;
	vi4.SetX(9);
	check<string>(num_tests, num_failed, vi4.ToString(), "(9,0)", "int test 04a - SetX()");
	check<int   >(num_tests, num_failed, vi4.GetX(), 9, "int test 04b - GetX()");

	TVector<int> vi5;
	vi5.SetY(7);
	check<string>(num_tests, num_failed, vi5.ToString(), "(0,7)", "int test 05a - SetY()");
	check<int   >(num_tests, num_failed, vi5.GetY(), 7, "int test 05b - GetY()");

	// test operators
	TVector<int> vi6;            vi6 = vi2; check<string>(num_tests, num_failed, vi6.ToString(), "(9,7)", "int test 06 - operator =");
	TVector<int> vi7(7,9);   vi7 += vi2; check<string>(num_tests, num_failed, vi7.ToString(), "(16,16)", "int test 07 - operator +=");
	TVector<int> vi8(7,9);   vi8 -= vi2; check<string>(num_tests, num_failed, vi8.ToString(), "(-2,2)", "int test 08 - operator -=");
	TVector<int> vi9(7,9);   vi9 *= 2;  check<string>(num_tests, num_failed, vi9.ToString(), "(14,18)", "int test 09 - operator *=");
	TVector<int> vi10(7,9);   vi10 /= 2;  check<string>(num_tests, num_failed, vi10.ToString(), "(3,4)", "int test 10 - operator /=");
	TVector<int> vi11 = (vi7 + vi2);           check<string>(num_tests, num_failed, vi11.ToString(), "(25,23)", "int test 11 - operator +");
	TVector<int> vi12 = (vi7 - vi2);           check<string>(num_tests, num_failed, vi12.ToString(), "(7,9)", "int test 12 - operator -");
	TVector<int> vi13 = (vi7 * 2);            check<string>(num_tests, num_failed, vi13.ToString(), "(32,32)", "int test 13 - operator *");
	TVector<int> vi14 = (vi7 / 2);            check<string>(num_tests, num_failed, vi14.ToString(), "(8,8)", "int test 14 - operator /");

	TVector<int> vi15(3, 5);
	check<bool>(num_tests, num_failed, (vi7 == vi15), false, "int test 15 - operator ==");
	check<bool>(num_tests, num_failed, (vi7 != vi15), true, "int test 16 - operator !=");
	
	// Short test
	// test constructors
	TVector<short> vs1;             check<string>(num_tests, num_failed, vs1.ToString(), "(0,0)", "short test 01 - default constructor");
	TVector<short> vs2(8,9);   check<string>(num_tests, num_failed, vs2.ToString(), "(8,9)", "short test 02 - memberwise-copy constructor");
	TVector<short> vs3(vs2);         check<string>(num_tests, num_failed, vs3.ToString(), "(8,9)", "short test 03 - copy constructor");

	// test getters and setters
	TVector<short> vs4;
	vs4.SetX(6);
	check<string>(num_tests, num_failed, vs4.ToString(), "(6,0)", "test 04a - SetX()");
	check<int   >(num_tests, num_failed, vs4.GetX(), 6, "test 04b - GetX()");

	TVector<short> vs5;
	vs5.SetY(4);
	check<string>(num_tests, num_failed, vs5.ToString(), "(0,4)", "test 05a - SetY()");
	check<int   >(num_tests, num_failed, vs5.GetY(), 4, "test 05b - GetY()");

	// test operators
	TVector<short> vs6;            vs6 = vs2; check<string>(num_tests, num_failed, vs6.ToString(), "(8,9)", "short test 06 - operator =");
	TVector<short> vs7(6,4);   vs7 += vs2; check<string>(num_tests, num_failed, vs7.ToString(), "(14,13)", "short test 07 - operator +=");
	TVector<short> vs8(6,4);   vs8 -= vs2; check<string>(num_tests, num_failed, vs8.ToString(), "(-2,-5)", "short test 08 - operator -=");
	TVector<short> vs9(6,4);   vs9 *= 2;  check<string>(num_tests, num_failed, vs9.ToString(), "(12,8)", "short test 09 - operator *=");
	TVector<short> vs10(6,4);   vs10 /= 2;  check<string>(num_tests, num_failed, vs10.ToString(), "(3,2)", "short test 10 - operator /=");
	TVector<short> vs11 = (vs7 + vs2);           check<string>(num_tests, num_failed, vs11.ToString(), "(22,22)", "short test 11 - operator +");
	TVector<short> vs12 = (vs7 - vs2);           check<string>(num_tests, num_failed, vs12.ToString(), "(6,4)", "short test 12 - operator -");
	TVector<short> vs13 = (vs7 * 2);            check<string>(num_tests, num_failed, vs13.ToString(), "(28,26)", "short test 13 - operator *");
	TVector<short> vs14 = (vs7 / 2);            check<string>(num_tests, num_failed, vs14.ToString(), "(7,6)", "short test 14 - operator /");

	TVector<short> vs16(3, 5);
	check<bool>(num_tests, num_failed, (vs7 == vs16), false, "short test 16 - operator ==");
	check<bool>(num_tests, num_failed, (vs7 != vs16), true, "short test 17 - operator !=");
	*/
	// print test results
	if (num_failed == 0)
		cout << endl << "passed all " << num_tests << " test cases" << endl;
	else
		cout << endl << "failed " << num_failed << " cases out of " << num_tests << " cases" << endl;
	cout << endl;
	system("pause");
	return 0;
}
