/**
 * @file Graph.hs
 *
 * @author DHREV: ZJ
 */

#include "Graph.h"
#include <map>

using std::map;
using std::vector;
using std::pair;
using std::cout;
using std::endl;

Graph::Graph(){


}

Graph::Graph(const vector<Route> & routes, const vector<Airport> & airports)
{
    airports_ptr_ = &airports;
    routes_ptr_ = &routes;

    unsigned numAirports = airports.size();
    unsigned numRoutes = routes.size();

    adj_.resize(numAirports,vector<double>(numAirports,0));
  
    map<pair<unsigned,unsigned>,double> routesMap_;
    //build routesMap from routes
    for (const Route & route : routes)
    {
        routesMap_[make_pair(route.startID,route.endID)]=route.dist;
    }
    
    // build adjacency list
    for (size_t row = 1; row < numAirports; row++)
    {
        for (size_t col = 1; col < numAirports; col++)
        {
            pair<unsigned,unsigned> IDs = make_pair(airports[row].getID(), airports[col].getID());
            bool isIn = routesMap_.find(IDs) != routesMap_.end();
            if (isIn)
            {
                adj_[row][col] = routesMap_[IDs];
            } else
            {
                adj_[row][col] = 0;
            }
        }  
    }
}

void Graph::printGraph()
{  
    for (size_t i = 1; i < airports_ptr_->size(); i++)
    {
        cout << "Airport " << airports_ptr_->at(i).getID() << " is adjacent to: " << endl;
        for (size_t j = 1; j < airports_ptr_->size(); j++)
        {

            if (adj_[i][j]!=0)
            {
                cout << "    Airport" << airports_ptr_->at(j).getID() << " with a distance of " << adj_[i][j] << endl;
            }
            
        }
        
    }
    
}

