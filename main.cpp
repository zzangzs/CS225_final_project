// main.cpp
#include "Readfile.h"
#include "Graph.h"
#include "Airport.h"
// #include "Route.h"

#include <bits/stdc++.h>
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

    // Initialize the routes vector
    vector<Route> routes;
    vector<Route*> routes_ptrs;
    //string filename = "./tests/airport_test.txt";
    Readfile read_test = Readfile();
    read_test.readfile_airport(airports, "./tests/airport_test.txt");
    read_test.readfile_routes(routes_ptrs, airports, "./tests/routes_test.txt");
    
    for (auto & ptr : routes_ptrs)
    {
        routes.push_back(*ptr);
    }

    Graph testGraph(routes,airports);
    testGraph.printGraph();
    testGraph.BFS();

    vector<unsigned> flight = testGraph.Dijkstra(0,3);
    for(auto stop:flight)
    {
        cout<<stop<<endl;
    }
    

    airports.clear();
    routes.clear();
    routes_ptrs.clear();
    flight.clear();

    Readfile read = Readfile();
    read.readfile_airport(airports, "./data/airport.txt");
    read.readfile_routes(routes_ptrs, airports, "./data/route.txt");

    for (auto & ptr : routes_ptrs)
    {
        routes.push_back(*ptr);
    }

    Graph myGraph(routes,airports);

    flight = myGraph.Dijkstra(100,110);
    for(auto stop:flight)
    {
        cout<<stop<<endl;
    }
    
    return 0;
}