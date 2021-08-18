An Implementation of a class that stores a set of `strings`. The class should use a `dynamic array` as its 
underlying representation.


StringSet Class
Methods

`default constructor` – creates an array of strings of size 2 in dynamic memory and assigns its address to the class' 
                          double array pointer, sets maximum size to 2, and current size to 0
    
`copy constructor` – creates a deep copy of its constant StringSet reference parameter
    
`destructor` – deallocates dynamic memory associated with the object’s string (array) pointer
    
`overloaded assignment operator` – deep copies its constant StringSet reference parameter to the calling object; 
                                    deallocates dynamic memory associated with the calling object's original array; 
                                    returns a reference to the calling object; should behave correctly during 
                                    self-assignment
    
`insert` – returns false (a bool, not an int) without inserting value if a string matching the parameter is already in 
            the array, otherwise: inserts its string parameter at the next available index; if the underlying array is full, doubles the maximum size attribute, creates an array of twice the size of the current array, copies the contents of the old array to the new array, frees memory associated with the old array, and assigns new array’s address to object’s array pointer, then inserts parameter; increments current size and returns true
    
`remove` – if a string matching its string parameter is in the array replaces the matching string with the last string 
            in the array (if there is one) and decrements current size
    
`find` – if a string matching the string parameter is in the array returns the integer index of that string, otherwise 
        returns -1
    
`size` – returns an integer equal to the number of values in the calling object
    
`unions` – returns a StringSet object that contains the union of the calling object and the StringSet parameter 
            (if the result is the empty set the returned StringSet object’s current size should equal zero); 
            neither the calling object nor the parameter should be modified; in case you were wondering, 
            this method is called unions because union is a reserved word
    
`intersection` – returns a StringSet object that contains the intersection of the calling object and its StringSet 
                  parameter (if the result is the empty set the returned StringSet object’s current size should equal 
                  zero); neither the calling object nor the parameter should be modified
    
`difference` – returns a StringSet object that contains the set difference of the calling object and its StringSet 
                parameter, i.e. calling object - parameter (if the result is the empty set the returned StringSet object’s current size should equal zero); neither the calling object nor the parameter should be modified

Attributes

The class is implemented with a dynamic array and has the following private member variables

    A pointer to a string that will be used to point to an array of strings in dynamic memory
    An int that records the current size of the array (the number of values stored in the array)
    An int that records the maximum size of the array


Set Operations

    A set cannot contain duplicate values

    The `union` of two sets, R ∪ S, is the set of values that appear in either R or S (or in both)
        e.g. {1,3,4,5} ∪ {2,3,4,6} = {1,2,3,4,5,6}
        e.g. {cat, bat, rat, badger} ∪ {elephant, bat, hamster} = {cat, bat, rat, badger, elephant, hamster}
    
    The `intersection` of two sets, R ∩ S, is the set of values that are common to both R and S
        e.g. {1,3,4,5} ∩ {2,3,4} = {3,4}
        e.g. {cat, bat, rat, badger} ∩ {elephant, bat, hamster} = {bat}
    
    The set `difference` of two sets, R – S, is the set of values that appear in R but not in S.
        Set difference is not commutative (i.e. A - B  ≠ B - A) 
        e.g. {1,3,4,5} – {2,3,4} = {1,5}
        e.g. {cat, bat, rat, badger} – {elephant, bat, hamster} = {cat, rat, badger}