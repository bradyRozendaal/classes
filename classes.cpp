#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

#include "mediaparent.h"
#include "videogame.h"
#include "music.h"
#include "movie.h"

using namespace std;

/*
  Project: Classes
  Made by: Brady Rozendaal
  Date: 
*/

// Gets a C-string from the user.
// The array is created by the function that calls getString().
void getString(char* message, char* arr, int len)
{
  cout << message;
  cin.getline(arr, len);
}


// Gets an integer from the user.
int getInt(char* message)
{
  int value;

  cout << message;
  cin >> value;
  cin.ignore(1000, '\n');

  return value;
}


// Gets a floating-point number from the user.
float getFloat(char* message)
{
  float value;

  cout << message;
  cin >> value;
  cin.ignore(1000, '\n');

  return value;
}

// Adds a new piece of media to the library.
void addMedia(vector<Media*>& media)
{
  char type[20];

  cout << "What type of media would you like to add?\n";
  cout << "Video Game, Music, or Movie: ";

  cin.getline(type, 20);

  // Look at the first letter so the user can enter
  // something like "video game", "music", or "movie".
  char firstLetter = tolower(type[0]);

  if (firstLetter == 'v')
    {
      char name[100];
      char publisher[100];
      char rating[20];

      getString((char*)"What is the name of the video game?: ", name, 100);

      int year = getInt((char*)"What year was the video game published?: ");

      getString((char*)"What is the publisher of the video game?: ", publisher, 100);

      getString((char*)"What is the rating of the video game?: ", rating, 20);

      media.push_back(new VideoGame(name, year, publisher, rating));
    }

  else if (firstLetter == 'm')
    {
      if (tolower(type[1]) == 'u')
        {
	  char name[100];
	  char artist[100];
	  char publisher[100];

	  getString((char*)"What is the name of the song?: ", name, 100);

	  getString((char*)"Who is the artist?: ", artist, 100);

	  int year = getInt((char*)"What year was the song published?: ");

	  getString((char*)"Who is the publisher?: ", publisher, 100);

	  float duration = getFloat((char*)"What is the duration of the song?: ");

	  media.push_back(new Music(name, artist, year, duration, publisher)
			  );
        }

      else if (tolower(type[1]) == 'o')
        {
	  char name[100];
	  char director[100];
	  char rating[20];

	  getString((char*)"What is the name of the movie?: ", name, 100);

	  getString((char*)"Who is the director of the movie?: ",director, 100);

	  int year = getInt((char*)"What year was the movie released?: ");

	  float duration = getFloat((char*)"What is the duration of the movie?: ");

	  getString((char*)"What is the movie rated?: ", rating, 20);

	  media.push_back(new Movie(name, director, year, duration, rating));
        }
    }

  else
    {
      cout << "That is not a valid media type.\n";
    }
}

vector<Media*> searchMedia(vector<Media*>& media)
{
  char input[20];
  vector<Media*> searchedItems;

  cout << "How would you like to search? (year/title): ";
  cin.getline(input, 20);

  if (tolower(input[0]) == 'y')
    {
      int year = getInt((char*)"What year would you like to search for?: ");

      for (Media* m : media)
        {
	  if (m->getYear() == year)
            {
	      searchedItems.push_back(m);
            }
        }
    }

  else if (tolower(input[0]) == 't')
    {
      char title[100];

      getString((char*)"What title would you like to search for?: ", title, 100);

      for (Media* m : media)
        {
	  if (strcmp(title, m->getTitle()) == 0)
            {
	      searchedItems.push_back(m);
            }
        }
    }

  else
    {
      cout << "Invalid search option.\n";
      return searchedItems;
    }

  cout << "\nHere are the media you searched for:\n";

  for (Media* m : searchedItems)
    {
      m->print();
    }

  if (searchedItems.size() == 0)
    {
      cout << "No matching media found.\n";
      return searchedItems;
    }

  char answer[10];

  getString((char*)"\nWould you like to search within these results? (y/n): ", answer, 10);

  if (tolower(answer[0]) == 'y')
    {
      return searchMedia(searchedItems);
    }

  return searchedItems;
}
void deleteMedia(vector<Media*>& library)
{
  vector<Media*> toDelete = searchMedia(library);

  if (toDelete.size() == 0)
    {
      return;
    }

  char answer[10];

  getString((char*)"\nWould you like to delete these media? (y/n): ", answer, 10);

  if (tolower(answer[0]) == 'y')
    {
      for (Media* m : toDelete)
        {
	  for (int i = 0; i < library.size(); i++)
            {
	      if (library[i] == m)
                {
		  delete library[i];
		  library.erase(library.begin() + i);
		  i = library.size();
                }
            }
        }

      cout << "Media deleted.\n";
    }
}

int main()
{
  vector<Media*> library;

  bool run = true;

  while (run)
    {
      char input[20];

      cout << "\nWhat would you like to do?\n";
      cout << "Add, Search, Delete, or Quit: ";

      cin.getline(input, 20);

      char command = tolower(input[0]);

      if (command == 'a')
        {
	  addMedia(library);
        }

      else if (command == 's')
        {
	  searchMedia(library);
        }

      else if (command == 'd')
        {
	  deleteMedia(library);
        }

      else if (command == 'q')
        {
	  run = false;
        }

      else
        {
	  cout << "Invalid command.\n";
        }
    }
  deleteAllMedia(library);
  return 0;
}
