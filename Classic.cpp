#include "Readerfile.h"
#include "Grids.h"
#include "Classic.h"
#include <iostream>
#include <fstream>

using namespace std;

Classic::Classic()
{

}
Classic::~Classic()
{

}

void Classic::ClassicGame(Grids* g)
{
    int neighbors = 0;
    int neighborCount = 0;
    int check = 0;

    for (int i = 0; i < g->rows; ++i)
    {
        for (int j = 0; j < g->columns; ++j)
        {
            while(check == 0)
            {
                if(((j+1) < (g->columns)))
                {
                    if (g->curGrid[i][j+1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                if(((j-1) >= (0)))
                {
                    if (g->curGrid[i][j-1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                if(((i+1) < (g->rows)))
                {
                    if (g->curGrid[i+1][j] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                if(((i-1) >= (0)))
                {
                    if (g->curGrid[i-1][j] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                if(((i+1) < (g->rows)) && ((j-1) >= (0)))
                {
                    if (g->curGrid[i+1][j-1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                if(((i-1) >= (0)) && ((j+1) < (g->columns)))
                {
                    if (g->curGrid[i-1][j+1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                if(((i-1) >= (0)) && ((j-1) >= (0)))
                {
                    if (g->curGrid[i-1][j-1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                if(((i+1) < (g->rows)) && ((j+1) < (g->columns)))
                {
                    if (g->curGrid[i+1][j+1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }
                check++;
            }

            // cout << neighbors << endl;

            if(neighbors < 2)
            {
                g->nextGrid[i][j] = '-';
            }
            else if (neighbors == 2)
            {
                g->nextGrid[i][j] = g->curGrid[i][j];
            }
            else if (neighbors == 3)
            {
                g->nextGrid[i][j] = 'X';
            }
            else if (neighbors >= 4)
            {
                g->nextGrid[i][j] = '-';
            }
            check--;
            neighbors = 0;

        }
    }

}

int Classic::CopyGrid(Grids* g)
{
    int ans = 0;
    int stablized = 0;
    stablized = g->rows * g->columns;
    int stableCount = 0;

    for (int i = 0; i < g->rows; ++i)
    {
        for (int j = 0; j < g->columns; ++j)
        {
            if(g->curGrid[i][j] == g->nextGrid[i][j])
            {
                stableCount++;
            }
            g->curGrid[i][j] = g->nextGrid[i][j];
        }
    }

    if (stableCount == stablized)
    {
        cout << "Grid has stablized, Press 'Enter' to exit" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        if(cin.get()=='\n')
            delete g;
            exit(0);
    }
}
