#include <iostream>
#include "quetype.cpp"
#include "stacktype.cpp"
using namespace std;

void PrintBinary(int n)
{
    QueType<string> q;
    // string temp;
    q.Enqueue("1");
    while (n--)
    {

        string temp_str_1 = q.Front();
        q.Dequeue();
        cout << temp_str_1 << endl;
        string temp_str_2 = temp_str_1;
        q.Enqueue(temp_str_1.append("0"));
        q.Enqueue(temp_str_2.append("1"));
    }
}

void CheckEmpty(QueType<int> q)
{
    if (q.isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is Not empty" << endl;
    }
}

void CheckFull(QueType<int> q)
{
    if (q.isFull())
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        cout << "Queue is Not full" << endl;
    }
}

void Print(QueType<int> q)
{
    QueType<int> temp;

    while (!q.isEmpty())
    {
        temp.Enqueue(q.Front());
        cout << q.Front() << " ";
        q.Dequeue();
    }

    while (!temp.isEmpty())
    {
        q.Enqueue(temp.Front());
        temp.Dequeue();
    }
    cout << endl;
}

void PrintReverse(QueType<int> q)
{
    StackType<int> stack;

    while (!q.isEmpty())
    {
        stack.Push(q.Front());
        q.Dequeue();
    }

    StackType<int> tempStack;
    while (stack.isEmpty() == false)
    {
        tempStack.Push(stack.Top());
        cout << stack.Top() << " ";
        stack.Pop();
    }

    cout << endl;
}

bool WeightMeter(QueType<int> q, int weightLimit)
{
    int sum = 0;

    while (!q.isEmpty())
    {
        sum = sum + q.Front();
        q.Dequeue();
    }

    // cout << "Total weight: " << sum;

    if (sum <= weightLimit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    QueType<int> q;
    int n;
    CheckEmpty(q);
    q.Front();
    for (int i = 0; i < 4; i++)
    {
        cin >> n;
        q.Enqueue(n);
    }
    CheckEmpty(q);
    CheckFull(q);
    cin >> n;
    q.Enqueue(n); //enqueuing another item
    Print(q);
    CheckFull(q);
    cin >> n;
    q.Enqueue(n);
    q.Dequeue(); //dequeing
    q.Dequeue(); //two items
    Print(q);
    q.Dequeue(); //dequeing
    q.Dequeue(); //three
    q.Dequeue(); //items
    CheckEmpty(q);
    q.Dequeue();                //dequeing an item
    for (int i = 0; i < 5; i++) //enqueuing five items
    {
        cin >> n;
        q.Enqueue(n);
    }
    cout << "printing reverse" << endl;
    PrintReverse(q);
    Print(q);

    QueType<int> lift;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        lift.Enqueue(n);
    }
    int weigtLimit;
    cout << "Enter weight limit: ";
    cin >> weigtLimit;
    if (WeightMeter(lift, weigtLimit))
    {
        cout << "Good to go" << endl;
    }
    else
    {
        cout << "Over Weight.\nMaximum limit " << weigtLimit;
    }

    //Now change the max_items
    //TODO:gotta check
    // int *ptr;
    // ptr = (int *)&max_items;
    // *ptr = 50;

    int binaryNumbers;
    cin >> binaryNumbers;
    PrintBinary(binaryNumbers);

    return 0;
}