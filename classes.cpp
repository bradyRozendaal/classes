#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
  Project: Classes
  Made by: Brady Rozendaal
  Date: 
 */


void addMedia(vector<Media*> media)
{
  char typearray[50];
  cout << "What type of media would you like to add: \n";
  cin >> typearray;
  char type = typearray[0];
  type = (char)tolower(type);
  if (type == 'v')
    {
      char name[50];
      cout << "What is the name of the videogame?: \n";
      cin.getline(name, 50);
      char publisher[50];
      cout << "What is the publisher of the videogame?: \n";
      cin.getline(publisher, 50);
      char rating[50];
      cout << "What is the rating of the videogame?: \n";
      cin.getline(rating, 50);
      int year;
      cout << "What is the year the videogame was published?: \n";
      cin >> year;
      media.push_back(new VideoGame(name, year, publisher, rating));
    }
  else if (type == 'm')
    {
      if (typearray[1] == 'u')//music
	{
	  char name[50];
	  cout << "What is the name of the song?: \n";
	  cin.getline(name, 50);
	  char artist[50];
	  cout << "Who is the artist: \n";
	  cin.getline(artist, 50);
	  char publisher[50];
	  cout << "Who is the publisher?: \n";
	  cin.getline(publisher, 50);
	  int year;
	  cout << "What is the year the videogame was published?: \n";
	  cin >> year;
	  float duration;
	  cout << "What is the duration of the song?";
	  cin >> duration;
	  media.push_back(new Music(name, year, publisher, rating));
	}
      else if (typearray == 'o')//movies
	{
	  char name[50];
	  cout << "What is the name of the movie?: \n";
	  cin.getline(name, 50);
	  char director[50];
	  cout << "Who is the director of the movie?: \n";
	  cin.getline(publisher, 50);
	  char rating[50];
	  cout << "What is the rating of the movie?: \n";
	  cin.getline(rating, 50);
	  int year;
	  cout << "What is the year the movie was published?: \n";
	  cin >> year;
	  float duration;
	  cout << "What is the duration of the movie?";
	  cin >> duration;
	  media.push_back(new Movie(name, year, publisher, rating, duration); 
	}
    }
}
void deleteMedia(vector<Media*> media)
{
  
}
void searchMedia(vector<Media*> media)//The user should be able to search for and print objects currently in the media database by searching for the title or the year.  If multiple objects match, list them all.
{
  char input;
  cout << "How would you like to search?(year/title): \n";
  cin >> input;
  input = (char)tolower(input);
  vector<Media*> searchedItems;
  if (input == 'y')
    {
      int year;
      cout << "What year would you like to search for?: \n";
      cin >> year;
      for (Media* m : media) {
	if (year == m->getYear())
	  {
	    searchedItems.push_back(m);
	  }
      }
    }
  else if (input == 't')
    {
      char title[20];
      cout << "What title would you like to search for?: \n";
      cin.getline(title, 20);
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
  cout << "\nWould you like to continue searching this list? \n";
  char answer[10];
  cin.getline(answer, 10);
  if (answer[] == 'y')
    {
      searchMedia(searchedItems);
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
