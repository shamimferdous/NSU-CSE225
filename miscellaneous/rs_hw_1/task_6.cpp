// Task 6: Write a program that determines whether an integer input is odd or even.

#include <iostream>

using namespace std;

int main()
{
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    if (number % 2 == 0)
    {
        cout << "The Number is even!" << endl;
    }
    else
    {
        cout << "The Number is odd!" << endl;
    }
}