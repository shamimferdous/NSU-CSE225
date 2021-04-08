#include "sortedtype.h"
#include <iostream>
using namespace std;

//defining constructor
template <class T>
SortedType<T>::SortedType()
{
    length = 0;
    info = NULL;
    currentLocation = NULL;
}

//defining MakeEmpty method
template <class T>
void SortedType<T>::MakeEmpty()
{
    Node *temp;
    while (info != NULL)
    {
        temp = info;
        info = info->next;
        delete temp;
    }
    length = 0;
}

//TODO:Need to implement isEmpty
template <class T>
bool SortedType<T>::IsEmpty()
{
    if (length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//defining IsFull method
template <class T>
bool SortedType<T>::IsFull()
{
    Node *location;
    try
    {
        location = new Node;
        delete location;
        return false;
    }
    catch (bad_alloc &exception)
    {
        return true;
    }
}

//defining LengthIs method
template <class T>
int SortedType<T>::LengthIs()
{
    return length;
}

//defining InsertItem method
template <class T>
void SortedType<T>::InsertItem(T item)
{
    Node *newNode;
    Node *predLoc;
    Node *location;

    bool ts;

    location = info;
    predLoc = NULL;
    ts = (location != NULL);
    while (ts)
    {
        if (location->info < item)
        {
            predLoc = location;
            location = location->next;
            ts = (location != NULL);
        }
        else
            ts = false;
    }
    newNode = new Node;
    newNode->info = item;
    if (predLoc == NULL)
    {
        newNode->next = info;
        info = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

//defining DeleteItem method
template <class T>
void SortedType<T>::DeleteItem(T item)
{
    Node *location = info;
    Node *tempLocation;
    if (item == info->info)
    {
        tempLocation = location;
        info = info->next;
    }
    else
    {
        while (!(item == (location->next)->info))
        {
            location = location->next;
        }

        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

//defining RetrieveItem method
template <class T>
void SortedType<T>::RetrieveItem(T &item, bool &found)
{
    Node *location = info;
    bool ts = (location != NULL);
    found = false;
    while (ts && !found)
    {
        if (item == location->info)
            found = true;
        else if (item > location->info)
        {
            location = location->next;
            ts = (location != NULL);
        }
        else
            ts = false;
    }
}

//defining ResetList method
template <class T>
void SortedType<T>::ResetList()
{
    currentLocation = NULL;
}

//defining GetNextItem method
template <class T>
void SortedType<T>::GetNextItem(T &item)
{
    if (currentLocation == NULL)
        currentLocation = info;
    else
        currentLocation = currentLocation->next;
    item = currentLocation->info;
}