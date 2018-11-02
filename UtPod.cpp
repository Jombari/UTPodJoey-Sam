
#include "UtPod.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
//#include <random>
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
int UtPod::removeSong(Song const &s) {
    //temporary node
    SongNode *temp;
    //there are no songs in the list
    // return no songs
    if (songs == NULL) {
        return NOT_FOUND;
    }
        //first song is the song to be found
    else if (songs->s == s) {
        temp = songs;
        songs = songs->next;
        delete (temp);
        return SUCCESS;
    } else {
        //traverses the linked list to find the specific song
        //reset the linked list after being traversed
        SongNode *p = songs;
        SongNode *temp = p;
        p = p->next;
        while (p != NULL) {
            if(p->s == s){
                temp->next = p->next;
                delete(p);
                return SUCCESS;
            }
            p = p->next;
            temp=temp->next;
        };
        return NOT_FOUND;
    };
}

//Merges a linked list in an unordered random configuration
UtPod::SongNode* UtPod::ShuffledMerge(SongNode* list1, SongNode* list2)
{
    SongNode* result = NULL;

//if list empty return
    if (list1 == NULL)
        return(list2);
    else if (list2==NULL)
        return(list1);

    //Randomly  pick a list to pull its values and add to main Song list
    if (rand()%2 == 0)
    {
        result = list1;
        result->next = ShuffledMerge(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = ShuffledMerge(list1, list2->next);
    }
    return(result);
};

//Mergesorts a linked list
UtPod::SongNode* UtPod::SortedMerge(SongNode* list1, SongNode* list2){
    SongNode* result;
    //if list empty return
    if (list1 == NULL)
        return(list2);
    else if (list2==NULL)
        return(list1);

    //Pick whichever list has a smaller head value and append it to the  start of the main list
    if (list1->s < list2->s)
    {
        result = list1;
        result->next = SortedMerge(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = SortedMerge(list1, list2->next);
    }
    return(result);

};
//Splits a linked list into two halves
void UtPod::SplitList(SongNode* source, SongNode** startRef, SongNode** endRef) {
    SongNode* list1;
    SongNode* list2;
    list2 = source;
    list1 = source->next;

    while (list1 != NULL)
    {
        list1 = list1->next;
        if (list1 != NULL)
        {
            list2 = list2->next;
            list1 = list1->next;
        }
    }


    *startRef = source;
    *endRef = list2->next;
    list2->next = NULL;
}

void UtPod::Transform(struct SongNode** headRef,int mode)
{
    int option = mode;

    SongNode*  headPtr = *headRef;
    SongNode* list1;
    SongNode* list2;

    //if 0 or 1  element return
    if ((headPtr == NULL) || (headPtr->next == NULL))
    {
        return;
    }

    SplitList(headPtr, &list1, &list2);

/* Recursively sort the sublists */
    Transform(&list1,mode);
    Transform(&list2,mode);

/* answer = merge the two sorted lists together */

//If mode = 0 then shuffle songs
//if mode = 1 then sort songs
    if(mode == 0)
        *headRef = ShuffledMerge(list1, list2);
    else if(mode ==1)
        *headRef = SortedMerge(list1,list2);
};

void UtPod::shuffle(){
    Transform(&songs,0);
};


//Prints the songs to the screen
void UtPod::showSongList(){
    //head must be saved after iterating through linked list
    SongNode *head = songs;
    while(songs!= NULL){
        cout<< "\n" << "Title: " << songs->s.getTitle() << " Artist: " << songs->s.getArtist() << " Size: " << songs->s.getMemory() << " MB";
        songs = songs->next;
    }
    songs = head;
    cout << "\n";
};

int UtPod::getNumSongs(){
    SongNode *head = songs;
    int count = 0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
};

void UtPod::swapSongs(SongNode *s1, SongNode *s2){
    SongNode *temp = s1;
    s1->s = s2->s;
    s2->s = temp->s;
};

void UtPod::sortSongList(){
    Transform(&songs,1);
}

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
  
  
