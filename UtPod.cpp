
#include "UtPod.h"
#include <iostream>

UtPod::UtPod(){
  memSize = 0;
  SongNode *next = NULL;
};

UtPod::UtPod(int size){
  if((size>MAX_MEMORY) || (size <= 0)){
   memSize = MAX_MEMORY;
  }
  else{
    memSize = size;
  }
};

int UtPod::addSong(Song const &s){
    //Checks to see if there is space for the
  if(s.getMemory() > this->getTotalMemory() - this->getRemainingMemory()){
      return NO_MEMORY;
  }
  //Creates a new node to be added to the array
  SongNode *temp = new SongNode;
  temp->s.setArtist(s.getArtist());
  temp->s.setMemory(s.getMemory());
  temp->s.setSongTitle(s.getTitle());

  //Adds the node to the array
  temp->next = songs;
  songs = temp;
  return SUCCESS;
};

int UtPod::removeSong(Song const &s){
    //temporary node
    SongNode *temp = new SongNode;
    //first case for if the first node is the correct song;
    if(songs->s == s){
        temp = songs;
        songs = songs->next;
        delete(temp);
        return SUCCESS;
    }
    else{
    //traverses the linked list to find the specific song
    while(songs!= NULL){
        temp = songs;
        songs = songs->next;
        if(songs->s == s){
            temp->next = songs->next;
            delete(songs);
            return SUCCESS;
            }
        }
    }
  return NOT_FOUND;
};

void UtPod::shuffle(){

};

void UtPod::showSongList(){
    while(songs!= NULL){
        cout << songs->s.getTitle();
        cout << "/n";
        songs = songs->next;
    }
};

void UtPod::sortSongList(){
    SongNode *biggest;
  while(songs!= NULL){
      // temporary node for sort comparison
      SongNode *temp = new SongNode;
      temp = songs->next;
      while(temp!= NULL){
         biggest = songs;
          if(biggest->s < temp->s){
              biggest = temp;
          }
          //removes the biggest song from the list
          // once found
          int placeholder = this->removeSong(biggest->s);
      }
      //adds the biggest song in reverse order so the smallest is at the head
      int placholder = this->addSong(biggest->s);
      songs = songs->next;
  }
};

void UtPod::clearMemory(){
  while(songs!=NULL){
      SongNode *temp = new SongNode;
      temp = songs;
      songs = songs->next;
      delete(temp);
  }
};

int UtPod::getRemainingMemory(){
    //traverses linked list and finds the total amount of currrent memory
    int memory = 0;
    while(songs!= NULL){
        memory+= songs->s.getMemory();
    }
    //returns remaining memory
    return this->getTotalMemory() - memory;
};

UtPod::~UtPod() {
    this->clearMemory();
}
  
  
