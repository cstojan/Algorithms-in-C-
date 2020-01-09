/*

	NAME: Cory Stojan
	DUE DATE: 06 Sep 18
	COURSE: CSCI 340
	PROGRAM NUMBER: 1
	DISCRIPTION OF PROGRAM: This program sets a vector to a random amount of elements. Each element in the vector will have a random number placed inside it. 
							The elements are sorted in acending order.
							The program will also be able to print the numbers with each row that it prints will have 12 numbers max.
*/

// Headder Guards
#ifndef ThisIsProgramOne // should not be defined any place else
#define ThisIsProgramOne // same const value as for ifndef directive

// Include Statements
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::cout; using std::endl;
using std::setw; using std::left; 
using std::fixed; using std::vector; 
using std::sort;


// Function Declarations
	void genRndNums (vector<int>&);
	void printVec (const vector <int>&);
	
	
// Gloabal Variables
#define LOW 1
#define HIGH 10000
#define SEED 1
#define VEC_SIZE 250

	
// Headder Guard
#endif
