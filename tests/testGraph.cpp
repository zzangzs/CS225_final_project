#include "../Graph.h"
#include "../cs225/catch/catch.hpp"
#include "../Airport.h"
#include "../Readfile.h"

TEST_CASE("test_graph_simple", "[weight=10]")
{
    vector<Route> routes;
    vector<Airport> airports;
    airports.push_back(Airport());
    for(int i = 0 ; i < 3 ; i++){
        Route route;
        route.startID = i;
        route.endID = (i+1)%3;
        route.isLabeled = 0;
        route.dist = 5 + i;
        routes.push_back(route);
        //airports.push_back(Airport());
        string name = "Tdfnri";
        Airport a(name, "U.S.", "Champaign", i, 100, 200);
        airports.push_back(a);
    }
    Graph g(routes, airports);
    g.printGraph();
}
