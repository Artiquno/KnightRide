/*/////////////////////////////////////////
 * Knight's Tour spin-off
 * Fuck you, you can't sue me!!!
 * *evil laugh*
 *
/*/////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Board.h"

using namespace std;



int main(int argc, char** argv)
{
    srand(time(0));
    int rows = 8;
    int cols = 8;
    int startRow = rows/2;
    int startCol = cols/2;
    //int threshold = 2;
    char defaultMode;
    int sleepTime = 200;
    bool verbose = true;
    cout << "Do you want to enter the configuration menu? (Y/N)\n"
            "(It's not really a menu, just some annoying questions) ";
    cin >> defaultMode;
    if(defaultMode != 'n' && defaultMode != 'N')
    {
        cout << "Enter board height: ";
        cin >> rows;
        cout << "Enter board width: ";
        cin >> cols;
        cout << "Enter starting row (0-" << rows-1 << "): ";
        cin >> startRow;
        cout << "Enter starting column (0-" << cols-1 << "): ";
        cin >> startCol;
//        cout << "Enter threshold for removing squares (0-6): ";
//        cin >> threshold;
        cout << "Enter sleep time in milliseconds (default is 200): ";
        cin >> sleepTime;
    }
    if(sleepTime < 10)
        verbose = false;
    Board brd(startRow, startCol, rows, cols);
    //unsigned int handicap = brd.removeEdges(threshold);
    cout << brd << "\n";
    brd.automate(verbose, sleepTime);
    cout << brd << "\n";
    cin.get();
    return 0;
}
