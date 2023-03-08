/* UTPod_driver.cpp
Demo Driver for the UTPod.

Roberto Reyes
EE 312 10/31/20

*/
#include <cstdlib>
#include <iostream>
#include <string>
#include "Song.h"
#include "UTPod.h"

using namespace std;

void testStringsEqual(string s1, string expected, string type) {
    if (s1 == expected) {
        cout << s1 << "; Expected " << type << " \"" << expected << "\". Passed test." 
            << endl;
    } else {
        cout << "Failed test " << s1 << " != " << expected << endl;
    }
}

void testIntsEqual(int x, int expected, string type) {
    if (x == expected) {
        cout << x << " MB; Expected " << type << " of " << expected << " MB. Passed test." 
            << endl;
    } else {
        cout << "Failed test " << x << " != " << expected << endl;
    }
}

bool checkResults(int results[], int length) {
    for (int i = 0; i < length; i++) {
        if (results[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    
    UTPod t;

    cout << endl;
    // Testing song constructor, getters, and setters
    Song s1("Paint It Black", "Rolling Stones", 2);
    Song s2("Separate Ways", "Journey", 3);
    Song s3("I Will Survive", "Gloria Gaynor", 2);
    Song s4("You Give Love a Bad Name", "Bon Jovi", 4);
    Song s5("Eye of the Tiger", "Survivor", 2);
    Song s6("The Final Countdown", "Europe", 5);
    Song s7("It's My Life", "Bon Jovi", 4);
    Song s8("Can't Fight This Feeling", "REO Speedwagon", 5);
    Song s9("Carry on Wayward Son", "Kansas", 2);
    Song s10("Don't Stop Believing", "Journey", 4);
    Song s11("Heat of the Moment", "Asia", 3);
    Song s12("Livin on a Prayer", "Bon Jovi", 5);

    cout << "Now testing song constructor:" << endl;
    testStringsEqual(s1.getSongName(), "Paint It Black", "song name");
    testStringsEqual(s1.getArtist(), "Rolling Stones", "artist");
    testIntsEqual(s1.getSize(), 2, "size");

    // now test setters
    s1.setTitle("I Ran So Far Away");
    s1.setArtist("A Flock of Seagulls");
    s1.setSize(3);

    cout << endl << "Now testing song setter functions:" << endl;
    testStringsEqual(s1.getSongName(), "I Ran So Far Away", "song name");
    testStringsEqual(s1.getArtist(), "A Flock of Seagulls", "artist");
    testIntsEqual(s1.getSize(), 3, "size");

    // set back to original values
    cout << endl << "Song set to original values." << endl;
    s1.setTitle("Paint It Black");
    s1.setArtist("Rolling Stones");
    s1.setSize(2);

    cout << endl << "Now testing for invalid song constructor:" << endl;
    Song s13("", "", 1);
    Song s14("Boo", "Halloween", 0);
    cout << endl << "Successfully caught invalid inputs without crashing." << endl;

    // test add function
    cout << endl << "Now testing add function:" << endl;
    int results[12];
    results[0] = t.addSong(s1);
    results[1] = t.addSong(s2);
    results[2] = t.addSong(s3);
    results[3] = t.addSong(s4);
    results[4] = t.addSong(s5);
    results[5] = t.addSong(s6);
    results[6] = t.addSong(s7);
    results[7] = t.addSong(s8);
    results[8] = t.addSong(s9);
    results[9] = t.addSong(s10);
    results[10] = t.addSong(s11);
    results[11] = t.addSong(s12);
    t.showSongList();
    bool b = checkResults(results, 12);
    if (b) {
        cout << "Sucessfully added all songs." << endl << endl;
    } else {
        cout << "Failed.";
    }

    // test memory functions
    cout << "Now testing memory functions:" << endl;
    testIntsEqual(t.getRemainingMemory(), 471, "remaining memory");
    testIntsEqual(t.getTotalMemory(), 512, "total memory");

    cout << endl << "Now testing if not enough memory to add:" << endl;
    cout << "Attempting to add song that is 600 MB." << endl;
    Song s15("The Final Countdown", "Europe", 600);
    t.addSong(s15);

    // test remove function
    cout << "Now testing remove function:" << endl;
    cout << "Before:" << endl;
    t.showSongList();
    cout << "After:" << endl;
    int result = t.removeSong(s2);
    if (result == 0) {
        cout << "Successfully removed s2." << endl << endl;
    }
    t.showSongList();
    result = t.removeSong(s12);
    if (result == 0) {
        cout << "Successfully removed s12." << endl << endl;
    }
    t.showSongList();
    result = t.removeSong(s1);
    if (result == 0) {
        cout << "Successfully removed s1." << endl << endl;
    }
    t.showSongList();

    //Now testing memory after removing song
    cout << "Memory remaining after removing songs:" << endl;
    testIntsEqual(t.getRemainingMemory(), 481, "remaining memory");
    cout << endl << endl;


    // test sorting method
    cout << "Now testing sorting function." << endl << endl;
    t.sortSongList();
    t.showSongList();
    cout << "Finished sorting function. " <<
    "All songs sorted alphabetically by artist and song name." << endl << endl;

    cout << "Now testing shuffle function." << endl << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Shuffling..." << endl;
        t.shuffle();
        t.showSongList();
        cout << "Shuffling complete." << endl << endl;
    }

    // Now testing clear function
    cout << "Now testing clear function." << endl;
    t.clearMemory();
    t.showSongList();

    cout << "Shuffling a list with one song." << endl;
    t.addSong(s1);
    t.showSongList();
    cout << "Shuffling..." << endl;
    t.shuffle();
    t.showSongList();
    cout << "Shuffling complete." << endl << endl;

    //testing removing song not in the list
    cout << "Now testing removing song that is not in the list." << endl;
    t.removeSong(s2);

    cout << "Sucessfully passed all tests." << endl << endl;
}
