// Task 8 : Write a program that finds the maximum of the three numbers provided as input.

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter three integer respectively: " << endl; //getting user input
    cin >> a >> b >> c;

    if (a >= b && a >= c)
        cout << "Largest number: " << a;

    if (b >= a && b >= c)
        cout << "Largest number: " << b;

    if (c >= a && c >= b)
        cout << "Largest number: " << c;

    return 0;
}