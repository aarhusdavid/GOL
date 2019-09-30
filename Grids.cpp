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

    nextGrid[0][3] = {'X'};
    nextGrid[0][6] = {'X'};
    nextGrid[1][1] = {'X'};
    nextGrid[1][4] = {'X'};
    nextGrid[2][5] = {'X'};
    nextGrid[2][6] = {'X'};
    nextGrid[3][0] = {'X'};
    nextGrid[3][2] = {'X'};
    nextGrid[3][4] = {'X'};
    nextGrid[4][5] = {'X'};
    nextGrid[4][6] = {'X'};


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

// void Grids::Classic(Grids g)
// {
//     int neighbors = 0;
//     int null = 0;
//     int totalGridSpace = this->rows * this->columns;
//     int totalGridCount = 0;
//
//     for (int i = 0; i < this->rows; ++i)
//     {
//         for (int j = 0; j < this->columns; ++j)
//         {
//             char readCell = curGrid[i][j];
//             if (curGrid[i][j+1] == 'X')
//                 neighbors++;
//             else
//                 null++;
//             if (curGrid[i+1][j] == 'X')
//                 neighbors++;
//             else
//                 null++;
//             if (curGrid[i+1][j+1] == 'X')
//                 neighbors++;
//             else
//                 null++;
//             if (curGrid[i-1][j+1] == 'X')
//                 neighbors++;
//             else
//                 null++;
//             if (curGrid[i-1][j] == 'X')
//                 neighbors++;
//             else
//                 null++;
//             if (curGrid[i-1][j-1] == 'X')
//                 neighbors++;
//             else
//                 null++;
//             if (curGrid[i][j-1] == 'X')
//                 neighbors++;
//             else
//                 null++;
//             if (curGrid[i+1][j-1] == 'X')
//                 neighbors++;
//             else
//                 null++;
//         }
//     }
// }













//yeet
