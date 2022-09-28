//Michael Wang - 13 April 2021 - Linked List

#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>
#include <iostream>
using namespace std;

class student
{
private:
    char* firstN;
    char* lastN;
    int ID;
    float GPA;
public:
    student(char* first, char* last, int idNum, float grade);
    ~student();
    char* getFirst();
    char* getLast();
    int getID();
    float getGrade();
};

#endif
