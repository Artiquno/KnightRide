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
#include <climits>
#include "Board.h"
#include "commands.h"

using namespace std;

void checkCommands(int argc, char** argv);


/*/ List of command line... commands...
 *  -h, -?, --help - You guess it...
 *  -r, --random - brute-force through it
 *  -p, --position row, col - start at defined position
/*/
void checkCommands(int argc, char** argv)
{
    if(argc < 2)
    {
        normalMode();
        return;
    }
    string com;
    for(int i = 1; i < argc; ++i)
    {
        com = decode(argv[i]);
        if(com == "-r" || com == "--random")
        {
            randomMode();
        }
        else if(com == "--help" || com == "-h" || com == "-?")
        {
            help();
            break;
        }
        else if(com == "-p" || com == "--position")
        {
            position();
        }
        else
        {
            cout << "Unknown option. Try '--help' to see the available ones, and don't be a moron.\n";
            break;
        }
    }
}

int main(int argc, char** argv)
{
    Board brd;
    cout << brd[4][3] << "\n";
    brd.print();
    brd[3][5].setPriority(4);
    cout << "\n\n\n";
    brd.print();
    cout << brd[3][5] << "\n";
    checkCommands(argc, argv);
    return 0;
}
