/**
    This file contains all the helper functions that will be used to read databases files (airport
    and routes information). The process for checking potential data error is also implemented. The
    functions will store complete data into pre-implemented data structures. 

    The corresponding header file is 'Readfile.h'
**/
#include "Readfile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/**
    The readfile_airport function accepts a vector storing pointers of Airport objects, and 
    it reads every line of the input files. When reading every line, it will check the validity
    of the data and construct a corresponding Airport object. If every entry is valid, the newly
    constructed Airport object will be pushed into 'airport_vec', otherwise not. 

    @param airport_vec The vector that stores pointers of every Airport object
**/
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

/**
    parse_correct_airport is the helper function that parses strings from every line of the file, and
    checks for data validity. 

    @param airport_vec The vector that stores pointers of every Airport object
    @param s Every line of the input file
**/
void parse_correct_airport(string s, vector<Airport*> & airport_vec)
{
    // Construct an airport object
    Airport *airport = new Airport();

    stringstream s_stream(s);
    int count = 0;
    bool airport_valid = true;
    while(s_stream.good())
    {
        // 'substr' is the 
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
            if (substr == "")
            {
                airport_valid = false;
                break;
            }
            else
            {
                double latitude = std::stod(substr);
                if (latitude > 90 || latitude < -90)
                {
                    airport_valid = false;
                    break;
                }
                airport -> setLatitude(latitude);
            }
        }

        if (count == 7)
        {
            // Check for valid longtitude
            if (substr == "")
            {
                airport_valid = false;
                break;
            }
            else
            {
                double longitude = std::stod(substr);
                if (longitude > 180 || longitude < -180)
                {
                    airport_valid = false;
                    break;
                }
                airport -> setLongitude(longitude);
            }
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
