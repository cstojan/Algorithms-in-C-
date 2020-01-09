/*
	NAME: Cory Stojan
	DUE DATE: 30 October 2018
	COURSE: CSCI 340
	PROGRAM NUMBER: 6
	DISCRIPTION OF PROGRAM: Headder File for binTree.h
					Contains the binTree class
*/


#ifndef BINARYTREE_H
#define BINARYTREE_H


// Include Headder File (Node.h)
#include "/home/cs340/progs/18f/p6/Node.h"

//foward declartion of binTree class
template <class T> 
class binTree;

template <class T> class binTree {
    public:
    binTree() {root = NULL;};           //default constructor, sets root to NULL
    unsigned height() const;            //public height()
    virtual void insert(const T&);      //public insert()
    void inorder(void(*)(const T&));    //public inorder()

    typedef enum {left_side, right_side} SIDE;
    SIDE rnd() {return rand() % 2 ? right_side : left_side;}

    protected:
    Node <T>* root; //root of tree

    private:
    unsigned height(Node<T>*) const;                  //private height()
    void insert(Node<T>*&, const T&);                 //private insert()
    void inorder(Node<T>*, void (*) (const T&));      //private inorder()
};
 
/*
*Public version*
Name: height() const
Returns: The height of the tree
Arguments: none
Purpose: calls the private version of height()
*/
template <class T>
unsigned binTree<T>::height() const {
    return height(root);
}

/*
*Public version*
Name: inorder()
Returns: nothing
Arguments: A pointer to a function that takes a class T element
Purpose: Calls the private version of inorder()
*/
template <class T>
void binTree<T>::inorder(void (*func) (const T& )){
    inorder(root, func );
}

/*
*Public version*
Name: insert()
Returns: nothing
Arugments: a reference to a constant class T, called element
Purpose: calls the private version of insert()
*/
template <class T>
void binTree<T>::insert( const T& element ){
    insert(root, element);
}

/*
*Private version*
Name: height() const
Arguments: a pointer to a Node of class T (root)
Returns: the height of the tree
Purpose: finds the height of the tree, 
    if height is 0, returns a height of 0
*/
template <class T>
unsigned binTree<T>::height( Node<T>* ptr) const {

    // if height = 0, return 0
    if(!ptr)
        return 0;

    // Find height of tree
    return 1 + max(height(ptr->left), height(ptr->right));
}

/*
*Private version*
Name: insert()
Returns: nothing
Arguments: A pointer to a reference node of class T (root)
    A constant reference to a class T, called element
Purpose: Adds an item to the tree. If there is no Node, creates a new one, sets necessary pointers to NULL and sets Node data to the element.
*/
template <class T>
void binTree<T>::insert(Node<T>*& ptr, const T& element){
    // If empty, create a new node
    if(ptr == NULL) {
        ptr = new Node<T>();
        ptr->right = NULL;
        ptr->left = NULL;
        ptr->data = element;
    }

    //if rnd == right_side, make new node on right
    else if(rnd() == right_side)
        insert(ptr->right, element);
    // If not right side then go to left side
    else 
        insert(ptr->left, element);

}

/*
*Private version*
Name: inorder()
Returns: nothing
Arguments: a pointer to a Node of class T, called ptr (root).
   		a pointer function that takes a class T argument
Purpose: Goes through the tree using using inorder methord
*/
template <class T>
void binTree<T>::inorder(Node<T>* ptr, void (*func) (const T&)){
    if(ptr != NULL){
        inorder(ptr->left,func);
        func( ptr->data );
        inorder(ptr->right, func);
    }
}

#endif
