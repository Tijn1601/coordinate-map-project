/**
* @Author Valentijn van Overveld
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"

class LinkedList
{
    public:
        LinkedList(){head = tail = nullptr;}
        LinkedList(Node n){head = &n; tail = &n;}
        Node getHead(){return *head;}
        void setHead(Node n){*head = n;}
        Node getTail(){return *tail;}
        void setTail(Node n){*tail = n;}
        friend std::ostream& operator<<(std::ostream& o, LinkedList& l);
        void setSortOrder(std::string str){sortOrder = str;}
        std::string getSortOrder(){return sortOrder;}
        void swapNodes(Node*, Node*);
        void sortNodes();

        Node* head;
        Node* tail;

    protected:
        std::string sortOrder;
};

#endif // LINKEDLIST_H
