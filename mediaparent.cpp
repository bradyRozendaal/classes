#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;

Media::Media(char* t, int y)
{
    title = new char[strlen(t) + 1];
    strcpy(title, t);

    year = y;
}

Media::~Media()
{
    delete[] title;
}

void Media::print() const
{
    cout << title << " (" << year << ")";
}

char* Media::getTitle() const
{
    return title;
}

int Media::getYear() const
{
    return year;
}
