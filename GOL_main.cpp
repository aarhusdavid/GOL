#include "Readerfile.h"
#include "Grids.h"
#include "Classic.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

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
        cout << "-----------------------------------------------------------------" << endl;
        cout << "How many rows would you like to have?" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cin >> rows;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "How many columns would you like to have?" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cin >> columns;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Now enter a decimal value greater than 0 and less than or equal to 1.\nThis will represent the initial population density of the world" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cin >> pop;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "What Game Mode would you like to play?\nClassic (1)\nDounut (2)\nMirror (3)" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cin >> gameMode;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Generation Display:\nPause between Generations (1)\nPress 'Enter' to display each new generation (2)\nOutput results to a file (outfile.open(filename, ios::app)) (3)" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cin >> results;
        cout << "-----------------------------------------------------------------" << endl;

        if (gameMode == 1 && results == 1)
        {
            cout << "Classic Mode Initiated" << endl;
            cout << endl;
            Grids* g = new Grids(rows,columns,pop);
            Classic game;
            int simulation = 0;
            int Gen = 0;
            g->readGrid();
            cout << "-----------------------------------------------------------------" << endl;

            while (simulation == 0)
            {
                usleep(1800000);
                cout << "Gen " << Gen << endl;
                cout << endl;
                game.ClassicGame(g);
                g->readGrid();
                cout << "-----------------------------------------------------------------" << endl;
                game.CopyGrid(g);
                Gen++;
            }
            delete g;
        }

        if (gameMode == 1 && results == 2)
        {
            cout << "Classic Mode Initiated" << endl;
            cout << endl;
            Grids* g = new Grids(rows,columns,pop);
            Classic game;
            int simulation = 0;
            int Gen = 0;
            g->readGrid();
            cout << "-----------------------------------------------------------------" << endl;

            while (simulation == 0)
            {
                cout << "Press 'Enter' for next Generation, or 'Ctrl + c' to exit" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                if(cin.get()=='\n')
                {
                    cout << "Gen " << Gen << endl;
                    cout << endl;
                    game.ClassicGame(g);
                    g->readGrid();
                    cout << "-----------------------------------------------------------------" << endl;
                    game.CopyGrid(g);
                    Gen++;
                }
            }
            delete g;
        }

        if (gameMode == 1 && results == 3)
        {
            string file;
            cout << "What would you like the file to be named?" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cin >> file;
            cout << "-----------------------------------------------------------------" << endl;
            ofstream outputFile;
            outputFile.open(file);

            outputFile << "Classic Mode Initiated" << endl;
            outputFile << endl;
            Grids* g = new Grids(rows,columns,pop);
            Classic game;
            int simulation = 0;
            int Gen = 0;
            outputFile << "Initial Population" << endl;
            outputFile << endl;
            outputFile << g->writeGrid();
            outputFile << endl;


            while (simulation == 0)
            {
                outputFile << endl;
                game.ClassicGame(g);
                outputFile << "Gen " << Gen << endl;
                outputFile << endl;
                outputFile << g->writeGrid();
                outputFile << endl;

                game.CopyGrid(g);
                Gen++;
                if (Gen > 500)
                {
                    cout << "There are infinite populations" << endl;
                    delete g;
                    exit(0);
                }
            }
            outputFile.close();
            delete g;

        }

    }

    cout << "What Game Mode would you like to play?\nClassic (1)\nDounut (2)\nMirror (3)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cin >> gameMode;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Generation Display:\nA brief Pause between Generations (1)\nWould you like to press 'Enter' to display each new generation (2)\nOutput results to a file (3)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cin >> results;
    cout << "-----------------------------------------------------------------" << endl;


    if (gameMode == 1 && results == 1)
    {
        cout << "Classic Mode Initiated" << endl;
        cout << endl;
        Grids* g = new Grids(rows,columns,pop);
        Classic game;
        int simulation = 0;
        int Gen = 0;
        g->readGrid();
        cout << "-----------------------------------------------------------------" << endl;

        while (simulation == 0)
        {
            usleep(1800000);
            cout << "Gen " << Gen << endl;
            cout << endl;
            game.ClassicGame(g);
            g->readGrid();
            cout << "-----------------------------------------------------------------" << endl;
            game.CopyGrid(g);
            Gen++;
        }
        delete g;
    }

    if (gameMode == 1 && results == 2)
    {
        cout << "Classic Mode Initiated" << endl;
        cout << endl;
        Grids* g = new Grids(rows,columns,pop);
        Classic game;
        int simulation = 0;
        int Gen = 0;
        g->readGrid();
        cout << "-----------------------------------------------------------------" << endl;

        while (simulation == 0)
        {
            cout << "Press 'Enter' for next Generation, or 'Ctrl + c' to exit" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            if(cin.get()=='\n')
            {
                cout << "Gen " << Gen << endl;
                cout << endl;
                game.ClassicGame(g);
                g->readGrid();
                cout << "-----------------------------------------------------------------" << endl;
                game.CopyGrid(g);
                Gen++;
            }
        }
        delete g;
    }

    if (gameMode == 1 && results == 3)
    {
        string file;
        cout << "What would you like the file to be named?" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cin >> file;
        cout << "-----------------------------------------------------------------" << endl;
        ofstream outputFile;
        outputFile.open(file);

        outputFile << "Classic Mode Initiated" << endl;
        outputFile << endl;
        Grids* g = new Grids(rows,columns,pop);
        Classic game;
        int simulation = 0;
        int Gen = 0;
        outputFile << "Initial Population" << endl;
        outputFile << endl;
        outputFile << g->writeGrid();
        outputFile << endl;


        while (simulation == 0)
        {
            outputFile << endl;
            game.ClassicGame(g);
            outputFile << "Gen " << Gen << endl;
            outputFile << endl;
            outputFile << g->writeGrid();
            outputFile << endl;

            game.CopyGrid(g);
            Gen++;
            if (Gen > 500)
            {
                cout << "There are infinite populations" << endl;
                delete g;
                exit(0);
            }
        }
        outputFile.close();
        delete g;
    }

    else if (gameMode == 2 && results == 1)
    {
        return 0;
    }

    else if (gameMode == 2 && results == 2)
    {
        return 0;
    }

    else if (gameMode == 2 && results == 3)
    {
        return 0;
    }

    else if (gameMode == 3 && results == 1)
    {
        return 0;
    }
    else if (gameMode == 3 && results == 2)
    {
        return 0;
    }
    else if (gameMode == 3 && results == 3)
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
