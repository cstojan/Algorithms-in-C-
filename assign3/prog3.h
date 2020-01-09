/*
	NAME: Cory Stojan
	DUE DATE: 24 SEP 18
	COURSE: CSCI 340
	PROGRAM NUMBER: 3
	DISCRIPTION OF PROGRAM: Headder File for Assignment 3
*/

// Headder Guards
#ifndef ThisIsProgramTwo // should not be defined any place else
#define ThisIsProgramTwo // same const value as for ifndef directive

// Include Statements
#include <iostream>
#include <iomanip>
#include <set>

// Using Statments
using std::cout; using std::endl; using std::cin;
using std::setw; using std::right; using std::fixed;
using std::set;


// Constant Variables
#define ITEM_WIDTH 4 //Width between items
#define NUM_PER_LINE 20 //Items per line

// Function Declarations
void fill(set <int>&, int);
void sieve(set <int>&, int);
void print_primes(const set <int>&);

// End of Headder Guard
#endif
