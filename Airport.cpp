#include "Airport.h"

#include <string>
using namespace std;


Airport::Airport()
{
    name_ = "";
    country_ = "";
    city_ = "";
    id_ = 0;
    latitude_ = 0;
    longitude_ = 0;
}

Airport::Airport(string name, string country, string city, unsigned int id, double latitude, double longitude)
{
    name_ = name;
    country_ = country;
    city_ = city;
    id_ = id;
    latitude_ = latitude;
    longitude_ = longitude;
}

Airport::~Airport()
{

}

void Airport::setName(string name)
{
    name_ = name;
}

void Airport::setCountry(string country)
{
    country_ = country;
}

void setCity(string city)
{
    city_ = city;
}

void Airport::setId(unsigned int id)
{
    id_ = id;
}

void Airport::setLatitude(double latitude)
{
    latitude_ = latitude;
}

void Airport::setLongitude(double longitude)
{
    longitude_ = longitude;
}

string Airport::getName() const
{
    return name_;
}

string getCountry() const
{
    return country_;
}

string getCity() const
{
    return city_;
}

unsigned Airport::getID() const
{
    return id_;
}

double Airport::getLatitude() const
{
    return latitude_;
}

double Airport::getLongitude() const
{
    return longitude_;
}