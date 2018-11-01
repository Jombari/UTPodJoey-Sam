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
    Song();
    Song(string songArtist, string songTitle, int songSize);
    string getTitle() const;
    string getArtist() const;
    int getMemory() const;
    void setMemory(int songSize);
    void setArtist(string artistName);
    void setSongTitle(string song);

    bool operator==(Song const &song);
    bool operator<(Song const &song);
    bool operator>(Song const &song);
    ~Song();
};

#endif //LAB5_SONG_H
