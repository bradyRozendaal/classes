#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

Movie::Movie(char* t, int y, char* pub, char* r, float dur){
  publisher = new char[strlen(pub) + 1];
  strcpy(publisher, pub);
  rating = new char[strlen(r) + 1];
  strcpy(rating, r);
  duration = dur;
}

Movie::~Movie()
{
  delete[] publisher;
  delete[] rating;
  delete duration;
}

void Movie::print() const
{
  Media::print();
  cout << " - " << publisher << ", rated: " << rating << ", duration: " << duration << "\n";
}

char* Movie::getPublisher() const
{
  return publisher;
}
char* Movie::getRating() const
{
  return rating;
}
float Movie::getDuration() const
{
  return duration;
}
