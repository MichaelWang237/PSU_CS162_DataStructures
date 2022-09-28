#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

Node* head = NULL;
void ADD(string studentName, int studentId, float studentGPA);
void print();
void deleteNode();

int main(){
string input;
string studentName = "bob";
int studentId = 110112;
float studentGPA = 3.98;
Student* placeholder = NULL;
Student* newStudent = new Student(studentName, studentId, studentGPA);
cout << "values" << newStudent->getId() << "name" << newStudent->getName() << endl;
}
/*cout<<"Type ADD to add students, PRINT to list all students in order of ID, and DELETE to delete students."<<endl;
cin >> input;
    if(strcmp(input, "ADD") == 0){
        cout << "Name:" << endl;
        cin.getline(studentName, 100);
        cout << "ID:" << endl;
        cin >> studentId;
        cin.clear();
        cout << "GPA:" << endl;
        cin >> studentGPA;
        ADD(studentName, studentId, studentGPA);
        cin.clear();
    }

}
void ADD(char* studentName, int studentId, float studentGPA){
    Student* placeholder = NULL;
    Student* newStudent = new Student(studentName, studentId, studentGPA);
    Node* current = head;
    if(current == NULL){ //if list is empty...
        head = new Node(placeholder);
        head->setStudent(newStudent);
        else{
            while(current->getNext() != NULL){
                current = current->getNext();
            }
            current->setNext(new Node(placeholder));
            current->getNext()->setStudent(newStudent);
        }
    }
}*/
    
