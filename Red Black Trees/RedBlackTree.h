#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//include statements
using namespace std;
using std::cout;
using std::endl;


template <class T>  // template declaration
class NodeT {
public:
	T data;

	//	left - NodeT pointer to the left child
	NodeT<T>* left;
	
	//	right - NodeT pointer to the right child
	NodeT<T>* right;
	
	//	parent - NodeT pointer to the parent
	NodeT<T>* parent;
	
	//	isBlack - the colour of the node, either black or red but represented as a bool.
	//true if the node is black, false otherwise
	bool isBlack;
	
	//constructor definitions
	//Constructor - sets the data to its template type parameter, pointers to null, and isBlack to false
	NodeT(T value) : data(value), left(nullptr), right(nullptr), parent(nullptr), isBlack(false) { };

};

template <class T>
class RedBlackTree {
private:
	NodeT<T>* root;
	
	//helper method for clear() to clear nodes
	void clear(NodeT<T>* nd);

	//helper method to check if tree is empty
	bool empty() const;

	//helper method to check if a value to be inserted is alreafy in the tree
	//return true if found, false otherwise
	bool find(T value) const;

	//helper methof to print in order
	void inOrderPrint(NodeT<T>* nd);

	//helper method for size
	int sizeHelper(NodeT<T>* nd) const;

	//values helper
	void valuesHelper(vector<T> &res, NodeT<T>* nd)const;

	//search helper
	void searchHelper(vector<T>& res, NodeT<T>* nd, T start, T end);

	//copy constructor and overloaded opertor helper
	void copyRBT(NodeT<T>* original, NodeT<T>*& copy);

	////left rotate helper
	void leftRotate(NodeT<T>* &nd);

	//right rotate helper
	void rightRotate(NodeT<T>* &nd);

	//tree fix after insertion
	void rbtFixInsert( NodeT<T>* &temp);

	//binary search tree insert helper
	NodeT<T>* insertBST(NodeT<T>*& root, NodeT<T>*& nd);

	//binary search tree removal
	void deleteBST(NodeT<T>*& nd);

	//helper function to fix delete
	void fixDelete(NodeT<T>* &nd);
	
	//helper function to find and return the node to be removed
	NodeT<T>* findNode(T value);

	//helper function to find the successor to the node to be removed
	NodeT<T>* successor(NodeT<T>* nd);

	//swap two nodes
	void swap(NodeT<T>*& x, NodeT<T>*& y);

public:

	//default constructor
	//Pre:
	//Post: empty tree, root is a null pointer
	RedBlackTree();

	//destructor
	//Pre:
	//Post: deletes dynamic memory allocated by the tree
	~RedBlackTree();

	//copy constructor
	//Pre:
	//Param: RedBlackTree reference parameter
	//Post: deep copies its reference parameter
	RedBlackTree(const RedBlackTree& rbt);

	//Overloaded assignment operator
	//Pre: 
	//Post: deep copies its reference parameter into the calling object, returns a rference to 
	//		calling object after deallocating any dynamic memory associated
	//		with the original contents of the calling object
	RedBlackTree& operator=(const RedBlackTree& rbt);

	//Pre:
	//Param: single template parameter
	//Post: return true if parameter is not present in the tree and is inserted and false otherwise
	bool insert(T value);

	//Pre:
	//Param: single template parameter
	//Post: return true if paramater removed successfully from the tree and false if parameter is not present in the tree
	bool remove(T value);


	//Pre:
	//Param: single template parameter
	//Post: return true if parameter is found in the tree, false otherwise
	bool search(T value) const;


	//Pre:
	//Param: first and second template parameters
	//Post: returns a vector that contains all values between the two template parameters, both inclusive if they are in the tree
	//		returns an empty vector if no such values exist in the tree.
	//		order between the two template perameters is irrelevant
	vector<T> search(T start, T end);

	//if the tree contains the values 3, 5, 9, 12, 17 then closestLess(10) returns 9, closestLess(17)
	//returns 12 and closestLess(3) returns 3
	//Pre: 
	//Param: single template parameter
	//Post: returns largest value less than the template parameter, returns template parameter if no such value exists
	T closestLess(T value) const;

	//if the tree contains the values 3, 5, 9, 12, 17 then closestGreater(10) returns 12, closestGreater(17)
	//returns 17 and closestGreater(3) returns 5
	//Pre: 
	//Param: single template parameter
	//Post: returns smallest value greater than the template parameter, returns template parameter if no such value exists
	T closestGreater(T value) const;

	//Pre:
	//Post: returns a vector that contains all values in the tree in ascending order, if tree is empty vector should also be empty
	vector<T> values() const;

	//Pre:
	//Post: returns the number of values stored in the tree 
	int size() const;
};