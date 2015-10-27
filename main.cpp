
// tester function


#include <iostream>
#include "LinkedList.h"




int main(){
    
    LinkedList list1;
    
    // add elements
    list1.addNode(23);
    list1.addNode(45);
    list1.addNode(11);
    list1.addNode(30);
    list1.addNode(24);
    list1.addNode(17);
    
    list1.printList();
    
    // remove the first element
    list1.remNode(23);
    list1.printList();
    // remove the middle element
    list1.remNode(30);
    list1.printList();
    // remove the last element
    list1.remNode(17);
    list1.printList();
    // remove an element that does not exist
    list1.remNode(23);

    // copy constructor
    LinkedList list2(list1);    
    list2.printList();
    
    LinkedList list3;
    list3.printList();
    
    // copy assignment operator
    list3 = list2;
    list3.printList();
        
    return 0;
}

