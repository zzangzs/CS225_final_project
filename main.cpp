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
    // Route route1,route2,route3,route4;
    // route1.startID = 1;
    // route1.endID = 2;
    // route1.dist = 5;

    // route2.startID = 3;
    // route2.endID = 4;
    // route2.dist = 25;

    // route3.startID = 1;
    // route3.endID = 3;
    // route3.dist = 10;

    // route4.startID = 4;
    // route4.endID = 2;
    // route4.dist = 20;


    // routes.push_back(route1);
    // routes.push_back(route2);
    // routes.push_back(route3);
    // routes.push_back(route4);

    Graph myGraph(routes,airports);
    myGraph.printGraph();
    // for (unsigned int i = 1; i < airports.size(); i ++)
    // {
    //     cout << airports[i].getID() << " ";
    //     cout << airports[i].getName() << " ";
    //     cout << airports[i].getCity() << " ";
    //     cout << airports[i].getIATA() << " ";
    //     cout << airports[i].getICAO() << " ";
    //     cout << airports[i].getCountry() << " ";
    //     cout << airports[i].getLatitude() << " ";
    //     cout << airports[i].getLongitude() << endl;
    // }
    // cout << "\n";
    // for (unsigned int j = 0; j < routes.size(); j ++)
    // {
    //     cout << routes[j].startID << " ";
    //     cout << routes[j].endID << endl;
    // }

    return 0;
}