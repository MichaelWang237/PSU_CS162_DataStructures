//Class file for Music

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

Music::Music() {}

Music::~Music() {
  delete []Artist;
  delete []Title;
  delete []Publisher;
}
int Music::getType() {
return 1;
}

char* Music::getArtist() {
  return Artist;
}

int* Music::getDuration() {
  return &Duration;
}

char* Music::getPublisher() {
  return Publisher;
}
