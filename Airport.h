/**
 * @file Airport.h
 *
 * @author DHREV
 */
#pragma once

#include <string>;

using std::string;

class Airport
{
    private:
        string Name_;
        unsigned ID_;
        
        //may be useless
        double Latitude_;
        double Longitude_;
    
    public:
        Airport();
};
