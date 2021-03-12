#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

class Complex
{
public:
    Complex();
    Complex(double, double);
    Complex operator+(Complex);
    Complex operator-(Complex); //substraction overload
    Complex operator*(Complex); //multiplication overload
    bool operator!=(Complex);   //not equal overload
    bool operator==(Complex);   //equal overload
    void Print();

private:
    double Real, Imaginary;
};

#endif