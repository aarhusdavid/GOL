#include <iostream> //preprocessor directive

using namespace std; //allows you to print

class Readerfile
{
public:
    Readerfile(); //constructor
    ~Readerfile(); //destructor

    //initialized methods
    //method that gets rows
    int getRows(string input);
    //method that gets getColumns
    int getColumns(string input);
    //method that calculates density 
    double getDensity(string input);
};
