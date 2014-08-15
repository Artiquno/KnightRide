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

using namespace std;

const string decode(char str[]);
void checkCommands(int argc, char** argv);

//Warning! Command line modes below!
void normalMode();
void randomMode();
void help();
void position();

const string decode(char str[])
{
    string result(str);
    return result;
}

/*/ List of command line... commands...
 *  --help - You guess it...
 *  -r, --random - brute-force through it
 *  -p, --position row, col - start at defined position
/*/
void checkCommands(int argc, char** argv)
{
    if(argc < 2)
    {
        cout << "Less than 2 commands given.\n";
        cout << argv[0];
        return;
    }
    for(int i = 1; i < argc; ++i)
    {
        //<desired effect for each command goes here>
        cout << decode(argv[i]) << "\n";
    }
}

int main(int argc, char** argv)
{
    checkCommands(argc, argv);
    return 0;
}
