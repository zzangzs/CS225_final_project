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
#include "Graph.h"

using std::priority_queue;
using std::map;
using std::cout;
using std::endl;

/** 
    Default Graph constructor.
**/
Graph::Graph(const vector<Route> & routes, const vector<Airport> & airports) {
    // initialize the pointers
    airports_ptr_ = &airports;
    routes_ptr_ = &routes;

    // initialize number of airports and routes
    numAirports = airports.size();
    unsigned numRoutes = routes.size();

    // initialized the adjacent matrix
    adj_.resize(numAirports,vector<double>(numAirports,0));
  
    // build routesMap from routes
    map<pair<unsigned,unsigned>,double> routesMap_;
    for (const Route & route : routes) {
        routesMap_[make_pair(route.getStartID(),route.getEndID())]=route.getDist();
    }
    
    // build adjacent matrix using routesMap
    for (size_t row = 0; row < numAirports; row++) {
        for (size_t col = 0; col < numAirports; col++) {
            pair<unsigned,unsigned> IDs = make_pair(airports[row].getID(), airports[col].getID());
            bool isIn = routesMap_.find(IDs) != routesMap_.end();
            if (isIn) {
                adj_[row][col] = routesMap_[IDs];
            } else {
                adj_[row][col] = 0;
            }
        }  
    }
}

/**
 * Helper funtction to check the Graph constructor before implementing BFS
 */
void Graph::printGraph() const {  
    for (size_t i = 0; i < airports_ptr_->size(); i++) {
        cout << "Airport " << airports_ptr_->at(i).getID()+1 <<" "<<airports_ptr_->at(i).getName()<< " is adjacent to: " << endl;
        for (size_t j = 0; j < airports_ptr_->size(); j++) {
            if (adj_[i][j]!=0) {
                cout << "    Airport " << airports_ptr_->at(j).getID()+1<<" "<<airports_ptr_->at(j).getName()<< " with a distance of " << adj_[i][j] << endl;
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

// Descending sort the vector while keep track of the original indices
vector<size_t> sort_indices(const vector<double> & v) {

  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});

  return idx;
}

/**
 * Simplified PageRank Algorithm
 */
vector<size_t> Graph::simplifiedPageRank(int top) {
    vector<size_t> Rank;

    // assume each page has equal weight at the beginning
    double initial_PR = 1.0/numAirports;
    vector<double> PR(numAirports,initial_PR);

    // initialize the number of outbound links for each airport
    vector<double> L(numAirports,0);
    for (size_t row = 0; row < numAirports; row++) {
        int num_zeros = count(adj_[row].begin(), adj_[row].end(), 0);
        L[row] = numAirports-num_zeros;
    }

    // update weight of each airport using PR(i) = sum of PR(j)/L(j)
    //     where j is each airport that has a route ending in i
    for (size_t i = 0; i < PR.size(); i++) {
        double income = 0;
        for (size_t j = 0; j < PR.size(); j++) {
            if (adj_[j][i]>0) {
                income += initial_PR/L[j];
            }   
        }
        PR[i] = income;      
    }
    cout<<endl;
    cout<<"PageRank value for each Airport is:"<<endl;
    cout<<"    ";
    printVec(PR);

    // sort the weight of airports and keep track of the indices
    int count = 0;
    for (auto i: sort_indices(PR)) {
        if (count==top) {
            break;
        }
        Rank.push_back(i);
        count++;
    }
    return Rank;
}


// void MatrixMult (vector<vector<double>> & m1, vector<double> & m2, vector<double> & res)
// {
//     for (unsigned int i = 0; i < res.size(); i ++)
//     {
//         double result_row = 0;
//         for (unsigned int j = 0; j < m2.size(); j ++)
//         {
//             result_row = result_row + m1[i][j] * m2[j];
            
//         }
//         res[i] = result_row;
//         cout<<"res"<<i<<" is "<<result_row<<endl;
//     }
// }

// vector<vector<double> > Graph::transpose(vector<vector<double> > & V2D) {
//     vector<vector<double> > temp( V2D.size(), vector<double> (V2D.size()) );
//     for (size_t i = 0; i < V2D.size(); i++)
//     {
//         for (size_t j = 0; j < V2D[i].size(); j++)
//         {
//             temp[i][j] = V2D[j][i];
//         }
        
//     }
//     return temp;
// }


// vector<size_t> Graph::PageRank(int numIterations)
// {
//     vector<size_t> Rank;

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
    // for (auto i: sort_indices(v)) {
    //     Rank.push_back(i);
    // }

//     return Rank;
// }