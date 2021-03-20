#include "sortedtype.h"

#include <iostream>
using namespace std;

template <class T>
SortedType<T>::SortedType()
{
    length = 0;
    currentPos = -1;
}

template <class T>
void SortedType<T>::makeEmpty()
{
    length = 0;
}

template <class T>
bool SortedType<T>::isEmpty()
{
    return (length == 0);
}

template <class T>
bool SortedType<T>::isFull()
{
    return (length == max_items);
}

template <class T>
int SortedType<T>::lengthIs()
{
    return length;
}

template <class T>
void SortedType<T>::insertItem(T item)
{
    int position = 0;
    bool tS = (position < length);
    while (tS)
    {
        if (item > info[position])
        {
            position++;
            tS = (position < length);
        }
        else if (item < info[position])
            tS = false;
    }
    for (int index = length; index > position; index--)
        info[index] = info[index - 1];
    info[position] = item;
    length++;
}

template <class T>
void SortedType<T>::deleteItem(T item)
{
    int position = 0;
    while (item != info[position])
        position++;
    for (int index = position + 1; index < length; index++)
        info[index - 1] = info[index];
    length--;
}

template <class T>
void SortedType<T>::resetList()
{
    currentPos = -1;
}

template <class T>
void SortedType<T>::getNextItem(T &item)
{
    currentPos++;
    item = info[currentPos];
}

template <class T>
void SortedType<T>::retriveItem(T &item, bool &found)
{
    int mid, first = 0, last = length - 1;
    bool tS = (first <= last);
    found = false;
    while (tS && !found)
    {
        mid = (first + last) / 2;
        if (item < info[mid])
        {
            last = mid - 1;
            tS = (first <= last);
        }
        else if (item > info[mid])
        {
            first = mid + 1;
            tS = (first <= last);
        }
        else
        {
            found = true;
            item = info[mid];
        }
    }
}