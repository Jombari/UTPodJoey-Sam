//
// Created by Samuel Yeboah on 10/28/2018.
//

//#ifndef LAB5_SONG_H
//#define LAB5_SONG_H
#include <iostream>
#include <string>
#include "Song.h"
//using namespace std;

/*class Song {
    private:
    string title;
    string artist;
    int size;

public:
*/
Song::Song(){
        artist;
        size = 0;
        title;
}


Song::Song(string songTitle, int songSize, string songArtist){
        artist = songArtist;
        title = songTitle;
        size = songSize;
};

Song::~Song(){
    
};

string Song::getTitle() const{
    return title;
};

string Song::getArtist() const{
    return artist;
};

int Song::getMemory() const{
    return size;
};
void Song::setMemory(int songSize){
    size = songSize;
};
void Song::setArtist(string artistName){
    artist = artistName;
};
void Song::setSongTitle(string song){
    title = song;
};
bool operator ==(Song const &song){
    return this->artist == song.getArtist() && this->size == song.getMemory() && this->title == song.getTitle();
};
bool operator <(Song const &song){
    return this->size < song.getMemory() && this->artist < song.getArtist() && this->title < song.getTitle();
};

bool operator >(Song const &song){
    return this->size > song.getMemory() && this->artist > song.getArtist() && this->title > song.getTitle();
};
//};


//#endif //LAB5_SONG_H
