// main.cpp
#include "Readfile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void readfile_airport(vector<Airport*> & airport_vec)
{
    // Open a new file to perform read operation line by line
    fstream newfile;
    newfile.open("airport_test.txt", ios::in);
    if (newfile.is_open() == true)
    {
        string line;
        while(getline(newfile, line))
        {
            // Parse each line and check for data error
            parse_correct_airport(line, airport_vec);
        }
        
        newfile.close(); 
    }
}


void parse_correct_airport(string s, vector<Airport*> & airport_vec)
{
    // Construct an airport object
    Airport *airport = new Airport();

    stringstream s_stream(s);
    int count = 0;
    bool airport_valid = true;
    while(s_stream.good())
    {
        string substr;
        getline(s_stream, substr, ',');
        
        if (count == 1)
        {
            // Check for valid airport name
            if (substr == "")
            {
                airport_valid = false;
                break;
            }
            airport -> setName(substr);
        }

        if (count == 6)
        {
            // Check for valid latitude
            double latitude = std::stod(substr);
            if (latitude > 90 || latitude < -90)
            {
                airport_valid = false;
                break;
            }
            airport -> setLatitude(latitude);
        }

        if (count == 7)
        {
            // Check for valid longtitude
            double longitude = std::stod(substr);
            if (longitude > 180 || longitude < -180)
            {
                airport_valid = false;
                break;
            }
            airport -> setLongitude(longitude);
        }

        count ++;
    }

    // Determine whether the airport should be stored
    if (airport_valid == true)
    {
        airport -> setId(airport_vec.size());
        airport_vec.push_back(airport);
    }
    else
    {
        delete airport;
    }
}
