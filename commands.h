#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <iomanip>

#define WIDTH 25

using namespace std;

//Warning! Command line modes below!
const string decode(char str[]);
void normalMode();
void randomMode();
void help();
void position();

const string decode(char str[])
{
    string result(str);
    return result;
}

void normalMode()
{

}

void randomMode()
{
    cout << "RANDOM MODE!!! OOOHH YEAAAH!!!\nHowever this doesn't work yet... sorry...\n";
}

void help()
{
    cout << "Knight's Tour spin-off.\n"
            "Usage:\nKnightRide [[-r, --random], [-h, -?, --help], [-p, --position r,c]]\n"
            "Options as described below:\n";
    cout << setw(WIDTH) <<
            "-r, --random:" << setw(0) << "\tBrute-force through the field randomly\n" << setw(WIDTH) <<
            "-h, -?, --help:" << setw(0) << "\tThis\n" << setw(WIDTH) <<
            "-p, --position [r,c]:" << setw(0) << "\tStart at position (r,c)\n";
}

void position()
{

}

#endif // COMMANDS_H
