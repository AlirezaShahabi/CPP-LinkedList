
#include "LinkedList.h"
#include <iostream>



// constructor
LinkedList::LinkedList():head(nullptr),length(0) {}



// copy constructor
LinkedList::LinkedList(const LinkedList& obj) {
    
    if (obj.head == nullptr){
        
        head = nullptr;
        length = 0;
        
    }else{
        
        length = obj.length;
        copier(obj);
    }

}



// copy assignment operator
LinkedList& LinkedList::operator=(const LinkedList& rhs){
    
    if (head != nullptr) {
        terminator();
    }
    
    if (rhs.head == nullptr){
     
        head = nullptr;
        length = 0;
    
    }else{
        
        length = rhs.length;
        copier(rhs);

    }
    
    return *this;
}



// add a new node to link list
void LinkedList::addNode(int data) {
    
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
        
    if (head == nullptr) {
        head = newNode;
        ++length;
    }else{
                
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        ++length;
    }
}



// remove an existing node from the linked list
void LinkedList::remNode(int data) {
    Node* delPtr = nullptr;
    bool exist = false;

    if (length == 0) {
    
        std::cout << "the list is empty !" << std::endl;
        
    }else{

        if (head->data == data){

            delPtr = head;
            head = head->next;
            delete delPtr;
            --length;
        
        }else{
        
            Node* p1 = head;
            Node* p2 = head->next;

            while (p2 != nullptr) {
            
                if (p2->data == data) {
                    delPtr = p2;
                    p2 = p2->next;
                    p1->next = p2;
                    delete delPtr;
                    --length;
                    exist = true;
                    break;
                }
                p1 = p2;
                p2 = p2->next;
                
            }
            if (!exist){
                std::cout << data << " doest not exist in the list";
                std::cout << std::endl;
            }
            
        }
    }
}



// print the content of the linked list
void LinkedList::printList(){
    Node* p = head;
    
    if (p == nullptr){
        
        std::cout << "Empty list, nothing to show \n";
        
    }else{
        
        while (p->next != nullptr) {
            std::cout << p->data << " - ";
            p = p->next;
        }
        std::cout << p->data << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - \n";
    }
}



// destructor
LinkedList::~LinkedList(){
    if (head != nullptr) {terminator();}
}



// private utility function used by destructor and copy assignment
// destroys all the nodes in *this
void LinkedList::terminator(){
    Node* curr = head;
    while (curr->next != nullptr) {
        Node* delPtr = curr;
        curr = curr->next;
        delete delPtr;
    }
    delete curr;
}



// private utility function used by copy constructor and copy
// assinment operator
// It assumes there is no node in *this and the obj list has at
// least one node. It copies all node in obj into *this
void LinkedList::copier(const LinkedList& obj){
    
    Node* p1 = nullptr;
    Node* p2 = nullptr;
    
    head = new Node;
    head->data = obj.head->data;
    
    p1 = head;
    p2 = obj.head->next;
    
    while (p2 != nullptr) {
        p1->next = new Node;
        p1 = p1->next;
        p1->data = p2->data;
        p2 = p2->next;
    }
    p1->next = nullptr;
}








