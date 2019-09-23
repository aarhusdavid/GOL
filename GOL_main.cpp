#include "Readerfile.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    string map;
    Readerfile r;
    int start = 0;
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
            double pop = 0.0;
            int rows = 0;
            int columns = 0;
            cout << "How many rows would you like to have?" << endl;
            cin >> rows;
            cout << "How many columns would you like to have?" << endl;
            cin >> columns;
            cout << "Now enter a decimal value greater than 0 and less than or equal to 1.\nThis will represent the initial population density of the world" << endl;
            cin >> pop;



        }

    return 0;
}
