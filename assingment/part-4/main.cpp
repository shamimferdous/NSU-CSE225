#include <iostream>
#include "sortedtype.cpp"

using namespace std;

//defining the PrintList function
template <class T>
void PrintList(SortedType<T> *list)
{
    int temp;

    // cout << endl;
    for (int i = 0; i < list->LengthIs(); i++)
    {
        list->GetNextItem(temp);
        cout << temp << "\t";
    }
    cout << endl;
    list->ResetList();
}

int main()
{
    //creating a new sortedType object
    SortedType<int> list;

    //checking if the list is empty
    if (list.IsEmpty())
    {
        cout << "The list is empty!" << endl;
    }
    else
    {
        cout << "The list is not empty!" << endl;
    }

    //checking if the list is full or not
    // cout << endl;
    if (list.IsFull())
    {
        cout << "The list is full!" << endl;
    }
    else
    {
        cout << "The list is not full!" << endl;
    }

    //inserting five items
    int temp;
    cout
        << "Plesae enter 5 integers respectively - " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        list.InsertItem(temp);
    }
    //printing the list
    PrintList(&list);

    //deleting an item from the list
    cout << "Enter an integer from your previous input to delete it: " << endl;
    cin >> temp;
    list.DeleteItem(temp);
    //printing the list
    PrintList(&list);

    //printing the length of the list
    cout << "The current length of the list is: " << list.LengthIs() << endl;

    //retrieving an item from the list
    bool isFound;
    int item;
    cout << "Enter an integer to retrieve from the list: ";
    cin >> item;
    list.RetrieveItem(item, isFound);
    if (isFound)
    {
        cout << item << " was found and retrieved from the the list!" << endl;
    }
    else
    {
        cout << item << " was not found in the list!" << endl;
    }

    //making the list empty
    cout << "Making the list empty!" << endl;
    list.MakeEmpty();

    //checking if the list is empty
    if (list.IsEmpty())
    {
        cout << "The list is empty!" << endl;
    }
    else
    {
        cout << "The list is not empty!" << endl;
    }

    //checking if the list is full or not
    // cout << endl;
    if (list.IsFull())
    {
        cout << "The list is full!" << endl;
    }
    else
    {
        cout << "The list is not full!" << endl;
    }

    //GetNextItem and ResetList methods are demoed in the PrintList function

    return 0;
}