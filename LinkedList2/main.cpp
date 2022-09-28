//Michael Wang - 13 April 2021 - Linked List Part 2
//This project allows the user to create a database of students and includes various characteristics
#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"
#include "node.h"
using namespace std;


node* add(node* head, node* ohead, student* newStudent);
node* del(node* prev, node* head, node* ohead, int IDnum);
void print(node* head);
void average(node* head, float totalGPA, int totalStudents);

int main(){
    node* head = NULL;
    bool running = true;
    cout << "Welcome to yet another student list!" << endl;
    while (running == true)
    {
        char input[30];
        cout << "Please enter one of the following commands: ADD, PRINT, DELETE, AVERAGE, QUIT" << endl;
        cin >> input;
        if(strcmp(input, "ADD") == 0)
        {
            //takes user info to create a new student
            char* firstName = new char[100];
            char* lastName = new char[100];
            int idNumber = 0;
            float grade = 0.0;
            cout << "Command registered: ADD" << endl;
            cout << "enter student's first name: " << endl;
            cin.clear();
            cin.ignore(9999, '\n');
            cin.getline(firstName, 100);
            cout << "enter student's last name:" << endl;
            cin.getline(lastName, 100);
            cout << "enter student ID number:" << endl;
            cin >> idNumber;
            cout << "enter student gpa" << endl;
            cin.clear();
            cin.ignore(9999, '\n');
            cin >> grade;
            //feeds new student into the add function
            student* nnStudent = new student(firstName, lastName, idNumber, grade);
            head = add(head, head, nnStudent);
        }
        else if(strcmp(input, "DELETE") == 0)
        {
            //asks user for ID, then feeds it into the delete function
            int studentID = 0;
            cout << "Enter student ID Number: " << endl;
            cin >> studentID;
            head = del(NULL, head, head, studentID);
        }
        else if(strcmp(input, "PRINT") == 0)
        {
            //calls print to output the data of the linked list
            print(head);
        }
        else if(strcmp(input, "QUIT") == 0)
        {
            //quits the loop
            running = false; 
            cout << "successfully quit" << endl;
            break;
        }
        else if(strcmp(input, "AVERAGE") == 0)
        {
            //calls the average function to output average
            average(head, 0, 0);
        }
        else
        {
            //in case the user enters something invalid
            cout << "Please enter a valid command" << endl;
        }
    }
    return 0;
}

node* add(node* head, node* ohead, student* newStudent) 
//PARAMETERS: head is used to step through the list, ohead is the original head which is never changed in the function
//newStudent is the student that the user wants to add to the list
{
    node* temp = new node(newStudent);
    if(head == NULL){
        //if the list is empty, make temp the head of the list
        cout << "Successfully added student with follwing parameters: " << newStudent->getFirst() 
        << ", " << newStudent->getLast() << ", " << newStudent->getID() << ", " << newStudent->getGrade() << endl;
        return temp;
    }
    else if(head != NULL && temp->getStudent()->getID() < ohead->getStudent()->getID())
    {
        //if the new student's ID is less than the head, make temp the new head
        temp->setNext(ohead);
        cout << "Successfully added student with follwing parameters: " << newStudent->getFirst() 
        << ", " << newStudent->getLast() << ", " << newStudent->getID() << ", " << newStudent->getGrade() << endl;
        return temp;
    }
    if(head->getNext() == NULL || head->getNext()->getStudent()->getID() >= newStudent->getID())
    {
        //if the new student's ID is greater than the head, temp is connected with the node originally after head
        //then, head is connected to temp, resulting in temp being inserted between head and the node after
        //this means that new students are added in such a way to create a list where the ID numbers are ordered least to greatest
        temp->setNext(head->getNext());
        head->setNext(temp);
        cout << "Successfully added student with follwing parameters: " << newStudent->getFirst() 
        << ", " << newStudent->getLast() << ", " << newStudent->getID() << ", " << newStudent->getGrade() << endl;
        return ohead;
    }
    else
    {
        //if the IDs after head are not greater than than the one stored in temp, recursively call add
        //using recursion will eventually scan through the entire linked list for a place to add the new student
        add(head->getNext(), ohead, newStudent);
    }
    return ohead;
}

node* del(node* prev, node* head1, node* ohead, int idNumber)
{
    //PARAMETERS: prev is the previous node in relation to head1, which is connected to the node after head1 in the event head1 is deleted
    //head1 is the node used to step through the loop
    //ohead is original head, it is not changed and is returned when the list is empty or the end of the list is reached without finding the student
    //idNumber is the ID number of the student
    bool studentFound = false;
    node* head = head1;
    if(head != NULL)
    {  
        if(head->getStudent()->getID() == idNumber && prev == NULL)
        {
            //if there is a match and prev is NULL, it means head1 is the head of the list
            //in this case, the head is set to the next node in the list
            //then the original head is deleted and the new head is returned
            studentFound = true;
            head = head1->getNext();
            head1->~node();
            cout << "delete successful" << endl;
            return head;
        }
        else if(head->getStudent()->getID() == idNumber){
            //if there is a match prev is set to the node after head, leaving head cut off from the rest of the list
            //head is deleted
            prev->setNext(head->getNext());
            head->~node();
            cout << "delete successful" << endl;
            studentFound = true;
            return ohead;
        }
        if(studentFound == false && head->getNext() != NULL){
            del(head, head->getNext(), ohead, idNumber);
        }
        else if(studentFound == false && head->getNext() == NULL)
        {
            cout << "Student not found! Please make sure you have entered the ID number correctly" << endl;
            return ohead;
        }
    }
    else{
        //if head is NULL, the list is empty, the original head is returned
        cout << "List is empty! Please make sure there are students to delete" << endl;
        return ohead;
    }
    return ohead;
}

void print(node* temp)
{
    if(temp != NULL)
    {
        //if the node has something to print, the data is printed using cout
        //then, print is called recursively to check and print the next node
        //this repeats until the last node is printed, which points to NULL
        cout << "\n*****************************************" << endl;
        cout << "\tFIRST NAME: "<< temp->getStudent()->getFirst() << endl;
        cout << "\tLAST NAME:  " << temp->getStudent()->getLast() << endl;
        cout << "\tID Number:  " << temp->getStudent()->getID() << endl;
        cout << "\tGPA:        " << temp->getStudent()->getGrade() << setprecision(2) << fixed << endl; 
        print(temp->getNext());
    }
    
}

void average(node* head, float totalGPA, int totalStudents)
{
    //if the node passed in, head, contains a student, get the information and add it to the total and add 1 to the number of students
    //then recursively call the average function and pass through the total and number of students and add the next node's data
    //once the last node is added, the recursion stops and the average is calculated and displayed to 2 decimal places
    if(head != NULL) 
    {
        totalGPA = totalGPA + head->getStudent()->getGrade();
        totalStudents++;
        head = head->getNext();
        average(head, totalGPA, totalStudents);
    }
    else if(head == NULL && totalStudents > 0)
    {
        float avg = totalGPA / totalStudents;
        cout << "Average GPA of students in the list: " << setprecision(2) << fixed << avg << endl;
    }
    else
    {
        cout << "No students in the list! Please add students to calculate average GPA" << endl;
    }
}
