// main.cpp
#include "Readfile.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Initialize the airport vector
    vector<Airport> airport;
    airport.push_back(Airport());
    // Initialize the routes vector
    vector<Route> routes;

    string filename = "airport_test.txt";
    Readfile read = Readfile();
    read.readfile_airport(airport);
    read.readfile_routes(routes);
    for (unsigned int i = 1; i < airport.size(); i ++)
    {
        cout << airport[i].getID() << " ";
        cout << airport[i].getName() << " ";
        cout << airport[i].getCity() << " ";
        cout << airport[i].getIATA() << " ";
        cout << airport[i].getICAO() << " ";
        cout << airport[i].getCountry() << " ";
        cout << airport[i].getLatitude() << " ";
        cout << airport[i].getLongitude() << endl;
    }
    cout << "\n";
    for (unsigned int j = 0; j < routes.size(); j ++)
    {
        cout << routes[j].startID << " ";
        cout << routes[j].endID << endl;
    }
    return 0;
}