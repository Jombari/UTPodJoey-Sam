//
// Created by Samuel Yeboah on 10/28/2018.
//

#ifndef LAB5_SONG_H
#define LAB5_SONG_H
#include <iostream>
#include <string>
#include "Song.h"
using namespace std;

class Song {
    private:
    string title;
    string artist;
    int size;

public:
    Song(string songTitle, int songSize, string songArtist){
        artist = songArtist;
        title = songTitle;
        size = songSize;
    };

    string getTitle() const{
        return title;
    };

    string getArtist() const{
        return artist;
    };

    int getMemory() const{
        return size;
    };
    void setMemory(int songSize){
        size = songSize;
    };
    void setArtist(string artistName){
        artist = artistName;
    };
    void setSongTitle(string song){
        title = song;
    };
    bool operator ==(Song const &song){
       return this->artist == song.getArtist() && this->size == song.getMemory() && this->title == song.getTitle();
    };
};


#endif //LAB5_SONG_H
