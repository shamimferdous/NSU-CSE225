// Implement a linked list using these functions-
// 1.InsertAtFirst(int item)
// 2.InsertAtLast(int item )
// 3.InsertPosition(int pos, int item)
// 4.DeleteAtFirst( )
// 5.DeleteAtLast( )
// 6.DeletePosition(int pos)
// 7.DeleteValue(int item)
// and use proper input output to prove that these functions are viable

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

//initing the starting node
struct Node *head = NULL;

//defining InsertAtFirst function
void InsertAtFirst(int item)
{
    struct Node *temp = new Node;

    temp->data = item;
    temp->next = head;
    if (head != NULL)
    {
        temp->next = head;
    }
    head = temp;
}

//defining InsertAtLast function
void InsertAtLast(int item)
{
    struct Node *temp = new Node;
    struct Node *tail = head;

    temp->data = item;
    temp->next = NULL;

    //inserting in first node if empty
    if (head == NULL)
    {
        head = temp;
        return;
    }

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = temp;
}

//defining InsertPosition function
void InsertPosition(int pos, int item)
{

    struct Node *temp_foo = new Node;

    temp_foo->data = item;
    temp_foo->next = NULL;
    if (pos == 1)
    {
        temp_foo->next = head;
        head = temp_foo;
        return;
    }

    struct Node *temp_bar = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp_bar = temp_bar->next;
    }

    temp_foo->next = temp_bar->next;
    temp_bar->next = temp_foo;
}

//defining DeleteAtFirst function
void DeleteAtFirst()
{
    if (head == NULL)
    {
        cout << "Empty list!" << endl;
        return;
    }

    head = head->next;
}

//defining DeleteAtLast function
void DeleteAtLast()
{
    if (head->next == NULL)
    {
        delete head;
    }

    // finding the node before tail node
    Node *before_tail = head;
    while (before_tail->next->next != NULL)
        before_tail = before_tail->next;

    delete (before_tail->next);
    before_tail->next = NULL;
}

//defining DeletePosition function
void DeletePosition(int pos)
{
    struct Node *temp_foo = head;

    //if to be deleted node is the first node
    if (pos == 1)
    {
        head = temp_foo->next; // head points to second Node
        delete temp_foo;
        return;
    }

    for (int i = 0; i < pos - 2; i++)
    {
        temp_foo = temp_foo->next;
    }

    struct Node *temp_bar = new Node;
    temp_bar = temp_foo->next;
    temp_foo->next = temp_bar->next;
    delete temp_bar;
}

//defining DeleteValue function
void DeleteValue(int item)
{
    struct Node *temp_foo = head;
    Node *temp_bar = NULL;

    //checking if the head node has the item value we want to delete
    if (temp_foo != NULL && temp_foo->data == item)
    {
        head = temp_foo->next;
        return;
    }
    //or searching for the item to be deleted
    else
    {
        while ((temp_foo != NULL) && (temp_foo->data != item))
        {
            temp_bar = temp_foo;
            temp_foo = temp_foo->next;
        }

        // if the value not found just terminatinf the function
        if (temp_foo == NULL)
        {
            cout << "Given node not found in the list" << endl;
            return;
        }

        temp_bar->next = temp_foo->next;
        delete temp_foo;
    }
}

//defining a function to print the list
void Print()
{
    if (head == NULL)
    {
        cout << "Empty list!" << endl;
        return;
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    //inserting four node at first
    InsertAtFirst(10);
    InsertAtFirst(20);
    InsertAtFirst(30);
    InsertAtFirst(40);
    Print();

    //inserting node at last position
    InsertAtLast(50);
    Print();

    //inserting node at given position
    InsertPosition(2, 99);
    Print();

    //deleting node at first position
    DeleteAtFirst();
    Print();

    //deleting node at last position
    DeleteAtLast();
    Print();

    //deleting node at given position
    DeletePosition(3);
    Print();

    //delete node by given value
    DeleteValue(99);
    Print();

    return 0;
}