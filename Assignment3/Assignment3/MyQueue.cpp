#include "MyQueue.h"

// Constructor to initialize a queue
template <class t>
MyQueue<t>::MyQueue(int size)
{
    arr = new t[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

template <class t>
bool MyQueue<t>::isFull() {
    return (size() == capacity);
}

template <class t> int MyQueue<t>::size() {
	return count;
}

template <class t> bool MyQueue<t>::isEmpty() {
	return (size() == 0);
}

// Utility function to add an item to the queue
template <class t>
void MyQueue<t>::enqueue( t item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Utility function to dequeue the front element
template <class t>
void MyQueue<t>::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << arr[front] << endl;

    front = (front + 1) % capacity;
    count--;
}

template <class t>
t MyQueue<t>::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

void RunMain()
{
    // create a queue of capacity 4
    MyQueue<string> q(4);

    q.enqueue("a");
    q.enqueue("b");
    q.enqueue("c");

    cout << "The front element is " << q.peek() << endl;
    q.dequeue();

    q.enqueue("d");

    cout << "The queue size is " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.isEmpty()) {
        cout << "The queue is empty\n";
    }
    else {
        cout << "The queue is not empty\n";
    }

    
}


