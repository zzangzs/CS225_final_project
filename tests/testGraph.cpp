/**
 * @file testGraph.cpp
 * @author Zisu Jiang
 * @brief Test constructor and simplifiedPageRank in graph.cpp 
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../Graph.h"
#include "../cs225/catch/catch.hpp"
#include "../Airport.h"
#include "../Readfile.h"



TEST_CASE("CTR::testGraphConstructor","[part3]")
{
    vector<Route> routes;
    vector<Airport> airports;
    vector<Route*> routes_ptrs;

    Readfile read = Readfile();
    read.readfile_airport(airports, "./tests/airport_test_3.txt");
    read.readfile_routes(routes_ptrs, airports, "./tests/routes_test_3.txt");
    
    for (auto & ptr : routes_ptrs) {
        routes.push_back(*ptr);
    }

    cs225::PNG temp;
    temp.readFromFile("original.png");
    Graph myGraph(routes,airports,temp);
    myGraph.printGraph();
}

TEST_CASE("PR::testPageRank","[part3]") {
    vector<Route> routes;
    vector<Airport> airports;
    vector<Route*> routes_ptrs;
    vector<size_t> rank;

    Readfile read = Readfile();
    read.readfile_airport(airports, "./tests/airport_test_3.txt");
    read.readfile_routes(routes_ptrs, airports, "./tests/routes_test_3.txt");
    
    for (auto & ptr : routes_ptrs) {
        routes.push_back(*ptr);
    }

    cs225::PNG temp;
    temp.readFromFile("original.png");
    Graph myGraph(routes,airports,temp);

    int top = 4;
    rank = myGraph.PageRank(top,5);

    cout<<endl;
 
    cout<<"Top "<<top<<" Popular Airports: "<<endl; 
    for (unsigned i = 0; i < rank.size() ; i++) {
        cout<<"    ";
        size_t index = rank[i];
        Airport ap(airports[index]);
        cout<<"No. "<<i+1<<" Airport is "<<ap.getName()<<" in "<<ap.getCity()<<", "<<ap.getCountry()<<endl;
    }
    cout<<endl;
    
    REQUIRE(rank[0] == 1);
    REQUIRE(rank[1] == 3);
    REQUIRE(rank[2] == 2);
    REQUIRE(rank[3] == 0);
}