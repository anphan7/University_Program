/* Name: Peter Phan
 * File Name: node.h
 * Desription: Node that use to work with binary search tree to make every node connect
 */ 
#ifndef NODE_H
#define NODE_H 

#include <iostream>
using  namespace std;
template<class T> class BinarySearchTree; // declaration for friend statement below
template<class T> class Position; // declaration for friend statement below

template<class T>
class Node {
public:
   Node(); // default constuctor
   // constructor that takes node’s dat
   Node( const T& );
   // copy constructor.
   Node( const Node<T>& );  
   virtual ~Node<T>() {} // destructor
   void setItem( const T& );
   T getItem() const { return item; }
   Node<T>& operator=( const Node<T>& );
   friend class BinarySearchTree<T>;
   friend class Position<T>; // Position is an iterator class
private:
   Node<T>* leftPtr;
   Node<T>* rightPtr;
   Node<T>* parentPtr;
   T item;
};

// default constructor
template<class T>
Node<T>::Node() : leftPtr( NULL ), rightPtr( NULL ), parentPtr( NULL ) { }

template<class T>
Node<T>::Node( const T& i ){
    item = i;
    leftPtr = NULL;
    rightPtr = NULL;
    parentPtr = NULL;
}


// 1-arg copy constructor doesn't copy the next/prev pointers
template<class T>
Node<T>::Node( const Node<T>& n ) {
   *this = n;
   leftPtr = NULL;
   rightPtr = NULL;
   parentPtr = NULL;
} 

// setItem sets the item data values
template<class T>
void Node<T>::setItem( const T& b ) {
   this->item = b;
}

// operator= sets this' item values to n item values and
// this' nextPtr to null
template<class T>
Node<T>& Node<T>::operator=( const Node<T>& n ) {
     leftPtr = NULL;
     rightPtr = NULL;
     parentPtr = NULL;
     item = n.item;
     return *this;
}

#endif 