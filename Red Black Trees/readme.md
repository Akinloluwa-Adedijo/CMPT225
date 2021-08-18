Red Black Tree Class
Implementation a `Red-black tree` template class to store data of any (comparable) type.


Attributes
A NodeT* attribute which represents the root of the tree which must be called root. 


Public Methods
Methods  preserve the red-black and binary search tree properties.

`default constructor` - creates an empty tree whose root is a null pointer//

`copy constructor` - a constructor that creates a deep copy of its RedBlackTree reference parameter//

`operator=` - overloads the assignment operator for RedBlackTree objects, (deep) copies its RedBlackTree reference       
                parameter into the calling object and returns a reference to the calling object after de-allocating any dynamic memory associated with the original contents of the calling object; if the calling object is the same as the parameter the operator should not copy it

`destructor` - deletes dynamic memory allocated by the tree

`insert` - if the tree does not contain the method's single template parameter, inserts the parameter and returns
            true;otherwise does not insert the parameter and returns false; i.e. the tree will never contain duplicate values

`remove` - removes the method's template parameter from the tree and returns true; if the tree does not contain the parameter returns false

`search` - searches the tree for the method's single template parameter and returns true if it is found and false otherwise

`search` - returns a vector that contains all of the values between the method's first and second template parameters, 
    including both parameter values if they are in the tree; the contents of the returned vector are in ascending order; `
    if there are no such values the returned vector should be empty; note that the order of the parameters is not important, so search(3, 17) and search(17,3) should return the same vector

`closestLess` - returns the largest value stored in the tree that is less than the method's single template parameter;   
                returns the value of the parameter if there is no such value; e.g. if the tree contains the values 3,5,9,
                12,17 then closestLess(10) returns 9, closestLess (17) returns 12 and closestLess(3) returns 3

`closestGreater` - returns the smallest value stored in the tree that is greater than the method's single template  
                    parameter; returns the value of the parameter if there is no such value; e.g. if the tree contains the values 3,5,9,12,17 then closestGreater(10) returns 12, closestGreater(17) returns 17 and closestGreater(3) returns 5

`values` - returns a vector that contains all of the values in the tree; the contents of the vector are in ascending 
            order; if the tree is empty the returned vector should also be empty

`size` - returns the number of values stored in the tree


NodeT Class written in RedBlackTree.h, 
NodeT constructors written in the NodeT class definition

Nodes contain the following attributes, which must are all public, with names given below:

    `data` - a template type parameter
    `left` - NodeT pointer to the left child
    `right` - NodeT pointer to the right child
    `parent` - NodeT pointer to the parent
    `isBlack` - the colour of the node, either black or red but represented as a bool that is true if the node is black



`More About Red-Black Trees`

    Its almost like the normal binary search tree data structure. But for keeping the tree balanced, nodes are assigned a colour.

`Red-Black trees`  mantain the following properties:

    Every node is either `red` or `black`.
    The `root` is `black`.
    Every `null` node is `black`. (null nodes are the `leaf` nodes)
    If a node is `red`, both of its `children` are `black`. This means no two nodes on a path can be red nodes.
    Every path from a root node to a null node has the same number of `black` nodes.


Insertion of a new node in a Red-Black Tree - `https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Insertion `

Removal of a node in a Red-Black Tree - `https://en.wikipedia.org/wiki/Red%E2%80%93black_tree#Removal:_simple_cases`

Red-Black Tree Visualization by David Galles, University of San Francisco Computer Science: `https://www.cs.usfca.edu/~galles/visualization/RedBlack.html`