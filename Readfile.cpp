/**
    This file contains all functions that are in the Readfile class and will be used to read databases 
    files (airport and routes information). The process for checking potential data error is also implemented. 
    The functions will store complete data into pre-implemented data structures. 

    The corresponding header file is 'Readfile.h'
**/
#include "Readfile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;


Readfile::Readfile()
{
    /* Nothing */
}


Readfile::~Readfile()
{
    /* Nothing */
}


/**
    The readfile_airport function accepts a vector storing pointers of Airport objects, and 
    it reads every line of the input file (airport database). When reading every line, it will check the validity
    of the data and construct a corresponding Airport object. If every entry is valid, the newly
    constructed Airport object will be pushed into 'airport_vec', otherwise not. 

    @param airport_vec The vector that stores pointers of every Airport object
**/
void Readfile::readfile_airport(vector<Airport*> & airport_vec)
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
    The readfile_routes function accepts a vector storing pointers of Route struct, and 
    it reads every line of the input file (route database). When reading every line, it will check the validity
    of the data and instantiate a corresponding Route struct. If every entry is valid, the newly
    constructed Route struct will be pushed into 'routes_vec', otherwise not. 

    @param routes_vec The vector that stores pointers of every Route struct
**/
void Readfile::readfile_routes(vector<Route*> & routes_vec)
{
    // Open a new file to perform read operation line by line
    fstream newfile;
    newfile.open("route_test.txt", ios::in);
    if (newfile.is_open() == true)
    {
        string line;
        while(getline(newfile, line))
        {
            // Parse each line and check for data error
            parse_correct_routes(line, routes_vec);
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
void Readfile::parse_correct_airport(string s, vector<Airport*> & airport_vec)
{
    // Construct an airport object
    Airport *airport = new Airport();

    stringstream s_stream(s);
    int count = 0;
    bool airport_valid = true;
    unsigned int orig_id = 0;
    while(s_stream.good())
    {
        // 'substr' is the string of every parse (different portions of the line)
        string substr;
        getline(s_stream, substr, ',');
        
        if (count == 0)
        {
            // Read the airport's original id
            orig_id = std::stoul(substr);
        }

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

        if (count == 2)
        {
            // Check for valid city name
            if (substr == "")
            {
                airport_valid = false;
                break;
            }
            airport -> setCity(substr);
        }

        if (count == 3)
        {
            // Check for valid country name
            if (substr == "")
            {
                airport_valid = false;
                break;
            }
            airport -> setCountry(substr);
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
        /* airport_vec.size() is the actual index refers to the airport,
            which should equal to the airport assigned id. (not the original
            one if there exist invalid airports)
        */
        airport -> setId(airport_vec.size());
        id_change[orig_id] = airport_vec.size();
        airport_vec.push_back(airport);
    }
    else
    {
        delete airport;
    }
}


/**
    parse_correct_routes is the helper function that parses strings from every line of the file, and
    checks for data validity. 

    @param routes_vec The vector that stores pointers of every Route struct
    @param s Every line of the input file
**/
void Readfile::parse_correct_routes(string s, vector<Route*> & routes_vec)
{
    // Instantiate a Route struct
    Route *route = new Route;

    stringstream s_stream(s);
    int count = 0;
    bool route_valid = true;
    while(s_stream.good())
    {
        // 'substr' is the string of every parse (different portions of the line)
        string substr;
        getline(s_stream, substr, ',');
        
        if (count == 3)
        {
            // Check for valid source airport ID
            if (substr == "")
            {
                route_valid = false;
                break;
            }
            route -> startID = id_change[std::stoul(substr)];
        }

        if (count == 5)
        {
            // Check for valid destination airport ID
            if (substr == "")
            {
                route_valid = false;
                break;
            }
            route -> endID = id_change[std::stoul(substr)];
        }
        count ++;
    }

    // Determine whether the route should be stored
    if (route_valid == true)
    {
        routes_vec.push_back(route);
    }
    else
    {
        delete route;
    }
}
