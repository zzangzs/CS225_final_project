#include "Airport.h"
#include "Route.h"

#include <string>
#include <vector>
#include <map>
using namespace std;

class Readfile
{
    private:
        /*
            The map 'id_change' is used to record potential airport ID changes. 
            It maps the original IDs from the input file to the actual assigned IDs
        */
        map<unsigned int, unsigned int> id_change;
        void parse_correct_airport(string s, vector<Airport*> & airport_vec);
        void parse_correct_routes(string s, vector<Route*> & routes_vec);

    public:
        Readfile();
        ~Readfile();
        void readfile_airport(vector<Airport*> & airport_vec);
        void readfile_routes(vector<Route*> & routes_vec);
};

