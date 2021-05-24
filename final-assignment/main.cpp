#include "knightMovesCalculator.cpp"
// #include "chessPiece.cpp"
// #include "unsortedtype.cpp"

#include <iostream>
using namespace std;

// Driver code to test above methods
int main()
{
    int totalOpponents;
    cout << "Number of opponent pieces: ";
    cin >> totalOpponents;
    UnsortedType<chessPiece> opponents;

    cout << endl;
    for (int i = 0; i < totalOpponents; i++)
    {
        string identifier;
        int x;
        int y;
        cout << "Enter identifier and position of opponent " << i + 1 << " respectively: " << endl;
        cin >> identifier >> x >> y;
        chessPiece temp(x, y, identifier);
        opponents.insertItem(temp);
    }

    cout << endl;
    int totalOwnPieces;
    cout << "Number of own pieces: ";
    cin >> totalOwnPieces;
    UnsortedType<chessPiece> ownPieces;

    cout << endl;
    for (int i = 0; i < totalOwnPieces; i++)
    {
        // string identifier;
        int x;
        int y;
        cout << "Enter position of your piece " << i + 1 << ": " << endl;
        cin >> x >> y;
        chessPiece temp(x, y);
        ownPieces.insertItem(temp);
    }

    cout << endl;
    int knightPosX, knightPosY;
    cout << "Enter knight's position: " << endl;
    cin >> knightPosX >> knightPosY;
    int knightPosition[] = {knightPosX, knightPosY};

    knightMoveCalculator knight(ownPieces);

    chessPiece temp2;
    cout << endl;
    for (int i = 0; i < opponents.lengthIs(); i++)
    {
        knightMoveCalculator knight;
        opponents.getNextItem(temp2);
        int targetPos[] = {temp2.x, temp2.y};
        cout << temp2.identifier << ": " << knight.movesToCaptureTarget(knightPosition, targetPos) << endl;
    }

    return 0;
}