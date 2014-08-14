#ifndef BOARD_H
#define BOARD_H

class Square
{
    friend ostream& operator<<(ostream& out, const Square& toPrint) const;
public:
    Square();

    const bool getTaken() const
    {
        return taken;
    }
    void setTaken(bool val)
    {
        taken = val;
    }

    const int getPriority() const
    {
        return priority;
    }
    void setPriority(int val);  //Note: Check if it's between 0 and 7
private:
    bool taken;
    int priority;   //0-7; low priority to high
};  //Square class

class Board
{
public:
    Board();

    virtual void print() const;
private:
    Square square[8][8];
};  //Board class

#endif // BOARD_H
