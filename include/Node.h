/**
* @Author Valentijn van Overveld
*/

#ifndef NODE_H
#define NODE_H
#include "Driver.h"

class Node
{
    public:
        Driver d;

        Node(){nextNode = prevNode = nullptr;}
        Node(Driver driver1){d = driver1; nextNode = prevNode = nullptr;}
        Node* getNext(){return nextNode;}
        void setNext(Node* n){nextNode = n;}
        Node* getPrevious(){return prevNode;}
        void setPrevious(Node* n){prevNode = n;}
        Driver getDriver(){return d;}
        void setDriver(Driver drive){d = drive;}

    protected:
        Node* nextNode;
        Node* prevNode;
};

#endif // NODE_H
