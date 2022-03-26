/**
 * @file Graph.hs
 *
 * @author DHREV
 */

#include "Graph.h"

using std::vector;

Graph::Graph(){

}

Graph::Graph(const vector<Edge> & edges, const vector<Airport> & airports)
{
    unsigned numAirports = airports.size();

    visited_.reserve(numAirports);
    points_.reserve(numAirports);

    for (const Airport & airport : airports)
    {
        points_.push_back(Point(airport.getLatitude(), airport.getLongitude()));
    }
    
    

}
