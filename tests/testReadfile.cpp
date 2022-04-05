#include "../cs225/catch/catch.hpp"

#include <cmath>
#include <vector>

#include "../Airport.h"
#include "../Readfile.h"
#include "../Route.h"

//using namespace std;

//testfile1 for read_airport data set: airport_test.txt 
//testfile1 for read_routes data set: routes_test.txt
//edit readfile.cpp (add new input variable for testfile name) before running testReadfile.cpp
// string airport_testfile = "airport_test.txt";
// string route_testfile = "routes_test.txt";

// std::vector<Airport> airports;
// //airports.push_back(Airport());

// std::vector<Route> routes;

// Readfile read = Readfile();
// read.readfile_airport(airports);
// read.readfile_routes(routes);

std::vector<Airport> airport_init(){
    string airport_testfile = "airport_test.txt";

    std::vector<Airport> airports;
    //airports.push_back(Airport());
    Readfile read = Readfile();
    read.readfile_airport(airports);
    return airports;
}

std::vector<Route> routes_init(){
    std::vector<Route> routes;
    string route_testfile = "routes_test.txt";

    Readfile read = Readfile();
    read.readfile_routes(routes);
    return routes;
}

TEST_CASE("Test readfile_airport", "[weight=10][part1]")
{
    std::vector<Airport> airports = airport_init();
    REQUIRE("Kugaaruk Airport" == airports[0].getName());
    REQUIRE("Baker Lake Airport" == airports[3].getName());
	REQUIRE("Canada" == airports[0].getCountry());
    REQUIRE("Baie Comeau" == airports[1].getCity());
    REQUIRE(1 == airports[0].getID());
    REQUIRE(4 == airports[3].getID());
    REQUIRE(airports[0].getLatitude() == 68.534401);
    REQUIRE(airports[2].getLongitude() == -70.99639892578125);
    REQUIRE("YBC" == airports[1].getIATA());
    REQUIRE("CYBG" == airports[2].getICAO());
}

//dist is not tested
TEST_CASE("Test readfile_routes", "[weight=10][part1]")
{
    std::vector<Route> routes = routes_init();
    REQUIRE(1 == routes[0].startID);
    REQUIRE(3 == routes[1].startID);
    REQUIRE(1 == routes[2].startID);
    REQUIRE(4 == routes[3].startID);
    REQUIRE(2 == routes[0].endID);
    REQUIRE(4 == routes[1].endID);
    REQUIRE(3 == routes[2].endID);
    REQUIRE(2 == routes[3].endID);
}
