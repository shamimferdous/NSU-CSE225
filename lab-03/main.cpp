// Task : Recall the complex number class we discussed in our lectures. Modify the class and overload the
// –(subtraction), * (multiplication) , != (not equal) and the = =( equal) operators for the class given below.

#include <iostream>
#include "complex.h"
#include "complex.cpp"

using namespace std;

int main()
{
    Complex foo(1, 9);
    Complex bar(7, 2);

    Complex sum = foo + bar;
    sum.Print();

    Complex sub = foo - bar;
    sub.Print();

    Complex multip = foo * bar;
    multip.Print();

    bool isNotEqual = foo != bar;
    cout << isNotEqual << " => " << (isNotEqual == 1 ? "The complex numbers are not equal" : "The complex numbers are equal") << endl;

    bool isEqual = foo == bar;
    cout << isEqual << " => " << (isNotEqual == 0 ? "The complex numbers are equal" : "The complex numbers are not equal") << endl;

    return 0;
}