#include <iostream>

using namespace std;

class Dounut
{
public:
    Dounut(); //constructor
    ~Dounut(); //destructor

    //declares methods
    //game
    void DounutGame(Grids* g);
    //copys grids
    int CopyGrid(Grids* g);


};
