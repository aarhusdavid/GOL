//packages and .h files needed for program
#include "Grids.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//empty constructor
Grids::Grids()
{

}
//destructor that deletes grid object
Grids::~Grids()
{
    //deletes each row of curgrid and nextgrid
    for(int i = 0; i < this -> rows; ++i)
    {
        delete[] curGrid[i];
        delete[] nextGrid[i];
    }
    //deletes curgrid and nextgrid
    delete[] curGrid;
    delete[] nextGrid;

    cout << "Thank You for playing!" << endl;
}

//grids method that creates grid
Grids::Grids(int rows, int columns, double pop)
{
    //creates pointers for the rows of curgrid and nextgrid
    curGrid = new char*[rows];
    nextGrid = new char*[rows];
    for (int i = 0; i < rows; ++i)
    {
        //assigns space for each column
        curGrid[i] = new char[columns];
        nextGrid[i] = new char[columns];
    }

    //fills each grid cell with '-' for curgrid and nextgrid
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            curGrid[i][j] = '-';
            nextGrid[i][j] = '-';

        }
    }

    //makes this grids rows, columns, and population soley theres
    this->rows = rows;
    this->columns = columns;
    this->pop = pop;

    //double forloop that fills grids depending on the the population density
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            double a = ((double)rand()/RAND_MAX);
            if(a <= pop)
            {
                curGrid[i][j] = {'X'};
            }
            else if (a > pop)
            {
                curGrid[i][j] = {'-'};
            }
        }
    }

    //copys over nextgrid to curgrid
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            nextGrid[i][j] = curGrid[i][j];
        }
    }

}

//method that reads grid
void Grids::readGrid()
{
    //method variables
    int colCount = this->columns;
    int count = -1;

    //forloop that couts each element of the grid to the user
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->columns; ++j)
        {
            //if the end of the row comes up then cout a new line
            count++;
            if (count == colCount)
            {
                cout << "\n" << endl;
                count = 0;
            }
            //puts space between each element
            cout << " " << this->nextGrid[i][j] <<  " ";

        }
    }
    cout << endl;
    cout << endl;

}

//write grid method for outputting to file
string Grids::writeGrid()
{
    //method variables
    int colCount = this->columns;
    int count = -1;
    string line;

    //double forloop that iterates through grid
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->columns; ++j)
        {
            //writes new line when row is finished printing
            count++;
            if (count == colCount)
            {
                line = line += "\n";
                count = 0;
            }
            //writes each element to string
            char spot = this->nextGrid[i][j];
            line = line += spot;

        }
    }
    //returns string 
    return line;


}
