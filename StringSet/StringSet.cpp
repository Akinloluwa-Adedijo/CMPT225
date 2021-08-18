//StringSet.cpp
#include "StringSet.h"
#include <iostream>
using std::string;


// creates an array of strings of size 2 in dynamic memory and assigns its address to the class' 
// double array pointer, sets maximum size to 2, and current size to 0
StringSet::StringSet()
{
    Current_Size = 0;
    Max_Size = 2;
    S = new string[Max_Size];
}

// deallocates dynamic memory associated with the object’s string (array) pointer
StringSet::~StringSet()
{
    delete[] S;
}

// creates a deep copy of its constant StringSet reference parameter
StringSet::StringSet(const StringSet& st)
{
   copy(st);
}

//helper function for the copy constructor
void StringSet::copy(const StringSet& st)
{
    //deep copy
    Max_Size = st.Max_Size;
    Current_Size = st.Current_Size;

    //Copying the underlying array i.e
    S = new string[Max_Size];
    for( int i = 0; i < Current_Size; i++)
    {
        S[i] = st.S[i];
    }
}


// deep copies its constant StringSet reference parameter to the calling object; 
// deallocates dynamic memory associated with the calling object's original array; 
// returns a reference to the calling object; should behave correctly during 
// self-assignment
StringSet& StringSet::operator=(const StringSet& st)
{
    if( this != &st)
    {
        delete[] S;
        copy(st);
    }
    return *this; 
}


// returns false (a bool, not an int) without inserting value if a string matching the parameter is already in the
// array, otherwise: inserts its string parameter at the next available index; if the underlying array is full, 
// doubles the maximum size attribute, creates an array of twice the size of the current array, copies the 
// contents of the old array to the new array, frees memory associated with the old array, and assigns new array’s
// address to object’s array pointer, then inserts parameter; increments current size and returns true
bool StringSet::insert( string x)
{
    bool check = true;
    for (int i = 0; i < Current_Size; i++)
    {
        if (S[i] == x)
        {
            check = false;
        }
    }

    if (check == false)
    {
        return check;
    }
    else if( Current_Size < Max_Size)
    {
        S[Current_Size] = x;
        Current_Size = Current_Size + 1;
        check = true;
        return check;
    }
    else
    {
        Max_Size = Max_Size * 2;
        string* A = new string[Max_Size];

        for (int i = 0; i < Current_Size; i++)
        {
            A[i] = S[i];
        }

        delete[] S;
        
        S = A;
        S[Current_Size] = x;
        Current_Size = Current_Size + 1;

        check = true;
        return check;
    }
    
}

// if a string matching its string parameter is in the array replaces the matching string with 
// the last string in the array (if there is one) and decrements current size
void StringSet::remove( string x)
{   
    int i = find(x);
    S[i] = S[Current_Size-1];
    Current_Size = Current_Size - 1;
}


// if a string matching the string parameter is in the array returns 
// the integer index of that string, otherwise returns -1
int StringSet::find(string x) const
{
    for (int i = 0; i < Current_Size; i++)
    {
        if (S[i] == x)
        {
            return i;
        }   
    }
    return -1;
}

// returns an integer equal to the number of values in the calling object
int StringSet::size() const
{
    return Current_Size;
}

// returns a StringSet object that contains the union of the calling object and the StringSet parameter 
// (if the result is the empty set the returned StringSet object’s current size should equal zero); 
// neither the calling object nor the parameter should be modified; in case you were wondering, 
// this method is called unions because union is a reserved word
StringSet StringSet::unions( const StringSet st)
{
    StringSet St_New;
    for (int i = 0; i < Current_Size; i++)
    {
        St_New.insert(S[i]);
    }

    for (int j = 0; j < st.Current_Size; j++)
    {
        St_New.insert(st.S[j]);
    }
    
    if (St_New.size() == 0)
    {
        St_New.Current_Size = 0;
    }

    return St_New;
}
    
// returns a StringSet object that contains the intersection of the calling object and its StringSet 
// parameter (if the result is the empty set the returned StringSet object’s current size should equal 
// zero); neither the calling object nor the parameter should be modified
StringSet StringSet::intersection(StringSet st)
{
    StringSet St_New;

    for (int i = 0; i < Current_Size; i++)
    {
        for (int j = 0; j < st.Current_Size; j++)
        {
            if (S[i] == st.S[j])
            {
                St_New.insert(S[i]);
            }
        }
    }

    for (int i = 0; i < st.Current_Size; i++)
    {
        for (int j = 0; j < Current_Size; j++)
        {
            if (S[i] == st.S[j])
            {
                St_New.insert(st.S[i]);
            }
        }
    }
        
    if(St_New.size() == 0)
    {
        St_New.Current_Size = 0;
    }
    return St_New;
}
    
// // returns a StringSet object that contains the set difference of the calling object and its StringSet 
// // parameter, i.e. calling object - parameter (if the result is the empty set the returned StringSet object’s
// // current size should equal zero); neither the calling object nor the parameter should be modified
StringSet StringSet::difference(StringSet st)
{
    StringSet St_New;
    int j = 0;
       for (int i = 0; i < Current_Size; i++)
        {
            if (S[i] != st.S[j])
            {
                St_New.insert(S[i]);
                j++;
            }
        }

    if(St_New.size() == 0)
    {
        St_New.Current_Size = 0;
    }
    return St_New;    
}