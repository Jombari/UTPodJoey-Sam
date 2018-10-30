
#include "UtPod.h"


UtPod::UtPod(){
  
};

UtPod::UtPod(int size){
  if((size>MAX_MEMORY) || (size <= 0)){
   memsize = MAX_MEMORY;
  }
  else{
    memsize = size;
  }
};

int UtPod::addSong(Song const &s){
  SongNode *tmp;
  tmp ->s = s;
  if(getRemainingMemory() == getTotalMemory()){
    tmp -> next = tmp;
  }
  else{
    tmp -> next = songs->next;
  }
  songs-> next = tmp;
  
};

int UtPod::removeSong(Song const &s){
  
};

void UtPod::shuffle(){

};

void UTPod::showSongList(){
  
};

void UTPod::sortSongList(){
  
};

void UTPod::clearMemory(){
  
};

int UTPod::getTotalMemory(){
  
};

int UTPod::getRemainingMemory(){
  
};
  
  
