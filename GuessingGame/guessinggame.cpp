/* Michael Wang 2/14/2021 Guessing Game

   This program generates a random number between 0 and 100. The user repeatedly enters guesses with feedback from the computer until they find the number. They may then choose to play again or not.*/



#include <iostream>

using namespace std;

int main()
{
  /* initialize variables */
  int randomnum = 0;
  int usernum = 0;
  int playstatus = 1;
  int guessnum = 1;
  char input = 'y';

  /*intialize Rand */
  srand(time(NULL));

  /*Set Rand to a number between 0 and 100*/
  randomnum = rand() % 100 + 1;
  
  /* do while loop that runs until the user guesses the correct number*/
  while (playstatus == 1){
  do{
    cout << "Guess a number between 0 and 100!" << endl;
      cin >> usernum;
      
    if(usernum > randomnum)
      {
	cout << "Your guess is too high!" << endl;
	guessnum += 1;
      }
    else if (usernum < randomnum)
      {
	cout << "Your guess is too low!" << endl;
	guessnum += 1;
	  }
     }while (usernum != randomnum);
  
  /* Once the user guesses correctly, display a congratulatory message and ask if they'd like to play again. If they enter y (yes), the variable in charge of tracking the number of guesses used is reset to 1 to compensate for the correct guess not being counted. Note the playstatus variable doesn't change so the while loop keeps running. If they enter n, playstatus is changed to 0, stopping the while loop*/
  cout << "Congratulations! You are correct! Would you like to play again? (y/n)? Number of Guesses: " << guessnum << endl;
  cin >> input;
  if (input == 'y'){
    playstatus = 1;
    int guessnum = 1;
    randomnum = rand() % 100 + 1; 
  }
  if (input == 'n'){
    playstatus = 0;
  }
  }
}
