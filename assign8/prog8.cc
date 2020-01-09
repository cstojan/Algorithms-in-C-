/*
	NAME: Cory Stojan
	DUE DATE: 16 November 2018
	COURSE: CSCI 340
	PROGRAM NUMBER: 8
	DISCRIPTION OF PROGRAM: 
*/

#include "/home/cs340/progs/18f/p8/prog8.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: get_list
Returns: nothing
Arguments: a refrence to a vector of T items, and a pointer to a  pathname of chars
Purpose: opens an input file for reading, reads the items, inserts them into a vector.
			closes the file after reading.
************************************/
template <class T> 
void get_list(vector<T>& v, const char* path){
	
	// open file (ifstream)
	ifstream file;
	file.open(path, ios::binary);

	// if file fails to open?
	if (file.fail()) {
			cerr << "Fail To open File";
			exit(-1);
	}
	// clear the heap
	v.clear();
	// insert Value into heap
	T Value;
	while(file >> Value)
	{
		v.push_back(Value);
	}
	// close the file
	file.close();
	

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: construct_heap
Returns: nothing
Arguments: refrence to a vector of T values (v), P class (pred)
Purpose: Constructs a heap structure from the items of vector v 
			and uses the pred to compare the items for building the 
			heap and sorting it.
************************************/
template <class T, class P> 
void construct_heap(vector <T>& v, P pred){
	// construct a heap
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: print_list
Returns: nothing
Arguments: unsigned refrence (s), unsigned refrence (w), unsigned 
			refrence (l), unsigned refrence (c)
Purpose: It is the constructor of the print_list class.
************************************/
template <class T> 
print_list<T>::print_list(const unsigned& s, const unsigned& w, const unsigned& l, const unsigned& c){
	// save given values for the print_list class
	sz = s; // heap size
	wid = w; // minimum numbers of chars writen in printout
	len = l; // max numbers of chars written in printout
	cnt = c; // used as a counter with default value of 0 (used to insert a newline)
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: print_list
Returns: nothing
Arguments: operator (), refrence to a const T value (x)
Purpose: prints the item x of a heap stdout
************************************/
template <class T>
void print_list<T>::operator( )( const T& x ){
	// set the width for cout
	cout.width(wid);
	// set the setprecision
	cout.precision(2);
	// allow for heap output
	cout << fixed << showpoint << x << " ";
	// increase cnt for line count accuracy
	cnt++;
	// if too long, creat a newline
	if (cnt % len == 0 && cnt != 0)
		cout << endl;
}


// main copied form given directory.
int main(){

    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

    // first heap
    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
   




	return 0;
}
