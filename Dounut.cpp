#include "Readerfile.h"
#include "Grids.h"
#include "Dounut.h"
#include <iostream>
#include <fstream>

using namespace std;

Dounut::Dounut()
{

}
Dounut::~Dounut()
{

}

void Dounut::DounutGame(Grids* g)
{
    int neighbors = 0;
    int neighborCount = 0;
    int check = 0;
    int col = g->columns - 1;
    int row = g->rows - 1;

    for (int i = 0; i < g->rows; ++i)
    {
        for (int j = 0; j < g->columns; ++j)
        {
            while(check == 0)
            {
                if(((j-1) < (0)) && ((i-1) < (0)))
                {
                    cout << "hey" << endl;
                    cout << col << endl;
                    if(g->curGrid[i][col] == 'X')
                    {
                        cout << "yo" << endl;

                        neighbors++;
                    }
                    else if(g->curGrid[row][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[row][col] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][col] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[row][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else
                    {
                        neighborCount++;
                    }
                }

                if(((i-1) < (0)))
                {
                    if(g->curGrid[row][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[row][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[row][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        neighbors++;
                    }
                }

                if(((i-1) < (0)) && ((j+1) > (col)))
                {
                    if(g->curGrid[row][col] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[row][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[row][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[0][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[1][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        neighbors++;
                    }

                }

                if(((j-1) < (0)))
                {
                    if(g->curGrid[i-1][col] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][col] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][col] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j+1] == 'X')
                    {
                        neighbors++;
                    }
                }

                if(((j+1) > (col)))
                {
                    if(g->curGrid[i-1][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        neighbors++;
                    }
                }

                if(((i+1) > (row)) && ((j-1) < (0)))
                {
                    if(g->curGrid[0][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[0][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][col] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][col] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        neighbors++;
                    }
                }

                if(((i+1) > (row)))
                {
                    if(g->curGrid[0][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[0][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[0][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j+1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        neighbors++;
                    }
                }

                if(((i+1) > (row)) && ((j+1) > (col)))
                {
                    if(g->curGrid[0][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[row][0] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[0][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[0][j] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        neighbors++;
                    }
                }

                else if(((j+1) < (g->columns)))
                {
                    if (g->curGrid[i][j+1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                else if(((j-1) >= (0)))
                {
                    if (g->curGrid[i][j-1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                else if(((i+1) < (g->rows)))
                {
                    if (g->curGrid[i+1][j] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                else if(((i-1) >= (0)))
                {
                    if (g->curGrid[i-1][j] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                else if(((i+1) < (g->rows)) && ((j-1) >= (0)))
                {
                    if (g->curGrid[i+1][j-1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                else if(((i-1) >= (0)) && ((j+1) < (g->columns)))
                {
                    if (g->curGrid[i-1][j+1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                else if(((i-1) >= (0)) && ((j-1) >= (0)))
                {
                    if (g->curGrid[i-1][j-1] == 'X')
                    {
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                else if(((i+1) < (g->rows)) && ((j+1) < (g->columns)))
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

            // determines cells state in next generation
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

int Dounut::CopyGrid(Grids* g)
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
