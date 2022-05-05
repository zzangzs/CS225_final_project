#include "Graph.h"
#include "Airport.h"
#include "Route.h"
#include "Readfile.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <vector>
#include <iostream>

//#include "../cs225/catch/catch.hpp"

int main()
{
    
    // Initialize the airport vector
    vector<Airport> airports;

    // Initialize the routes vector
    vector<Route> routes;
    vector<Route*> routes_ptrs;
    Readfile read = Readfile();
    read.readfile_airport(airports, "./data/airport.txt");
    read.readfile_routes(routes_ptrs, airports, "./data/route.txt");

    for (auto & ptr : routes_ptrs)
    {
        routes.push_back(*ptr);
    }

    cs225::PNG temp;
    temp.readFromFile("original.png");
    Graph myGraph(routes,airports,temp);
    myGraph.BFS();
    std::vector<size_t> rk = myGraph.PageRank(10,4,0.85);
    //std::vector<unsigned> path = {(unsigned int)rk[0],(unsigned int)rk[1],(unsigned int)rk[2], (unsigned int)rk[3]};
    myGraph.draw_rank(rk);
    //myGraph.drawLine(path);
    cs225::PNG output = myGraph.getBasePic();
    output.writeToFile("test_output.png");
}
