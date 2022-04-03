#include <cmath>

#include "Airport.h"

//set airport by default constructor
TEST_CASE("empty airport", "[weight=10][part1]")
{
    Airport airport();

    REQUIRE("" == airport.getName());
	REQUIRE("" == airport.getCountry());
    REQUIRE("" == airport.getCity());
    REQUIRE(0 == airport.getID());
    REQUIRE(0 == airport.getLatitude());
    REQUIRE(0 == airport.getLongitude());
    REQUIRE("" == airport.getIATA());
    REQUIRE("" == airport.getICAO());
}

//set airport by constructor
TEST_CASE("airport 1 ", "[weight=10][part1]")
{
    Airport airport("Ísafjörður Airport","Iceland", "Isafjordur",0,66.05809783935547,-23.135299682617188);
    airport.setIATA("IFJ");
    airport.setICAO("BIIS");

    const double eps = 1e-8;//error for comparing doubles

    REQUIRE("Ísafjörður Airport" == airport.getName());
	REQUIRE("Iceland" == airport.getCountry());
    REQUIRE("Isafjordur" == airport.getCity());
    REQUIRE(0 == airport.getID());
    REQUIRE(eps >= abs(airport.getLatitude() - 66.05809783935547);
    REQUIRE(eps >= abs(airport.getLongitude() + 23.135299682617188);
    REQUIRE("IFJ" == airport.getIATA());
    REQUIRE("BIIS" == airport.getICAO());
}

//set airport by default constructor and then set its value
TEST_CASE("airport 2 ", "[weight=10][part1]")
{
    Airport airport();
    airport.setName("St. Anthony Airport");
    airport.setCountry("Canada");
    airport.setCity("St. Anthony");
    airport.setId(1);
    airport.setLatitude(51.3918991089);
    airport.setLongitude(-56.083099365200006);
    airport.setIATA("YAY");
    airport.setICAO("CYAY");

    const double eps = 1e-8;//error for comparing doubles

    REQUIRE("St. Anthony Airport" == airport.getName());
	REQUIRE("Canada" == airport.getCountry());
    REQUIRE("St. Anthony" == airport.getCity());
    REQUIRE(1 == airport.getID());
    REQUIRE(eps >= abs(airport.getLatitude() - 51.3918991089);
    REQUIRE(eps >= abs(airport.getLongitude() + 56.083099365200006);
    REQUIRE("YAY" == airport.getIATA());
    REQUIRE("CYAY" == airport.getICAO());
}

//set the airport by constructor with airport 1 value, and then set new value of airport 2 to the airport2
TEST_CASE("airport 3 ", "[weight=10][part1]")
{
    Airport airport("Zenata – Messali El Hadj Airport","Algeria", "Tlemcen", 3, 35.0167007446, -1.45000004768);
    airport.setIATA("TLM");
    airport.setICAO("DAON");


    airport.setName("St. Anthony Airport");
    airport.setCountry("Canada");
    airport.setCity("St. Anthony");
    airport.setId(1);
    airport.setLatitude(51.3918991089);
    airport.setLongitude(-56.083099365200006);
    airport.setIATA("YAY");
    airport.setICAO("CYAY");

    const double eps = 1e-8;//error for comparing doubles

    REQUIRE("St. Anthony Airport" == airport.getName());
	REQUIRE("Canada" == airport.getCountry());
    REQUIRE("St. Anthony" == airport.getCity());
    REQUIRE(1 == airport.getID());
    REQUIRE(eps >= abs(airport.getLatitude() - 51.3918991089);
    REQUIRE(eps >= abs(airport.getLongitude() + 56.083099365200006);
    REQUIRE("YAY" == airport.getIATA());
    REQUIRE("CYAY" == airport.getICAO());
}