#pragma once

#include <iostream>
#include "HashTable.h"
#include <string>

using namespace std;

////default constructor
////Pre:
////Post:  creates a hash table of default size: 101, sets all array elements to the empty string(""); sets the value used by h2
HashTable::HashTable()
{
	max_sz = 101;
	S = new string[max_sz];
	current_size = 0;
	p2_distance = findPrime(current_size/2);
}

//constructor
//Pre: 
//Params: an integer n
//Post: creates a hash table to store n items, the size of the underlying array should be the smallest prime number equal to or greater than 2n
//      sets all array elements to the empty string; sets the value used by h2
HashTable::HashTable(int n)
{
	max_sz = findPrime(2*n);
	S = new string[max_sz];
	current_size = 0;
	p2_distance = findPrime(current_size / 2);
}

////destructor
////Pre:
////Post: de-allocates any dynamic memory associated with the calling object
HashTable::~HashTable()
{
	delete[] S;
}

////copy constructor
////Pre:
////Params: HashTable reference parameter
////Pre: creates a deep copy of its HashTable reference parameter
HashTable::HashTable(HashTable& ht)
{
	copy(ht);
}

////	operator= - overloaded assignment operator
//	//Pre: 
//	//Params: HashTable reference parameter
//	//Post: makes the calling object a deep copy of its HashTable reference parameter;
//	//	    returns a reference to the calling object
HashTable& HashTable::operator=(HashTable& ht)
{
	if (this != &ht)
	{
		delete[] S;
		copy(ht);
	}
	return *this;
}

////insert 
////Pre:
////Params: string parameter
////Post: if the string parameter is found it does not perform insertion
////      else inserts the string parameter.if the hash table's load factor is greater then 0.67 after insertion, it creates a new hash table of size equal to the 
////      first prime number greater than twice the size of the original table, inserts the original contents in the new table at the appropriate places
////      and sets the value used by h2
void HashTable::insert(string x)
{
	//first hash function
	int h1 = stringValue(x);

	if (find(x) == false)
	{
		//insert x if the element at index h1 is empty, else proceed to perform double hashing 
		if (S[h1] == "")
		{
			S[h1] = x;
			current_size++;
		}
		else
		{
			int sum = h1;

			//calaulating the second hadh function
			int h2 = p2_distance - (sum % p2_distance);
			sum += h2;

			//if h1 + h2 is greater than the maximum size of the hashtable, wrap around the hashtable by using the modulo operator
			if (sum >= max_sz)
			{
				sum = sum % max_sz;
			}

			while (true)
			{
				if (S[sum] == "")
				{
					S[sum] = x;
					current_size++;
					break;
				}
				sum += h2;
				
				//if h1 + h2 is greater than the maximum size of the hashtable, wrap around the hashtable by using the modulo operator
				if (sum >= max_sz)
				{
					sum = sum % max_sz;
				}
			}
		}

		if (loadFactor() > 0.67)
		{
			int old_max_sz = max_sz;
			max_sz = findPrime(2 * max_sz);
			string* S_new = new string[max_sz];
			current_size = current_size;
			
			p2_distance = findPrime(current_size / 2);

			for (int i = 0; i < old_max_sz; i++)
			{
				if (S[i] != "")
				{
					int h1_new = stringValue(S[i]);
					if (S_new[h1_new] == "")
					{
						S_new[h1_new] = S[i];
					}
					else
					{
						int sum = h1_new;
						int h2 = p2_distance - (sum % p2_distance);
						sum += h2;

						if (sum >= max_sz)
						{
							sum = sum % max_sz;
						}

						while (true)
						{
							if (S_new[sum] == "")
							{
								S_new[sum] = x;
								break;
							}
							sum += h2;
							if (sum >= max_sz)
							{
								sum = sum % max_sz;
							}
						}
					}
				}
			}

			delete[] S;
			S = S_new;
		}
	}
}		

////find
////Pre: 
////Params: string parameter
////Post: return true if the string parameter is in the hash table, false otherwise
bool HashTable::find(string x) const
{
	int h1 = stringValue(x);
	if (S[h1] == x)
	{
		return true;
	}
	else
	{
		int sum = h1;
		int h2 = p2_distance - (sum % p2_distance);
		int count_for_break = 0;
		sum += h2;

		if (sum >= max_sz)
		{
			sum = sum % max_sz;
		}

		while (true)
		{
			if (S[sum] == x)
			{
				return true;
			}

			sum += h2;
			if (sum >= max_sz)
			{
				sum = sum % max_sz;
			}
			count_for_break++;
			
			if (count_for_break >=  2 * max_sz)
			{
				break;
			}
		}
	}
	return false;
}

////size
////Pre:
////Post: returns the number of items stored in the hash table
int HashTable::size() const
{
    return current_size;
}

////maxSize
////Pre:
////Post: returns the size of the hash table’s underlying array
int HashTable::maxSize() const
{
    return max_sz;
}

////loadFactor
////Pre:
////Post: returns the load factor of the hash table
double HashTable::loadFactor() const
{
    return (double)current_size / (double)max_sz;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////HELPER METHODS/////////////////////////////////////////////////////////////
int HashTable::findPrime(int n) const
{
	int new_N = n + 1;
    while (true)
    {
		if (isPrime(new_N) == true)
		{
			break;
		}
		new_N++;
    }
	return new_N;
}

bool HashTable::isPrime(int n) const
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

void HashTable::copy(HashTable& ht)
{
	//deep copy
	max_sz = ht.max_sz;
	current_size = ht.current_size;
	p2_distance = ht.p2_distance;

	//Copying the underlying array i.e
	S = new string[max_sz];
	for (int i = 0; i < max_sz; i++)
	{
		S[i] = ht.S[i];
	}
}

int HashTable::stringtoInt(char x)const
{
	int asci = x - 96;
	return asci;
}

int HashTable::stringValue(string x) const
{
	int hashval = 0;
	for (int i = 0; i < x.length(); i++)
	{
		int asci = stringtoInt(x[i]);
		hashval = (hashval * 32 + asci) % max_sz;
	}
	return hashval;
}