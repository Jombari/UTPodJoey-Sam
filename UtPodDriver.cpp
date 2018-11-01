/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    cout <<"UtPOD has memory size " << t.getRemainingMemory();

    UtPod test(4000);
    cout << "\nUtPod test(4000)     Test memory = " << test.getRemainingMemory();

    UtPod test2(-1);
    cout << "\nUtPod test2(-1)      Test2 memory = " << test2.getRemainingMemory();

    UtPod test3(12);
    cout << "\nUtPod test3(12)      Test3 memory = " << test3.getRemainingMemory();

    UtPod test4(512);
    cout << "\nUtPod test4(400)     Test4 memory = " << test4.getRemainingMemory();

    UtPod test5(60);
    cout << "\nUtPod test5(60)      Test5 memory = " << test5.getRemainingMemory() << "\n";


    cout << "\nTesting add song";
    Song s1("Beatles1", "Hey Jude1", 4);
    Song s2("Beatles2", "Hey Jude2", 5);
    Song s3("Beatles3", "Hey Jude3", 6);
    Song s4("Beatles4", "Hey Jude4", 7);
    Song s5("Beatles5", "Hey Jude5", 241);
    Song s6("Beatles6", "Hey Jude6", 6464);
    int result = t.addSong(s1);
    cout << "\nSong s1(\"Beatles1\", \"Hey Jude1\", 4); result = " << result;

    result = t.addSong(s2);
    cout << "\nSong s2(\"Beatles2\", \"Hey Jude2\", 5); result = "  << result;

    result = t.addSong(s3);
    cout << "\nSong s3(\"Beatles3\", \"Hey Jude3\", 6); result = "  << result;

    result = t.addSong(s4);
    cout << "\nSong s4(\"Beatles4\", \"Hey Jude4\", 7); result = "  << result;

    result = t.addSong(s5);
    cout << "\nSong s5(\"Beatles5\", \"Hey Jude5\", 241); result = "  << result << "\n";

    result = t.addSong(s6);
    cout << "Song s6(\"Beatles6\", \"Hey Jude6\", 6464); result = "  << result << "\n";
    t.showSongList();

    cout << "\nTesting remove song";
    result = t.removeSong(s3);
    cout << "\nRemoved Song s3(\"Beatles3\", \"Hey Jude3\", 6); result = "  << result;

    result = t.removeSong(s5);
    cout << "\nRemoved Song s5(\"Beatles5\", \"Hey Jude5\", 241); result = "  << result << "\n";

    t.showSongList();

    result = t.removeSong(s3);
    cout << "\nRemoved Song s3(\"Beatles3\", \"Hey Jude3\", 6); result = "  << result;

    result = t.removeSong(s2);
    cout << "\nRemoved Song s2(\"Beatles2\", \"Hey Jude2\", 5); result = "  << result;

    result = t.removeSong(s1);
    cout << "\nRemoved Song s1(\"Beatles1\", \"Hey Jude1\", 4);   result = " << result;
    t.showSongList();

    cout << "\nTesting sort";
    Song s7("Kanye", "Stronger", 4);
    Song s8("Kanye", "All of the Lights", 5);
    Song s9("Kanye", "Love Lockdown", 6);
    Song s10("Kanye", "Bounded", 7);
    Song s11("Drake", "Marvins Room", 8);
    Song s13("Sheq wes", "Mo Bamba", 9);
    Song s14("Drake", "More Life", 9);
    Song s15("Kendrick Lamar", "Sherane AKA Master Splinters Daughter", 9);
    Song s16("J cole", "Wet Dreamz", 9);

    result = test4.addSong(s7);
    result = test4.addSong(s8);
    result = test4.addSong(s9);
    result = test4.addSong(s10);
    result = test4.addSong(s11);
    result = test4.addSong(s13);
    result = test4.addSong(s14);
    result = test4.addSong(s15);
    result = test4.addSong(s16);
    result = test4.addSong(s11);

    test4.sortSongList();
    test4.showSongList();

    cout << "\nTesting shuffle";
    test4.shuffle();
    test4.showSongList();
    cout << "\nTest Sort";
    test4.sortSongList();
    test4.showSongList();

    cout << "\n Shuffle again";
    test4.shuffle();
    test4.showSongList();
    cout << "\nTest Sort";
    test4.sortSongList();
    test4.showSongList();

    cout << "\n Shuffle again";
    test4.shuffle();
    test4.showSongList();
    cout << "\nTest Sort";
    test4.sortSongList();
    test4.showSongList();

    cout << "\n Shuffle again";
    test4.shuffle();
    test4.showSongList();
    cout << "\nTest Sort";
    test4.sortSongList();
    test4.showSongList();


}