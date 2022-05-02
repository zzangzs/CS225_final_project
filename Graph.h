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
#include <bits/stdc++.h> // Dijkstra
#include <random> // std::random_device, std::mt19937
#include <stdint.h> // UINT32_MAX
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort


using std::vector;
using std::pair;

// helper functions
template <typename T>
void printVec(const vector<T> & v){
    for (size_t i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

// Directed Weighted Graph
class Graph
{
    private:
        // adjacency matrix: represent the graph itself; may be replaced by routesMap_
        vector<vector<double> > adj_;
        // add size of airport
        unsigned numAirports;

        vector<Airport>* airports_ptr_;
        const vector<Route>* routes_ptr_;

        void BFS(vector<bool> * visited, int start_idx);

        vector<vector<double> > transpose(vector<vector<double> > & V2D);

    public:
        double total_dist;
        // default constructor
        Graph();

        // customized constructor
        Graph(const vector<Route> & routes, vector<Airport> & airports);

        vector<unsigned> Dijkstra(unsigned int departure, unsigned int destination);

        void printGraph() const;

        int BFS();

        vector<size_t> simplifiedPageRank(int = 10);

        vector<size_t> PageRank(int = 100);
};