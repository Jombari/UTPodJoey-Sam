//
// Created by Samuel Yeboah on 10/28/2018.
//

#ifndef LAB5_SONG_H
#define LAB5_SONG_H
#include <iostream>
#include <string>
using namespace std;

class Song {

private:
    
    
public:
//Default Constructor
    Song();
    
//Overload Constructor
    Song(string songTitle, int songSize, string songArtist);

//Destructor
    ~Song();
    
//Accessor Functions
    
    //gets Title of Song
    string getTitle() const;
    
    //gets Artist Name
    string getArtist() const;
        
    //Gets the int value of how much memory the song takes up
    int getMemory() const;
    
    
//Modifier Functions
    
    //Sets the value of Song Memory size
    void setMemory(int size);
    
    //Sets the Song Artist Name
    void setArtist(string artistName);
    
    //Sets the Song Title Name
    void setSongTitle(string song);
    
    
    bool operator ==(Song const &song);
    bool operator <(Song const &song);
    bool operator >(Song const &song);
};


#endif //LAB5_SONG_H
