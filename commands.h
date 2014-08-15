#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <iomanip>

#if defined WIN32
    #define CLEAR "cls"
#elif defined __linux__
    #define CLEAR "clear"
#elif defined __APPLE__
    #define CLEAR "clear"
#endif

#define WIDTH 20

using namespace std;

//Warning! Command line modes below!
const string decode(char str[]);
void normalMode();
void randomMode();
void help();
void position(int& i, char** argv);
void humanMode();
void showMoves();


//Warning! Command line mode definitions below! Proceed with care!
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
            "Usage:\nKnightRide [ [-r], [-h], [-p <r,c>], [-t <time>], [-H] ]\n"
            "Options as described below:\n";
    cout << setw(WIDTH) <<
            "-r, --random:" << setw(0) << "\tBrute-force through the field randomly\n\n" << setw(WIDTH) <<
            "-t, --timed:" << setw(0) << "\tDoesn't work with -H. Show every move for [time] milliseconds.\n" << setw(WIDTH) <<
            " " << setw(0) << "\tDefault time is 500ms.\n\n" << setw(WIDTH) <<
            "-h, -?, --help:" << setw(0) << "\tThis\n\n" << setw(WIDTH) <<
            "-p, --position:" << setw(0) << "\tStart at position (r,c)\n\n" << setw(WIDTH) <<
            "-H, --human:" << setw(0) << "\tTry to beat the game yourself, you lazy bastard!\n";
}

void position(int& i, char** argv)
{

}

void humanMode()
{

}

void showMoves()
{

}

#endif // COMMANDS_H
