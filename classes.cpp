#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
  Project: Classes
  Made by: Brady Rozendaal
  Date: 
 */

char* getret(char* message, int len = 50)
{
  char* arr;
  cout << message;
  cin.getline(arr, 50);
  return arr;
}
int getint(char* message)
{
  int value;
  cout << message;
  cin >> value;
  return value;
}
float getfloat(char* message)
{
  float value;
  cout << message;
  cin >> value;
  return value;
}

void addMedia(vector<Media*> media)
{
  char type = getret("What type of media would you like to add: \n", 10)[0];
  type = (char)tolower(type);
  if (type == 'v')
    {
      char* name = getret("What is the name of the videogame?: \n");
      char* publisher = getret("What is the publisher of the videogame?: \n");
      char* rating = getret("What is the rating of the videogame?: \n");
      int year = getint("What is the year the videogame was published?: \n");
      media.push_back(new VideoGame(name, year, publisher, rating));
    }
  else if (type == 'm')
    {
      if (typearray[1] == 'u')//music
	{
	  char* name = getret("What is the name of the song?: \n");
	  char* artist = getret("Who is the artist?: \n");
	  char* publisher = getret("Who is the publisher?: \n");
	  int year = getint("What is the year the videogame was published?: \n");
	  float duration = getfloat("What is the duration of the song?: \n");
	  media.push_back(new Music(name, year, publisher, artist, duration));
	}
      else if (typearray == 'o')//movies
	{
	  char name = getret("What is the name of this movie?: \n");
	  char director = getret("Who is the diretor of this movie?: \n");
	  char* rating = getret("What is this movie rated?");
	  int year = getint("What is the year the movie was published?: \n");
	  float duration = getfloat("What is the duration of the movie? \n");
	  media.push_back(new Movie(name, year, publisher, rating, duration); 
	}
    }
}
void deleteMedia(vector<Media*> media, vector<Media*> todelete)
{
  for (Media* todel : todelete)
    {
      erase(media, todel);
    }
}
 void searchMedia(vector<Media*> medialib, vector<Media*> media = medialib, bool del = false)//The user should be able to search for and print objects currently in the media database by searching for the title or the year.  If multiple objects match, list them all.
{
  char input = getret("How would you like to search?(year/title): \n");
  input = (char)tolower(input);
  vector<Media*> searchedItems;
  if (input == 'y')
    {
      int year = getint("What year would you like to search for?: \n");
      for (Media* m : media) {
	if (year == m->getYear())
	  {
	    searchedItems.push_back(m);
	  }
      }
    }
  else if (input == 't')
    {
      char* title = getret("What title would you like to search for?: \n");
      for (Media* m : media) {//change this to search to see if it matches the string as long as it goes
	if (title == m->getName())
	  {
	    searchedItems.push_back(m);
	  }
      }
    }
  cout << "Here are the media you searched for: \n";
  for (Media* m : searchedItems)
    {
      m->print();
    }
  char answer = getret("\nWould you like to continue searching this list? \n")[0];
  if (answer == 'y')
    {
      searchMedia(medialib, searchedItems);
    }
  if (del)
    {
      char delanswer = getret("Would you like to remove these media? \n")[0];
      if (delanswer == 'y')
	{
	  deleteMedia(medialib, searchedItems);
	}
    }
}

int main()
{
  vector<Media*> library;
  bool run = true;
  while (run)
    {
      char inputarray[];
      cout << "What would you like to do? (quit, search, delete, add)\n";
      cin >> input;
      char input = inputarray[0];
      if (input == 'a')//add
	{
	  addMedia(library);
	}
      else if (input == 's')//search
        {
	  searchMedia(library);
	}
      else if (input == 'd')//delete
	{
	  deleteMedia(library);
	}
      else if (input == 'q')//quit
	{
	  run = false;
	}
    }
  
  
  for (Media* m : library) {
    // getRating() doesn't exist on Media, only VideoGame —> need to check + cast
    if (VideoGame* vg = dynamic_cast<VideoGame*>(m)) {
      cout << vg->getRating();
    }
  }

}
