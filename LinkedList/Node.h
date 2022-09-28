//Michael Wang 4/13/21
//header file for node class
#ifndef NODE_H
#define NODE_H

#include <cstring>
#include <iostream>
#include "student.h"

class node
{
	private:
		student* nStudent;
		node* next;
	public:
		node(student* nstudent);
		node* getNext();
		student* getStudent();
		void setNext(node* newNext);
		void setStudent(student* newStudent);
		~node();
};

#endif
