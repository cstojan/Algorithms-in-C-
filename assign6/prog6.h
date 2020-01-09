/*
	NAME: Cory Stojan
	DUE DATE: 26 October 2018
	COURSE: CSCI 340
	PROGRAM NUMBER: 6
	DISCRIPTION OF PROGRAM: Headder File for prog5.cc
*/

// Include Statements



// Using Statements


// Class Declarations
template < class T > class binTree {
	public:
	binTree ( ); // default constructor
	unsigned height ( ) const; // returns height of tree
	virtual void insert ( const T& ); // inserts node in tree
	void inorder ( void ( * ) ( const T& ) ); // inorder traversal of tree
	protected:
	Node < T >* root; // root of tree

	private:
	unsigned height ( Node < T >* ) const; // private version of height ( )
	void insert ( Node < T >*&, const T& ); // private version of insert ( )
	void inorder ( Node < T >*, void ( * ) ( const T& ) );// private version of inorder ( )
};


// Function/ Method Declarations

///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: 
Returns: 
Arguments: 
Purpose: 
************************************/
insert ( const T& x ){
/*
This virtual function can be used to insert a node with the data
value x in a binary tree, applying the following technique: if the tree is empty, then the
new node will be the root of the tree with the value x; otherwise, the left or the right
subtree is randomly selected and the value x is inserted in that side. To implement the
random selection, you can use the following RNG.
*/

// Local Variables

// Given implmemtations 
/*
typedef enum { left_side, right_side } SIDE;
SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; }
*/

	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: 
Returns: 
Arguments: 
Purpose: 
************************************/

{

	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: 
Returns: 
Arguments: 
Purpose: 
************************************/

{

	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: 
Returns: 
Arguments: 
Purpose: 
************************************/

{

	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////	
/************************************
Function: 
Returns: 
Arguments: 
Purpose: 
************************************/

{

	
}

