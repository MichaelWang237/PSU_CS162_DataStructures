//This program accepts an input and removes spaces, punctuation and capitalization before checking to see whether it reads the same back and forth -- ie. whether it is a palindrome.
// Michael Wang
// 2/27/2021

#include <iostream>
#include <cstring>
using namespace std;
int main()

{
  //Initialize variables
  char input [80];
  int count = 0;
  int count1 = 0;
  bool isPalindrome = true;
  char input2 [80];
  char input3 [80];
  //Clears cstrings
  for (int i = 0; i < 80; i++) {
    input[i] = 0;
  }
  for (int i = 0; i < 80; i++) {
    input2[i] = 0;
  }
  for (int i = 0; i < 80; i++) {
    input3[i] = 0;
  }
  cin.get(input, 80);
  cin.get();
  //Removes spaces and punctuation by transferring letters and numbers to another array
  for (int i = 0; i < 80; i++) {
    if ((input[i] >= 97 && input[i] <= 122) || (input[i] >= 65 && input[i] <= 90) || (input[i] >= 48 && input[i] <= 57)) {
      input2[count1] = input[i];
      count1++;
    }
  }
  //Remove capitalization
  for (int i = 0; i < 80; i++) {
    if (input2[i] >= 65 && input2[i] <= 90) {
      input3[i] = input2[i] + 32;
    }
    else {
      input3[i] = input2[i];
    }
  }
  //Count the number of characters to find length of the string. 
  for (int i = 0; i < 80; i++) {
    if ((input3[i] >= 97 && input3[i] <= 122) ||(input3[i] >= 48 && input3[i] <= 57)) {
      count++;
    }
  }
  // Checks whether modified input is a palindrome
  for (int i = 0; i < count; i++) {
    if (input3[i] != input3[count - i - 1]) {
	isPalindrome = false;
        }
      
  }
    if (isPalindrome == false) {
      cout << "This is not a palindrome";
    }
    else {
      cout << "This is a palindrome";
    }
  return 0;
}
