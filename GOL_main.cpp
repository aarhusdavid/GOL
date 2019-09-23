#include "Readerfile.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    Readerfile r;
    int start = 0;
    int rows = 0;
    int columns = 0;
    double pop = 0.0;
    int gameMode = 0;
    int results = 0;

    cout << "Would you like to import a file (1) or use a randomized file (2)?" << endl;
    cin >> start;
    while(start != 1 && start != 2)
    {
        cout << "This is not a valid entry, please try again." << endl;
        cin >> start;
    }

        if (start == 1)
        {
            string file;
            cout << "Enter the name of the file" << endl;
            cin >> file;
            cout << r.read(file) << endl;        }

        else if (start == 2)
        {
            cout << "How many rows would you like to have?" << endl;
            cin >> rows;
            cout << "How many columns would you like to have?" << endl;
            cin >> columns;
            cout << "Now enter a decimal value greater than 0 and less than or equal to 1.\nThis will represent the initial population density of the world" << endl;
            cin >> pop;
            cout << "What Game Mode would you like to play?\nClassic (1)\nDounut (2)\nMirror (3)" << endl;
            cin >> gameMode;
            cout << "Would you like a pause between every generations, allowing you to see each generation or would you like the generations to be printed to a file?\nPause (1)\nPrint results to Output file (2)" << endl;
            cin >> results;
        }

        if (gameMode == 1)
        {
            return 0;
        }
        else if (gameMode == 2)
        {
            return 0;
        }
        else if (gameMode == 3)
        {
            return 0;
        }

    return 0;
}
