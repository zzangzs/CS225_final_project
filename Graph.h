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
        // add size of airport
        unsigned numAirports;

        const vector<Airport>* airports_ptr_;
        const vector<Route>* routes_ptr_;

        //void BFS(int start_idx);



    public:   
        // default constructor
        Graph();

        // customized constructor
        Graph(const vector<Route> & routes, const vector<Airport> & airports);

        //vector<unsigned> Dijkstra(unsigned int departure, unsigned int destination);

        // BFS later
        void printGraph();

        //void BFS();
};