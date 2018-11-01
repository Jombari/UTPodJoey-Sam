//
// Created by Samuel Yeboah on 10/28/2018.
//

//#ifndef LAB5_SONG_H
//#define LAB5_SONG_H
#include <iostream>
#include "Song.h"
using namespace std;


Song::Song() {
    artist;
    size = 0;
    title;
}
Song::Song(string songArtist, string songTitle, int songSize) {
    artist = songArtist;
    title = songTitle;
    size = songSize;
};

string Song::getTitle() const{
    return title;
};

string Song::getArtist() const{
    return artist;
};

int Song::getMemory() const {
    return size;
};

void Song::setMemory(int songSize) {
    size = songSize;
};

void Song::setArtist(string artistName) {
    artist = artistName;
};

void Song::setSongTitle(string song) {
    title = song;
};

bool Song::operator ==(Song const &song) {
    return this->artist == song.getArtist() && this->size == song.getMemory() && this->title == song.getTitle();
};

bool Song::operator <(Song const &song) {
    if(this->artist<song.getArtist()){
        return true;
    }
    if(this->artist == song.getArtist()){
        if(this->title < song.getTitle()){
            return true;
        }
        else if(this->title == song.getTitle()){
            if(this->getMemory() < song.getMemory()){
                return true;
            }
        }
    }
    return false;
};

bool Song::operator >(Song const &song) {
    if(this->artist>song.getArtist()){
        return true;
    }
    if(this->artist == song.getArtist()){
        if(this->title > song.getTitle()){
            return true;
        }
        else if(this->title == song.getTitle()){
            if(this->getMemory() > song.getMemory()){
                return true;
            }
        }
    }
    return false;
}

Song::~Song() {
    size = 0;
    artist = "";
    title = "";
}