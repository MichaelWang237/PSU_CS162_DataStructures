// The binary tree allows users to contribute and search up numbers. 
// Michael Wang
// 5/17/21
#include "Node.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;
void add(Node* head, int wadd);
void print(Node* head, int format);
Node* deleteN(Node* head, int wdel);
void search(Node* head, bool rsearch, int wsearch);
Node* small(Node* head); 

//Main Line, UI, Function Caller
int main() {
  char* input = new char[1000];
  cout << "File, Console? Take your Pick, you have a variety of options \n";
  cin.getline(input, 1000);
  int count = 0;
  bool running = true;
  int* array = new int[1000];
  if(strcmp(input, "CONSOLE") == 0) {
      cout << "Enter numbers with spaces to seperate \n";
      char* input2 = new char[1000];
      cin.getline(input2, 1000);
      char* token = strtok(input2, " ");
      while (token != NULL) {
	array[count] = atoi(token);
        token = strtok(NULL, " ");
	count++;
      }
    }
    if (strcmp(input, "FILE") == 0) {
      cout << "Enter File Name: \n";
      char* fileName = new char[1000];
      cin.getline(fileName, 1000);
      ifstream inFile;
      inFile.open(fileName);
      int count2 = 0;
      while (inFile >> count2) {
	array[count] = count2;
	count++; 
      }
    }
    Node* head = new Node();
    for (int i = 0; i < count; i++) {
      add(head, array[i]); 
    }
    while (running == true) {
      cout << "\nYou can do stuff now, you can ADD, DELETE, PRINT, SEARCH, EXIT \n";
      char* getInput = new char[50];
      cin.getline(getInput, 50);
      int wadd = 0;
      int wdel = 0;
      int wsearch = 0;
      bool rsearch = false; 
      if (strcmp(getInput, "ADD") == 0) {
	cout << "Enter number you would like to add \n";
	cin >> wadd;
	cin.get();
	add(head, wadd);
	cout << "Added \n";
	}
      else if (strcmp(getInput, "DELETE") == 0) {
	//Function!
	cout << "What number do you want to delete? \n";
	cin >> wdel;
	cin.ignore(9999, '\n');
	if (head -> getLeft() == NULL && head -> getRight() == NULL) {
	  head -> setData(NULL);
	}
	else {
	  head = deleteN(head, wdel);
	}
	cout << "Deleted \n";
	}
      else if (strcmp(getInput, "PRINT") == 0) {
        //Function!
	if (head-> getData() == NULL) {
	  cout << "Nothing to Print \n";
	}
	else {
	  print(head, 0);
	}
      }
      else if (strcmp(getInput, "SEARCH") == 0) {
	cout << "What number would you like to search for? \n";
	cin >> wsearch;
	cin.ignore(9999, '\n');
	search(head, rsearch, wsearch);
      }
      else if (strcmp(getInput, "EXIT") == 0) {
	running = false; 
      }
    }


  return 0; 
}
//Add an integer value to the tree
void add(Node* head, int wadd) {
  if (head -> getData() == NULL) {
    head -> setData(wadd);
    return; 
  }
  else if (head -> getData() > wadd) {
    if (head -> getLeft() != NULL) {
      Node* add2 = head -> getLeft();
      add(add2, wadd); 
    }
    else {
      Node* add2 = new Node();
      add2 -> setData(wadd);
      head -> setLeft(add2);
      return; 
    }
  }
  else if (head -> getData() < wadd) {
    if (head -> getRight() != NULL) {
      Node* add2 = head -> getRight();
      add(add2, wadd); 
    }
    else {
      Node* add2 = new Node();
      add2 -> setData(wadd);
      head -> setRight(add2);
      return; 
    }
  }
  return; 
}
//Print out Tree
void print(Node* head, int format) {
  if (head == NULL) 
    return;
  format = format + 3;
  print(head -> getRight(), format);
  cout << '\n';
  for (int i = 3; i < format; i++)
    cout << " ";
    cout << head -> getData();
    print(head -> getLeft(), format); 
}

//Search for a node
void search(Node* head, bool rsearch, int wsearch) { 
  Node* filler = NULL;
  int tracker = 0;
  if (head == NULL) {
    cout << "Nothing";
    return; 
  }
  if (head != NULL) {
    if (head -> getData() > wsearch) {
      search(head -> getLeft(), rsearch, wsearch);
    }
    else if (head -> getData() < wsearch) {
      search(head -> getRight(), rsearch, wsearch);
    }
   else if (head -> getData() == wsearch) {
      cout << "Match found";
      rsearch = true;
      tracker = 1; 
      return; 
      }
  }
    
}

//Delete a node
Node* deleteN(Node* head, int wdel) {
  if (head -> getData() > wdel) {
    head -> setLeft(deleteN(head -> getLeft(), wdel)); 
  }
  else if (head -> getData() < wdel) {
    head -> setRight(deleteN(head -> getRight(), wdel));
  }
  else {
    if (head -> getLeft() == NULL) {
      Node* temp = head -> getRight();
      free(head);
      return temp; 
    }
    else if (head -> getRight() == NULL) {
      Node* temp = head -> getLeft();
      free(head);
      return temp; 
    }
    Node* temp = small(head -> getRight());
    head -> setData(temp -> getData());
    head -> setRight(deleteN(head -> getRight(), temp -> getData())); 
  }
}

//Find smallest data point
Node* small(Node* head) {
  Node* current = head;
  while (current -> getLeft() != NULL) {
    current = current -> getLeft(); 
  }
  return current; 
}
