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
#include <cmath>

using std::map;
using std::vector;
using std::pair;
using std::cout;
using std::endl;
using std::priority_queue;
using std::stable_sort;
using std::iota;

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

vector<vector<double> > Graph::transpose(vector<vector<double> > & V2D) {
    vector<vector<double> > temp( V2D.size(), vector<double> (V2D.size()) );
    for (size_t i = 0; i < V2D.size(); i++)
    {
        for (size_t j = 0; j < V2D[i].size(); j++)
        {
            temp[i][j] = V2D[j][i];
        }
        
    }
    return temp;
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
        // cout<<"Airport id: "<<airports_ptr_->at(v).getID()<<endl;
        // cout<<"Airport name: "<<airports_ptr_->at(v).getName()<<endl;
        // cout<<"Airport country: "<<airports_ptr_->at(v).getCountry()<<endl;
        // cout<<"Airport city: "<<airports_ptr_->at(v).getCity()<<endl;
        drawPoint(airports_ptr_->at(v), 0, 0, 0, 1);
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
                    pq.push(make_pair( -d[i], i)); //push neighbors to pq, push negative dist as it is Max Priority queue
                }
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

void Graph::drawPoint(Airport airport, double h, double s, double l, double a){
    long double lat = airport.getLatitude();
    long double lon = airport.getLongitude();
    int width = base.width();
    int height = base.height();
    long double middle_x = width/2.0;
    long double middle_y = height/2.0;
    int x = floor(middle_x + lon*((double)width/360.0));
    int y = floor(middle_y - lat*((double)height/180.0));
    if(x > width - 2 || x < 2 || y > height - 2 || y < 2){
        return;
    }
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            cs225::HSLAPixel & pixel = base.getPixel(x+(i-1), y+(j-1));
            pixel.h = h;
            pixel.s = s;
            pixel.l = l;
            pixel.a = a;
        }
    }
}

void Graph::draw_rank(vector<size_t> rk){
    int size = rk.size();
    cs225::PNG icon;
    icon.readFromFile("airport3.png");
    int w = icon.width();
    int h = icon.height();
    int icon_mid_x = floor(w/2);
    int icon_mid_y = floor(h/2);
    for(int i = 0 ; i < size ; i++){
        long double lat = airports_ptr_->at(rk[i]).getLatitude();
        long double lon = airports_ptr_->at(rk[i]).getLongitude();
        int width = base.width();
        int height = base.height();
        long double middle_x = width/2.0;
        long double middle_y = height/2.0;
        int x = floor(middle_x + lon*((double)width/360.0));
        int y = floor(middle_y - lat*((double)height/180.0));
        for(int j = 0 ; j < w ; j++){
            for(int k = 0 ; k < h ; k++){
                if(icon.getPixel(j,k).a == 0){
                    continue;
                }
                cs225::HSLAPixel & pixel = base.getPixel(x+(j-icon_mid_x), y+(k-icon_mid_y));
                pixel.h = 0;
                pixel.s = 1;
                pixel.l = 0.5;
                pixel.a = icon.getPixel(j,k).a;
            }
        }
    }
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
        cout<<"res"<<i<<" is "<<result_row<<endl;
    }
}

// Descending sort the vector while keep track of the original indexes
vector<size_t> sort_indexes(const vector<double> & v) {

  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});

  return idx;
}

// Simplified version of PageRank
// top is default 10
vector<size_t> Graph::simplifiedPageRank(int top) {
    vector<size_t> Rank;

    double initial_PR = 1.0/numAirports;
    vector<double> PR(numAirports,initial_PR);
    vector<double> L(numAirports,0);

    for (size_t row = 0; row < numAirports; row++)
    {
        int num_zeros = count(adj_[row].begin(), adj_[row].end(), 0);
        L[row] = numAirports-num_zeros;
    }

    // cout<<"Outgoing links: ";
    // printVec(L);
    // cout<<endl;


    for (size_t i = 0; i < PR.size(); i++)
    {
        double income = 0;
        for (size_t j = 0; j < PR.size(); j++)
        {
            if (adj_[j][i]>0)
            {
                income += initial_PR/L[j];
            }
            
        }
        PR[i] = income;
        
    }
    // cout<<"PageRank: ";
    // printVec(PR);
    // cout<<endl;
    int count = 0;
    for (auto i: sort_indexes(PR)) {
        if (count==top)
        {
            break;
        }
        Rank.push_back(i);
        count++;
    }

    return Rank;
    
}


vector<size_t> Graph::PageRank(int numIterations)
{
    vector<size_t> Rank;

    // unsigned N = numAirports;

    // std::random_device dev;
    // std::mt19937 rng(dev());
    // std::uniform_int_distribution<uint32_t> udist;

    // vector<double> v;
    // double sum = 0;
    // vector<double> res(5);

    // for(size_t i = 0; i < 5 ; i++)
    // {
    //     double rand = udist(rng)*1.0/UINT32_MAX;
    //     sum += rand;
    //     v.push_back(rand);
    // }
    // cout<<"Original v = "<<endl;
    // printVec(v);

    // for(size_t i = 0; i < 5 ; i++)
    // {
    //     v[i] = v[i] / sum;
    // }
    // cout<<"Normalized v = "<<endl;
    // printVec(v);

    // vector<double> PR(numAirports, 1);

    // for (size_t row = 0; row < numAirports; row++)
    // {
    //     int vote = 0;

    //     for (size_t col = 0; col < numAirports; col++)
    //     {
    //         if(adj_[row][col]>0)
    //         {
    //             vote++;
    //         }
           
    //     }

    //     if (vote!=0) PR[row] = 1.0/vote;
    // }

    // cout<<"PR = "<<endl;
    // printVec(PR);

    // vector<vector<double> > M(numAirports,vector<double>(numAirports,0));

    // for (size_t col = 0; col < numAirports; col++)
    // {
    //     for (size_t row = 0; row < numAirports; row++)
    //     {
    //         if (adj_[col][row]>0)
    //         {
    //             M[row][col] = PR[col];
    //         }
           
    //     }
    // }
    // cout<<"M = "<<endl;
    // for (size_t i = 0; i < M.size(); i++)
    // {
    //     printVec(M[i]);
    //     cout<<endl;
        
    // }

    // // vector<vector<double> > M_hat
    // // {
    // //     {0, 0, 0, 0, 1},
    // //     {0.5, 0, 0, 0, 0},
    // //     {0.5, 0, 0, 0, 0},
    // //     {0, 1, 0.5, 0, 0},
    // //     {0, 0, 0.5, 1, 0}
    // // };

    // for (int i = 0; i < numIterations; i++)
    // {
    //     MatrixMult(M, v, res);
    //     v = res;
    // }
    // cout<<"Final v = "<<endl;
    // printVec(v);
    // for (auto i: sort_indexes(v)) {
    //     Rank.push_back(i);
    // }

    return Rank;
}

cs225::PNG Graph::getBasePic(){
    return base;
}

void Graph::drawLine(vector<unsigned> path){
    int size = path.size();
    int width = base.width();
    int height = base.height();
    long double middle_x = width/2.0;
    long double middle_y = height/2.0;
    for(int i = 1 ; i < size ; i++){
        long double lat_1 = airports_ptr_->at(path[i]).getLatitude();
        long double lon_1 = airports_ptr_->at(path[i]).getLongitude();
        int x_1 = floor(middle_x + lon_1*((double)width/360.0));
        int y_1 = floor(middle_y - lat_1*((double)height/180.0));
        long double lat_2 = airports_ptr_->at(path[i-1]).getLatitude();
        long double lon_2 = airports_ptr_->at(path[i-1]).getLongitude();
        int x_2 = floor(middle_x + lon_2*((double)width/360.0));
        int y_2 = floor(middle_y - lat_2*((double)height/180.0));
        double x_start, x_end, y_start, y_end;
        if(x_2 > x_1){
            x_start = x_1;
            y_start = y_1;
            x_end = x_2;
            y_end = y_2;
        }else{
            x_start = x_2;
            y_start = y_2;
            x_end = x_1;
            y_end = y_1;
        }
        long double slope;
        if(x_end != x_start){
            slope = ((long double)(y_end - y_start))/((long double)(x_end - x_start));
        }else{
            slope = (y_end - y_start)/std::abs(y_end - y_start);
        }
        while(x_start != x_end){
            ++x_start;
            y_start = y_start + slope;
            cs225::HSLAPixel & pixel = base.getPixel((int)x_start, (int)y_start);
            pixel.h = 240;
            pixel.s = 1;
            pixel.l = 0.25;
            pixel.a = 1;
        }
    }
}