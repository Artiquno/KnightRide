#ifndef BOARD_H
#define BOARD_H

#define BOARD_HEIGHT 30
#define BOARD_WIDTH 30

#define PI 3.14159265

#define RAD2DEG PI/180.0

#include <iostream>
using namespace std;

class Square
{
    friend ostream& operator<<(ostream& out, const Square& obj);
public:
    Square();

    const int getMoving() const
    {
        return moving;
    }
    void setMoving(int val);

    const int getAvail() const
    {
        return avail;
    }
    void setAvail(int val);

    const int getPriority() const
    {
        return priority;
    }
    void setPriority(int val);  //Note: Check if it's between 0 and 8
private:
    unsigned short int avail;
    unsigned short int priority;    //0-8; high priority to low
    unsigned short int moving;
};  //Square class

class Knight
{
public:
    Knight(int row, int col);

    const int validateRow(int row) const;
    const int validateCol(int col) const;

    virtual bool move(int row, int col);

    const int getCurrRow() const
    {
        return currRow;
    }
    const int getCurrCol() const
    {
        return currCol;
    }

private:
    unsigned short int currRow;
    unsigned short int currCol;
};

class Board
{
    friend ostream& operator<<(ostream& out, const Board& obj);
public:
    Board(int startRow = (BOARD_HEIGHT-1)/2,
          int startCol = (BOARD_WIDTH-1)/2);  //Default constructor

    //The '*' should make it cascadeable. If not, FUCK IT!!!
    //Update: It does! Yaaay!
    const Square* operator[](int index) const;   //Choose a square
    Square* operator[](int index);   //Same, just non-const

    virtual void setPriorities();
    //virtual void setPriority(int row, int col);

    void setMoves();

    int checkMoves(int row, int col);
    int checkMoves2(int row, int col);

    void moveKnight(int row, int col);
    bool move(int pos);

    const int validateRow(int row) const;
    const int validateCol(int col) const;

    const Knight getKnight() const
    {
        return knight;
    }
    Knight getKnight()
    {
        return knight;
    }

    void humanMode();
    void automate(bool visible = false, int sleepTime = 500);
private:
    const bool throwRow(int  row) const;
    const bool throwCol(int col) const;

    Knight knight;
    Square squares[BOARD_HEIGHT][BOARD_WIDTH];
};  //Board class

#endif // BOARD_H
