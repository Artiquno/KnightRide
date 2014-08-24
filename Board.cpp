#include "Board.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <SFML/System/Sleep.hpp>
using namespace std;

#define SPACE "  "

#if defined __linux__
    #define CLEAR "clear"
#elif defined _WIN32_
    #define CLEAR "cls"
#elif defined __apple__
    #define CLEAR "clear"
#endif // __linux__


//Start of friend functions

ostream& operator<<(ostream& out, const Square& obj)
{
    if(obj.avail == 0)
        out << ' ';
    else if(obj.avail == 1)
        out << '0';
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
        out.flush();
        //sf::sleep(sf::milliseconds(50));
    }
    out << "\n\n";
    for(short int i = 0; i < BOARD_HEIGHT; ++i)
    {
        out << setw(2) << i + 1 << SPACE;
        for(short int j = 0; j < BOARD_WIDTH; ++j)
        {
            out << " " << brd.squares[i][j];
            out.flush();
            //sf::sleep(sf::milliseconds(50));
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
    priority = 0;
    moving = 0;
}

void Square::setAvail(int val)
{
    if(val > 2 || val < 0)
    {
        throw out_of_range("Availability is from 0 to 2. YOU MORON!!!");
    }
    avail = val;
}

void Square::setPriority(int val)
{
    if(val > 8 || val < 0)
    {
        throw out_of_range("Priority must be from 0 to 8!");
    }
    priority = val;
}

void Square::setMoving(int val)
{
    moving = val;
}

//End of Square


//Start of Board

Board::Board(int startRow, int startCol) :
    knight(startRow, startCol)
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
    setPriorities();
}

const Square* Board::operator[](int index) const
{
    throwRow(index);
    return squares[index];
}

Square* Board::operator[](int index)
{
    throwRow(index);
    return squares[index];
}

void Board::setPriorities()
{
    for(int r = 0; r < BOARD_HEIGHT; ++r)
    {
        for(int c = 0; c < BOARD_WIDTH; ++c)
        {
            squares[r][c].setPriority(checkMoves(r, c));
        }
    }
}

void Board::setMoves()
{
    int row = knight.getCurrRow();
    int col = knight.getCurrCol();
    int hor = 1;
    int ver = 2;
    float radius = sqrt(hor*hor + ver*ver);
    for(int r = 0; r < BOARD_HEIGHT; ++r)
    {
        for(int c = 0; c < BOARD_WIDTH; ++c)
        {
            squares[r][c].setMoving(0);
        }
    }
    for(int i = 1, rot = 30; rot <= 8*45; ++i, rot += 45)
    {
        hor = rint(cos(rot*RAD2DEG)*radius);
        ver = rint(sin(rot*RAD2DEG)*radius);
        if(validateRow(row+ver) == -1 || validateCol(col+hor) == -1)
        {
            continue;
        }
        if(squares[row+ver][col+hor].getAvail() == 1)
        {
            squares[row+ver][col+hor].setMoving(i);
        }
    }
}

int Board::checkMoves(int row, int col)
{
    int moves = 0;
    int hor = 1;
    int ver = 2;
    float radius = sqrt(hor*hor + ver*ver);
    for(int rot = 30; rot <= 8*45; rot += 45)
    {
        hor = rint(cos(rot*RAD2DEG)*radius);
        ver = rint(sin(rot*RAD2DEG)*radius);
        if(validateRow(row+ver) == -1 || validateCol(col+hor) == -1)
        {
            continue;
        }
        if(squares[row+ver][col+hor].getAvail() == 1)
        {
            ++moves;
            squares[row+ver][col+hor].setPriority(checkMoves2(row+ver, col+hor));
        }
    }
    return moves;
}

int Board::checkMoves2(int row, int col)
{
    int moves = 0;
    int hor = 1;
    int ver = 2;
    float radius = sqrt(hor*hor + ver*ver);
    for(int rot = 30; rot <= 8*45; rot += 45)
    {
        hor = rint(cos(rot*RAD2DEG)*radius);
        ver = rint(sin(rot*RAD2DEG)*radius);
        if(validateRow(row+ver) == -1 || validateCol(col+hor) == -1)
        {
            continue;
        }
        if(squares[row+ver][col+hor].getAvail() == 1)
        {
            ++moves;
        }
    }
    return moves;
}

void Board::moveKnight(int row, int col)
{
    int oldRow = knight.getCurrRow();
    int oldCol = knight.getCurrCol();
    if(knight.move(row, col))
    {
        squares[oldRow][oldCol].setAvail(0);
        squares[row][col].setAvail(2);
        checkMoves(row, col);
        setMoves();
        setPriorities();
    }
}

bool Board::move(int pos)
{
    if(pos < 1 || pos > 8);
    else
    {
        for(int r = 0; r < BOARD_HEIGHT; ++r)
        {
            for(int c = 0; c < BOARD_WIDTH; ++c)
            {
                if(squares[r][c].getMoving() == pos)
                {
                    moveKnight(r, c);
                    return true;
                }
            }
        }
    }
    cout << "That position is not available!\n";
    return false;
}

void Board::automate(bool visible, int sleepTime)
{
    bool canMove = true;
    int currRow = knight.getCurrRow();
    int currCol = knight.getCurrCol();
    int hor = 1;
    int ver = 2;
    float radius = sqrt(hor*hor + ver*ver);
    int pos;
    int priority;
    for(int moves = 0; canMove; ++moves)
    {
        if(visible)
        {
            cout << "Round " << moves << "\n";
            cout << (*this) << "\n";
            sf::sleep(sf::milliseconds(sleepTime));
            system(CLEAR);
        }
        currRow = knight.getCurrRow();
        currCol = knight.getCurrCol();
        setPriorities();
        setMoves();
        pos = 0;
        priority = 9;
        for(int rot = 30, cosine, sine; rot <= 8*45; rot += 45)
        {
            cosine = rint(cos(rot*RAD2DEG)*radius);
            sine   = rint(sin(rot*RAD2DEG)*radius);
            if(validateRow(currRow+sine) == -1 || validateCol(currCol+cosine) == -1)
                continue;
            Square currSqr = squares[currRow+sine][currCol+cosine];
            if(currSqr.getPriority() < priority && currSqr.getAvail() != 0)
            {
                priority = currSqr.getPriority();
                hor = cosine;
                ver = sine;
            }
        }
        if(priority != 9)
        {
            setMoves();
            pos = squares[currRow+ver][currCol+hor].getMoving();
            move(pos);
        }
        else
        {
            canMove = false;
        }
        if(!canMove)
        {
            if(moves == BOARD_HEIGHT*BOARD_WIDTH - 1)
                cout << "OMFG!!! You did it!!!\n";
            else
                cout << "No more moves, sorry.\n";
        }

    }
}

const int Board::validateRow(int row) const
{
    if(row >= BOARD_HEIGHT || row < 0)
    {
        return -1;
    }
    return row;
}

const int Board::validateCol(int col) const
{
    if(col >= BOARD_WIDTH || col < 0)
    {
        return -1;
    }
    return col;
}

const bool Board::throwRow(int row) const
{
    if(row >= BOARD_HEIGHT || row < 0)
    {
        throw out_of_range("Row is out of range. YOU DAMN MORON!!!");
    }
    return true;
}

const bool Board::throwCol(int col) const
{
    if(col >= BOARD_WIDTH)
    {
        throw out_of_range("Column is out of range. You had ONE job. Now you have NONE. You're fired!");
    }
    return true;
}

//End of Board


//Start of Knight

Knight::Knight(int row, int col)
{
    currRow = row;
    currCol = col;
}

bool Knight::move(int row, int col)
{
    if(validateRow(row) == -1 || validateCol(col) == -1)
    {
        return false;
    }
    if(row > currRow + 2 || row < currRow - 2 ||
       col > currCol + 2 || col < currCol - 2)
        return false;
    currRow = row;
    currCol = col;
    return true;
}

const int Knight::validateRow(int row) const
{
    if(row >= BOARD_HEIGHT)
    {
        return -1;
    }
    return row;
}

const int Knight::validateCol(int col) const
{
    if(col >= BOARD_WIDTH)
    {
        return -1;
    }
    return col;
}




