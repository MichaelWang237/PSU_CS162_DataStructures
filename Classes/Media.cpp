//Class for Parent Class, Media

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

Media::Media() {

}

Media::~Media() {
  delete []Title;
}


int Media::getType() {
  return 0;
}


char* Media::getTitle() {
  return Title;
  
}

int* Media::getYear() {
  return &Year;
}

