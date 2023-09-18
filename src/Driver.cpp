/**
* @Author Valentijn van Overveld
*/

#include "Driver.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

/** Calculates the area from coordinates
* @param coords the coordinates to be turned into an area
*/
void Driver::calcArea(string coords)
{
    replace(coords.begin(), coords.end(), ',', ' ');
    stringstream ss(coords);

    //turn it into x and y coordinates
    vector<double> vect;
    string x;
    string y;
    while(ss >> x >> y){
        vect.push_back(stod(x));
        vect.push_back(stod(y));
    }

    unsigned long lastIdx = vect.size() - 1;
    double newArea = 0.0;
    unsigned long j = lastIdx - 1;

    //calculates the area of the coordinates
    for (unsigned long i = 0; i < lastIdx; i += 2)
    {
       newArea += (vect.at(j) + vect.at(i)) * (vect.at(j + 1) - vect.at(i + 1));
       j = i;
    }

    area = abs(newArea / 2.0);
}
