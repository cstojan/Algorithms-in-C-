/*
Victor Amaro
Section 1
Prog7
implement a derived class (as a template) to represent a binary search tree
*/
#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <vector>
#include <algorithm>
using std::generate; using std::sort;

#include "binTree.h"

template <class T> //foward declartion
class binSTree;

template < class T >
class binSTree : public binTree <T> {
    public:
    void insert ( const T& x); // public insert()
    void remove ( const T& x); // public remove()
	search
    
	private:
    void insert ( Node < T >*&, const T& ); // private version of insert
    void remove ( Node < T >*&, const T& ); // private version of remove
    search
    leaf
 //   Node<T>* pred ( Node<T>* ); // returns predecessor of node
};

/*
   ==== Public Version====
insert(const T&)
returns: nothing
purpose: calls the private version of insert() and passes the root along
    with the item to be inserted
arguments: a constant reference to a class T object, called element, which
    is the item to be inserted
*/
template <class T>
void binSTree<T>::insert( const T& x ) {
    insert(this->root, x);
}
/*
   ==== Private Version ====
Name: insert(const T&)
returns: nothing
purpose: Inserts a element in the tree
arguments: A reference to a Node pointer of class T, ptr - holds the root
    A constant reference to a class T object, element - item to be inserted
*/
template <class T>
void binSTree<T>::insert( Node<T>*& ptr, const T& x ) {
    if(ptr == NULL)
        ptr = new Node<T>(x);
    else {
        if(element < ptr->data)
            insert(ptr->left, x);
        else
            insert(ptr->right, x);
    }
}

/*
   ==== Public Version ====
Name: remove(const T&)
returns: nothing
purpose: calls the private version of remove() and passes the root along
    with the item to be deleted
arguments: a constant reference to a class T object, called element, which
    is the item to be deleted
*/
template <class T>
void binSTree<T>::remove( const T& x ) {
    remove(this->root, x);
}

/*
  ==== Private Version ====
Name: remove(Node*&, const T&)
returns: nothing
purpose: removes the desired element from the tree
arguments: A reference to a class T object, element - item to be deleted
    A reference to a Node pointer of class T, ptr - holds the root
*/
template <class T>
void binSTree<T>::remove( Node<T>*& ptr, const T& x ) {
    Node<T>* temp = ptr;

    if(ptr == NULL)
    	//node doesnt exist
        return ; 
    else if(element < ptr->data)
        remove(ptr->left, x);
    else if(element > ptr->data)
        remove(ptr->right, x);
    else {
        //no Child
        if(ptr->left == NULL && ptr->right == NULL){
                delete ptr;
                ptr = NULL;
        }
        //one child
        else if( ptr->right == NULL) {
            ptr = ptr->left;
            delete temp;
        }
        else if( ptr->left == NULL) {
            ptr = ptr->right;
            delete temp;
        }
        //two childs
        else {
            temp = pred(ptr->left);
            ptr->data = temp->data;
            remove(ptr->left, temp->data);
        }
    }
}

/*
Name: search (public)
returns: bool (true/false)
arguments: constant refrence to a template value
purpose: searches leaf with value of x
*/
template <class T>
bool search(const T& x) const {
	if
	return false;
}

/*
Name: search
returns: bool (true/false)
arguments: node, a T refrence
purpose: 
*/
template <class T>
bool search(Node <T>*, const T&) const {
	
	return false;
}

/*
Name: leaf
returns: 
arguments: 
purpose: 
*/
bool leaf(Node <T>* node) const {
	
}

#endif
