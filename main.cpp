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

#include <cstddef>

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
            position(i, argv);
        }
        else if(com == "-H" || com == "--human")
        {
            humanMode();
        }
        else
        {
            cout << "Unknown option. Try '--help' to see the available ones, and don't be a moron.\n";
            break;
        }
    }
}

int power(int n, int power)
{
    int temp = n;
    for(int i = 1; i < power; ++i)
    {
        n *= temp;
    }
    return n;
}

int main(int argc, char** argv)
{
    srand(time(0));
    cout << sizeof(Square) << "\n"
         << sizeof(Board) << "\n"
         << sizeof(bool) << "\n"
         << sizeof(unsigned short int) << "\n"
         << sizeof(short int) << "\n"
         << sizeof(ostream) << "\n";
    Board brd;
    cout << brd << "\n";
    checkCommands(argc, argv);
    cout << sizeof(long long int) << "\n";
    unsigned long long int result = power(2, (sizeof(long long int)-1)*CHAR_BIT)-1;
    cout << result << "\n";
    return 0;
}
