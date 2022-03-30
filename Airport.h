#pragma once
#include <string>
using namespace std;

class Airport
{
    private:
        string name_;
        string country_;
        string city_;
        string iata_;
        string icao_;
        unsigned int id_;
        double latitude_;
        double longitude_;
    
    public:
        Airport();
        Airport(string name, string country, string city, unsigned int id, double latitude, double longitude);
        ~Airport();

        void setName(string name);
        void setCountry(string country);
        void setCity(string city);
        void setIATA(string iata);
        void setICAO(string icao);
        void setId(unsigned int id);
        void setLatitude(double latitude);
        void setLongitude(double longitude);

        string getName() const;
        string getCountry() const;
        string getCity() const;
        string getIATA() const;
        string getICAO() const;
        unsigned int getID() const;
        double getLatitude() const;
        double getLongitude() const;
};
