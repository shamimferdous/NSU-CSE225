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

    if (head != NULL)
    {
        temp->next = head;
        temp->prev = NULL;
        temp->data = item;

        head->prev = temp;
        head = temp;
    }
    else
    {
        head = temp;

        temp->prev = NULL;
        temp->next = NULL;
        temp->data = item;

        foot = temp;
    }
}

//defining InsertAtLast function
void InsertAtLast(int item)
{
    struct Node *temp = new Node;

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

//defining DeleteAtFirst function
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
        struct Node *temp = foot;

        foot = foot->prev;
        foot->next = NULL;

        delete temp;
        return; //terminating here
    }
    else
    {
        struct Node *temp = head;

        head = NULL;
        foot = NULL;

        delete temp;
    }
}

//defining DeletePosition function
void DeletePosition(int pos)
{
    struct Node *temp;

    temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (pos == 1) //if given position is head
    {
        DeleteAtFirst();
    }
    else if (temp == foot)
    {
        DeleteAtLast();
    }
    else if (temp != NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }
    else
    {
        cout << "Invalid position!";
    }
}

//defining DeleteValue function
void DeleteValue(int item)
{
    struct Node *temp_foo = head;
    Node *temp_bar = foot;

    //checking if head has our item
    if (temp_foo->data == item)
    {
        DeleteAtFirst();
        return;
    }
    //checking if foot has out item
    else if (foot->data == item)
    {
        DeleteAtLast();
        return;
    }
    //or looking through the list
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
    int x, pos;

    //inserting four node at first
    cout << "Enter 4 values to insert at first: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        InsertAtFirst(x);
    }
    Print();

    //printing the list in reverse
    cout << endl
         << "Printing the list in reverse" << endl;
    PrintReverse();

    //inserting node at last position
    cout << "Enter a value to insert at last: " << endl;
    cin >> x;
    InsertAtLast(x);
    Print();

    //inserting node at given position
    cout << endl
         << "Enter a position and it's value respectively: " << endl;
    cin >> pos >> x;
    InsertPosition(pos, x);
    Print();

    //deleting node at first position
    cout << endl
         << "Deleting node at first position" << endl;
    DeleteAtFirst();
    Print();

    //deleting node at last position
    cout << endl
         << "Deleting node at last position"
         << endl;
    DeleteAtLast();
    Print();

    //deleting node at given position
    cout << endl
         << "Enter a position to delete node at: " << endl;
    cin >> pos;
    DeletePosition(pos);
    Print();

    //delete node by given value
    cout << endl
         << "Enter a value to delete from the list: " << endl;
    cin >> x;
    DeleteValue(x);
    Print();

    return 0;
}