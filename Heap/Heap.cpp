//This program allows the user to enter various numbers as input  and then create a binary tree as output
//Michael Wang
// 5/2/2021

#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;
//Function Prototypes
void heap (int* array, int input, int count);
void build (int* array, int count);
void printree (int* array, int count, int input, int input2); 

//Main
int main() {
  char* input = new char[50];
  cout << "Enter your preferred method of entry -- console or file: \n";
  cin.getline(input, 50);
  int count = 0;
  int* array = new int[250];
  //Console Input
  if(strcmp(input, "console") == 0) {
    cout << "Enter the numbers you want to add to the heap, seperate each one with a space \n";
    char* input2 = new char[250];
    cin.getline(input2, 250);
    char* token = strtok(input2, " ");
    int index = 1;
    while(token != NULL) {
      array[index] = atoi(token);
      token = strtok(NULL, " ");
      index++;
      count++;
    }
  }
  //File Input
  else if (strcmp(input, "file") == 0) {
    cout << "Enter file name: \n";
    char* filename = new char[50];
    cin.getline(filename, 50);
    ifstream inFile;
    inFile.open(filename);
    char* input2 = new char[250];
    int count2 = 0;
    int index2 = 1;
    while (inFile >> count2) {
      array[index2] = count2;
      index2++;
      count++;
    }
  }
  else {
    cout << "Invalid input";
  }
  //Build heap, print out tree
  build(array, count);
  cout << "Tree: \n";
  printree(array, count, 0, 1); 
  cout << " " << endl; 
  cout << "Heap Output: ";
  for (int i = count; i > 0; i--) {
    cout << array[1] << " "; 
    array[1] = array[i];
    array[i] = 0; 
    build(array, i);
    array[i] = array[i - 1]; 
  }  
}

//Builds heap
void build (int* array, int count) {
  int i;
  for(i = count/2; i >= 1; i--) {
    heap(array, i, count); 
  }  
}

//Sort - greatest to least
void heap (int* array, int input, int count) {
  int index;
  int temp;
  temp = array[input];
  index = input*2;
  while (index <= count) {
    if (array[index+1] > array[index] && index < count)
      index = index + 1;
    if (temp > array[index])
      break;
    else if (temp <= array[index]) {
      array[index/2] = array[index];
      index = 2 * index;
    }
  }
  array[index/2] = temp;
  return; 
}

//Prints tree
void printree (int* array, int count, int input, int input2) {
  int leftposition = 2*input2;
  int rightposition = 2*input2+1;
  if (rightposition <= count) {
    printree(array, count, input+1, rightposition); 
  }
  int current = input;
  while (input > 0) {
    cout << "    ";
    input--; 
  }
  cout << array[input2] << endl;
  if (leftposition <= count) {
    printree(array, count, current + 1, leftposition); 
  }
}