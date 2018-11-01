
#include "UtPod.h"
#include <iostream>
//Base constructor for UTPod
// MEmory is 512 MB
UtPod::UtPod(){
  memSize = 512;
  songs = NULL;
};

//constructor for UTPod
//Memory is 512 MB
// or user input
UtPod::UtPod(int size){
  if((size>MAX_MEMORY) || (size <= 0)){
   memSize = MAX_MEMORY;
  }
  else{
    memSize = size;
  }
  songs = NULL;
};


//Pre-Conditions
//The UTPOD must have accurate memory
//s must be a real song
//Post-Conditions
// 0 = the song was added to the linked list
// -1 = there was not eneough memory in the utpod
int UtPod::addSong(Song const &s){
    // checks to see if the song takes up to much space
    if(s.getMemory()> this->getRemainingMemory()){
        return NO_MEMORY;
    }
  //Creates a new node to be added to the array
  SongNode *temp = new SongNode;
  temp->s.setArtist(s.getArtist());
  temp->s.setMemory(s.getMemory());
  temp->s.setSongTitle(s.getTitle());

  //Adds the node to the array
  temp->next = this->songs;
  songs = temp;
  return SUCCESS;
};

//Pre-conditions
//s must be a valid song
//Post Conditions
//-2 = song not found or UTpod Empty
//0 = song deleted
int UtPod::removeSong(Song const &s){
    //temporary node
    SongNode *temp;
    //there are no songs in the list
    // return no songs
    if(songs == NULL){
        return NOT_FOUND;
    }
    //first song is the song to be found
    else if(songs->s == s){
        temp = songs;
        songs = songs->next;
        delete(temp);
        return SUCCESS;
    }
    else{
    //traverses the linked list to find the specific song
    //reset the linked list after being traversed
    SongNode *head;
    while(songs != NULL){
        temp = songs;
        songs = songs->next;
        if(songs->s == s){
            temp->next = songs->next;
            delete(songs);
            songs = head;
            return SUCCESS;
            }
        }
        songs = head;
    }
  return NOT_FOUND;
};

void UtPod::shuffle(){

};


//Prints the songs to the screen
void UtPod::showSongList(){
    //head must be saved after iterating through linked list
    SongNode *head = songs;
    while(songs!= NULL){
        cout<< "\n" << songs->s.getTitle();
        songs = songs->next;
    }
    songs = head;
    cout << "\n";
};

void UtPod::sortSongList(){
    int indexOfSmallest;
    int i;
    SongNode *head = songs;


    SongNode *smallest = songs;
    for(songs;songs!= NULL;songs = songs->next){
        SongNode *temp = songs->next;
        for(temp;temp!=NULL;temp=temp->next){
            i++;
            if(smallest->s > temp->s){
                smallest = temp;
                indexOfSmallest = i;
            }
        }
        //swap the smallest song into the highest available spot in the linked list
        Song tempSong(songs->s.getArtist(),songs->s.getTitle(),songs->s.getMemory());
        songs->s.setArtist(smallest->s.getArtist());
        songs->s.setSongTitle(smallest->s.getTitle());
        songs->s.setMemory(smallest->s.getMemory());

        //replace the lovation of the smallest node with new data
        for(int i = indexOfSmallest;indexOfSmallest>0;i--){
            songs = songs->next;
        }
        songs->s.setMemory(tempSong.getMemory());
        songs->s.setSongTitle(tempSong.getTitle());
        songs->s.setArtist(tempSong.getArtist());
    };

//
//  while(songs!= NULL){
//      // temporary node for sort comparison
//      SongNode *temp = new SongNode;
//      temp = songs->next;
//      while(temp!= NULL){
//         biggest = songs;
//          if(biggest->s < temp->s){
//              biggest = temp;
//          }
//          //removes the biggest song from the list
//          // once found
//          int placeholder = this->removeSong(biggest->s);
//      }
//      //adds the biggest song in reverse order so the smallest is at the head
//      int placholder = this->addSong(biggest->s);
//      songs = songs->next;
//  }
  songs = head;
};

//removes all node from the linked list
void UtPod::clearMemory(){
  while(songs!=NULL){
      SongNode *temp;
      temp = songs;
      songs = songs->next;
      delete(temp);
  }
};

//traverses linked list and finds the total amount of usable memory
int UtPod::getRemainingMemory(){
    int memory = 0;
    SongNode *temp = songs;
    while(temp!=0){
        memory+= temp->s.getMemory();
        temp = temp->next;
    }
    //returns remaining memory
    return this->getTotalMemory() - memory;
};

//overidden deconstructer
UtPod::~UtPod() {
    this->clearMemory();
    memSize = 0;
}
  
  
