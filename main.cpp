// main.cpp
#include "Readfile.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<Airport*> airport;
    readfile_airport(airport);
    return 0;
}