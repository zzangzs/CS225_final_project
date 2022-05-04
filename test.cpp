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
    // vector<Route> routes;
    // vector<Airport> airports;
    // for(int i = 0 ; i < 3 ; i++){
    //     Route route(0,0,0);
    //     route.setStartID(i);
    //     route.setEndID((i+1)%3);
    //     route.setDist(5 + i);
    //     routes.push_back(route);
    //     //airports.push_back(Airport());
    //     string name = "Tdfnri";
    //     Airport a(name, "U.S.", "Champaign", i, 60, 0);
    //     airports.push_back(a);
    // }
    // cs225::PNG temp;
    // temp.readFromFile("original.png");
    // Graph g(routes, airports, temp);
    // g.BFS();
    //g.drawPoint(airports[0]);


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
    std::vector<unsigned> rk = myGraph.PageRank(100);
    // std::cout<<rk[0]<<std::endl;
    // myGraph.draw_rank(rk);
    cs225::PNG output = myGraph.getBasePic();
    output.writeToFile("test_output.png");
}
