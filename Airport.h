#pragma once
#include <string>
using namespace std;

class Airport
{
    private:
        string name_;
        unsigned int id_;
        double latitude_;
        double longitude_;
    
    public:
        Airport();
        Airport(string name, unsigned int id, double latitude, double longitude);
        ~Airport();
        void setName(string name);
        void setId(unsigned int id);
        void setLatitude(double latitude);
        void setLongitude(double longitude);
};
