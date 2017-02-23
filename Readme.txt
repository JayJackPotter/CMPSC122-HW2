//---------------------------------------------------------------------
// How to compile
//   g++ -ansi -pedantic -Wall vector.cxx main.cxx -o main
//   g++ -ansi -pedantic -Wall tvector.h testmain.cxx -o testmain
//
// - to run the program, use the following command
//
//   ./main
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
//friend std::ostream& operator<< (std::ostream& os, const TVector<T>& vec)//
// Which lines professor wrote it.
// Donglin Xu help me out of it
//---------------------------------------------------------------------