/*
	NAME: Cory Stojan
	DUE DATE: 06 SEP 18
	COURSE: CSCI 340
	PROGRAM NUMBER: 1
	DISCRIPTION OF PROGRAM: Contains the CPP file for assignment 1
*/

//Include statements
#include "prog1.h"

//Using Statements
using namespace std;

//int main
int main()
{
	// create a new vector
	vector<int> v; // new vector name is v

	// check if first funciton works
	genRndNums(v); // generate numbers

	// check to see if second function works
	printVec(v); // print numbers in acending order

}

// Functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
	/*
	NAME OF FUNCTION: genRndNums
	INPUT VARIABLES: a refrence to a vector (v)
	RETURN TYPE: Void
	FUNCTION: Changes the size of the vector (v) to a random size (VEC_SIZE). 
				It then places random number(s) inside the vector. 
				This function reserves memory before changing size of the vector (v).
				Sorts the numbers in ascending order.
	*/
	void genRndNums (vector <int>& v) {
		// variables
		int ranNum;
		
		// set seed value
		srand(SEED);
	
		// insert random vector numbers using a random number generator    
		for (int i = 0; i != VEC_SIZE; ++i){
			ranNum = rand() % (HIGH - LOW + 1) + LOW; // generate random number
			v.push_back(ranNum); // insert random number
		}
		
		// sort numbers in acending order
		sort(v.begin(), v.end());
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	NAME OF FUNCTION: printVec
	INPUT VARIABLES: a refrence to a vector (v) constant
	RETURN TYPE: Void
	FUNCTION: void printVec ( const vector < int >& v ) : This routine displays the
				contents of vector v on stdout, printing exactly NO_ITEMS = 12 numbers on
				a single line, except perhaps the last line. The sorted numbers need to be properly
				aligned on the output. For each printed number, allocate ITEM_W = 5 spaces
				on stdout
	
	*/
	void printVec (const vector<int>& v){

		// local variables
		int NO_ITEMS = 12;
		int ITEM_W = 5;
		int index = 0;

		// cout statement
		cout << left; // left justify runmbers
		for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i){
			// ouput number with ITEM_W spaces reserved
			cout << setw(ITEM_W) << *i;
			
			// if NO_ITEMS are present on a single line then a new line is created otherwise a " " is added. 
			if ((index + 1) % NO_ITEMS == 0)
				cout << endl;
			else
				cout << setw(1) << " ";
			index++;
		}
		cout << endl; // create a new line
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////	

