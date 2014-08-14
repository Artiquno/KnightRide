#ifndef BOARD_H
#define BOARD_H

class Square
{
    friend ostream& operator<<(ostream& out, const Square& toPrint) const;
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
    void setPriority(int val);  //Note: Check if it's between 0 and 7
private:
    bool avail;
    int priority;   //0-7; low priority to high
};  //Square class

class Board
{
public:
    Board();    //Start in the center (somewhere around there...)
    Board(int startRow, int startCol = 0);  //Different starting place

    //The '&' should make it cascadeable. If not, FUCK IT!!!
    const Square& operator[](int index) const;   //Check for out_of_range
    Square& operator[](int index);   //Same, just non-const

    virtual void setPriorities();   //Set priorities of the movable-to squares

    virtual void move(int row, int col);    //This will change the current position
    virtual bool checkMoves();  //This will modify the availabilities of the squares

    virtual void print() const; //Print the whole board
private:
    int currRow;
    int currCol;
    Square squares[8][8];
};  //Board class

#endif // BOARD_H
