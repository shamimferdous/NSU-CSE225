#ifndef CHESSPIECE_H_INCLUDED
#define CHESSPIECE_H_INCLUDED
#include "string"

class chessPiece
{
public:
    chessPiece();
    chessPiece(int, int);
    chessPiece(int, int, std::string);
    int x;
    int y;
    std::string identifier;

private:
};
#endif // CHESSPIECE_H_INCLUDED