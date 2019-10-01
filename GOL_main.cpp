//packages and .h files needed for program
#include "Readerfile.h"
#include "Grids.h"
#include "Classic.h"
#include "Dounut.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

using namespace std;

//main method
int main(int argc, char** argv)
{
    //declares variables
    //file var
    string file;
    int start = 0;
    //dem variables
    int rows = 0;
    int columns = 0;
    double pop = 0.0;
    //user input variables
    int gameMode = 0;
    int results = 0;

    //asks user if they would like to import file or give demensions
    cout << "Would you like to import a file (1) or use a randomized file (2)?" << endl;
    //takes in user input
    cin >> start;
    //checks to see if user input is valid
    while(start != 1 && start != 2)
    {
        cout << "This is not a valid entry, please try again." << endl;
        cin >> start;
    }

    //if user wants to import file
    if (start == 1)
    {
        cout << "-----------------------------------------------------------------" << endl;
        //prompts user for name of file
        cout << "What is the name of file? " << endl;
        //takes in file
        cin >> file;
        cout << "-----------------------------------------------------------------" << endl;
        //creates file reader object
        Readerfile r;
        //calls object methods to retrieve rows, columns,and density
        rows = r.getRows(file);
        pop = r.getDensity(file);
        columns = r.getColumns(file);
        //prints out input file statistics to the user
        cout << "Input File Statistics:" << endl;
        cout << "rows: " << rows << endl;
        cout << "columns: " << columns << endl;
        cout << "Density: " << pop << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }

    //if user wants to imort file
    else if (start == 2)
    {
        //asks user for rows, columns, population density, gameMode, and how they want results displayed to them
        cout << "-----------------------------------------------------------------" << endl;
        cout << "How many rows would you like to have?" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        //takes in user input
        cin >> rows;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "How many columns would you like to have?" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        //takes in user input
        cin >> columns;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Now enter a decimal value greater than 0 and less than or equal to 1.\nThis will represent the initial population density of the world" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        //takes in user input
        cin >> pop;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "What Game Mode would you like to play?\nClassic (1)\nDounut (2)\nMirror (3)" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        //takes in user input
        cin >> gameMode;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Generation Display:\nPause between Generations (1)\nPress 'Enter' to display each new generation (2)\nOutput results to a file (outfile.open(filename, ios::app)) (3)" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        //takes in user input
        cin >> results;
        cout << "-----------------------------------------------------------------" << endl;

        //if user selects Classic mode with a pause display
        if (gameMode == 1 && results == 1)
        {
            //classic mode starts
            cout << "Classic Mode Initiated" << endl;
            cout << endl;
            //creates grids object with a pointer
            Grids* g = new Grids(rows,columns,pop);
            //creates classic game object
            Classic game;
            //variables for simulation while loop and generation number
            int simulation = 0;
            int Gen = 0;
            //reads grid to user
            g->readGrid();
            cout << "-----------------------------------------------------------------" << endl;

            while (simulation == 0)
            {
                //pauses computer
                usleep(1800000);
                //prints current generation
                cout << "Gen " << Gen << endl;
                cout << endl;
                //passes grid through classic game object
                game.ClassicGame(g);
                //then reads new grid to user
                g->readGrid();
                cout << "-----------------------------------------------------------------" << endl;
                //copies nextgrid to curgrid
                game.CopyGrid(g);
                //increments generation count
                Gen++;
            }
            //deletes pointer object
            delete g;
        }

        //if user selects Classic mode and wants to press enter to see each generation
        if (gameMode == 1 && results == 2)
        {
            cout << "Classic Mode Initiated" << endl;
            cout << endl;
            //creates grids object with a pointer
            Grids* g = new Grids(rows,columns,pop);
            //creates classic game object
            Classic game;
            //variables for simulation while loop and generation number
            int simulation = 0;
            int Gen = 0;
            //reads grid to user
            g->readGrid();
            cout << "-----------------------------------------------------------------" << endl;

            //while loop that only ends if grids stablizes or user exits
            while (simulation == 0)
            {
                //prompts user to press enter for next generation
                cout << "Press 'Enter' for next Generation, or 'Ctrl + c' to exit" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                //takes in enter key
                if(cin.get()=='\n')
                {
                    cout << "Gen " << Gen << endl;
                    cout << endl;
                    //passes grid object through game object
                    game.ClassicGame(g);
                    //reads new grid to user
                    g->readGrid();
                    cout << "-----------------------------------------------------------------" << endl;
                    //copys new grid to old grid
                    game.CopyGrid(g);
                    //increments generation count
                    Gen++;
                }
            }
            //deletes pointer grid object
            delete g;
        }

        //classic game mode and writes results out to a file
        if (gameMode == 1 && results == 3)
        {
            string file;
            //asks user for name of created file
            cout << "What would you like the file to be named?" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            //takes in user input
            cin >> file;
            cout << "-----------------------------------------------------------------" << endl;
            //creates and opens writer file
            ofstream outputFile;
            outputFile.open(file);

            outputFile << "Classic Mode Initiated" << endl;
            outputFile << endl;
            //creates pointer grid object
            Grids* g = new Grids(rows,columns,pop);
            //creates game object
            Classic game;
            //creates simulation variables
            int simulation = 0;
            int Gen = 0;
            //writes out results to file
            outputFile << "Initial Population" << endl;
            outputFile << endl;
            outputFile << g->writeGrid();
            outputFile << endl;


            while (simulation == 0)
            {
                //writes out results to file
                outputFile << endl;
                game.ClassicGame(g);
                outputFile << "Gen " << Gen << endl;
                outputFile << endl;
                outputFile << g->writeGrid();
                outputFile << endl;

                game.CopyGrid(g);
                Gen++;
                //checks to see if grid is continuous
                if (Gen > 1000000)
                {
                    cout << "There are infinite populations" << endl;
                    delete g;
                    exit(0);
                }
            }
            //closes file and deletes grid object
            outputFile.close();
            delete g;

        }

    }



    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //The next three if statements and all the code in them are the same as the three if statements above.
    //this code was ran in the case that the user provided an input file for the program.
    /////////////////////////////////////////////////////////////////////////////////////

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

    //This are the unfinished else if statemetns for mirror and dounut mode
    else if (gameMode == 2 && results == 1)
    {
        cout << "Dounut Mode Initiated" << endl;
        cout << endl;
        Grids* g = new Grids(rows,columns,pop);
        Dounut game;
        int simulation = 0;
        int Gen = 0;
        g->readGrid();
        cout << "-----------------------------------------------------------------" << endl;

        while (simulation == 0)
        {
            usleep(1800000);
            cout << "Gen " << Gen << endl;
            cout << endl;
            game.DounutGame(g);
            g->readGrid();
            cout << "-----------------------------------------------------------------" << endl;
            game.CopyGrid(g);
            Gen++;
        }
        delete g;
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
    //tells user if their input for gameMode is valid or not
    {
        cout << "That is not a valid input." << endl;
        cout << "What Game Mode would you like to play?\nClassic (1)\nDounut (2)\nMirror (3)" << endl;
        cin >> gameMode;
    }

    return 0;
}
