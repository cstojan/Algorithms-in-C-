/*
	NAME: Cory Stojan
	DUE DATE: 24 SEP 18
	COURSE: CSCI 340
	PROGRAM NUMBER: 3
	DISCRIPTION OF PROGRAM: Finds all prime numbers that are less than or equal to a given upper 
							limit. The numbers are part of a list and all non prime numbers are rmoved.
*/
#include "prog3.h"

int main() {
    int upperLimit;

    cout << "Upper limit for the set of primes: "; //asks user to enter the upper limit for the set
    cin >> upperLimit;
    cout << endl;

    set<int> sieveSet;
    fill(sieveSet, upperLimit); //fills set
    sieve(sieveSet, upperLimit); // remove all non prime numbers
    print_primes(sieveSet); //prints set

    return 0;
}

// Function Definations
///////////////////////////////////////////////////////////////////////////////////////////////////////////	

/************************************
Function: fill()
Returns: Nothing
Arguments: A reference to a set of integers, sieve
    	   A integer that holds the upper limit of the set, upperLimit
Purpose: Fills the set starting from 2 all the way to the upper	limit.
			Allows for easy minipulation for the prime numbers
************************************/
void fill(set<int> & sieve, int upperLimit) {
    for(int i = 2; i <= upperLimit; i++)
        sieve.insert(i);
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////	

/************************************
Function: sieve()
Returns: Nothing
Arguments: A reference to a set of integers, (s)
    	   A integer that holds the upper limit of the set, upperLimit
Purpose: Applies the Sieve of Eratosthenes algorithm to
    	 remove all non prime numbers from the set.
************************************/
void sieve(set <int>& s, int n) {
	// Find prime for each positon in list. Remove non prime numbers.
    for(int j = 2;  j * j <= n; j++) { //runs until the upper limit is reached
        if(s.find(j) != s.end()) {
            int i = 0;
            i = 2 * j;
                while(i <= n) {
                    s.erase(i); // <-- (note to self) awsome functionn from the STL
                    i += j;
                }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////	

/************************************
Function: print_primes()
Returns: Nothing
Arguments: A constant reference to a set of integers (s)
Purpose: Prints out the set, with desired width and items per line
************************************/
void print_primes(const set <int>& s) {
    set <int>::const_iterator i; //iterator (use for position)
    int itemCount = 0; //count for items

    for(i = s.begin(); i != s.end(); i++) {
        if(itemCount % NUM_PER_LINE == 0 && itemCount != 0) //makes a new line once desired  amount is reached
            cout << endl;
        cout << fixed << right << setw(ITEM_WIDTH) << *i << " "; //prints out current element and sets width
        itemCount++;
    }
    cout << endl;
}

