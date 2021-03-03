// Task 9: Write a program that asks user for an arithmetic operator (+, - , * or / ) and two operands, a and b. Display the result of the corresponding operation using switch statement.
// Example:
// Enter the operator: *
// Enter a: 50
// Enter b: 3
// Result: 150

#include <iostream>

using namespace std;

int main()
{
    int month;
    cout << "Enter month: ";
    cin >> month;

    switch (month)
    {
    case 1:
        cout << "Jan - 31" << endl;
        break;
    case 2:
        cout << "Feb - 28" << endl;
        break;
    case 3:
        cout << "Mar - 31" << endl;
        break;
    case 4:
        cout << "Apr - 30" << endl;
        break;
    case 5:
        cout << "May - 31" << endl;
        break;
    case 6:
        cout << "Jun - 30" << endl;
        break;
    case 7:
        cout << "Jul - 31" << endl;
        break;
    case 8:
        cout << "Aug - 31" << endl;
        break;
    case 9:
        cout << "Sep - 30" << endl;
        break;
    case 10:
        cout << "Oct - 31" << endl;
        break;
    case 11:
        cout << "Nov - 30" << endl;
        break;
    case 12:
        cout << "Dec - 31" << endl;
        break;

    default: // default is for when you enter a number out of 1-12 range. for instance, 13
        cout << "invalid input!" << endl;
    }

    return 0;
}