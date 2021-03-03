// Task 7: Write a program that checks whether a particular year (provided as input) is leap year or not. To determine whether a year is leap year or not, use the following rules.
// A leap year must satisfy any or both of the following conditions:
// • Year is divisible by 4 but not divisible by 100
// • Year is divisible by 400

#include <iostream>

using namespace std;

int main()
{
    int year;

    //getting user input
    cout << "Enter a year: ";
    cin >> year;

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                cout << year << " is a leap year." << endl;
            else
                cout << year << " is not a leap year." << endl;
        }
        else
            cout << year << " is a leap year." << endl;
    }
    else
        cout << year << " is not a leap year." << endl;

    return 0;
}