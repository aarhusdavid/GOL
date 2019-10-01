#include <iostream>

using namespace std;

class Classic
{
public:
    Classic(); //constructor
    ~Classic(); //destructor

    void ClassicGame(Grids* g);
    int CopyGrid(Grids* g);

};
