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
    int startRow = BOARD_HEIGHT/2;
    int startCol = BOARD_WIDTH/2;
    char defaultMode;
    int sleepTime = 50;
    cout << "Do you want to enter the configuration menu? (Y/N)\n"
            "(It's not really a menu, just some annoying questions) ";
    cin >> defaultMode;
    if(defaultMode != 'n' && defaultMode != 'N')
    {
        cout << "Enter starting row (0-" << BOARD_HEIGHT-1 << "): ";
        cin >> startRow;
        cout << "Enter starting column (0-" << BOARD_WIDTH-1 << "): ";
        cin >> startCol;
        cout << "Enter sleep time in milliseconds (default is 200): ";
        cin >> sleepTime;
    }
    Board brd(startRow, startCol);
    brd.automate(true, sleepTime);
    cout << brd << "\n";
    cin.get();
    return 0;
}
