#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Media {
protected:
  string title;
  int year;
public:
  Media(string t, int y) : title(t), year(y) {}
  virtual ~Media() {} 

  virtual void print() const {
    cout << title << " (" << year << ")";
  }
  string getTitle() const { return title; }
  int getYear() const { return year; }
};
