
#include "UtPod.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
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
        };
        return NOT_FOUND;
    };
}

UtPod::SongNode* UtPod::ShuffledMerge(SongNode* a, SongNode* b)
{
    SongNode* result = NULL;

/* Base cases */
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

/* Pick either a or b, and recur */
    if (rand()%2 == 0)
    {
        result = a;
        result->next = ShuffledMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = ShuffledMerge(a, b->next);
    }
    return(result);
};

UtPod::SongNode* UtPod::SortedMerge(SongNode* a, SongNode* b){
    SongNode* result;

/* Base cases */
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

/* Pick either a or b, and recur */
    if (a->s < b->s)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);

};

void UtPod::SplitList(SongNode* source, SongNode** frontRef, SongNode** backRef) {
    SongNode* fast;
    SongNode* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void UtPod::Transform(struct SongNode** headRef,int mode)
{
    int option = mode;

    SongNode*  head = *headRef;
    SongNode* a;
    SongNode* b;

/* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

/* Split head into 'a' and 'b' sublists */
    SplitList(head, &a, &b);
/* Recursively sort the sublists */
    Transform(&a,mode);
    Transform(&b,mode);

/* answer = merge the two sorted lists together */

//If mode = 0 then shuffle songs
//if mode = 1 then sort songs
    if(mode == 0)
        *headRef = ShuffledMerge(a, b);
    else if(mode ==1)
        *headRef = SortedMerge(a,b);
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
  
  
