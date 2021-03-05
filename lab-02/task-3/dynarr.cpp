#include "dynarr.h"
#include <iostream>
using namespace std;

dynArr::dynArr()
{
    data = NULL;
    row = 0;
    col = 0;
}

dynArr::dynArr(int row, int col)
{
    this->row = row;
    this->col = col;

    data = new int *[row];
    //allocating col for each row
    for (int i = 0; i < row; i++)
    {
        data[i] = new int[col];
    }
}

dynArr::~dynArr()
{
    delete[] data;
}

int dynArr::getValue(int row, int col)
{
    return data[row][col];
}

void dynArr::setValue(int row, int col, int value)
{
    data[row][col] = value;
}

//defining allocate method
void dynArr::allocate(int row, int col)
{
    this->row = row;
    this->col = col;

    data = new int *[row];
    //allocating col for each row
    for (int i = 0; i < row; i++)
    {
        data[i] = new int[col];
    }
}
