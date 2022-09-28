//Michael Wang 4/10 - Nodecpp
#include "node.h" // include node.h and by extension iostream, cstring, student.h
node::node(student* aStudent) //constructor
{
	nStudent = aStudent;
	next = NULL;
}

node::~node() //destructor -- free's the memory used by the student
{
	delete nStudent;
}

student* node::getStudent() //return student associated with a given node
{
	return nStudent;
}

void node::setStudent(student* newStudent) //assign a student to a node
{
	nStudent = newStudent;
}

node* node::getNext() //return the next node
{
	return next;
}

void node::setNext(node* newNext) // change a given node's next node
{
	next = newNext;
}





