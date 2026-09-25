#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
  Project: Classes
  Made by: Brady Rozendaal
  Date: 
 */


void addMedia(vector<Media*> &mediaContainer)
{
  char type;
  cout << "What type of media would you like to add: \n";
  cin >> type;
  type = (char)tolower(type);
  
}
void deleteMedia(vector<Media*> &mediaContainer)
{
  
}
void searchMedia(vector<Media*> &mediaContainer)//The user should be able to search for and print objects currently in the media database by searching for the title or the year.  If multiple objects match, list them all.
{
  char input;
  cout << "How would you like to search?(year/publisher/type/rating): \n";
  cin >> input;
  input = (char)tolower(input);
  
  if (input == 'y')
    {
      int year;
      cout << "What year would you like to search for?: \n";
      cin >> year;
    }
  else if (input == 'p')
    {
      char publisher[];
      cout << "What publisher would you like to search for?: \n";
      cin.getline(publisher, 20);
    }
  else if (input == 't')
    {
      char type;
      cout << "What type would you like to search in?: \n";
      cin.getline(type, 1);
    }
  else if (input == 'r')
    {
      char direction;
      cout << "Would you like to search above or below a certain rating?(a/b): ";
      cin >> direction;
      direction = (char)tolower(direction);
      float rating;
      cout << "What rating would you like to search at?: ";
      cin >> rating;
    }
}

int main()
{
  vector<Media*> library;
  library.push_back(new VideoGame("Zelda", 2023, "Nintendo", "E10+"));
  for (Media* m : library) {
    // getRating() doesn't exist on Media, only VideoGame —> need to check + cast
    if (VideoGame* vg = dynamic_cast<VideoGame*>(m)) {
      cout << vg->getRating();
    }
  }
  for (Media* m : library) {
    m->print(); // works for ANY child
    cout << m->getYear(); // common field, no cast needed
  }
}
