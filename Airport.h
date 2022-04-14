#pragma once
#include <string>
using namespace std;

/*
struct Route
{
    unsigned int startID;
    unsigned int endID;
    long double dist;
    bool isLabeled;
};
*/

class Airport
{
    private:
        string name_;
        string country_;
        string city_;
        string iata_;
        string icao_;
        unsigned int id_;
        long double latitude_;
        long double longitude_;
    
    public:
        Airport();
        Airport(string name, string country, string city, unsigned int id, long double latitude, long double longitude);
        ~Airport();

        void setName(string name);
        void setCountry(string country);
        void setCity(string city);
        void setIATA(string iata);
        void setICAO(string icao);
        void setId(unsigned int id);
        void setLatitude(long double latitude);
        void setLongitude(long double longitude);

        string getName() const;
        string getCountry() const;
        string getCity() const;
        string getIATA() const;
        string getICAO() const;
        unsigned int getID() const;
        long double getLatitude() const;
        long double getLongitude() const;
};
