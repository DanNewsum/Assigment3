#include <iostream>
#include <cstdlib>
#pragma once
#define SIZE 10

using namespace std;
template <class t> class MyQueue {
public:
    void enqueue(t t);
    void dequeue();
    t peek();
    bool isEmpty();
    int size();
    MyQueue(int size = SIZE);     // constructor
    bool isFull();
private:
    int capacity;
    int count;
    int rear;
    int front;
    t* arr;
};

void RunMain();

