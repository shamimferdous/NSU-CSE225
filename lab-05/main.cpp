#include <iostream>
#include "sortedtype.cpp"
#include "timestamp.cpp"

using namespace std;

int main()
{
    //creating a list of integers
    SortedType<int> ol;

    //checking if the list is empty
    if (ol.isEmpty())
    {
        cout << "The list is empty!" << endl;
    }
    else
    {
        cout << "The list is not empty!" << endl;
    }

    //inserting five items
    int temp;
    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        ol.insertItem(temp);
    }

    //printing the list
    cout << endl;
    for (int i = 0; i < ol.lengthIs(); i++)
    {
        ol.getNextItem(temp);
        cout << temp << "\t";
    }
    ol.resetList();

    //checking if the list is full or not
    cout << endl;
    if (ol.isFull())
    {
        cout << "The list is full!";
    }
    else
    {
        cout << "The list is not full!";
    }

    //deleting 3
    ol.deleteItem(3);

    //printing the list again
    cout << endl;
    for (int i = 0; i < ol.lengthIs(); i++)
    {
        ol.getNextItem(temp);
        cout << temp << "\t";
    }
    ol.resetList();

    //checking if the list is full or not
    cout << endl;
    if (ol.isFull())
    {
        cout << "The list is full!";
    }
    else
    {
        cout << "The list is not full!";
    }

    //creating list of objects of class timeStamp
    SortedType<timeStamp> timeStamps;

    //Inserting 5 time values in the format ssmmhh
    timeStamp ts_1(15, 34, 23);
    timeStamp ts_2(45, 12, 12);
    timeStamp ts_3(35, 12, 6);
    timeStamp ts_4(12, 40, 18);
    timeStamp ts_5(12, 12, 12);

    timeStamps.insertItem(ts_1);
    timeStamps.insertItem(ts_2);
    timeStamps.insertItem(ts_3);
    timeStamps.insertItem(ts_4);
    timeStamps.insertItem(ts_5);

    //printing the timestamp list
    cout << endl
         << endl;
    timeStamp timeStamp_temp;
    for (int i = 0; i < timeStamps.lengthIs(); i++)
    {
        timeStamps.getNextItem(timeStamp_temp);
        cout << timeStamp_temp << "\n";
    }
    timeStamps.resetList();

    //deleting one timestmap
    timeStamps.deleteItem(ts_5);

    //printing the timestamp list again
    cout << endl
         << endl;
    for (int i = 0; i < timeStamps.lengthIs(); i++)
    {
        timeStamps.getNextItem(timeStamp_temp);
        cout << timeStamp_temp << "\n";
    }
    timeStamps.resetList();

    //checking if the list is full or not
    cout << endl;
    if (timeStamps.isFull())
    {
        cout << "The list is full!";
    }
    else
    {
        cout << "The list is not full!";
    }

    return 0;
}