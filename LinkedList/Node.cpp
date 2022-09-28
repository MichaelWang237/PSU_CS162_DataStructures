#include <cstring>
#include <string>
#include <iostream>
#include "Student.h"
#include "Node.h"    

using namespace std;

    Node::Node(Student* student){
        studentValue = NULL;
        next = NULL;
    }
    
    Node::~Node(){
        delete &studentValue;
        next = NULL;
    }
    
    Student* Node::getStudent(){
        return studentValue;
    }
    
    Node* Node::getNext(){
        return next;
    }
    
    void Node::setNext(Node* nextNode){
        next = nextNode;
    }

    void Node::setStudent(Student* newStudent){
        studentValue = newStudent;
    }