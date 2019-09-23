#include "Readerfile.h"
#include <iostream>
#include <fstream>

using namespace std;

Readerfile::Readerfile()
{

}
Readerfile::~Readerfile()
{
    cout << "object deleted" << endl;
}

string Readerfile::read(string input)
{
    string strand;
    string line;
    ifstream infile;
    infile.open(input);
    while(infile.peek() != EOF)
    {
        getline(infile, strand);
        line = line += strand + "\n";
    }

    return line;
    infile.close();


}
