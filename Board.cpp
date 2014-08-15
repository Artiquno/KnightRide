#include "Board.h"

#include <iostream>
#include <stdexcept>
using namespace std;

#define SPACE "  "

ostream& operator<<(ostream& out, const Square& obj)
{
    if(obj.avail)
        out << obj.priority;
    else
        out << 0;
    return out;
}

Square::Square()
{
    avail = true;
    priority = 8;
}

void Square::setPriority(int val)
{
    if(val > 8 || val < 0)
    {
        throw out_of_range("Priority must be from 0 to 8!");
        return;
    }
    priority = val;
}

//End of Square

//Start of Board

Board::Board()
{
    for(int r = 0; r < 8; ++r)
    {
        for(int c = 0; c < 8; ++c)
        {
            squares[r][c].setAvail(true);
        }
    }
    squares[4][3].setAvail(false);
    currRow = 4;
    currCol = 3;
    setPriorities();
}

Board::Board(int startRow, int startCol)
{
    if((startRow < 0 || startRow >= 8) ||
       (startCol < 0 || startCol >= 8))
    {
        throw out_of_range("Starting row or column is out of range. YOU FUCKING MORON!!!");
        return;
    }
    for(int r = 0; r < 8; ++r)
    {
        for(int c = 0; c < 8; ++c)
        {
            squares[r][c].setAvail(true);
        }
    }
    squares[startRow][startCol].setAvail(false);
    currRow = startRow;
    currCol = startCol;
    setPriorities();
}

const Square* Board::operator[](int index) const
{
    if(index < 0 || index >= 8)
    {
        throw out_of_range("Out of range index for operator[]!");
    }
    return squares[index];
}

Square* Board::operator[](int index)
{
    if(index < 0 || index >= 8)
    {
        throw out_of_range("Out of range index for operator[]!");
    }
    return squares[index];
}

void Board::setPriorities()
{

}

void Board::setPriority(int row, int col)
{

}

void Board::move(int row, int col)
{

}

bool Board::checkMoves(int row, int col)
{
    return true;
}

void Board::print() const
{
    cout << SPACE "  ";
    for(int c = 'a', i = 1; i <= 8; ++i, ++c)
    {
        cout << (char)c << " ";
    }
    cout << "\n\n";
    for(int i = 0; i < 8; ++i)
    {
        cout << i + 1 << SPACE;
        for(int j = 0; j < 8; ++j)
        {
            cout << " " << squares[i][j];
        }
        cout << "\n";
    }
}
