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
#include "commands.h"

using namespace std;

void checkCommands(int argc, char** argv);

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
            position(i, argv);
        }
        else if(com == "-H" || com == "--human")
        {
            humanMode();
        }
        else if(com == "-t" || com == "--timed")
        {
            showMoves();
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
    srand(time(0));
    cout << time(0) << "\n";
    Board brd;
    cout << brd << "\n";
    checkCommands(argc, argv);
    return 0;
}
