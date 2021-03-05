#include <iostream>
#include "dynarr.h"
#include "dynarr.cpp"

using namespace std;

int main()
{
    //creating new dynArr obj of 3 as cons arg
    dynArr<float> arr(3);

    //getting five values from user and storing
    //inside arr obj the using set method
    float temp;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter a value: ";
        cin >> temp;
        arr.setValue(i, temp);
    }

    //printing the values
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr.getValue(i) << endl;
    }
}