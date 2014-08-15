#include "Board.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

#define SPACE "  "


//Start of friend functions

ostream& operator<<(ostream& out, const Square& obj)
{
    if(obj.avail == 0)
        out << 0;
    else if(obj.avail == 1)
        out << obj.priority;
    else
        out << 'K';
    return out;
}

ostream& operator<<(ostream& out, const Board& brd)
{
    out << SPACE "   ";
    for(char c = 'a', i = 1; i <= BOARD_WIDTH; ++i, ++c)
    {
        out << c << " ";
    }
    out << "\n\n";
    for(short int i = 0; i < BOARD_HEIGHT; ++i)
    {
        out << setw(2) << i + 1 << SPACE;
        for(short int j = 0; j < BOARD_WIDTH; ++j)
        {
            out << " " << brd.squares[i][j];
        }
        out << "\n";
    }
    return out;
}

//End of friend functions


//Start of Square

Square::Square()
{
    avail = 1;
    priority = 8;
}

void Square::setAvail(short int val)
{
    if(val > 2 || val < 0)
    {
        throw out_of_range("Availability is from 0 to 2. YOU MORON!!!");
    }
    avail = val;
}

void Square::setPriority(short int val)
{
    if(val > 8 || val < 0)
    {
        throw out_of_range("Priority must be from 0 to 8!");
    }
    priority = val;
}

//End of Square


//Start of Board

Board::Board(short int startRow, short int startCol)
{
    throwRow(startRow);
    throwCol(startCol);
    for(short int r = 0; r < BOARD_HEIGHT; ++r)
    {
        for(short int c = 0; c < BOARD_WIDTH; ++c)
        {
            squares[r][c].setAvail(1);
        }
    }
    squares[startRow][startCol].setAvail(2);
    currRow = startRow;
    currCol = startCol;
    setPriorities();
}

const Square* Board::operator[](short int index) const
{
    throwRow(index);
    return squares[index];
}

Square* Board::operator[](short int index)
{
    throwRow(index);
    return squares[index];
}

void Board::setPriorities()
{

}

void Board::setPriority(short int row, short int col)
{

}

void Board::move(short int row, short int col)
{
    if(validateRow(row) == -1 || validateCol(col) == -1)
    {
        return;
    }
    currRow = row;
    currCol = col;
}

bool Board::checkMoves(short int row, short int col)    //Note: DON'T FORGET ABOUT ME!!!
{
    return true;
}

const short int Board::validateRow(short int row) const
{
    if(row < 0 || row >= BOARD_HEIGHT)
    {
        return -1;
    }
    return row;
}

const short int Board::validateCol(short int col) const
{
    if(col < 0 || col >= BOARD_WIDTH)
    {
        return -1;
    }
    return col;
}

const bool Board::throwRow(short int row) const
{
    if(row < 0 || row >= BOARD_HEIGHT)
    {
        throw out_of_range("Row is out of range. YOU DAMN MORON!!!");
    }
    return true;
}

const bool Board::throwCol(short int col) const
{
    if(col < 0 || col >= BOARD_WIDTH)
    {
        throw out_of_range("Column is out of range. You had ONE job. Now you have NONE. You're fired!");
    }
    return true;
}
