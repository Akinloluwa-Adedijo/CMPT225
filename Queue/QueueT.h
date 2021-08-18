#pragma once
#include <iostream>
#include <stdexcept>
using std::runtime_error;
using std::cout;
using std::endl;

template <class V>
class NodeT
{
public:
    V data;
    NodeT* next;


    // Constructors using initialization lists
	NodeT(V val) : data(val), next(nullptr) { ; };
	NodeT(V val, NodeT* nd) : data(val), next(nd) { ; };
};


template <class V>
class QueueT
{
private:
    NodeT<V>* front;
    NodeT<V>* back;
    int len;

    //helper funcrion for the destructor
    void deleteQueueT();
    
    //helper function for copy constructor
    void copyQueueT(const QueueT& qt);

public:
    // creates an empty queue
    QueueT();

    //deallocates dynamic memory allocated by the queue
    ~QueueT();


    // a constructor that creates a deep copy of its constant QueueT reference parameter
    QueueT(const QueueT& qt);

    // overloads the assignment operator for QueueT – (deep) copies its constant QueueT 
    // reference parameter into the calling object and returns a reference to the calling object
    QueueT& operator=( const QueueT& qt);

    // inserts its template type parameter at the back of the queue
    void enqueue( V t);

    // removes and returns the value at the front of the queue; 
    // throw a runtime_error if queue is empty
    V dequeue();


    // prints the contents of the queue, one value per line, from front to back
    void print() const;

    // returns true if the queue is empty, false otherwise
    bool empty() const;

    // size – returns the number of items stored in the queue
    int size() const;

    // has two parameters, a QueueT reference and an integer t 
    // adds the first t values stored in its QueueT parameter to the end of the calling object.
    void concatenate( QueueT& qt, int t);

    // returns a QueueT object that contains the contents of the calling object and its constant QueueT reference 
    // arameter, the resulting queue should start with the first value in the calling object, followed by the first 
    // value in the parameter
    QueueT merge(const QueueT& qt);
};