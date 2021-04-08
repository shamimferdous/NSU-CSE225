#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

//initing the starting node
struct Node *head = NULL;

//initing the end node
struct Node *foot = NULL;

//defining InsertAtFirst function
void InsertAtFirst(int item)
{
    struct Node *temp = new Node;

    if (head == NULL)
    {
        head = temp;

        temp->prev = NULL;
        temp->next = NULL;
        temp->data = item;

        foot = temp;
    }
    else
    {

        temp->next = head;
        temp->prev = NULL;
        temp->data = item;

        head->prev = temp;
        head = temp;
    }
}

//defining InsertAtLast function
void InsertAtLast(int item)
{
    struct Node *temp;
    temp = new Node;

    temp->data = item;

    if (head != NULL)
    {
        temp->prev = foot;
        temp->next = NULL;
        foot->next = temp;

        foot = temp;
    }
    else
    {
        head = temp;
        temp->prev = NULL;
        temp->next = NULL;

        foot = temp;
    }
}

//defining InsertPosition function
void InsertPosition(int pos, int item)
{

    struct Node *temp_foo, *temp_bar;
    temp_bar = head;

    int i = 1;
    while (i < (pos - 1) && (temp_bar != NULL))
    {
        temp_bar = temp_bar->next;
        i++;
    }

    if (pos == 1)
    {
        InsertAtFirst(item);
    }
    else if (temp_bar == foot)
    {
        InsertAtLast(item);
    }
    else if (temp_bar != NULL)
    {
        temp_foo = new Node;

        temp_foo->next = temp_bar->next;
        temp_foo->prev = temp_bar;
        temp_foo->data = item;

        if (temp_bar->next != NULL)
        {
            temp_bar->next->prev = temp_foo;
        }
        temp_bar->next = temp_foo;
    }
    else
    {
        cout << "Invalid position!";
    }
}

// //defining DeleteAtFirst function
void DeleteAtFirst()
{
    //terminating if the list is empty
    if (head == NULL)
    {
        return;
    }

    if (head != foot)
    {
        struct Node *temp;

        temp = head;
        head = head->next;
        head->prev = NULL;

        delete temp;
        return; //terminating here
    }
    else //if there's only one item in the list
    {
        struct Node *temp;
        temp = head;
        head = NULL;
        foot = NULL;

        delete temp;
    }
}

//defining DeleteAtLast function
void DeleteAtLast()
{
    //terminating if the list is empty
    if (head == NULL)
    {
        return;
    }

    if (head != foot)
    {
        struct Node *temp;

        temp = foot;
        foot = foot->prev;
        foot->next = NULL;

        delete temp;
        return; //terminating here
    }
    else
    {
        struct Node *temp;

        temp = head;
        head = NULL;
        foot = NULL;

        delete temp;
    }
}

//defining DeletePosition function
void DeletePosition(int pos)
{
    struct Node *curNode;
    int i;

    curNode = head;
    for (i = 1; i < pos && curNode != NULL; i++)
    {
        curNode = curNode->next;
    }

    if (pos == 1)
    {
        DeleteAtFirst();
    }
    else if (curNode == foot)
    {
        DeleteAtLast();
    }
    else if (curNode != NULL)
    {
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;

        delete curNode;
    }
    else
    {
        cout << " The given position is invalid!\n";
    }
}

//defining DeleteValue function
void DeleteValue(int item)
{
    struct Node *temp_foo = head;
    Node *temp_bar = foot;

    //checking if the head node has the item value we want to delete
    if (temp_foo->data == item)
    {
        DeleteAtFirst();
        return;
    }
    else if (foot->data == item)
    {
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
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

//defining the print reverse fuction
void PrintReverse()
{
    struct Node *temp;
    temp = foot;

    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->prev;
    }
    cout << endl;
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
    PrintReverse();

    //inserting node at last position
    InsertAtLast(50);
    Print();
    PrintReverse();

    //inserting node at given position
    InsertPosition(2, 99);
    Print();
    PrintReverse();

    //deleting node at first position
    DeleteAtFirst();
    Print();
    PrintReverse();

    //deleting node at last position
    DeleteAtLast();
    Print();
    PrintReverse();

    //deleting node at given position
    DeletePosition(3); //TODO:Issue in this function
    cout << "deleted form position";
    Print();
    PrintReverse();

    //delete node by given value
    DeleteValue(99);
    Print();
    PrintReverse();

    return 0;
}