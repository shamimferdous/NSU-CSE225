#include <iostream>
#include "stacktype.h"

using namespace std;

template <class T>
StackType<T>::StackType()
{
    this->top = -1;
}

template <class T>
bool StackType<T>::isFull()
{
    return (this->top == max_items_x - 1);
}

template <class T>
bool StackType<T>::isEmpty()
{
    return (this->top == -1);
}

template <class T>
void StackType<T>::Push(T item)
{
    if (isFull())
    {
        throw FullStack();
    }

    top++;
    info[top] = item;
}

template <class T>
void StackType<T>::Pop()
{
    if (isEmpty())
    {
        throw EmptyStack();
    }

    top--;
}

template <class T>
T StackType<T>::Top()
{
    if (isEmpty())
    {
        throw EmptyStack();
    }

    return info[top];
}