// main.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    double latitude;
    double longtitude;
    string airport_name;

    // Open a new file to perform read operation line by line
    fstream newfile;
    newfile.open("airport.txt", ios::in);
    if (newfile.is_open() == true)
    {
        string first_line;
        getline(newfile, first_line);

        cout << first_line << endl;
        newfile.close(); 
    }
}