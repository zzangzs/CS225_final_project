/**
 * @file Graph.h
 *
 * @author DHREV: ZJ
 */
#pragma once

// #include "Point.h"
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

        // necessary? may be duplicate with adj_
        map<pair<unsigned,unsigned>,double> routesMap_; 

        vector<Route> edges_;

        //const vector<Airport>* airports_ptr_;
        vector<Airport> vertices_;

    public:   
        // default constructor
        Graph();

        // customized constructor
        Graph(const vector<Route> & routes, const vector<Airport> & airports);

        double findDist(unsigned ID_A, unsigned ID_B) const;
  
        void setVisited(int idx, bool visited);

        bool getVisited();

        void BFS(int start_idx);
};