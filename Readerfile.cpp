#include "Readerfile.h"
#include <iostream>
#include <fstream>

using namespace std;

Readerfile::Readerfile()
{

}
Readerfile::~Readerfile()
{
    
}

int Readerfile::getRows(string input)
{
    int row = 0;
    string strand;
    ifstream infile;
    infile.open(input);
    getline(infile, strand);
    row = strand[0] - '0';
    return row;
    infile.close();
}

int Readerfile::getColumns(string input)
{
    string strand2;
    string strand;
    ifstream infile;
    infile.open(input);
    int count = 0;
    int col = 0;
    getline(infile, strand);
    getline(infile, strand2);
    col = strand2[0] - '0';
    return col;
    infile.close();
}

double Readerfile::getDensity(string input)
{
    double x_count = 0;
    double null_count = 0;
    double density = 0;
    double totalcount = 0;
    string strand;
    char line;
    ifstream infile;
    infile.open(input);
    while(infile.peek() != EOF)
    {
        getline(infile, strand);
        for (int i = 0; i < strand.size(); ++i)
        {
            line = toupper(strand[i]);
            if (line == 'X')
            {
                x_count++;
                totalcount++;
            }
            else if (line == '-')
            {
                totalcount++;
            }
        }
    }
    density = (x_count/totalcount);
    return density;
    infile.close();
}
