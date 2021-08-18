//StringSet.h
#include <iostream>
using std::string;

class StringSet
{

private:
    int Current_Size;
    int Max_Size;
    string* S;

public:
    // creates an array of strings of size 2 in dynamic memory and assigns its address to the class' 
    // double array pointer, sets maximum size to 2, and current size to 0
    StringSet();

    // deallocates dynamic memory associated with the object’s string (array) pointer    
    ~StringSet();

    // creates a deep copy of its constant StringSet reference parameter
    StringSet(const StringSet& st);

    //helper function for the copy constructor
    void copy(const StringSet& st);

    // deep copies its constant StringSet reference parameter to the calling object; 
    // deallocates dynamic memory associated with the calling object's original array; 
    // returns a reference to the calling object; should behave correctly during 
    // self-assignment
    StringSet& operator=(const StringSet& st);

    // returns false (a bool, not an int) without inserting value if a string matching the parameter is already in the
    // array, otherwise: inserts its string parameter at the next available index; if the underlying array is full, 
    // doubles the maximum size attribute, creates an array of twice the size of the current array, copies the 
    // contents of the old array to the new array, frees memory associated with the old array, and assigns new array’s
    // address to object’s array pointer, then inserts parameter; increments current size and returns true
    bool insert( string x);

    // if a string matching its string parameter is in the array replaces the matching string with 
    // the last string inthe array (if there is one) and decrements current size
    void remove( string x);


    // if a string matching the string parameter is in the array returns 
    // the integer index of that string, otherwise returns -1
    int find( string x) const;

    // returns an integer equal to the number of values in the calling object
    int size() const;

    // returns a StringSet object that contains the union of the calling object and the StringSet parameter 
    // (if the result is the empty set the returned StringSet object’s current size should equal zero); 
    // neither the calling object nor the parameter should be modified; in case you were wondering, 
    // this method is called unions because union is a reserved word
    StringSet unions(StringSet st);
    
    // returns a StringSet object that contains the intersection of the calling object and its StringSet 
    // parameter (if the result is the empty set the returned StringSet object’s current size should equal 
    // zero); neither the calling object nor the parameter should be modified
    StringSet intersection(StringSet st);
    
    // returns a StringSet object that contains the set difference of the calling object and its StringSet 
    // parameter, i.e. calling object - parameter (if the result is the empty set the returned StringSet object’s
    // current size should equal zero); neither the calling object nor the parameter should be modified
    StringSet difference(StringSet st);
};
