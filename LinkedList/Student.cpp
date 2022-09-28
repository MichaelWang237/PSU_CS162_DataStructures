#include <cstring>
#include "student.h"

using namespace std;

Student::Student(string studentName, int studentId, float studentGPA){
    name = studentName;
    Id = studentId;
    GPA = studentGPA;
}
Student::~Student(){
    delete &name;
}
string Student::getName(){
    return name;
}
int Student::getId(){
    return Id;
}
float Student::getGPA(){
    return GPA;
}
