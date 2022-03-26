// "Point.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string.h>

using namespace std;

struct Point {
    double x;
    double y;
    double z;
    Point() : Point(0, 0) { }
 
    //construct a point by xyz coordinates
    Point(double x, double y, double z) : x(x), y(y), z(z) { } 

    //construct a point by latitude and longitude
    Point(double latitude, double longitude){//
        double radLat = latitude * M_PI / 180; //convert to radius
        double radLon = longitude * M_PI / 180;
        double radius = 6371393; //avarage earth radius

        y = radius * sin(radLat);
        double temp = radius * cos(radLat);
        x = temp * sin(radLon);
        z = temp * cos(radLon);
    }

    //return a xyz coordinates of a point from its latitude and longtitude
    Point LatLongToXYZ(double latitude, double longitude){
        double radLat = latitude * M_PI / 180; //convert to radius
        double radLon = longitude * M_PI / 180;
        double radius = 6371393; //avarage earth radius

        double y = radius * sin(radLat);
        double temp = radius * cos(radLat);
        double x = temp * sin(radLon);
        double z = temp * cos(radLon);
        return Point(x,y,z);
    }

    
};

string printPointXYZ(Point a){
    return "XYZ Position: x: " + to_string(a.x) + " y: " + to_string(a.y) + " z: " + to_string(a.z);
}
