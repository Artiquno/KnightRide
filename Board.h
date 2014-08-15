#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Square
{
    friend ostream& operator<<(ostream& out, const Square& obj);
public:
    Square();

    const bool getAvail() const
    {
        return avail;
    }
    void setAvail(bool val)
    {
        avail = val;
    }

    const int getPriority() const
    {
        return priority;
    }
    void setPriority(int val);  //Note: Check if it's between 0 and 8
private:
    bool avail;
    int priority;   //0-8; high priority to low
};  //Square class

class Board
{
public:
    Board();    //Start in the center (somewhere around e4...)
    Board(int startRow, int startCol = 0);  //Different starting place

    //The '&' should make it cascadeable. If not, FUCK IT!!!
    const Square* operator[](int index) const;   //Note: Check for out_of_range
    Square* operator[](int index);   //Same, just non-const

    virtual void setPriorities();   //Set priorities of all the movable-to squares
    virtual void setPriority(int row, int col); //Set priorities of given square, and all adjacent ones

    virtual void move(int row, int col);    //This will change the current position
    virtual bool checkMoves(int row, int col);  //This will modify the availabilities of the squares

    virtual void print() const;
private:
    int currRow;
    int currCol;
    Square squares[8][8];
};  //Board class

#endif // BOARD_H
