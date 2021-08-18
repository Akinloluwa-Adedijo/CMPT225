Implementation of a `Queue` template class.
This class uses a `linked list` as its underlying representation.  


Queue Class

Class Attributes

This class is implemented using a linked list and should has the following private member variables

    A pointer to a NodeT that represents the front of the queue
    A pointer to a NodeT that represents the back of the queue
    An int that records the current size of the queue (i.e. the number of values in the queue)

Queue Public Methods

Queue template class to store data of any type. 
The queue is implemented using a singly linked list of nodes, where NodeT is a class that is
also implemented. The enqueue and dequeue methods are implemented in constant time.

 The Queue class has the following public methods:

`constructor` – creates an empty queue

`copy constructor` – a constructor that creates a deep copy of its constant QueueT reference parameter

`destructor` – deallocates dynamic memory allocated by the queue

`operator=` – overloads the assignment operator for QueueT – (deep) copies its constant QueueT 
                reference parameter into the calling object and returns a reference to the calling object after 
                de-allocating any dynamic memory associated with the original contents of the calling object; 
                if the calling object is the parameter the operator should not copy it
    
`enqueue` – inserts its template type parameter at the back of the queue

`dequeue` – removes and returns the value at the front of the queue; 
            if the queue is empty throws a runtime_error (error class is defined 
            in the stdexcept library file)

`print` – prints the contents of the queue, one value per line, from front to back

`empty` – returns true if the queue is empty, false otherwise

`size` – returns the number of items stored in the queue

`concatenate` – has two parameters, a QueueT reference and an integer (referred to as n in this description) 
                  adds the first n values stored in its QueueT parameter to the end of the calling object, the 
                  resulting queue therefore contains its original contents – order unchanged – followed by the first 
                  n values of the parameter queue in their original order; the values added to the calling object should 
                  be removed from the parameter; both queue's sizes should be adjusted as appropriate; if n is greater 
                  than the size of the parameter a runtime_error should be thrown and no changes made to either queue

`merge` – returns a QueueT object that contains the contents of the calling object and its constant QueueT reference 
            parameter, the resulting queue should start with the first value in the calling object, followed by the first 
            value in the parameter, subsequent values should be copied – in order – from the two queues alternating 
            between them; no changes should be made to either the calling object or the parameter; 
            example: calling object = {a,b,c,d,e}, parameter = {r,s,t}, result = {a,r,b,s,c,t,d,e}


NodeT Class

The NodeT class has a template type attribute for its `data` and a pointer to the `next` NodeT 
in the list.