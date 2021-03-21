#include <iostream>
#include "stacktype.cpp"

using namespace std;

//defining stack Print method
void Print(StackType<int> s)
{

    StackType<int> aux;

    while (!s.isEmpty())
    {
        aux.Push(s.Top());
        s.Pop();
    }
    while (!aux.isEmpty())
    {
        cout << aux.Top() << " ";
        aux.Pop();
    }
    cout << endl;
}

//defining findBiggest method
void findBiggest(StackType<int> s)
{
    StackType<int> aux;
    int m = s.Top();
    int a;

    while (!s.isEmpty())
    {
        aux.Push(s.Top());
        s.Pop();
    }
    while (!aux.isEmpty())
    {
        cout << aux.Top() << " ";
        a = aux.Top();
        if (m < a)
        {
            m = a;
        }
        aux.Pop();
    }
    cout << endl;

    cout << "Biggest element is: " << m << endl;
}

int main()
{
    //creating new stack of integers
    StackType<int> stack;

    //checking if the stack is empty
    if (stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    //pushing four items
    int temp;
    try
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "Enter a value: ";
            cin >> temp;
            stack.Push(temp);
        }
    }
    catch (FullStack f)
    {
        cout << "Stack overflow!" << endl;
    }

    //checking if the stack is empty
    if (stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    //checking if the stack is full
    if (stack.isFull())
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }

    //printing the stack
    Print(stack);

    //pushing another item to stack
    stack.Push(5);

    //printing the stack
    Print(stack);

    //checking if the stack is full
    cout << endl;
    if (stack.isFull())
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }

    //popping two items
    stack.Pop();
    stack.Pop();

    //printing top item
    cout << "Top item: " << stack.Top() << endl;

    //inserting 3 more items
    try
    {
        stack.Push(6);
        stack.Push(7);
        stack.Push(8);
    }
    catch (FullStack f)
    {
        cout << "Stack Overflow!" << endl;
    }

    //finding biggest value from stack
    findBiggest(stack);

    //creating new character stack
    StackType<char>
        stp;
    string tempStr;

    cout << "Enter paranthesis to check balance: " << endl; // taking user input four times for checking
    for (int i = 0; i < 4; i++)
    {
        // cout <<;
        cin >> tempStr;
        cin.clear();

        for (int j = 0; tempStr[j] != '\0'; j++)
        {
            if (tempStr[j] == '(')
            {
                stp.Push(tempStr[j]);
            }

            try
            {
                if (tempStr[j] == ')')
                {
                    stp.Pop();
                }
            }
            catch (EmptyStack e)
            {
                cout << "Not Balanced" << endl;
                return 0;
            }
        }

        if (stp.isEmpty())
        {
            cout << "Balanced" << endl;
        }
        else
        {
            cout << "Not Balanced" << endl;
        }
    }

    return 0;
}