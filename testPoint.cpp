#include "Point.h"
#include <iostream>

using namespace std;

int main() {

    Point a(0, 0);//latitude, longitude
    string x = printPointXYZ(a);
    cout<<x<<endl;
    
    return 0;
}