#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student{
    public:
        Student(string studentName, int studentId, float studentGPA);
        ~Student();
        string getName();
        int getId();
        float getGPA();
    private:
        string name;
        int Id = 0;
        float GPA = 0;
        
};
#endif