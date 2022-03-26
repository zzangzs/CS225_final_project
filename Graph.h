/**
 * @file Graph.hs
 *
 * @author DHREV
 */
#pragma once

#include "Point.h"
#include "Airport.h"

#include <vector>
#include <map>

using std::vector;
using std::map;

// Directed Weighted Graph

struct Edge
        {
        unsigned startID;
        unsigned endID;
        double dist;
        };

class Graph
{
    private:
        vector<bool> visited_;  // used in DFS
        // vector<Edge> edges_;
        // vector<Airport> nodes_;
        vector<vector<double>> adj_; // adjacency list
        map<Point,Airport> map_; // used in KDTree

    public:
        

        Graph();
        Graph(const vector<Edge> & edges, const vector<Airport> & airports);

        Airport & locateAirport(const Point & point) const;



    
};