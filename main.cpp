// main.cpp
#include "Readfile.h"
#include "Graph.h"
#include "Airport.h"
// #include "Route.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Initialize the airport vector
    vector<Airport> airports;
    airports.push_back(Airport());
    // Initialize the routes vector
    vector<Route> routes;

    //string filename = "./tests/airport_test.txt";
    Readfile read = Readfile();
    read.readfile_airport(airports);
    read.readfile_routes(routes);

    // Graph myGraph(routes,airports);
    // myGraph.printGraph();
    for (unsigned int i = 1; i < airports.size(); i ++)
    {
        cout << airports[i].getID() << " ";
        cout << airports[i].getName() << " ";
        cout << airports[i].getCity() << " ";
        cout << airports[i].getIATA() << " ";
        cout << airports[i].getICAO() << " ";
        cout << airports[i].getCountry() << " ";
        cout << airports[i].getLatitude() << " ";
        cout << airports[i].getLongitude() << endl;
    }
    cout << "\n";
    for (unsigned int j = 0; j < routes.size(); j ++)
    {
        cout << routes[j].startID << " ";
        cout << routes[j].endID << endl;
    }

    return 0;
}