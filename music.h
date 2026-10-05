#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media {
 private:
  char* artist;
  char* publisher;
  float duration;
 public:
  Music(char* t, int y, char* artist, char* pub, float dur);
  ~Music();

  void print() const override;
  char* getPublisher() const;
  char* getArtist() const;
  float getDuration() const;
}
