/**
 * @file Graph.h
 *
 * @author DHREV
 */
#pragma once

#include "Point.h"
#include "Route.h"
#include "Airport.h"

#include <vector>
#include <map>

using std::vector;
using std::map;
using std::pair;

// Directed Weighted Graph
class Graph
{
    private:
        // used in DFS
        vector<bool> visited_;  

        // adjacency list: represent the graph itself; may be replaced by routesMap_
        vector<vector<double>> adj_; 

        vector<Point> points_;

        // used in KDTree
        map<Point,Airport> map_; 

        // necessary? may be duplicate with adj_
        map<pair<unsigned,unsigned>,double> routesMap_; 

    public:   
        // default constructor
        Graph();

        // customized constructor
        Graph(const vector<Route> & routes, const vector<Airport> & airports);

        // 
        Airport & locateAirport(double latitude, double longitude) const;

        double findDist(unsigned ID_A, unsigned ID_B) const;
  
};