//packages and .h files needed for program 
#include "Readerfile.h"
#include "Grids.h"
#include "Classic.h"
#include <iostream>
#include <fstream>

using namespace std;

//empty constuctor
Classic::Classic()
{

}
//destructor
Classic::~Classic()
{

}

void Classic::ClassicGame(Grids* g)
{
    //classic game variables
    int neighbors = 0;
    int neighborCount = 0;
    int check = 0;

    //double forloop that iterates through grids
    for (int i = 0; i < g->rows; ++i)
    {
        for (int j = 0; j < g->columns; ++j)
        {
            while(check == 0)
            {
                //checks to see if boundary cell exists
                if(((j+1) < (g->columns)))
                {
                    if (g->curGrid[i][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                //checks to see if boundary cell exists
                if(((j-1) >= (0)))
                {
                    if (g->curGrid[i][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                //checks to see if boundary cell exists
                if(((i+1) < (g->rows)))
                {
                    if (g->curGrid[i+1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                //checks to see if boundary cell exists
                if(((i-1) >= (0)))
                {
                    if (g->curGrid[i-1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                //checks to see if boundary cell exists
                if(((i+1) < (g->rows)) && ((j-1) >= (0)))
                {
                    if (g->curGrid[i+1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }
                //checks to see if boundary cell exists
                if(((i-1) >= (0)) && ((j+1) < (g->columns)))
                {
                    if (g->curGrid[i-1][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                //checks to see if boundary cell exists
                if(((i-1) >= (0)) && ((j-1) >= (0)))
                {
                    if (g->curGrid[i-1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }

                //checks to see if boundary cell exists
                if(((i+1) < (g->rows)) && ((j+1) < (g->columns)))
                {
                    if (g->curGrid[i+1][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                        neighborCount++;
                    }
                    else
                        neighborCount++;
                }
                check++;
            }

            // determines cells state in next generation, by neighbor count
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

//copyGrid method
int Classic::CopyGrid(Grids* g)
{
    //variables for method
    int ans = 0;
    int stablized = 0;
    stablized = g->rows * g->columns;
    int stableCount = 0;

    //double forloop that iterates through grid
    for (int i = 0; i < g->rows; ++i)
    {
        for (int j = 0; j < g->columns; ++j)
        {
            //checks if curGrid cell is the same as next grid cell
            if(g->curGrid[i][j] == g->nextGrid[i][j])
            {
                //if so increments stable count
                stableCount++;
            }
            //if not curGrid cell = nextgrid cell
            g->curGrid[i][j] = g->nextGrid[i][j];
        }
    }

    //if statement that only runs if every cell in the curgrid is equal to every cell in the future grid
    if (stableCount == stablized)
    {
        cout << "Grid has stablized, Press 'Enter' to exit" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        //takes in enter key and deletes grid, as well as exits program.
        if(cin.get()=='\n')
            delete g;
            exit(0);
    }
}
