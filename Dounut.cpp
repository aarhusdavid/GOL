//packages and .h files needed for program
#include "Readerfile.h"
#include "Grids.h"
#include "Dounut.h"
#include <iostream>
#include <fstream>

using namespace std;

//empty constructor
Dounut::Dounut()
{

}
//destructor
Dounut::~Dounut()
{

}

//game method
void Dounut::DounutGame(Grids* g)
{
    //variables for dounut game
    int neighbors = 0;
    int neighborCount = 0;
    int check = 0;
    int col = g->columns - 1;
    int row = g->rows - 1;

    //double for loop that iterates through grid
    for (int i = 0; i < g->rows; ++i)
    {
        for (int j = 0; j < g->columns; ++j)
        {
            //checks all of curGrid[i][j] neighbors
            while(check == 0)
            {
                //checks if cell is in top left corner, if so checks opposing boundary cells as well as surrounding cells
                if(((j-1) < (0)) && ((i-1) < (0)))
                {
                    //tried to find the solution with print statements
                    cout << "hey" << endl;
                    cout << col << endl;
                    cout << g->curGrid[i][col] << endl;

                    if(g->curGrid[i][col] == 'X')
                    {
                        //tried to find the solution with print statements
                        cout << "yo" << endl;
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[row][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[row][col] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][col] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[row][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else
                    {
                        neighborCount++;
                    }
                }

                //checks if cell has no cell above, if so checks opposing boundary cells as well as surrounding cells
                if(((i-1) < (0)))
                {
                    if(g->curGrid[row][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[row][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[row][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                }

                //checks to see of cell is in the right corner,if so checks opposing boundary cells as well as surrounding cells
                if(((i-1) < (0)) && ((j+1) > (col)))
                {
                    if(g->curGrid[row][col] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[row][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[row][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[0][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[1][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }

                }

                //checks if cell has no cell to the left of it, if so checks opposing boundary cells as well as surrounding cells
                if(((j-1) < (0)))
                {
                    if(g->curGrid[i-1][col] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][col] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][col] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                }

                //checks to see if cell has no cell to the right of it, if so checks opposing boundary cells as well as surrounding cells
                if(((j+1) > (col)))
                {
                    if(g->curGrid[i-1][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i+1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                }

                //checks to see if cell is at the bottom left corner,if so checks opposing boundary cells as well as surrounding cells
                if(((i+1) > (row)) && ((j-1) < (0)))
                {
                    if(g->curGrid[0][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[0][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][col] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][col] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                }

                //checks to see if cell has no cell below it, if so checks opposing boundary cells as well as surrounding cells
                if(((i+1) > (row)))
                {
                    if(g->curGrid[0][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[0][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[0][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j+1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                }

                //checks to see if cell is at the bottom right corner,if so checks opposing boundary cells as well as surrounding cells
                if(((i+1) > (row)) && ((j+1) > (col)))
                {
                    if(g->curGrid[0][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[row][0] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[0][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[0][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i][j-1] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }
                    else if(g->curGrid[i-1][j] == 'X')
                    {
                        //increments neighbors
                        neighbors++;
                    }

                    cout << "bound" << endl;
                }

                //checks to see if boundary cell exists
                else if(((j+1) < (g->columns)))
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
                else if(((j-1) >= (0)))
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
                else if(((i+1) < (g->rows)))
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
                else if(((i-1) >= (0)))
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
                else if(((i+1) < (g->rows)) && ((j-1) >= (0)))
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
                else if(((i-1) >= (0)) && ((j+1) < (g->columns)))
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
                else if(((i-1) >= (0)) && ((j-1) >= (0)))
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
                else if(((i+1) < (g->rows)) && ((j+1) < (g->columns)))
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
int Dounut::CopyGrid(Grids* g)
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
