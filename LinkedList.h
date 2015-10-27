
#ifndef LinkedList_H
#define LinkedList_H


class LinkedList{

private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
    int length;
    // private utility functions
    void terminator();
    void copier(const LinkedList&);

public:
    // constructor - assignment operator
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    // member functions
    void addNode(int);
    void remNode(int);
    void printList();
    // destructor
    ~LinkedList();
};


#endif