#include "Airport.h"

#include <string>
using namespace std;


Airport::Airport()
{
    name_ = "";
    id_ = 0;
    latitude_ = 0;
    longitude_ = 0;
}

Airport::Airport(string name, unsigned int id, double latitude, double longitude)
{
    name_ = name;
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