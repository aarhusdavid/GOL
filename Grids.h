#include <iostream>

using namespace std;

class Grids
{
public:
    Grids(); //constructor
    ~Grids(); //destructor

    Grids(int rows, int columns, double density);
    void readGrid();
    string writeGrid();

    char** curGrid;
    char** nextGrid;
    int rows;
    int columns;
    double pop;
    bool inf;
};
