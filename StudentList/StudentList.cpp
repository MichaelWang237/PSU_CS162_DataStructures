// This program allows the user to compile a list of students by entering their// first name, last name, ID number, and GPA.
// Michael Wang
// 3/14/2021
// 
//
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;
// Characterstics of a student
struct Student {
  char firstName[100];
  char lastName[100];
  int ID;
  double GPA;
};
// Prototypes for delete and print
void deleteName(vector<Student*>* StudentList);
void printNames(vector<Student*> StudentList);
// Add function
Student* addName() {
Student* createStudent = new Student();
    // Asks user to enter student characteristics
    cout << "\nEnter Student Firstname:";
    cin >> createStudent -> firstName;
    cin.clear();
    cin.ignore(999, '\n');
    cout << "\nEnter Student Lastname:";
    cin >> createStudent -> lastName;
    cin.clear();
    cin.ignore(999, '\n');
    cout << "\n Enter Student ID #:";
    cin >> createStudent -> ID;
    cin.clear();
    cin.ignore(999, '\n');
    cout << "\n Enter Student GPA:";
    cin >> createStudent -> GPA;
    cin.clear();
    cin.ignore(999, '\n');
    return createStudent;
}

int main() {
  // Runs main function 
  char input[10];
  bool onQuit = false; 
  vector<Student*> StudentList;
  while (onQuit == false) {
  cout << "Welcome to Student List, ADD, PRINT, DELETE, QUIT\n";
  cin.getline (input, 10); 
  if (strcmp(input, "QUIT") == 0) {
    exit(0);
  }
  else if (strcmp(input, "ADD") == 0) {
    // Runs add function 
    StudentList.push_back(addName()); 
    cout << "Done \n";
  }
  else if (strcmp(input, "PRINT") == 0) {
       //Runs Print
       printNames(StudentList);
  }
  else if (strcmp(input, "DELETE") == 0) {
    // Runs delete function 
    deleteName(&StudentList);
    cin.clear();
    cin.ignore(999, '\n');
  }
  else 
   {
    cout << "\nPlease Enter a Valid Command, ADD, DELETE, PRINT, QUIT";
  }

  }  
  return 0;
}

void printNames(vector<Student*> StudentList) {
  //In case the list is empty:
    if (StudentList.empty() == true) {
    cout << "Student List is Empty, Nothing to Print! \n";
  }
  else {
  // Prints all students 
  for (vector<Student*>:: iterator printAll = StudentList.begin(); printAll != StudentList.end(); ++printAll) {
    cout << (*printAll) -> firstName << " ";
    cout << (*printAll) -> lastName << ", ";
    cout << (*printAll) -> ID << ", ";
    cout << setprecision(2)<< fixed << (*printAll) -> GPA << "\n"; 
   }
}
}
void deleteName(vector<Student*>* StudentList) {
  int StudentIDinput; 
  cout << "Which Student do you want to delete? \n";
  cin >> StudentIDinput;
  if (StudentList -> empty() == true) {
      cout << "Student List is Empty, Nothing to Delete! \n";
	  //Deletes nothing if empty
      return;
  }
  else {
	  //Search for specific studnent to delete 
    for (vector<Student*>:: iterator find = StudentList -> begin(); find != StudentList -> end(); ++find) {
      if ((*find) -> ID == StudentIDinput) {
	delete *find;
	StudentList -> erase(find);
	return;
    }
      else {
	// If no match is found, function ends. 
    }
  }
  }
} 
