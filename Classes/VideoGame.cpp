//Class File for Video Games

#include <iostream>
#include <cstring>
#include "Media.h"
#include "VideoGame.h"

using namespace std;

VideoGame::VideoGame()

{}
VideoGame::~VideoGame() {
  delete []Publisher;
  delete []Title;
}
int VideoGame::getType() {
  return 0;
}

char* VideoGame::getPublisher() {
  return Publisher;
}

float* VideoGame::getRating() {
  return &Rating;
}

