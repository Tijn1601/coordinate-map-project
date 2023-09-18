/**
* @Author Valentijn van Overveld
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Driver.h"
#include "Node.h"
#include "LinkedList.h"

using namespace std;

/** Prints the LinkedList in ascending order
* @param ll the LinkedList to be printed
*/
void printAscending(LinkedList ll){
    Node* ptr = ll.head;
    while(ptr != nullptr){
        Node n = *ptr;
        cout << n.getDriver();
        ptr = ptr->getNext();
    }
}

/** Prints the LinkedList in descending order
* @param ll the LinkedList to be printed
*/
void printDecending(LinkedList ll){
    Node* ptr = ll.tail;
    while(ptr != nullptr){
        Node n = *ptr;
        cout << n.getDriver();
        ptr = ptr->getPrevious();
    }
}

/** Finds the driver whose area is provided
* @param num the area of the driver
* @param ll the LinkedList to search for the driver
* @return the driver if found
*/
string findDriver(double num, LinkedList ll){
    Node* ptr = ll.head;
    while(ptr != nullptr){
        Driver d = ptr->getDriver();
        if(d.getArea() == num)
            return d.getName();
        ptr = ptr->getNext();
    }
    return "";
}

/** Finds the area of the driver whose name is provided
* @param name the name of the driver
* @param ll the LinkedList to search for the area
* @return the area if found
*/
double findArea(string name, LinkedList ll){
    Node* ptr = ll.head;
    while(ptr != nullptr){
        Driver d = ptr->getDriver();
        if(d.getName() == name)
            return d.getArea();
        ptr = ptr->getNext();
    }
    return 0;
}

/** Reads the input file and tests each line's validity
* @param fileName the name of the file to be read
* @param drivers a vector where the names of all drivers are stored
* @param coords a vector where the coordinates of all drivers are stored
*/
void readFile(string fileName, vector<string> &drivers, vector<string> &coords){
    //creates an input and opens it
    ifstream input(fileName);

    int i = 0;
    string line;

    //while there is another line, it takes it and retrieves its values
    while(!input.eof() && i < 20){
        string name;
        string temp;
        input >> name;
        while(input >> temp){
            if(isalpha(temp[1])){
                name += " ";
                name += temp;
            } else {
                getline(input, line);
                temp += line;
                line = temp;
                break;
            }
        }

        stringstream testing(line);
        string str;
        string newStr = "";
        int commaCount = 0;
        bool isValid = true;

        //checks each character of the name to see if the character is valid
        for(unsigned long i = 0; i < name.length(); i++){
            if(!isalnum(name[i]) && name[i] != '-' && name[i] != '\'' && !isspace(name[i]))
                isValid = false;
        }

        //loops through each coordinate
        while(testing >> str){
            commaCount = 0;
            //checks each character to see if it is valid
            for(unsigned long i = 0; i < str.length(); i++){
                if(str[i] == ','){
                    commaCount++;
                    if(commaCount > 1)
                        isValid = false;
                }
                if(!isdigit(str[i]) && !isspace(str[i]) && str[i] != ',' && str[i] != '.' && str[i] != '-')
                    isValid = false;
            }
            //adds the string to the new string
            newStr += str;
            newStr += " ";
        }

        //if the output is valid, it will add both to the vectors
        if(isValid){
            drivers.push_back(name);
            coords.push_back(newStr);
            i++;
        }
    }

    //closes the ifstream
    input.close();
}

/** Main method executed the program
*/
int main()
{
    //reads in the file names
    LinkedList ll;
    string file1Name;
    string file2Name;
    cin >> file1Name >> file2Name;

    ifstream input(file1Name);
    vector<string> drivers;
    vector<string> coords;
    if(input.good()){
        readFile(file1Name, drivers, coords);

        //traverses through the coords vector to turn it into a driver object
        for(unsigned long i = 0; i < coords.size(); i++){
            if(drivers.at(i) != ""){
                Driver d(drivers.at(i));
                d.calcArea(coords.at(i));
                Node temp(d);
                Node* n = new Node(d);
                if(ll.head == nullptr){
                    ll.head = n;
                    ll.tail = n;
                } else {
                    ll.tail->setNext(n);
                    n->setPrevious(ll.tail);
                    ll.tail = n;
                }
            }
        }
    }

    //opens the 2nd file for the commands
    ifstream input2(file2Name);
    if(input2.good()){
        string line;
        string name;
        double area;
        bool sorting = false;

        //loops until there are no more lines of commands left
        while(!input2.eof()){
            sorting = false;
            name = "";
            area = -1;
            line = "";
            getline(input2, line);

            //makes sure there is something on the line
            if(line.length() > 0){
                //checks if it needs to sort
                if(line.find("sort") != string::npos){
                    sorting = true;
                    //checks if it needs to sort by area or driver
                    if(line.find("area") != string::npos){
                        ll.setSortOrder("area");
                        ll.sortNodes();
                    } else if(line.find("driver") != string::npos){
                        ll.setSortOrder("driver");
                        ll.sortNodes();
                    }
                    //checks if it should sort ascending or descending
                    if(line.find("asc") != string::npos){
                        printAscending(ll);
                    } else if(line.find("des") != string::npos){
                        printDecending(ll);
                    }
                //if not sorting, check if it needs to find a driver or an area and finds it
                } else if(isdigit(line[0])){
                    area = stod(line);
                    name = findDriver(stod(line), ll);
                } else {
                    name = line;
                    area = findArea(line, ll);
                }

                //if it is not sorting it will print out the following
                if(!sorting){
                    if(name == ""){
                        cout << area << " not found" << endl;
                    } else if(area == 0){
                        cout << name << " not found" << endl;
                    } else {
                        cout << name << "\t" << area << endl;
                    }
                }
            }
        }
    }

    //closes inputs
    input2.close();
    input.close();
    return 0;
}
