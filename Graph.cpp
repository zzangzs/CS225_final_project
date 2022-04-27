/**
 * @file Graph.hs
 *
 * @author DHREV: ZJ KN
 */
//#include <bits/stdc++.h> //for priority queue
#include "Graph.h"
#include "./cs225/HSLAPixel.h"
#include "./cs225/PNG.h"
#include <map>
#include <stack>
#include <queue>
#include "Graph.h"

using std::map;
using std::vector;
using std::pair;
using std::cout;
using std::endl;
using std::priority_queue;

Graph::Graph(){


}

Graph::Graph(const vector<Route> & routes, const vector<Airport> & airports, cs225::PNG & png)
{
    base = png;
    airports_ptr_ = &airports;
    routes_ptr_ = &routes;

    numAirports = airports.size();
    unsigned numRoutes = routes.size();

    adj_.resize(numAirports,vector<double>(numAirports,0));
  
    map<pair<unsigned,unsigned>,double> routesMap_;
    //build routesMap from routes
    for (const Route & route : routes)
    {
        routesMap_[make_pair(route.getStartID(),route.getEndID())]=route.getDist();
    }
    
    // build adjacency matrix
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
// test Adjacent Matrix
void Graph::printGraph() const
{  
    for (size_t i = 0; i < airports_ptr_->size(); i++)
    {
        cout << "Airport " << airports_ptr_->at(i).getID()+1 << " is adjacent to: " << endl;
        for (size_t j = 0; j < airports_ptr_->size(); j++)
        {

            if (adj_[i][j]!=0)
            {
                cout << "    Airport" << airports_ptr_->at(j).getID()+1 << " with a distance of " << adj_[i][j] << endl;
            }
            
        }
        
    }
    
}

int Graph::BFS()
{
    vector<bool> visited;
    visited.resize(numAirports, false);
    int count = 0;
    for(unsigned int i = 0 ; i < numAirports ; i++){
        if(visited[i] == false){
            BFS(&visited, i);
            count++;
        }
    }
    return count;
}

void Graph::BFS(vector<bool>* visited, int start_idx)
{
    std::queue<int> q;
    (*visited)[start_idx] = true;
    q.push(start_idx);
    while(!q.empty()){
        int v = q.front();
        cout<<"Airport id: "<<airports_ptr_->at(v).getID()<<endl;
        cout<<"Airport name: "<<airports_ptr_->at(v).getName()<<endl;
        cout<<"Airport country: "<<airports_ptr_->at(v).getCountry()<<endl;
        cout<<"Airport city: "<<airports_ptr_->at(v).getCity()<<endl;
        drawPoint(airports_ptr_->at(v));
        q.pop();
        for(unsigned int i = 0 ; i < numAirports ; i++){
            if(adj_[v][i]!=0 && !(*visited)[i]){     //if adjacent to start_idx, if not visited before
                (*visited)[i] = true;           //set to visited
                q.push(i);                      //add to queue
            }
        }
    }
}

//Dijkstra: find the shortest path from one airport to the other
//input: adjMatrix, departure airport id, destination airport id
//output: vector of airport id representing the path
vector<unsigned> Graph::Dijkstra(unsigned int departure, unsigned int destination){
    //initialize distance matrix, previous node matrix, and visited matrix
    vector<double> d; //distance matrix
    vector<unsigned> p; //previous node matrix
    p.resize(numAirports);
    vector<bool> visited; //visited matrix
    double inf = std::numeric_limits<double>::max();

    for (unsigned i = 0; i < numAirports; i++){
        d.push_back(inf);
        visited.push_back(false);
    }
    d[departure] = 0;
    p.resize(numAirports);
    //initialize the priority queue
    priority_queue<pair<double, unsigned>> pq;
    pq.push(make_pair(0, departure));

    while(!pq.empty()&& pq.top().second != destination){
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

    if (pq.empty()){
        total_dist = 0;
        vector<unsigned> fail;
        fail.push_back(999999);
        return fail;
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

void Graph::drawPoint(Airport airport){
    long double lat = airport.getLatitude();
    long double lon = airport.getLongitude();
    int width = base.width();
    int height = base.height();
    int middle_x = width/2;
    int middle_y = height/2;
    unsigned int x = (int)(middle_x + lon*(width/360));
    unsigned int y = (int)(middle_y - lat*(height/180));
    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j++){
            cs225::HSLAPixel & pixel = base.getPixel(x+(i-5), y+(j-5));
            pixel.h = 0;
            pixel.s = 0;
            pixel.l = 0;
            pixel.a = 0;
        }
    }
    //base.writeToFile("test_output.png");
}
void MatrixMult (vector<vector<double>> & m1, vector<double> & m2, vector<double> & res)
{
    /** Matrix-Vector multiplication **/
    for (unsigned int i = 0; i < res.size(); i ++)
    {
        double result_row = 0;
        for (unsigned int j = 0; j < m2.size(); j ++)
        {
            result_row = result_row + m1[i][j] * m2[j];
        }
        res[i] = result_row;
    }
}

vector<unsigned> Graph::PageRank(int numIterations=100) const
{
    unsigned N = numAirports;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<uint32_t> udist;

    vector<double> v;
    double sum = 0;
    vector<double> res(numAirports);

    for(size_t i = 0; i < numAirports ; i++)
    {
        double rand = udist(rng)*1.0/UINT32_MAX;
        sum += rand;
        v.push_back(rand);
    }

    for(size_t i = 0; i < numAirports ; i++)
    {
        v[i] = v[i] / sum;
    }

    vector<double> PR(numAirports, 1);

    for (size_t row = 0; row < numAirports; row++)
    {
        int vote = 0;

        for (size_t col = 0; col < numAirports; col++)
        {
            if(adj_[row][col]>0)
            {
                vote++;
            }
           
        }

        PR[row] = 1/vote;
    }
    vector<vector<double> > M;
    for (size_t row = 0; row < numAirports; row++)
    {
        for (size_t col = 0; col < numAirports; col++)
        {
            if (adj_[col][row]>0)
            {
                M[row][col] = PR[row];
            }
           
        }
    }
    for (int i = 0; i < numIterations; i++)
    {
        MatrixMult(M, v, res);
        v = res;
    }
    vector<unsigned> Rank(numAirports,0);

    return Rank;
}
