#pragma once
#include <string>
using namespace std;

class Airport
{
    private:
        string name_;
        string country_;
        string city_
        unsigned int id_;
        double latitude_;
        double longitude_;
    
    public:
        Airport();
        Airport(string name, unsigned int id, double latitude, double longitude);
        ~Airport();
        void setName(string name);
        void setCountry(string country);
        void setCity(string city);
        void setId(unsigned int id);
        void setLatitude(double latitude);
        void setLongitude(double longitude);
        string getName() const;
        string getCountry() const;
        string getCity() const;
        unsigned getID() const;
        double getLatitude() const;
        double getLongitude() const;
};
