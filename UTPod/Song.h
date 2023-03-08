/* Song.h
Header file for Song.cpp

Roberto Reyes
EE 312 10/31/20

*/


#include <cstdlib>
#include <iostream>

#ifndef Song_H
#define Song_H

using namespace std;

// Song class declaration
class Song {

    private:
        string songTitle;
        string songArtist;
        int songSize;

    public:
    
    // create a default constructor
    Song();

    // create a song object
    // input params:
    // title: title of the song, artist: name of the artist
    // size: size of song in MB
    Song(string title, string artist, int size);

    // returns the song name
    string getSongName() const;

    // returns the artist name
    string getArtist() const;

    // returns the size of the song in MB
    int getSize() const;

    // set songTitle to input title
    void setTitle(string title);

    // set artist name to input artist
    void setArtist(string artist);

    // set songSize to input size
    void setSize(int size);

    // override equals operator
    // input params:
    // right = value to compare to this 
    // two Song objects are equal if they have the same title, artist, and size
    bool operator == (Song const &right);

    // override less than operator
    // input params:
    // right = value to compare to this 
    // this < right if artist less than right alphabetically, then song alphabetically
    // and finally if size less than right
    bool operator < (Song const &right);

    // override less than operator
    // input params:
    // right = value to compare to this 
    // this > right if artist greater than right alphabetically, then song alphabetically
    // and finally if size greater than right
    bool operator > (Song const &right);

};

#endif