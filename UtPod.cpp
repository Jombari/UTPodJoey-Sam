
#include "UtPod.h"
#include "song.h"
#include "song.cpp"

UtPod::UtPod(void){
  cout << "Object has been created" << endl;
}
UtPod::UtPod(int size){
  if((size>MAX_MEMORY) || (size <= 0)){
   memsize = MAX_MEMORY;
  }
  else{
    memsize = size;
  }
}

int UtPod::addSong(Song const &s){
  
}
