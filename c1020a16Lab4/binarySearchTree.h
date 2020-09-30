
/* Name: Peter Phan
 * File Name: binarySearchTree.h
 * Desription: Binary Search Tree that create tree for the main program 
 */ 
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <algorithm>
#include "position.h"
#include "node.h"
using std::max;
template<class T> class Position;

const int PREORDER = 1;
const int INORDER = 2;
const int POSTORDER = 3;

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree();
                    BinarySearchTree( const BinarySearchTree& );
    // returns num nodes in tree
    int size() const { return numNodes; }
    // returns true if tree empty of real nodes
    bool empty() const { return numNodes == 0; }
    // superroot right pointer always points to real root node
    Position<T> root() const {
        return Position<T>( superRootPtr->rightPtr ); }
    void traverseAndPrint( const Position<T>& p, int type ) const;
	double traverseAndCalcTotalMiles(const Position<T>& p) const;
	void writeTree(ostream&, const Position<T>& p);
    int depth( const Position<T>& ) const;
    int height( const Position<T>& ) const;
    Position<T> begin() const;
    // returns NULL iterator
    Position<T> end() const { return Position<T>( ); }
    Position<T> find( const T& ) const;
    Position<T> insert( const T& );
    bool erase( const T& );
    bool erase( const Position<T>& );
    virtual ~BinarySearchTree() { deleteUtility(superRootPtr); }
    friend class Position<T>;
private:
    Node<T>* superRootPtr;
    // number real nodes in tree, not including fake super
    // root and fake ends nodes
    int numNodes;
    void preorderTraverseAndPrint( const Position<T>& ) const;
    void inorderTraverseAndPrint( const Position<T>& ) const;
    void postorderTraverseAndPrint( const Position<T>& ) const;
    // finds item in tree starting at position
    Position<T> findUtility( const T& item, const Position<T>& p ) const ;    
       // inserts item into tree
       Position<T> insertUtility( const T& item );
       // deletes all nodes in the tree
       void deleteUtility( Node<T>* );
       // erases just one node from the tree at position p
       Position<T> eraseUtility( const Position<T>& p);
       // insert item data at position p
       void expandExternal( const T& item, Position<T>& p);
       // remove node above fake leaf node at position p
       Position<T> removeAboveExternal( const Position<T>& p );
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
    superRootPtr = new Node<T>();
    superRootPtr->rightPtr = new Node<T>();
    superRootPtr->rightPtr->parentPtr = superRootPtr;
    superRootPtr->leftPtr = NULL;
    numNodes = 0;
}

template <class T> // save for later
BinarySearchTree<T>::BinarySearchTree( const BinarySearchTree& b){
    this -> deleteUtility(this -> begin() );
}

template <class T>
void BinarySearchTree<T>::preorderTraverseAndPrint( const Position<T>& r ) const{
    if (r.isInternal() ){
        cout << r.nodePtr->item ;
        preorderTraverseAndPrint( r.left() );
        preorderTraverseAndPrint(r.right() );
    }
}

template <class T>
void BinarySearchTree<T>::inorderTraverseAndPrint( const Position<T>& r) const{
    if ( r.isInternal() ){
        inorderTraverseAndPrint( r.left() );
        cout << r.nodePtr->item << " ";
        inorderTraverseAndPrint( r.right() );
    }
}

template <class T>
void BinarySearchTree<T>::postorderTraverseAndPrint( const Position<T>& r ) const{

    if ( r.isInternal() ){
        postorderTraverseAndPrint(  r.left() );
        postorderTraverseAndPrint( r.right() );
        cout << r.nodePtr->item << " ";
    }
}

template<class T>
void BinarySearchTree<T>::deleteUtility( Node<T>* subRoot){
    if (subRoot != NULL){
        deleteUtility( subRoot -> leftPtr);
        deleteUtility( subRoot -> rightPtr);
        delete (subRoot);
    }
}

template <class T>
Position<T> BinarySearchTree<T>::begin() const{
    if ( numNodes > 0 ) {
        Position<T> p = root();
        while (p.isInternal()) {
            p = p.left();
        }
        return p.parent();
    }
   else return Position<T>( superRootPtr );
}

template<class T>
Position<T> BinarySearchTree<T>::find( const T& item ) const  {
    if ( numNodes > 0 ){
        Position<T> v = findUtility( item, root());
        return v;
   }
   else return Position<T>(superRootPtr);
}

template <class T>
Position<T> BinarySearchTree<T>::findUtility( const T& item, const Position<T>& p) const  {
    if (p.isExternal()){ return p;}
    if (p.nodePtr->item == item ) {return p;}
    if (item < p.nodePtr->item){ return findUtility(item, p.left());}
    else return findUtility(item, p.right());
}

template<class T>
int BinarySearchTree<T>::depth( const Position<T>& p ) const {
   if ( p.isSuperRoot()) return -1;
   if ( p.isRoot()) return 0;
   else {return 1+depth( p.parent() ); }
}

template<class T>
int BinarySearchTree<T>::height( const Position<T>& p ) const {
   // if leaf
   if ( p.isExternal() ) return 0;
   int h = 0;
   // h = max of 0 and height of left subtree
   // max() is the STL function
   h= max( h, height( Position<T>( p.nodePtr->leftPtr )));
   // h = max of height of left subtree and
   // height of right subtree
   h = max( h, height( Position<T>( p.nodePtr->rightPtr )));
   return 1 + h;
}

template<class T>
void BinarySearchTree<T>::traverseAndPrint( const Position<T>& p, int type )const {
    if( type == PREORDER ) preorderTraverseAndPrint( p );
    if( type == INORDER ) inorderTraverseAndPrint( p );
    if( type == POSTORDER ) postorderTraverseAndPrint( p );
}

template<class T>
Position<T> BinarySearchTree<T>::insertUtility( const T& item ){
    Position<T> foundPosition = findUtility(item,root());
    if (foundPosition.isExternal() ){
        expandExternal(item, foundPosition);
        return foundPosition;
    }
    else {return Position<T>( superRootPtr ); }
}
template<class T>
Position<T> BinarySearchTree<T>::insert( const T& item ) {
   // root() = superroot's right ptr
   Position<T> p = insertUtility( item );
   // return iterator to position where new node inserted
   return p;
}

template<class T>
Position<T> BinarySearchTree<T>::removeAboveExternal( const Position<T>& p ){
    Node<T> * siblingPtr;
    Node<T> * w = p.nodePtr;
    Node<T> * v = p.nodePtr -> parentPtr;
    if (w == v -> leftPtr ){ 
        siblingPtr = v -> rightPtr; 
    }
    else siblingPtr = v -> leftPtr;
    if ( v == superRootPtr -> rightPtr){
        superRootPtr -> rightPtr = siblingPtr;
        siblingPtr -> parentPtr = superRootPtr;
    }
    else {
        Node<T> * grandParentPtr = v -> parentPtr;
        if (grandParentPtr -> leftPtr == v){grandParentPtr->leftPtr = siblingPtr;}
        else {grandParentPtr -> rightPtr = siblingPtr;}
        siblingPtr -> parentPtr = grandParentPtr;
    }
    delete(w);
    delete(v);
    return Position<T> (siblingPtr);
}

template<class T>
void BinarySearchTree<T>::expandExternal( const T& item, Position<T>& p){
    Node<T>* left = new Node<T>();
    Node<T>* right = new Node<T>();
    p.nodePtr->leftPtr = left;
    p.nodePtr->rightPtr = right;
    left->parentPtr = p.nodePtr;
    right->parentPtr = p.nodePtr;
    p.nodePtr->item = item;
    numNodes++;
}
 
template <class T>
Position<T> BinarySearchTree<T>::eraseUtility( const Position<T>& p){
    Position<T> w( p.nodePtr );
    Position<T> u( p.nodePtr );
    if ( p.left().isExternal() ){ //
        w = p.left();
    }
    else if( p.right().isExternal() ){
        w = p.right();
    }
    else{
        w = p.right();
        do{
            w = w.left();
        }while( w.isInternal() );
        u = w.parent();
        p.nodePtr->item = u.nodePtr->item;
    }
    removeAboveExternal( w );
    return p;
}

template<class T>
bool BinarySearchTree<T>::erase( const T& item ){
    Position<T> w = find( item );
    if ( !w.isSuperRoot() && !w.isExternal() ) {
      eraseUtility( w );
      return true;
   }
   else
      return false;
}

template<class T>
bool BinarySearchTree<T>::erase( const Position<T>& p ) {
   // can't remove superroot or fake external node
   if ( !p.isSuperRoot() && !p.isExternal() ) {
      eraseUtility( p );
      return true;
   }
   else
      return false;
}
 /* 
  * traverseAndCalcTotalMiles: traverses through the tree and get the total miles from each participant.
  * Then adds all the miles together.
  * Parameters: Position<T>& p - the position of the participant that is being used.
  * Returns: double - the total miles of the tree.
  */
template<class T>
double BinarySearchTree<T>::traverseAndCalcTotalMiles( const Position<T>& p) const{
    double totalMiles = 0;
    if(p.isInternal()){
        totalMiles = p.nodePtr->item.getTotalMiles();
        totalMiles = totalMiles + traverseAndCalcTotalMiles(Position<T>(p.nodePtr->leftPtr));
        totalMiles = totalMiles + traverseAndCalcTotalMiles(Position<T>(p.nodePtr->rightPtr));
        return totalMiles;
    }
    else{return 0;}
}
 /* 
  * writeTree: writes the tree in a formatted output. This prints in a preorder fashion.
  * Parameters: ostream& out - used to keep track of what we are outputting to.
  *             Position<T>& p - the position of the participant that is being printed.
  * Returns: none
  */
template<class T>
void BinarySearchTree<T>::writeTree(ostream& out, const Position<T>& p){
    if(p.isInternal()){
        p.nodePtr->item.write(out);
        writeTree(out, p.nodePtr->leftPtr);
        writeTree(out, p.nodePtr->rightPtr);
    }
}
#endif