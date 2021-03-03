// Task 2: Write a program that asks the user to enter two integer numbers,
// obtains the two numbers from the user and prints the sum, product,
// difference, quotient and remainder of the two numbers

#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cout << "Enter two integer respectively: " << endl;
    cin >> a >> b;

    cout << "Sum: " << a + b << endl;
    cout << "Product: " << a * b << endl;
    cout << "Difference: " << a - b << endl;
    cout << "Quotient: " << a / b << endl;
    cout << "Remainder: " << a % b << endl;
}