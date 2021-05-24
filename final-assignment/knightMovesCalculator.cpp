#include "knightMovesCalculator.h"
#include "quetype.cpp"
#include "unsortedtype.cpp"
#include "chessPiece.cpp"

#include <iostream>

using namespace std;

//defining default constructor
knightMoveCalculator::knightMoveCalculator()
{
}

//defining constructor with ownPieces list
knightMoveCalculator::knightMoveCalculator(UnsortedType<chessPiece> ownPieces)
{
    this->ownPieces = ownPieces;
}

//defining isConflicted method
bool knightMoveCalculator::isConflicted(int x, int y)
{
    bool conflict;
    chessPiece temp;
    for (int i = 0; i < ownPieces.lengthIs(); i++)
    {
        ownPieces.getNextItem(temp);
        if (temp.x == x && temp.y == y)
        {
            ownPieces.resetList();
            conflict = true;
        }
        else
        {
            ownPieces.resetList();
            conflict = false;
        }
    }

    return conflict;
}

//defining isValid method
bool knightMoveCalculator::isValid(int x, int y)
{
    if (x >= 0 && x <= TOTAL_SQUARES && y >= 0 && y <= TOTAL_SQUARES)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int knightMoveCalculator::movesToCaptureTarget(int knightPosition[], int targetPosition[])
{
    //direction of the knight
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    QueType<cell> queue;

    queue.Enqueue(cell(knightPosition[0], knightPosition[1], 0));

    cell current;
    int x, y;
    bool visit[TOTAL_SQUARES + 1][TOTAL_SQUARES + 1];

    for (int i = 1; i <= TOTAL_SQUARES; i++)
    {
        for (int j = 1; j <= TOTAL_SQUARES; j++)
        {
            if (isConflicted(i, j) == true)
            {
                visit[i][j] = true;
            }
            else
            {
                visit[i][j] = false;
            }
        }
    }

    visit[knightPosition[0]][knightPosition[1]] = true;

    while (!queue.isEmpty())
    {
        current = queue.Front();
        queue.Dequeue();

        if (current.x == targetPosition[0] && current.y == targetPosition[1])
            return current.distance;

        for (int i = 0; i < 8; i++)
        {
            x = current.x + dx[i];
            y = current.y + dy[i];

            if (isValid(x, y) && !visit[x][y])
            {
                visit[x][y] = true;
                queue.Enqueue(cell(x, y, current.distance + 1));
            }
        }
    }
}