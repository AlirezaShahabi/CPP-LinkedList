
#include "LinkedList.h"
#include <iostream>


// constructor - assignment - destructor - - - - - -


// constructor
LinkedList::LinkedList():head(nullptr),length(0) {}

// copy constructor
LinkedList::LinkedList(const LinkedList& rhs) {copy_helper(rhs);}

// assignment operator (copy/move)
LinkedList& LinkedList::operator=(LinkedList rhs) {
    swap(*this, rhs);
    return *this;
}

// move constructor
LinkedList::LinkedList(LinkedList&& rhs):LinkedList() {swap(*this, rhs);}

// destructor
LinkedList::~LinkedList() {if (head != nullptr) {destruct_helper(head);}}


// public member functions: - - - - - - - - - - - - -


// return the list length
void LinkedList::get_length() const {
    std::cout << "length: " << length << std::endl;
}

// print the content of the linked list (front to end)
void LinkedList::print_forward() const {
    Node* p = head;
    if (!p) {
        std::cout << "the list is empty !" << std::endl;
    } else {
        while (p->next) {
            std::cout << p->data << " - ";
            p = p->next;
        }
        std::cout << p->data << " - ";
        std::cout << "\n - - - - - - - - - - - - - - - - - \n";
    }
}

// print the content of the linked list (end to front)
void LinkedList::print_reverse() const {
    if (!head) {
        std::cout << "the list is empty !" << std::endl;
    } else {
        print_rev_helper(head);
        std::cout << "\n - - - - - - - - - - - - - - - - - \n";
    }
}

// check if a data exists in the linked list
void LinkedList::print_node(double data) {
        int position = 0;
        Node* ans = find_helper(data, head, position);
        if (ans) {
            std::cout << ans->data << " is at index " << position;
            std::cout << std::endl;
        }
}

// update the data of an existing node
void LinkedList::update_node(double old_val, double new_val) {
        int position = 0;
        Node* ans = find_helper(old_val, head, position);
        if (ans) {ans->data = new_val;}
}

// add a new node to the beginning of the linked list
void LinkedList::add_first(double data) {
    Node* new_node = new Node(data);
    if (!head) {
        head = new_node;
        ++length;
    } else {
        new_node->next = head;
        head = new_node;
        ++length;
    }
}

// add a new node to the nth position of the linked list
// if n bigger than size, adds to the end
void LinkedList::add_middle(double data, int n) {
    Node* new_node = new Node(data);
    if (!head) {
        head = new_node;
        ++length;
    } else if (n == 0) {
        add_first(data);
    } else {
        int position = 1;
        Node* p = head;
        while (position != n && p->next) {
            p = p->next;
            ++position;
        }
        Node* temp = p->next;
        p->next = new_node;
        new_node->next = temp;
        ++length;
    }
}

// add a new node to the end of the linked list
void LinkedList::add_last(double data) {
    Node* new_node = new Node(data);
    if (!head) {
        head = new_node;
        ++length;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_node;
        ++length;
    }
}

// remove an existing node from the linked list
void LinkedList::rem_node(double data) {
    Node* delPtr = nullptr;
    bool exist = false;
    if (!head) {
        std::cout << "the list is empty!" << std::endl;
    } else if (head->data == data) {
        delPtr = head;
        head = head->next;
        delete delPtr;
        --length;
    } else {
        Node* p1 = head;
        Node* p2 = head->next;
        while (p2 && p2->data != data ) {
            p1 = p2;
            p2 = p2->next;
        }
        if (!p2) {
            std::cout << data << " is not in the list!";
            std::cout << std::endl;
        } else {
            delPtr = p2;
            p1->next = p2->next;
            delete p2;
            --length;
        }
    }
}

// reverse the list through iteration
void LinkedList::reverse_list_iterate() {
    if (head && head->next) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = head->next;
        while (next) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        head = curr;
    }
}

// reverse the list through recursion
void LinkedList::reverse_list_recurse() {
    if (head && head->next) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = head->next;
        reverse_helper(prev, curr, next);
    }
}


// private utility functions: - - - - - - - - - - - - -


// used by copy constructor. performs deep copy
void LinkedList::copy_helper(const LinkedList& obj) {
    if (!(obj.head)) {
        length = 0;
        head   = nullptr;
    } else {
        length = obj.length;
        Node* creator = new Node(obj.head->data);
        head = creator;
        Node* iterator = obj.head->next;
        while (iterator != nullptr) {
            creator->next = new Node;
            creator = creator->next;
            creator->data = iterator->data;
            iterator = iterator->next;
        }
        creator->next = nullptr;
    }
}

// used by print_node() and update_node(). look for data starting
// at search to the end of the list
LinkedList::Node* LinkedList::find_helper(double data, Node* search,
                                          int& position) {
    if (!search) {
        std::cout << "the list is empty !" << std::endl;
        return nullptr;
    } else {
        while (search->data != data && search->next) {
            search = search->next;
            ++position;
        }
        if (search->data == data) {
            return search;
        } else {
            std::cout << data << " is not in the list!" << std::endl;
            return nullptr;
        }
    }
}

// used by print_reverse()
void LinkedList::print_rev_helper(Node* temp) const {
    if (!temp) {return;}
    print_rev_helper(temp->next);
    std::cout << temp->data << " - ";
}

// used by reverse_list_recurse()
void LinkedList::reverse_helper(Node* prev, Node* curr, Node* next) {
    if (!next) {
        curr->next = prev;
        head = curr;
        return;
    }
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
    reverse_helper(prev, curr, next);
}

// used by destructor. destroys all the nodes from temp to the end 
void LinkedList::destruct_helper(Node* temp) {
    while (temp) {
        Node* delPtr = temp;
        temp = temp->next;
        delete delPtr;
    }
}


