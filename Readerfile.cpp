#include "Readerfile.h"
#include <iostream>
#include <fstream>

using namespace std;

//constructor
Readerfile::Readerfile()
{

}
//destructor
Readerfile::~Readerfile()
{

}

//method that gets files rows
int Readerfile::getRows(string input)
{
    //method variables
    int row = 0;
    string strand;
    //opens file
    ifstream infile;
    infile.open(input);
    //gets files first element
    getline(infile, strand);
    row = strand[0] - '0';
    return row;
    //close file
    infile.close();
}

//method that gets columns of file
int Readerfile::getColumns(string input)
{
    //method variables
    string strand2;
    string strand;
    //opens file
    ifstream infile;
    infile.open(input);
    int count = 0;
    int col = 0;
    //gets first and second lines of file
    getline(infile, strand);
    getline(infile, strand2);
    col = strand2[0] - '0';
    //return second line of file which is the amount of columns
    return col;
    //closes file
    infile.close();
}

//method that calculates density of file
double Readerfile::getDensity(string input)
{
    //density variables
    double x_count = 0;
    double null_count = 0;
    double density = 0;
    double totalcount = 0;
    string strand;
    char line;
    //opens file
    ifstream infile;
    infile.open(input);
    //while loop
    while(infile.peek() != EOF)
    {
        //gets line
        getline(infile, strand);
        //iterates through line
        for (int i = 0; i < strand.size(); ++i)
        {
            line = toupper(strand[i]);
            //if line is X or - increments x count or total count
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
    //calculates density
    density = (x_count/totalcount);
    //return density
    return density;
    //close file 
    infile.close();
}
