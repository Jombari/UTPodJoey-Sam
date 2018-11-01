/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    cout << t.getTotalMemory() << "\n";

    Song s1("Beatles", "Hey Jude1", 10);
    Song s2("Beatles", "Hey Jude2", 2);
    int result = t.addSong(s1);
    t.showSongList();
    result = t.addSong(s2);
    cout << t.getRemainingMemory()<<"\n";

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    t.addSong(s3);
    cout<<"Adding song s3 \n\n";
    t.showSongList();
    t.removeSong(s1);
    cout <<"\n"<< "removing song s1 \n";
    t.removeSong(s3);
    cout<<"removing song s3 \n\n";
    t.showSongList();
    cout<<"\n";
    t.addSong(s1);

    t.addSong(s3);
    t.addSong(s3);
    t.addSong(s3);
    t.addSong(s3);
    t.showSongList();
    t.clearMemory();
    t.showSongList();
//
//    Song s4("Beatles", "Hey Jude4", 7);
//    result = t.addSong(s4);
//    cout << "result = " << result << endl;
//
//    Song s5("Beatles", "Hey Jude5", 241);
//    result = t.addSong(s5);
//    cout << "add result = " << result << endl;
//
//    t.showSongList();

//    result = t.removeSong(s2);
//    cout << "delete result = " << result << endl;
//
//    result = t.removeSong(s3);
//    cout << "delete result = " << result << endl;
//
//    t.showSongList();
//
//    result = t.removeSong(s1);
//    cout << "delete result = " << result << endl;
//
//    result = t.removeSong(s5);
//    cout << "delete result = " << result << endl;
//
//    result = t.removeSong(s4);
//    cout << "delete result = " << result << endl;
//
//
//    t.showSongList();
//
//    result = t.addSong(s5);
//    cout << "add result = " << result << endl;
//
//    t.showSongList();
//    cout << "memory = " << t.getRemainingMemory() << endl;
//

}