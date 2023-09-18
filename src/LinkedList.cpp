/**
* @Author Valentijn van Overveld
*/

#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

/** Overloads the output operator
* @param o the ostream where the ouput has to be sent
* @param l the LinkedList that contains the nodes
* @return the ostream
*/
ostream& operator<<(ostream& o, LinkedList& l){
    Node n = l.getHead();
    while(n.getNext() != nullptr){
        cout << n.getDriver();
        n.setNext(n.getNext());
    }
    return o;
}

/** Swaps the nodes
* @param n1 the first node to be swapped
* @param n2 the second node to be swapped
*/
void LinkedList::swapNodes(Node* n1, Node* n2){
    Driver temp = n1->getDriver();
    n1->setDriver(n2->getDriver());
    n2->setDriver(temp);
}

/** A bubble sort to sort the nodes
*/
void LinkedList::sortNodes(){
    bool swapped = true;
    Node* ptr, *next;
    while(swapped){
        swapped = false;
        ptr = head;
        next = ptr->getNext();
        while(ptr->getNext() != nullptr){
            if(getSortOrder() == "driver"){
                if(ptr->getDriver().getName() > next->getDriver().getName()){
                    swapped = true;
                    swapNodes(ptr, next);
                }
            } else if(getSortOrder() == "area"){
                if(ptr->getDriver().getArea() > next->getDriver().getArea()){
                    swapped = true;
                    swapNodes(ptr, next);
                }
            }
            ptr = ptr->getNext();
            next = next->getNext();
        }
    }
}
