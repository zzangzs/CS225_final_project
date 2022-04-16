/**
 * @file Graph.hs
 *
 * @author DHREV: ZJ
 */
#include <bits/stdc++.h> //for priority queue
#include "Graph.h"
#include <map>
#include <stack>

using std::map;
using std::vector;
using std::pair;
using std::cout;
using std::endl;
//using std::priority_queue;

Graph::Graph(){


}

Graph::Graph(const vector<Route> & routes, const vector<Airport> & airports)
{
    airports_ptr_ = &airports;
    routes_ptr_ = &routes;

    //unsigned numAirports = airports.size();
    numAirports = airports.size();
    unsigned numRoutes = routes.size();

    adj_.resize(numAirports,vector<double>(numAirports,0));
  
    map<pair<unsigned,unsigned>,double> routesMap_;
    //build routesMap from routes
    for (const Route & route : routes)
    {
        routesMap_[make_pair(route.getStartID(),route.getEndID())]=route.getDist();
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
                adj_[row][col] = 0;
            }
        }  
    }
}

void Graph::printGraph()
{  
    for (size_t i = 0; i < airports_ptr_->size(); i++)
    {
<<<<<<< HEAD
        cout << "Airport " << airports_ptr_->at(i).getID()+1 << " is adjacent to: " << endl;
=======
        cout << "Airport " << airports_ptr_->at(i).getID() +1 << " is adjacent to: " << endl;
>>>>>>> 2f2762b28026eebc60eb7fd583c08eb28de17aef
        for (size_t j = 0; j < airports_ptr_->size(); j++)
        {

            if (adj_[i][j]!=0)
            {
<<<<<<< HEAD
                cout << "    Airport" << airports_ptr_->at(j).getID()+1 << " with a distance of " << adj_[i][j] << endl;
=======
                cout << "    Airport " << airports_ptr_->at(j).getID() + 1 << " with a distance of " << adj_[i][j] << endl;
>>>>>>> 2f2762b28026eebc60eb7fd583c08eb28de17aef
            }
            
        }
        
    }
    
}

//Dijkstra: find the shortest path from one airport to the other
//input: adjMatrix, departure airport id, destination airport id
//output: vector of airport id representing the path
<<<<<<< HEAD
// vector<unsigned> Graph::Dijkstra(unsigned int departure, unsigned int destination){
//     //initialize distance matrix, previous node matrix, and visited matrix
//     vector<double> d; //distance matrix
//     vector<unsigned> p; //previous node matrix
//     vector<bool> visited; //visited matrix
//     double inf = std::numeric_limits<double>::max();

//     for (unsigned i = 0; i < numAirports; i++){
//         d.push_back(inf);
//         p.push_back(NULL);
//         visited.push_back(false);
//     }
//     d[departure] = 0;

//     //initialize the priority queue
//     priority_queue<unsigned> pq;
//     pq.push(departure);

//     while(pq.top() != destination){
//         unsigned cur = pq.pop();
//         for (unsigned i = 0; i < numAirports; i++){//for neighbor in current_node's neighbors
//             if (adj_[cur][i] != 0 && !visited[i]){ //push unvisisted neighbors to pq
//                 if ((d[cur] + adj_[cur][i]) < d[i]){ //if cost is cheap
//                     d[i] = d[cur] + adj_[cur][i]; //update its neighbor's distance
//                     p[i] = cur; //update previous node
//                 }
//                 pq.push(i); //push neighbors to pq
//             } 
//         }
//         visited[cur] = true;
//     }

//     //extract path from previous
//     vector<unsigned> path; //from departure to destination order
//     stack<unsigned> s;
//     double total_dist; //use to calculate total distance 

//     unsigned temp = destination;
//     while(p[temp] != departure){
//         s.push(temp);
//         total_dist += adj_[p[temp]][temp]; //use to calculate total distance 
//         temp = p[temp];
//     }
//     s.push(departure);

//     while(!s.empty()){
//         unsigned temp = s.pop();
//         path.push_back(temp);
//     }

//     return path;
// }
=======
vector<unsigned> Graph::Dijkstra(unsigned int departure, unsigned int destination){
    //initialize distance matrix, previous node matrix, and visited matrix
    vector<double> d; //distance matrix
    vector<unsigned> p; //previous node matrix
    vector<bool> visited; //visited matrix
    double inf = std::numeric_limits<double>::max();

    for (unsigned i = 0; i < numAirports; i++){
        d.push_back(inf);
        p.push_back(NULL);
        visited.push_back(false);
    }
    d[departure] = 0;

    //initialize the priority queue
    priority_queue<pair<double, unsigned>> pq;
    pq.push(make_pair(0, departure));

    while(pq.top().second != destination){
        pair<double,unsigned> cur_dist_id = pq.top();
        unsigned cur = cur_dist_id.second;
        pq.pop();
        for (unsigned i = 0; i < numAirports; i++){//for neighbor in current_node's neighbors
            if (adj_[cur][i] != 0 && !visited[i]){ //push unvisisted neighbors to pq
                if ((d[cur] + adj_[cur][i]) < d[i]){ //if cost is cheap
                    d[i] = d[cur] + adj_[cur][i]; //update its neighbor's distance
                    p[i] = cur; //update previous node
                }
                pq.push(make_pair( -d[i], i)); //push neighbors to pq, push negative dist as it is Max Priority queue
            } 
        }
        visited[cur] = true;
    }

    //extract path from previous
    vector<unsigned> path; //from departure to destination order
    stack<unsigned> s;
    total_dist = 0; //use to calculate total distance 

    unsigned temp = destination;
    s.push(temp);
    while(p[temp] != departure){
        s.push(p[temp]);
        total_dist += adj_[p[temp]][temp]; //use to calculate total distance 
        temp = p[temp];
    }
    total_dist += adj_[p[temp]][temp];
    s.push(departure);

    while(!s.empty()){
        unsigned temp = s.top();
        s.pop();
        path.push_back(temp);
    }

    return path;
}
>>>>>>> 622b9a83911e7baa3816a53bf22fdca774c99311

