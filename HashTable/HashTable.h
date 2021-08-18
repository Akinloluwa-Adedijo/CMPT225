#pragma once
#include <iostream>
#include <string>
using namespace std;

class HashTable
{
private:
	//to refer to the underlying array of string objects
	string* S;

	//to record the size of the underlying array
	int  max_sz;
		
	//to record the value used by h2 which is equal to p2 which is first prime number greater than array_size / 2 used in the second hash function
	int p2_distance;
	
	//to record the current number of items in the hash table
	int current_size;

	//helper method to find the smallest prime number equal to or greater than n
	int findPrime(int n) const;

	//helper method to check if n is a prime number
	bool isPrime(int n) const;
	
	//helper function for copy constructor and overloaded operator that creates a deep copy of the calling object
	void copy(HashTable& ht);

	//helper function to convert strings characters to ascii code integers
	int stringtoInt(char x) const;

	//helper function to find the hash value of string x using horners method
	int stringValue(string x) const;

public:
	
	//default constructor
	//Pre:
	//Post:  creates a hash table of default size: 101, sets all array elements to the empty string(""); sets the value used by h2
	HashTable();

	//constructor
	//Pre: 
	//Params: an integer n
	//Post: creates a hash table to store n items, the size of the underlying array should be the smallest prime number equal to or greater than 2n
	//      sets all array elements to the empty string; sets the value used by h2
	HashTable(int n);

	//destructor
	//Pre:
	//Post: de-allocates any dynamic memory associated with the calling object
	~HashTable();
	
	//copy constructor
	//Pre:
	//Params: HashTable reference parameter
	//Pre: creates a deep copy of its HashTable reference parameter
	HashTable(HashTable& hht);
//
//
//	operator= - overloaded assignment operator
	//Pre: 
	//Params: HashTable reference parameter
	//Post: makes the calling object a deep copy of its HashTable reference parameter;
	//	    returns a reference to the calling object
	HashTable& operator=(HashTable& hht);

	//insert 
	//Pre:
	//Params: string parameter
	//Post: if the string parameter is found it does not perform insertion
	//      else inseets the string parameter.if the hash table's load factor is greater then 0.67 after insertion, it creates a new hash table of size equal to the 
	//      first prime number greater than twice the size of the original table, inserts the original contents in the new table at the appropriate places
	//      and sets the value used by h2
	void insert(string x);
	
	//find
	//Pre: 
	//Params: string parameter
	//Post: return true if the string parameter is in the hash table, false otherwise
	bool find(string x)const ;
	
	//size
	//Pre:
	//Post: returns the number of items stored in the hash table
	int size() const;
	
	//maxSize
	//Pre:
	//Post: returns the size of the hash table�s underlying array
	int maxSize() const;
	
	//loadFactor
	//Pre:
	//Post: returns the load factor of the hash table
	double loadFactor() const;
};