#ifndef NODE_H
#define NODE_H

#include <cstring>
#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class Node{
public:
    Node(Student* student);
    ~Node();
    Student* getStudent();
    Node* getNext();
    void setNext(Node* nextNode);
    void setStudent(Student* newStudent);
private:
    Student* studentValue;
    Node* next;
};
#endif