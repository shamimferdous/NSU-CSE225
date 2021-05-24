#include "chessPiece.h"
#include "string"

//defining default constructor without identifier
chessPiece::chessPiece()
{
}

//defining constructor without identifier
chessPiece::chessPiece(int x, int y)
{
    this->x = x;
    this->y = y;
}

//defining constructor with identifier
chessPiece::chessPiece(int x, int y, std::string identifier)
{
    this->x = x;
    this->y = y;
    this->identifier = identifier;
}