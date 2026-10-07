#include <iostream>
#include <cstring>
#include "mediaparent.h"
using namespace std;

class VideoGame : public Media {
private:
  char* publisher;
  char* rating;

public:
  VideoGame(char* t, int y, char* pub, char* r);
  ~VideoGame();

  void print() const override;

  char* getPublisher() const;
  char* getRating() const;
};
