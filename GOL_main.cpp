#include "Readerfile.h"
#include "Grids.h"
#include "Classic.h"
#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char** argv)
{
    string file;
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
        cout << "-----------------------------------------------------------------" << endl;
        cout << "What is the name of file? " << endl;
        cin >> file;
        cout << "-----------------------------------------------------------------" << endl;
        Readerfile r;
        rows = r.getRows(file);
        pop = r.getDensity(file);
        columns = r.getColumns(file);
        cout << "Input File Statistics:" << endl;
        cout << "rows: " << rows << endl;
        cout << "columns: " << columns << endl;
        cout << "Density: " << pop << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
    else if (start == 2)
    {
        cout << "How many rows would you like to have?" << endl;
        cin >> rows;
        cout << "How many columns would you like to have?" << endl;
        cin >> columns;
        cout << "Now enter a decimal value greater than 0 and less than or equal to 1.\nThis will represent the initial population density of the world" << endl;
        cin >> pop;
        cout << "Generation Display:\nPause between Generations (1)\nPress 'Enter' to display each new generation (2)\nOutput results to a file (3)";
        cin >> results;
    }

    cout << "What Game Mode would you like to play?\nClassic (1)\nDounut (2)\nMirror (3)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cin >> gameMode;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Generation Display:\nPause between Generations (1)\nPress 'Enter' to display each new generation (2)\nOutput results to a file (3)";
    cin >> results;

    if (gameMode == 1)
    {
        cout << "Classic Mode Initiated" << endl;
        cout << endl;
        Grids* g = new Grids(rows,columns,pop);
        g->readGrid();
        cout << "-----------------------------------------------------------------" << endl;
        cout << "New Generation" << endl;
        Classic game;
        game.ClassicGame(g);
        g->readGrid();
        cout << "-----------------------------------------------------------------" << endl;
        delete g;
    }
    else if (gameMode == 2)
    {
        // Grids* g = new Grids(rows,columns,pop);
        // delete g;
        return 0;
    }
    else if (gameMode == 3)
    {
        // Grids* g = new Grids(rows,columns,pop);
        // delete g;
        return 0;
    }
    else
    {
        cout << "That is not a valid input." << endl;
        cout << "What Game Mode would you like to play?\nClassic (1)\nDounut (2)\nMirror (3)" << endl;
        cin >> gameMode;
    }

    return 0;
}
