#include <iostream>
#include "quetype.cpp"
#include "stacktype.cpp"
using namespace std;

void PrintBinary(int n)
{
    QueType<string> sq;
    string temp_str_1;
    string temp_str_2;

    sq.Enqueue("1");

    while (n--)
    {
        temp_str_1 = sq.Front();
        cout << temp_str_1 << endl;
        sq.Dequeue();

        temp_str_2 = temp_str_1;
        sq.Enqueue(temp_str_1.append("0"));
        sq.Enqueue(temp_str_2.append("1"));
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
        cout << q.Front() << "   ";
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
    QueType<int> temp;

    while (!q.isEmpty())
    {
        temp.Enqueue(q.Front());
        stack.Push(q.Front());
        q.Dequeue();
    }

    while (!temp.isEmpty())
    {
        q.Enqueue(temp.Front());
        temp.Dequeue();
    }

    StackType<int> tempStack;
    while (stack.isEmpty() == false)
    {
        tempStack.Push(stack.Top());
        cout << stack.Top() << "   ";
        stack.Pop();
    }

    cout << endl;
}

bool WeightMeter(QueType<int> q, int weightLimit)
{
    int sum = 0;
    QueType<int> temp;

    while (!q.isEmpty())
    {
        temp.Enqueue(q.Front());
        sum = sum + q.Front();
        q.Dequeue();
    }

    while (!temp.isEmpty())
    {
        q.Enqueue(temp.Front());
        temp.Dequeue();
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
    q.Enqueue(n);
    Print(q);
    CheckFull(q);
    cin >> n;
    q.Enqueue(n);
    q.Dequeue();
    q.Dequeue();
    Print(q);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    CheckEmpty(q);
    q.Dequeue();
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        q.Enqueue(n);
    }
    PrintReverse(q);
    Print(q);

    QueType<int> lift;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        lift.Enqueue(n);
    }
    int weigtLimit;
    cin >> weigtLimit;
    if (WeightMeter(lift, weigtLimit))
    {
        cout << "Good to go" << endl;
    }
    else
    {
        cout << "Over Weight.\nMaximum limit " << weigtLimit << endl;
    }

    //Now change the max_items
    //Note: I tried quite a few way of changing the max_items const using pointer. But none of them worked.
    //So I believe the max_items will be changed manually.
    //I've assigned 40 to max_items as this way the whole code will run okay.

    // int *ptr = const_cast<int *>(&max_items);
    //int const *ptr = &(max_items);
    //*ptr = 50;
    // max_items = 10;
    // int const test = 10;
    // int &ptr = const_cast<int &>(max_items);
    // ptr = 200;
    // cout << max_items;

    int binaryNumbers;
    cin >> binaryNumbers;
    PrintBinary(binaryNumbers);

    return 0;
}