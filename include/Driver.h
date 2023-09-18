/**
* @Author Valentijn van Overveld
*/

#ifndef DRIVER_H
#define DRIVER_H
#include <string>
#include <iostream>
#include <iomanip>

class Driver
{
    public:
        Driver(){name = "";}
        Driver(std::string name){this->name = name;}
        std::string getName(){return name;}
        void setName(std::string newName){name = newName;}
        double getArea(){return area;}
        void calcArea(std::string);
        friend std::ostream& operator<<(std::ostream& o, const Driver& d){o << d.name << "\t" << std::fixed << std::setprecision(2) << d.area << "\n"; return o;}
        bool operator<(const Driver& d){return area < d.area;}
        bool operator>(const Driver& d){return area > d.area;}

    protected:
        std::string name;
        double area = 0;
        std::string compVar = "";
};

#endif // DRIVER_H
