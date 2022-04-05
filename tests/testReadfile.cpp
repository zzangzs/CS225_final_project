#include "../cs225/catch/catch.hpp"

#include <cmath>
#include <vector>

#include "../Airport.h"
#include "../Readfile.h"
#include "../Route.h"

using namespace std;

//testfile1 for read_airport data set: airport_test.txt 
//testfile1 for read_routes data set: routes_test.txt
//edit readfile.cpp (add new input variable for testfile name) before running testReadfile.cpp
string airport_testfile = "airport_test.txt";
string route_testfile = "routes_test.txt";

vector<Airport> airports;
airports.push_back(Airport());

vector<Route> routes;

Readfile read = Readfile();
read.readfile_airport(airports);
read.readfile_routes(routes);

TEST_CASE("Test readfile_airport", "[weight=10][part1]")
{
    REQUIRE("Kugaaruk Airport" == airports[0].getName());
    REQUIRE("Baker Lake Airport" == airports[3].getName());
	REQUIRE("Canada" == airports[0].getCountry());
    REQUIRE("Baie Comeau" == airports[1].getCity());
    REQUIRE(1 == airports[0].getID());
    REQUIRE(4 == airports[3].getID());
    REQUIRE(compareDouble(airports[0].getLatitude(), 68.534401) == true);
    REQUIRE(compareDouble(airports[2].getLongitude(), -70.99639892578125) == true);
    REQUIRE("YBC" == airports[1].getIATA());
    REQUIRE("CYBG" == airports[2].getICAO());
}

//dist is not tested
TEST_CASE("Test readfile_routes", "[weight=10][part1]")
{
    REQUIRE(1 == routes[0].startID);
    REQUIRE(3 == routes[1].startID);
    REQUIRE(1 == routes[2].startID);
    REQUIRE(4 == routes[3].startID);
    REQUIRE(2 == routes[0].endID);
    REQUIRE(4 == routes[1].endID);
    REQUIRE(3 == routes[2].endID);
    REQUIRE(2 == routes[3].endID);
}
