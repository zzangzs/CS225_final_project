/**
 * @file Graph.h
 * Using directed weighted graph to store airports and routes with the purpose
 *   of finding the shortest path between two airports and visualizing the top
 *   100 popular airports.
 * 
 * @author Zisu Jiang
 * @author Nan Kang
 * @author Yu Li
 * @date 05/03/2022
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
#include <random>       // std::random_device, std::mt19937
#include <stdint.h>     // UINT32_MAX

using std::vector;
using std::pair;
using std::string;

#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"

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
 * Helper function of descending argsort in PageRank 
 * 
 * @param v vector to be sorted
 * @return vector<size_t> indices of the sorted vector in descending order 
 */
vector<size_t> sort_indices(const vector<double> & v);

/**
 *  Directed Weighted Graph class
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

        cs225::PNG base;

        void BFS(vector<bool> * visited, int start_idx);

        /**
         * @brief 
         * 
         * @param oldPR 
         * @param L 
         * @param d 
         */
        void PageRank(vector<double> & oldPR, const vector<double> & L, double d);

        void drawPoint(Airport airport);

    public:
        double total_dist;
        
        /**
         * Default constructor
         * 
         * @param routes vector of Route parsed by Readfile()
         * @param airports vector of Airport parsed by Readfile()
         */
        Graph(const vector<Route> & routes, const vector<Airport> & airports, cs225::PNG b);

        vector<unsigned> Dijkstra(unsigned int departure, unsigned int destination);

        /**
         * Helper funtction to check the Graph constructor before implementing BFS
         *
         * @brief Traverse over the graph by iteration and print every airport and its
         * incident edges.
         */
        void printGraph() const;

        int BFS();
        
        cs225::PNG getBasePic();

        void draw_rank(vector<size_t> rk);
        
        void drawPoint(Airport airport, double h, double s, double l, double a);

        void drawLine(vector<unsigned> path);

        /**
         * PageRank algorithm
         * 
         * @param top 
         * @param iterations 
         * @param d 
         * @return vector<size_t> 
         */
        vector<size_t> PageRank (int top = 10, int iterations = 100, double d = 0.85);
        vector<size_t> simplifiedPageRank(int top = 10);
};