#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED

class dynArr
{
private:
    int **data;
    int row, col; //need two var to store row size and col size

public:
    dynArr();
    dynArr(int, int); //row size, col size
    ~dynArr();
    void setValue(int, int, int); //row size, col size, value
    int getValue(int, int);       //row size, col size
    void allocate(int, int);      //new row size, new col size
};

#endif