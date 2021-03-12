#include <iostream>
#include "complex.h"

using namespace std;

Complex::Complex()
{
    Real = 0;
    Imaginary = 0;
}

Complex::Complex(double r, double i)
{
    Real = r;
    Imaginary = i;
}

Complex Complex::operator+(Complex a)
{
    Complex t;
    t.Real = Real + a.Real;
    t.Imaginary = Imaginary + a.Imaginary;

    return t;
}

Complex Complex::operator-(Complex a)
{
    Complex t;
    t.Real = Real - a.Real;
    t.Imaginary = Imaginary - a.Imaginary;

    return t;
}

Complex Complex::operator*(Complex a)
{
    Complex t;
    t.Real = (Real * a.Real) - (Imaginary * a.Imaginary);
    t.Imaginary = (Real * a.Imaginary) + (Imaginary * a.Real);

    return t;
}

bool Complex::operator!=(Complex a)
{
    return (a.Real != Real && a.Imaginary != Imaginary);
}

bool Complex::operator==(Complex a)
{
    return (a.Real == Real && a.Imaginary == Imaginary);
}

void Complex::Print()
{
    cout << Real << (Imaginary >= 0 ? "+" : "") << Imaginary << "i" << endl;
}