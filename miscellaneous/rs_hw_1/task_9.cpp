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
    char op;
    float num1, num2;

    cout << "Please enter operator: ";
    cin >> op;

    cout << "Please enter two operands: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << num1 + num2;
        break;

    case '-':
        cout << num1 - num2;
        break;

    case '*':
        cout << num1 * num2;
        break;

    case '/':
        cout << num1 / num2;
        break;

    default:
        cout << "Invalid Operator!";
        break;
    }

    return 0;
}