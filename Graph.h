/**
 * @file Graph.h
 *
 * @author DHREV: ZJ
 */
#pragma once

#include "Airport.h"
#include "Route.h"

#include <map>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
// #include <bits/stdc++.h> // Dijkstra
#include <random> // std::random_device, std::mt19937
#include <stdint.h> // UINT32_MAX

using std::vector;
using std::pair;

// Directed Weighted Graph
class Graph
{
    private:
        // adjacency matrix: represent the graph itself; may be replaced by routesMap_
        vector<vector<double> > adj_;
        // add size of airport
        unsigned numAirports;

        const vector<Airport>* airports_ptr_;
        const vector<Route>* routes_ptr_;

        void BFS(vector<bool> * visited, int start_idx);



    public:
        double total_dist;
        // default constructor
        Graph();

        // customized constructor
        Graph(const vector<Route> & routes, const vector<Airport> & airports);

        vector<unsigned> Dijkstra(unsigned int departure, unsigned int destination);

        void printGraph() const;

        int BFS();

        vector<unsigned> PageRank(int numIterations) const;
};