#ifndef BOARD_H
#define BOARD_H

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

#include <iostream>
using namespace std;

class Square
{
    friend ostream& operator<<(ostream& out, const Square& obj);
public:
    Square();

    const short int getAvail() const
    {
        return avail;
    }
    void setAvail(short int val);

    const short int getPriority() const
    {
        return priority;
    }
    void setPriority(short int val);  //Note: Check if it's between 0 and 8
private:
    /*//////
     *  Availability values
     *  0 - not available
     *  1 - available
     *  2 - current position
    /*//////
    short int avail;
    unsigned short int priority;    //0-8; high priority to low
};  //Square class

class Board
{
    friend ostream& operator<<(ostream& out, const Board& obj);
public:
    Board(short int startRow = (BOARD_HEIGHT-1)/2, short int startCol = (BOARD_WIDTH-1)/2);  //Default constructor

    //The '*' should make it cascadeable. If not, FUCK IT!!!
    //Update: It does! Yaaay!
    const Square* operator[](short int index) const;   //Choose a square
    Square* operator[](short int index);   //Same, just non-const

    virtual void setPriorities();   //Set priorities of all the movable-to squares
    virtual void setPriority(short int row, short int col); //Set priorities of given square, and all adjacent ones

    virtual void move(short int row, short int col);    //This will change the current position
    virtual bool checkMoves(short int row, short int col);  //This will modify the availabilities of the squares

    const unsigned short int getCurrRow() const
    {
        return currRow;
    }
    const unsigned short int getCurrCol() const
    {
        return currCol;
    }
private:
    const short int validateRow(short int row) const;
    const short int validateCol(short int col) const;
    const bool throwRow(short int row) const;
    const bool throwCol(short int col) const;

    unsigned short int currRow;
    unsigned short int currCol;
    Square squares[BOARD_HEIGHT][BOARD_WIDTH];
};  //Board class

#endif // BOARD_H
