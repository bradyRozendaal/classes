#include <iostream>
#include <cstring>
#include "videogame.h"
using namespace std;

VideoGame::VideoGame(char* t, int y, char* pub, char* r) : Media(t, y)
{
  publisher = new char[strlen(pub) + 1];
  strcpy(publisher, pub);

  rating = new char[strlen(r) + 1];
  strcpy(rating, r);
}

VideoGame::~VideoGame()
{
  delete[] publisher;
  delete[] rating;
}

void VideoGame::print() const
{
  Media::print();
  cout << " - " << publisher << ", Rated: " << rating << endl;
}

char* VideoGame::getPublisher() const
{
  return publisher;
}

char* VideoGame::getRating() const
{
  return rating;
}
