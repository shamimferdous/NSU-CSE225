#include "quetype.h"
#include <iostream>

using namespace std;

template <class T>
QueType<T>::QueType()
{
    rear = -1;
    front = -1;
    // info = new T[max_items];
}

template <class T>
void QueType<T>::MakeEmpty()
{
    front = max_items - 1;
    rear = max_items - 1;
}

template <class T>
bool QueType<T>::isEmpty()
{
    return (rear == -1 && front == -1);
}

template <class T>
bool QueType<T>::isFull()
{
    return ((rear + 1) % max_items == front);
}

template <class T>
void QueType<T>::Enqueue(T item)
{
    try
    {
        if (isFull())
        {
            throw FullQueue();
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
        }
        else
        {
            // cout << "Inserting item to queue[rear, iValue] " << rear << ", " << item;
            rear = (rear + 1) % max_items;
        }
        info[rear] = item;
    }
    catch (FullQueue f)
    {
        cout << "Queue is full" << endl;
    }
}

template <class T>
void QueType<T>::Dequeue()
{
    try
    {
        if (isEmpty())
        {
            throw EmptyQueue();
        }
        else if (rear == front)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front = (front + 1) % max_items;
        }
    }
    catch (EmptyQueue e)
    {
        cout << "Queue is already empty" << endl;
    }
}

template <class T>
T QueType<T>::Front()
{
    try
    {
        if (isEmpty())
        {
            throw EmptyQueue();
        }
        else
        {
            return info[front];
        }
    }
    catch (EmptyQueue e)
    {
        cout << "The queue is already empty!" << endl;
    }
}