//
// Created by Samuel Yeboah on 10/28/2018.
//

#ifndef LAB5_SONG_H
#define LAB5_SONG_H
#include <iostream>
#include <string>
using namespace std;

class Song {

    Song(string songTitle, int songSize, string songArtist);

    string getTitle() const;

    string getArtist() const;

    int getMemory() const;
    void setMemory(int size);
    void setArtist(string artistName);
    void setSongTitle(string song);
    bool operator ==(Song const &song);
};


#endif //LAB5_SONG_H
