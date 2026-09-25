#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class VideoGame : public Media {
private:
    string publisher;
    string rating;
public:
    VideoGame(string t, int y, string pub, string r)
        : Media(t, y), publisher(pub), rating(r) {}

    void print() const override {
        Media::print(); // call base version, then add more
        cout << " - " << publisher << ", Rated: " << rating << endl;
    }

    string getRating() const { return rating; } // unique to VideoGame
};
