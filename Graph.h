/**
 * @file Graph.h
 *
 * @author DHREV: ZJ
 */
#pragma once

#include "Airport.h"
#include "Route.h"

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

// Directed Weighted Graph
class Graph
{
    private:
        // adjacency list: represent the graph itself; may be replaced by routesMap_
        vector<vector<double> > adj_; 

        const vector<Airport>* airports_ptr_;
        const vector<Route>* routes_ptr_;

    public:
       
        // default constructor
        Graph();

        // customized constructor
        Graph(const vector<Route> & routes, const vector<Airport> & airports);

        // BFS later
        void printGraph();

  
};