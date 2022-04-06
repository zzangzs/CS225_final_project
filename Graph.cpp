/**
 * @file Graph.hs
 *
 * @author DHREV: ZJ
 */

#include "Graph.h"

using std::vector;
using std::pair;
using std::cout;
using std::endl;

Graph::Graph(){


}

Graph::Graph(const vector<Route> & routes, const vector<Airport> & airports) : edges_(routes), vertices_(airports)
{
    //airports_ptr_ = &airports;

    unsigned numAirports = airports.size();
    unsigned numRoutes = routes.size();

    //visited_.resize(numAirports,false);
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
                adj_[row][col] = routesMap_[IDs];
            } else
            {
                adj_[row][col]=0;
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

void Graph::printGraph()
{
    for (size_t i = 1; i < vertices_.size(); i++)
    {
        cout << "Airport " << vertices_.at(i).getID() << " is adjacent to: " << endl;
        for (size_t j = 1; j < vertices_.size(); j++)
        {

            if (adj_[i][j]!=0)
            {
                cout << "    Airport" << vertices_.at(j).getID() << " with a distance of " << adj_[i][j] << endl;
            }
            
        }
        
    }
    
}

