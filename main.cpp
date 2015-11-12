
// tester function


#include <iostream>
#include "LinkedList.h"




int main(){
    
    LinkedList list1;
    
    // add elements
    list1.add_last(23.5);
    list1.add_last(45.6);
    list1.add_last(11.7);
    list1.add_last(30);
    list1.add_last(24);
    list1.add_last(17.4);
    list1.add_first(99);
    list1.add_first(88.5);
    list1.get_length();
    list1.print_forward();
    list1.print_reverse();
    
    // find element (first/middle/last/not exist)
    list1.print_node(88.5);
    list1.print_node(45.6);
    list1.print_node(17.4);
    list1.print_node(100);
    
    // remove element (first/middle/last/not exist)
    list1.rem_node(88.5);
    list1.rem_node(11.7);
    list1.rem_node(17.4);
    list1.rem_node(5.9);
    list1.get_length();
    list1.print_forward();
   
     // copy constructor
    LinkedList list2(list1);    
    list2.print_forward();
    
    // reverse the list (iteration)
    list2.reverse_list_iterate();
    list2.print_forward();
    
    
    LinkedList list3;
    // operation on empty list
    list3.print_forward();
    list3.rem_node(1.1);
    list3.print_node(22);
    list3.update_node(4,8.8);
    list3.reverse_list_iterate();
    
    // copy assignment operator
    list3 = list2;
    list3.print_forward();
    
    // update element
    list3.update_node(99,9.5);
    list3.update_node(19.3,6);
    list3.add_middle(20.7,3);
    list3.print_forward();
    
    // reverse the list (recursion)
    list3.reverse_list_recurse();
    list3.get_length();
    list3.print_forward();
    
    // move constructor
    LinkedList list4(std::move(list3));
    list4.print_forward();
    list3.print_forward();
    
    return 0;
}

