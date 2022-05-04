/**
 * @file Graph.h
 * Using directed weighted graph to store airports and routes with the purpose
 *   of finding the shortest path between two airports and visualizing the top
 *   100 popular airports.
 * 
 * @author Zisu Jiang
 * @author Nan Kang
 * @author Yu Li
 * 
 * @date 2022-05-03
 */
#pragma once

#include "Airport.h"
#include "Route.h"

#include <iostream>

#include <map>
#include <stack>
#include <queue>
#include <vector>

#include <numeric>      // std::iota
#include <algorithm>    // std::stable_sort

using std::vector;
using std::pair;

/**
 * Helper function to print vectors / 2d vectors
 * 
 * @tparam T item in vector
 * @param v vector to be printed
 * @param V2D 2d vector to be printed
 */
template <typename T>
void printVec(const vector<T> & v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}
template <typename T>
void print2DVec(const vector<vector<T> > & V2D) {
    for (size_t i = 0; i < V2D.size(); i++) {
        for (size_t j = 0; j < V2D[i].size(); j++) {
            cout<<V2D[i][j]<<' ';
        }
        cout<<endl;
    }
}

/**
 *  Helper function in simplifiedPageRank
 * 
 * @param v vector to be sorted
 * @return vector<size_t> indices of the sorted vector in descending order 
 */
vector<size_t> sort_indices(const vector<double> & v);

/**
 *  Directed Weighted Graph date structure
 */
class Graph
{
    private:
        // adjacent matrix
        vector<vector<double> > adj_;
        
        // size of airport cleaned by Readfile
        unsigned numAirports;

        // pointer that have access to actual vectors stored in caller scope
        const vector<Airport>* airports_ptr_;
        const vector<Route>* routes_ptr_;

        void BFS(vector<bool> * visited, int start_idx);

    public:
        double total_dist;
        
        /**
         * Default constructor
         *
         * @param routes vector of Route parsed by Readfile()
         * @param airports vector of Airport parsed by Readfile()
         */
        Graph(const vector<Route> & routes, const vector<Airport> & airports);

        vector<unsigned> Dijkstra(unsigned int departure, unsigned int destination);

        /**
         * Helper funtction to check the Graph constructor before implementing BFS
         * 
         * Traverse over the graph by iteration and print every airport and its
         *     incident edges
         */
        void printGraph() const;

        int BFS();

        /**
         * PageRank algorithm
         * 
         *  
         * 
         * @param int number of toppest airport, default to be 10
         * @return vector<size_t> indices of (*airports) that are top 10(default) popular airports
         */
        vector<size_t> simplifiedPageRank(int = 10);
};