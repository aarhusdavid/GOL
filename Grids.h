#include <iostream>

using namespace std;

class Grids
{
public:
    Grids(); //constructor
    ~Grids(); //destructor

    //method that makes grid
    Grids(int rows, int columns, double density);
    //method that reads grid
    void readGrid();
    //method that writes grid
    string writeGrid();

    //creates pointers for grids
    char** curGrid;
    char** nextGrid;
    //delclares variables for grids
    int rows;
    int columns;
    double pop;
};
