#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

Music::Music(char* t, int y, char* pub, char* art, float dur) : Media(t, y)
{
  publisher = new char[strlen(pub) + 1];
  strcpy(publisher, pub);

  artist = new char[strlen(art) + 1];
  strcpy(artist, art);
  duration = dur;
}

Music::~Music()
{
  delete[] publisher;
  delete[] artist;
  delete duration;
}
void Music::print() const
{
  Media::print();
  cout << " - " << artist << ", Publisher: " << publisher << ", duration: " << duration << "\n";
}

char* Music::getPublisher() const
{
  return publisher;
}
char* Music::getArtist() const
{
  return artist;
}
float Music::getDuration() const
{
  return duration;
}
