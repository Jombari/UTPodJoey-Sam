//
// Created by Samuel Yeboah on 10/28/2018.
//

#ifndef LAB5_SONG_H
#define LAB5_SONG_H
#include <string>
using namespace std;

class Song {
private:
    string title;
    string artist;
    int size;

public:
    //constructor
    Song();

    //override constructor
    Song(string songArtist, string songTitle, int songSize);

    //accessor methods

    //gets song title
    string getTitle() const;

    //gets song artist
    string getArtist() const;

    //gets song memory
    int getMemory() const;


//Modifier subs

    //sets song memory
    void setMemory(int songSize);

    //sets song Artist
    void setArtist(string artistName);

    //Sets song Title
    void setSongTitle(string song);

    bool operator==(Song const &song);

    bool operator<(Song const &song);

    bool operator>(Song const &song);

    ~Song();
};

#endif //LAB5_SONG_H
