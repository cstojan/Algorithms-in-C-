/*
	NAME: Cory Stojan
	DUE DATE: 14 SEP 18
	COURSE: CSCI 340
	PROGRAM NUMBER: 2
	DISCRIPTION OF PROGRAM: Headder File for Assignment 2
*/
// Headder Guards
#ifndef ThisIsProgramTwo // should not be defined any place else
#define ThisIsProgramTwo // same const value as for ifndef directive


// Include Statments
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

/*
using std::cout; using std::endl;
using std::setw; using std::right; 
using std::fixed; using std::vector; 
using std::sort; using std::find;
using std::setprecision; using std::setiosflags;
*/
using namespace std;
// Using Statments


// Class/ Method/ Function Declarations
void Vectors (vector < int >&, vector < int >&, int, int);
bool linearSearch (const vector < int >&, int);
bool binarySearch (const vector < int >&, int);
int search (const vector < int >&, const vector < int >&, bool (*p) (const vector < int >&, int));
void sortVector (vector < int >& v);
void printVector (const vector < int >&);
void printStat (int, int);

// Constants
	// Constants
	#define SEED1 1 			// seed values v1
	#define SEED2 3 			// seed values v2
	#define ARR_SIZE 200
	#define TEST_ARR_SIZE 100
	#define LOW 1
	#define HIGH 1000

// End of Headder Guard
#endif
