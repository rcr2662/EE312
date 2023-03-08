/* Song.cpp

Roberto Reyes
EE 312 10/31/20

*/


#include <iostream>
#include "Song.h"

using namespace std;

Song::Song() {
    songTitle = "";
    songArtist = "";
    songSize = 0;
}

Song::Song(string title, string artist, int size) {
    if (title.length() > 0 && artist.length() > 0 && size > 0) {
        songTitle = title;
        songArtist = artist;
        songSize = size;
    } else if (title.length() == 0 || artist.length() == 0) {
        cout << "Title and artist cannot be blank." << endl;
    } else if (size <= 0) {
        cout << "Size must be greater than 0";
    }
}

string Song::getSongName() const {
    return songTitle;
}

string Song::getArtist() const {
    return songArtist;
}

int Song::getSize() const {
    return songSize;
}

void Song::setTitle(string newTitle) {
    songTitle = newTitle;
}

void Song::setArtist(string newArtist) {
    songArtist = newArtist;
}
    
void Song::setSize(int newSize) {
    songSize = newSize;
}

bool Song::operator == (Song const &right) {
    int songResult = songTitle == right.getSongName();
    int artistResult = songArtist == right.getArtist();
    bool sizeResult = songSize == right.getSize(); 
    return songResult && artistResult && sizeResult; 
}

bool Song::operator < (Song const &right) {
    int result = songArtist.compare(right.songArtist);
    if (result < 0) {
        return true;
    } else {
        if (result == 0) {
            result = songTitle.compare(right.getSongName());
            if (result < 0) {
                return true;
            } else if (result == 0) {
                return songSize < right.getSize();
            }
        }
        return false;
    }
}
    
bool Song::operator > (Song const &right) {
    int result = songArtist.compare(right.songArtist);
    if (result > 0) {
        return true;
    } else {
        if (result == 0) {
            result = songTitle.compare(right.getSongName());
            if (result > 0) {
                return true;
            } else if (result == 0) {
                return songSize > right.getSize();
            }
        }
        return false;
    }
}

