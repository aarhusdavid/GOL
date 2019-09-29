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

    cout << "Grid Destroyed" << endl;
}

Grids::Grids(int rows, int columns, double density)
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

    curGrid[0][3] = {'X'};
    curGrid[0][6] = {'X'};
    curGrid[1][1] = {'X'};
    curGrid[1][4] = {'X'};
    curGrid[2][5] = {'X'};
    curGrid[2][6] = {'X'};
    curGrid[3][0] = {'X'};
    curGrid[3][2] = {'X'};
    curGrid[3][4] = {'X'};
    curGrid[4][5] = {'X'};
    curGrid[4][6] = {'X'};


}


// void Grids::CopyGrid(Grids g)
// {
//     this->curGrid = new char*[g.rows];
//     this->nextGrid = new char*[g.rows];
//
//     for (int i = 0; i < g.rows; ++i)
//     {
//         this->curGrid[i] = new char[g.columns];
//         this->nextGrid[i] = new char[g.columns];
//     }
//     for (int i = 0; i < g.rows; ++i)
//     {
//         for (int j = 0; j < g.columns; ++j)
//         {
//             this->curGrid[i][j] = i;
//             this->nextGrid[i][j] = j;
//         }
//     }
//
// }

void Grids::readGrid()
{
    // cout << this->rows << endl;
    // cout << this->columns << endl;
    int count = 0;
    for (int i = 0; i < this->rows; ++i)
    {
        // cout << "1" << endl;
        for (int j = 0; j < this->columns; ++j)
        {
            // cout << "2" << endl;
            count++;
            cout << count << endl;
        }
    }
}









// curGrid = new char*[5];
// nextGrid = new char*[5];
// for (int i = 0; i < 5; ++i)
// {
//     curGrid[i] = new char[7];
//     nextGrid[i] = new char[7];
// }
// for (int i = 0; i < 5; ++i)
// {
//     for (int j = 0; j < 7; ++j)
//     {
//         curGrid[i][j] = '-';
//         nextGrid[i][j] = '-';
//     }
// }
// this -> rows = 5;
// this -> columns = 7;
//
// curGrid[0][3] = {'X'};
// curGrid[0][6] = {'X'};
// curGrid[1][1] = {'X'};
// curGrid[1][4] = {'X'};
// curGrid[2][5] = {'X'};
// curGrid[2][6] = {'X'};
// curGrid[3][0] = {'X'};
// curGrid[3][2] = {'X'};
// curGrid[3][4] = {'X'};
// curGrid[4][5] = {'X'};
// curGrid[4][6] = {'X'};
