#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED
const int max_items = 10;

class FullStack
{
};

class EmptyStack
{
};
template <class T>
class StackType
{

private:
    int top;
    T info[max_items];

public:
    StackType();
    bool isFull();
    bool isEmpty();
    void Push(T);
    void Pop();
    T Top();
};

#endif // STACKTYPE_H_INCLUDED


#include <iostream>
// #include "stacktype.h"

using namespace std;

template <class T>
StackType<T>::StackType()
{
    this->top = -1;
}

template <class T>
bool StackType<T>::isFull()
{
    return (this->top == max_items - 1);
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


#include <iostream>
// #include "stacktype.cpp"

using namespace std;


int main()
{
    int n, m, x, temp;
    cin >> n >> m >> x;

    //initing two stack obj
    StackType<int> A;
    StackType<int> B;

    //inserting items at stack A
    // cout << "Enter " << n << " values for Stack A: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp < 0)
        {
            cout << "Please enter a non-negative integer!" << endl;
            i = i - 1;
        }
        else
        {
            A.Push(temp);
        }
    }

    //inserting items at stack B
    // cout << "Enter " << m << " values for Stack B: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (temp < 0)
        {
            cout << "Please enter a non-negative integer!" << endl;
            i = i - 1;
        }
        else
        {
            B.Push(temp);
        }
    }

    int sum = 0;
    int score = 0;
    while (sum <= x)
    {

        //best bet will be to always try and pick
        //the integer that is small
        //to earn max possible score
        if (A.Top() < B.Top())
        {
            sum = sum + A.Top();
            A.Pop();
            score++;
        }
        else
        {
            sum = sum + B.Top();
            B.Pop();
            score++;
        }

        //this checks that after popping and adding the int to the sum
        //the sum exceeds x or not.
        //if x is exceeded it makes count, count-1
        if (!(sum <= x))
        {
            score = score - 1;
        }
    }

    cout << endl
         << score;
}