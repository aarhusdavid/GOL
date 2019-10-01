#include <iostream>

using namespace std;

class Classic
{
public:
    Classic(); //constructor
    ~Classic(); //destructor

    //declares methods
    //game
    void ClassicGame(Grids* g);
    //copys grids
    int CopyGrid(Grids* g);

};
