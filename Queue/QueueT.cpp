#include "QueueT.h"


//Makes an empty queue
template <class V>
QueueT<V>::QueueT()
{
    front = nullptr;
    back = nullptr;
    len = 0;
}

//deallocates dynamic memory allocated by the queue
template <class V>
QueueT<V>::~QueueT()
{
    deleteQueueT();
}

//helper function for the destructor
template <class V>
void QueueT<V>::deleteQueueT()
{
    NodeT<V>* temp = front;
	while (front != nullptr) 
    {
		front = temp->next;
		delete temp;
		temp = front;
	}
	len = 0;
	front = back = nullptr;
}

// a constructor that creates a deep copy of its constant QueueT reference parameter
template <class V>
QueueT<V>::QueueT(const QueueT& qt)
{
    copyQueueT(qt);
}

//helper function for copy constructor
template <class V>
void QueueT<V>::copyQueueT(const QueueT& qt)
{
    front = nullptr;
    back = nullptr;
    len = 0;

    NodeT<V>* temp = qt.front;
    while(temp != nullptr)
    {
        enqueue(temp->data);
        temp = temp->next;
    }
}

// overloads the assignment operator for QueueT – (deep) copies its constant QueueT 
// reference parameter into the calling object and returns a reference to the calling object after 
// de-allocating any dynamic memory associated with the original contents of the calling object; 
// if the calling object is the parameter the operator should not copy it
template <class V>
QueueT<V>& QueueT<V>::operator=( const QueueT& qt)
{
    if(this != &qt) 
    {
		deleteQueueT();
		copyQueueT(qt);
	}
	return *this;
}

// inserts its template type parameter at the back of the queue
template <class V>
void QueueT<V>::enqueue(V t)
{
    //if the queue is empty
    if(back == nullptr)
    {
		back = new NodeT<V>(t);
		front = back;
	}
	else 
    {
		back->next = new NodeT<V>(t);
		back = back->next;
	}
	len++;
}

// removes and returns the value at the front of the queue; 
// throws a runtime_error if queue is empty
template <class V>
V QueueT<V>::dequeue()
{
	// Queue is empty
    if (len == 0 && front == nullptr)
    {
        throw runtime_error("queue is empty, deque failed");
    }
	V result = front->data;
	NodeT<V>* temp = front;
    front = front->next;
    
	len--;

	delete temp;
	return result;
}

// prints the contents of the queue, one value per line, from front to back
template <class V>
void QueueT<V>::print() const
{
    NodeT<V>* p = front;
    while ( p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

// returns true if the queue is empty, false otherwise
template <class V>
bool QueueT<V>::empty() const
{
    return len == 0;
}

// size – returns the number of items stored in the queue
template <class V>
int QueueT<V>::size() const
{
    return len;
}

// has two parameters, a QueueT reference and an integer t 
// adds the first t values stored in its QueueT parameter to the end of the calling object.
template <class V>
void QueueT<V>::concatenate( QueueT& qt, int t)
{
    if (t > qt.size())
    {
        throw runtime_error("integer t is greater than parameter size.Concatenate failed!!!!!");
    }
    else
    {
        int i = 0;
        while (i < t)
        {
            NodeT<V>* temp = qt.front;
            enqueue(temp->data);
            temp = temp->next;
            qt.dequeue();    

            i++;
        }
    }
}

// returns a QueueT object that contains the contents of the calling object and its constant QueueT reference 
// arameter, the resulting queue should start with the first value in the calling object, followed by the first 
// value in the parameter
template <class V>
QueueT<V> QueueT<V>::merge(const QueueT& qt)
{
    QueueT<V> answer;
    NodeT<V>* temp1 = front;
    NodeT<V>* temp = qt.front;
    int len2 = qt.len;
    for (int i = 0; (i < len || i < len2); i++)
    {
        if (i < len && front != nullptr)
        {
            answer.enqueue(temp1->data);
            temp1 = temp1->next;
        }
        
        if (i < len2 && temp != nullptr)
        {
            answer.enqueue(temp->data);
            temp = temp->next;
        }
    }
    return answer;
}