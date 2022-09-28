// This program stores various classes, including video games, music, movies, etc.
// Michael Wang
// 3/21/21

// Imports
#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movies.h"
#include "Music.h"
#include "VideoGame.h"
#include <vector>

using namespace std;
//Add Function
void ADD(vector<Media*>* allMedia) {
  char mInput[20];
  cout << "What type of Media would you like to add? (Write either Video Game, Music, or Movie, in verbatim) \n";
  cin.get(mInput, 20);
  cin.clear();
  cin.ignore(9999, '\n');
  //Add Video Game
  if (strcmp(mInput, "Video Game") == 0) {
    VideoGame* Game = new VideoGame();
    cout << "Enter Video Game Title \n";
    cin.get(Game -> getTitle(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Year Released \n";
    cin >> *Game -> getYear();
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Publisher \n";
    cin.get(Game -> getPublisher(), 100);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Game Rating \n";
    cin >> *Game -> getRating();
    cin.clear();
    cin.ignore(9999, '\n');
    allMedia -> push_back(Game);
    
  }
  //Add Music
  else if (strcmp(mInput, "Music") == 0) {
    Music* Song = new Music();
    cout << "Enter Music Title \n";
    cin.get(Song -> getTitle(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Music Year; \n";
    cin >> *Song -> getYear(); 
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Music Artist: \n";
    cin.get(Song -> getArtist(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Music Duration: \n";
    cin >> *Song -> getDuration();
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Publisher: \n";
    cin.get(Song -> getPublisher(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    allMedia -> push_back(Song);
    
  }
  //Add Movie
  else if (strcmp(mInput, "Movie") == 0) {
    Movie* Film = new Movie();
    cout << "Enter Movie Title \n";
    cin.get(Film -> getTitle(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Year of Movie: \n";
    cin >> *Film -> getYear();
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Movie Director: \n";
    cin.get(Film -> getDirector(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Movie Duration: \n";
    cin >> *Film -> getDuration();
    cin.clear();
    cin.ignore(9999, '\n');

    cout << "Enter Movie Rating: \n";
    cin >> *Film -> getRating();
    cin.clear();
    cin.ignore(9999, '\n');
    allMedia -> push_back(Film);   
  }
  // Exits back to Home Page if User does not enter valid input
  else {
    cout << "This is not a type of Media. See you back at the home page\n"; 
  }
}
// Search for Media
void SEARCH(vector<Media*>* allMedia) {
  int input;
  char input2[50];
  char input3[50];
  // Asks to sort by title or year
  cout << "Would you like to search by TITLE or YEAR? \n";
  cin.get(input2, 50);
  cin.clear();
  cin.ignore(9999, '\n');
  vector<Media*>:: iterator cycle;
  //Title Search
  if (strcmp(input2, "TITLE") == 0) {
    cout << "What Title would you like to search by? \n";
    cin.get(input3, 50);
    cin.clear();
    cin.ignore(9999, '\n');
    //Iterates through the whole Vector
    for (cycle = allMedia -> begin(); cycle != allMedia -> end(); ++cycle) {
      //Video Game
      if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 0)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<VideoGame*>(*cycle) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<VideoGame*>(*cycle) -> getRating() << endl << endl;
      }
    
      else if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 1)) {
	//Music 
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*cycle) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*cycle) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*cycle) -> getPublisher() << endl << endl;
      }
      //Movie
      else if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 2)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*cycle) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movie*>(*cycle) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movie*>(*cycle) -> getRating() << endl << endl;
      }
    }
  }

  //Search by Year     
  else if (strcmp(input2, "YEAR") == 0) {
    cout << "What Year would you like to search by? \n";
    cin >> input;
    cin.clear();
    cin.ignore(9999, '\n');
    //Same Iterator
    for (cycle = allMedia -> begin(); cycle != allMedia -> end(); ++cycle) {
      //Video Game 
      if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 0)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<VideoGame*>(*cycle) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<VideoGame*>(*cycle) -> getRating() << endl << endl;
      }
      // Music 
      else if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 1)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*cycle) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*cycle) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*cycle) -> getPublisher() << endl << endl;
      }
      //Movie
      else if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 2)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*cycle) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movie*>(*cycle) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movie*>(*cycle) -> getRating() << endl << endl;
      }
    }
  }
  // Asks user to enter valid input, maybe it prevents Mr. Connor Shu from breaking my code	
  else {
    "You did not enter a valid input. See you back at the home page \n";
  }
  
}
//Delete Function, This Function is the Same as the SEARCH function, with about 15 new lines of code for actually deleting the media
void DELETE(vector<Media*>* allMedia) {
  int input;
  char input2[50];
  char input3[50];
  char deletE[50];
  cout << "Would you like to search by TITLE or YEAR? \n";
  cin.get(input2, 50);
  cin.clear();
  cin.ignore(9999, '\n');
  vector<Media*>:: iterator cycle;
  if (strcmp(input2, "TITLE") == 0) {
    cout << "What Title would you like to search by? \n";
    cin.get(input3, 50);
    cin.clear();
    cin.ignore(9999, '\n');
    //Prints class in the array only if it meets certain requirements, needs to match the title or year and varies depending on the 3 types of media
    for (cycle = allMedia -> begin(); cycle != allMedia -> end(); ++cycle) {
      if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 0)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<VideoGame*>(*cycle) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<VideoGame*>(*cycle) -> getRating() << endl << endl;
	   cout << "Do you wish to delete this Media? Only yes will delete, everything else is taken as no \n";
      //Deletes that specific media, the rest of the code on this function is just a duplicate of the same logic two more times
      //The second part is the same thing repeated but for a year search instead of a title one. 
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Ok, is fine";
      }
      }
      else if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 1)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*cycle) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*cycle) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*cycle) -> getPublisher() << endl << endl;
	   cout << "Do you wish to delete this Media? Only yes will delete, everything else is taken as no \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Ok, is fine";
      }
      }
      else if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 2)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*cycle) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movie*>(*cycle) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movie*>(*cycle) -> getRating() << endl << endl;
	   cout << "Do you wish to delete this Media? Only yes will delete, everything else is taken as no \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Ok, is fine";
      }
      }
    }
    return; 
  }
       
  else if (strcmp(input2, "YEAR") == 0) {
    cout << "What Year would you like to search by? \n";
    cin >> input;
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "test";
    for (cycle = allMedia -> begin(); cycle != allMedia -> end(); ++cycle) {
      if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 0)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<VideoGame*>(*cycle) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<VideoGame*>(*cycle) -> getRating() << endl << endl;
	  cout << "Do you wish to delete this Media? Only yes will delete, everything else is taken as no \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Ok, is fine";
      }
      }
    
      else if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 1)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*cycle) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*cycle) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*cycle) -> getPublisher() << endl << endl;
	   cout << "Do you wish to delete this Media? Only yes will delete, everything else is taken as no \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Ok, is fine";
      }
      }
      else if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 2)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*cycle) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movie*>(*cycle) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movie*>(*cycle) -> getRating() << endl << endl;
	   cout << "Do you wish to delete this Media? Only yes will delete, everything else is taken as no \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Ok, is fine";
      }
      }

    }
  }
  else {
    cout << "\n You did not enter a valid input";
  }
}    
//Main Line, asks user which of the 4 options they want and runs the function
int main() {
  char function[50]; 
  vector<Media*> TotalList;
  bool stillOn = true;
  while (stillOn == true) {
  cout << "\n What would you like to do? ADD, SEARCH, DELETE, QUIT \n";
  cin.get(function, 50);
  cin.clear();
  cin.ignore(9999, '\n');
  if (strcmp(function, "ADD") == 0) {
    ADD(&TotalList);
  }
  else if (strcmp(function, "SEARCH") == 0) {
    SEARCH(&TotalList);
  }
  else if (strcmp(function, "DELETE") == 0) {
    DELETE(&TotalList);
  }
  else if (strcmp(function, "QUIT") == 0) {
    stillOn = false; 
  }
  else {
    cout << "Please give Valid Input \n";
  }
  
  }
  return 0; 
}
