#include <iostream>
#define SPACE "  "

using namespace std;

int main()
{
    cout << SPACE "  ";
    for(int c = 'a', i = 1; i <= 8; ++i, ++c)
    {
        cout << (char)c << " ";
    }
    cout << "\n\n";
    for(int i = 0; i < 8; ++i)
    {
        cout << i + 1 << SPACE;
        for(int j = 0; j < 8; ++j)
        {
            cout << " " << j;
        }
        cout << "\n";
    }
    return 0;
}
