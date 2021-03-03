// Task 4 : Write a program that reads in 3 integer numbers and prints their average.

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter three integer respectively: " << endl; //getting user input
    cin >> a >> b >> c;

    cout << "Average: " << ((a + b + c) / 3) << endl;
}