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
    Readfile read = Readfile();
    read.readfile_airport(airports);
    read.readfile_routes(routes_ptrs, airports);
    
    for (auto & ptr : routes_ptrs)
    {
        routes.push_back(*ptr);
    }

    Graph myGraph(routes,airports);
    myGraph.printGraph();

    vector<unsigned> flight = myGraph.Graph::Dijkstra(0,3);
    for(auto stop:flight)
    {
        cout<<stop<<endl;
    }
    return 0;

    // vector<unsigned> test;
    // test.resize(3);
    // for (unsigned t:test)
    // {
    //     cout<<"default is "<<t<<endl;
    // }
    
}