/**
 * @file Graph.hs
 *
 * @author DHREV: ZJ
 */

#include "Graph.h"

using std::vector;
using std::pair;

Graph::Graph(){


}

Graph::Graph(const vector<Route> & routes, const vector<Airport> & airports) : edges_(routes), vertices_(airports)
{
    //airports_ptr_ = &airports;

    unsigned numAirports = airports.size();
    unsigned numRoutes = routes.size();

    visited_.resize(numAirports,false);
    adj_.resize(numAirports,vector<double>(numAirports,0));
  
    //build routesMap from routes
    for (const Route & route : routes)
    {
        routesMap_[make_pair(route.startID,route.endID)]=route.dist;
    }
    
    // build adjacency list
    for (size_t row = 0; row < numAirports; row++)
    {
        for (size_t col = 0; col < numAirports; col++)
        {
            pair<unsigned,unsigned> IDs = make_pair(airports[row].getID(), airports[col].getID());
            bool isIn = routesMap_.find(IDs) != routesMap_.end();
            if (isIn)
            {
                adj_[row].push_back(routesMap_[IDs]);
            } else
            {
                adj_[row].push_back(0);
            }
        }
        
    }
     

}

double Graph::findDist(unsigned ID_A, unsigned ID_B) const
{
    pair<unsigned,unsigned> IDs = make_pair(ID_A, ID_B);
    bool isIn = routesMap_.find(IDs) != routesMap_.end();
    if (isIn)
    {
        return routesMap_.at(IDs);
    } else
    {
        return 0;
    }
}