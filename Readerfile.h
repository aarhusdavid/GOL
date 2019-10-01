#include <iostream> //preprocessor directive

using namespace std; //allows you to print

class Readerfile
{
public:
    Readerfile(); //constructor
    ~Readerfile(); //destructor
    //initialized method
    int getRows(string input);
    int getColumns(string input);
    double getDensity(string input);
};
