/*
 * Pame: Peter Phan
 * Due date: April 23nd, 2019
 * File name: utilities.cpp
 * Desription: position file that locate the root, left and right's node
 */ 
#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include "node.h"
using namespace std;
template<class T> class BinarySearchTree; // declaration for friend statement below

template<class T>
class Position {
public:  
    Node<T>& operator*() { return *nodePtr; }
    Position parent() const {
        return Position<T>( this->nodePtr->parentPtr ); }
    Position left() const { 
        return Position<T>( nodePtr->leftPtr ); }
    Position right() const {
        return Position<T>( nodePtr->rightPtr ); }
    bool isRoot( ) const {
        return this->nodePtr->parentPtr->parentPtr == NULL; }
    bool isSuperRoot() const{
        return this->nodePtr->parentPtr == NULL; }
    bool isExternal() const {
        return this->nodePtr->leftPtr == NULL &&
        this->nodePtr->rightPtr == NULL; }
    bool isInternal() const { return !(isExternal() ); }
    bool operator==( const Position& p ) {
        return this->nodePtr == p.nodePtr; }
    Position& operator++( ); 
    T getItem() { return nodePtr->item; }
    friend class BinarySearchTree<T>;
private:
    Position( Node<T>* );
    Node<T>* nodePtr;
};

template<class T>   
Position<T>& Position<T>::operator++( ){
   Position<T> w (this-> right() );
    if (w.isInternal() ){
        do {
             *this = w;
             w = w.left();
        }while (w.isInternal() );
    }
    else {
        w = this -> parent();
        while (w.nodePtr != NULL && *this -> w.right() ){
            *this = w;
            w= w.parent();
            *this = w; 
        }
    return *this;
    }
    
}
template <class T>
Position<T>::Position( Node<T>* nPtr ){
    //nodePtr->parentPtr = nPtr->parentPtr;
    //nodePtr->leftPtr = nPtr->leftPtr;
    //nodePtr->rightPtr = nPtr->rightPtr;
    //nodePtr->item = nPtr->item;
    nodePtr = nPtr ;
}


#endif