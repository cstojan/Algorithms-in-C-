/*
	NAME: Cory Stojan
	DUE DATE: 02 October 2018
	COURSE: CSCI 340
	PROGRAM NUMBER: 4
	DISCRIPTION OF PROGRAM: Headder File for Assignment 4
*/

// Headder Guards
#ifndef ThisIsProgramFour // should not be defined any place else
#define ThisIsProgramFour // same const value as for ifndef directive

// Include Statements
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cctype>
#include <fstream>

// Using Statements
using namespace std;

// Functions
void get_words(map<string, int>& w);
void print_words(map<string, int>& w);
void clean_entry(const string& word, string& str);
void lowerstr(char & c);

// Global Varibles :(
int nonDistWords = 0;

#endif
