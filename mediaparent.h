#include <iostream>
#include <cstring>
using namespace std;

class Media {
protected:
    char* title;
    int year;

public:
    Media(char* t, int y);
    virtual ~Media();

    virtual void print() const;

    char* getTitle() const;
    int getYear() const;
};
