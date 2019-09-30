#include "Grids.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


Grids::Grids()
{

}
Grids::~Grids()
{
    for(int i = 0; i < this -> rows; ++i)
    {
        delete[] curGrid[i];
        delete[] nextGrid[i];
    }
    delete[] curGrid;
    delete[] nextGrid;

    cout << "Thank You for playing!" << endl;
}

Grids::Grids(int rows, int columns, double pop)
{
    curGrid = new char*[rows];
    nextGrid = new char*[rows];
    for (int i = 0; i < rows; ++i)
    {
        curGrid[i] = new char[columns];
        nextGrid[i] = new char[columns];
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            curGrid[i][j] = '-';
            nextGrid[i][j] = '-';

        }
    }

    this->rows = rows;
    this->columns = columns;
    this->pop = pop;

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

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            nextGrid[i][j] = curGrid[i][j];
        }
    }

}

void Grids::readGrid()
{

    int colCount = this->columns;
    int count = -1;

    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->columns; ++j)
        {
            count++;
            if (count == colCount)
            {
                cout << "\n" << endl;
                count = 0;
            }
            cout << " " << this->nextGrid[i][j] <<  " ";

        }
    }
    cout << endl;
    cout << endl;

}

string Grids::writeGrid()
{

    int colCount = this->columns;
    int count = -1;
    string line;

    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->columns; ++j)
        {
            count++;
            if (count == colCount)
            {
                line = line += "\n";
                count = 0;
            }
            char spot = this->nextGrid[i][j];
            line = line += spot;

        }
    }
    return line;


}
