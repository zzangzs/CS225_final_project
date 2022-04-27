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
#include <string>
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"


using std::vector;
using std::pair;
using std::string;

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

        cs225::PNG base;

        void BFS(vector<bool> * visited, int start_idx);

        // void drawPoint(Airport airport);



    public:
        double total_dist;
        // default constructor
        Graph();

        // customized constructor
        Graph(const vector<Route> & routes, const vector<Airport> & airports, cs225::PNG & png);

        vector<unsigned> Dijkstra(unsigned int departure, unsigned int destination);

        // BFS later
        void printGraph() const;

        //void printFlight() const;

        int BFS();

        void drawPoint(Airport airport);
};