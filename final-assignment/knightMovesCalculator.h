#ifndef KNIGHTMOVESCALCULATOR_H_INCLUDED
#define KNIGHTMOVESCALCULATOR_H_INCLUDED
#include <bits/stdc++.h>
#include "unsortedtype.h"
#include "chessPiece.h"
const int TOTAL_SQUARES = 56;

// structure for storing a cell's data
struct cell
{
    int x, y;
    int distance;
    cell() {}
    cell(int x, int y, int distance) : x(x), y(y), distance(distance) {}
};

class knightMoveCalculator
{
public:
    knightMoveCalculator();
    knightMoveCalculator(UnsortedType<chessPiece>);
    int movesToCaptureTarget(int[], int[]);

private:
    UnsortedType<chessPiece> ownPieces;
    bool isValid(int, int);
    bool isConflicted(int, int);
};
#endif // KNIGHTMOVESCALCULATOR_H_INCLUDED