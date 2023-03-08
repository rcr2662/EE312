/* UTPod.cpp

Roberto Reyes
EE 312 10/31/20

*/



#include <cstdlib>
#include <iostream>
#include <ctime>
#include "UTPod.h"
#include "Song.h"

using namespace std;

UTPod::UTPod() {  //Initialize pod
    memSize = MAX_MEMORY;   
    numSongs = 0;       
    songsHead = NULL;
    songsTail = NULL;
}

UTPod::UTPod(int size) {            
    if (size > MAX_MEMORY || size <= 0) {   //If the size is greater than MAX_MEMORY or less than or equal to 0, set the size to MAX_MEMORY.
        memSize = MAX_MEMORY;
    } else {
        memSize = size;
    }
    numSongs = 0;
    songsHead = NULL;
    songsTail = NULL;
}

int UTPod::addSong(Song const &s) {
    int songSize = s.getSize(); //size of song
    if (getRemainingMemory() < songSize) {   //If not enough memory to add song
        cout << "Not enough memory: " << getRemainingMemory() << " MB left." << endl << endl;
        return NO_MEMORY;   //0
    }
    SongNode *newSong = new SongNode;   //space for new node
    newSong->song = s;                  //set new node
    newSong->next = NULL;
    newSong->prev = NULL;
    if (numSongs == 0) {    //if first song
        songsHead = newSong;
        songsTail = newSong;
        newSong->prev = NULL;
    } else {
        newSong->prev = songsTail;  //set prev to list's current tail
        songsTail->next = newSong;  //set tail's next to new node
        songsTail = newSong;        //set new node as tail
    }
    numSongs++; //increment number of songs
    return SUCCESS;
}

void UTPod::updateList(SongNode* current) { //helper for removeSong()
    SongNode *prev = current->prev;
    SongNode *next = current->next;
    if (prev == NULL && next != NULL) { //if first song
        songsHead = next;
        next->prev = NULL;
    } else if (prev != NULL && next == NULL) {  //if last song
        songsTail = prev;
        prev->next = NULL;
    } else if (prev != NULL && next != NULL) {  //jf inbetween songs
        prev->next = next;
        next->prev = prev;
    } else {    //if only song in list
        songsHead = NULL;
        songsTail = NULL;
    }
    delete(current);    //free deleted song's space
    numSongs--; //decrement number of songs
}

int UTPod::removeSong(Song const &s) {
    if (numSongs == 0) {    //if list is empty
        cout << "List is empty." << endl << endl;
        return -1;
    }
    SongNode *current = songsHead;  //set to start of list
    while (current != NULL) {   //while the last song hasn't been checked
        Song song = current->song;
        if (song == s) {    //if song being checked is the same as the one to be removed
            updateList(current);
            return SUCCESS;
        }
        current = current->next;    //current song is now the next song
    }
    cout << "Song not found." << endl << endl;   //if song isn't in the list
    return -1;
}

void UTPod::shuffle() {
    if (numSongs > 1) {
        // copy the nodes into a temporary array
        SongNode *nodes[numSongs];
        SongNode *current = songsHead;
        for (int index = 0; index < numSongs; index++) {
            nodes[index] = current;
            current = current->next;
        }
        srand(time(0));
        // get a random number and swap the current element with the element
        // at the random index
        for (int index = numSongs - 1; index > 0; index--) {
            int random = rand() % index;
            SongNode *temp = nodes[index];
            nodes[index] = nodes[random];
            nodes[random] = temp;
        }
        copyList(nodes);
    }
}

void UTPod::copyList(SongNode *nodes[]) {   //helper 
    // copy newly ordered nodes back into the linked list
    songsHead = nodes[0];  
    songsHead->prev = NULL;
    songsHead->next = nodes[1];
    SongNode* temp = songsHead->next;
    for (int index = 1; index < numSongs - 1; index++) {
        temp->next = nodes[index + 1];
        temp->prev = nodes[index - 1];
        temp = temp->next;
    }
    songsTail = temp;
    temp->prev = nodes[numSongs - 2];
    temp->next = NULL;
}

void UTPod::showSongList() {
    if(numSongs == 0){
        cout << "List is empty." << endl;
    }
    //prints out list of songs 
    else{int maxArtist = getLongestArtist(); //longest artist
        int maxSong = getLongestSong(); //longest song
        SongNode *current = songsHead;
        while (current != NULL) {
            Song song = current->song;
            string name = "Song: " + song.getSongName();
            int numSpaces = maxSong - name.length();
            for (int i = 0; i < numSpaces; i++) {   //gives all songs same column space   
                name += " ";
            }
            string artist = "by " + song.getArtist();
            numSpaces = maxArtist - artist.length();
            for (int i = 0; i < numSpaces; i++) {   //gives all artists same column space   
                artist += " ";
            }
            cout << name << artist << song.getSize() << " MB" << endl;
            current = current->next;
        }
    }
    cout << endl;
}

int UTPod::getLongestArtist() { //helper for showSongList
    unsigned int maxLength = 0;
    SongNode *current = songsHead;
    while (current != NULL) {
        Song song = current->song;
        string artist = "by " + song.getArtist();
        if (artist.length() > maxLength) {
            maxLength = artist.length();
        }
        current = current->next;
    }
    return maxLength + 4;   //max length + tab
}

int UTPod::getLongestSong() {   //helper for showSongList     
    unsigned int maxLength = 0;
    SongNode *current = songsHead;
    while (current != NULL) {
        Song song = current->song;
        string name = "Song: " + song.getSongName();
        if (name.length() > maxLength) {
            maxLength = name.length();
        }
        current = current->next;
    }
    return maxLength + 4;   //max length + tab
}

// implemented using a merge sort algorithm
void UTPod::sortSongList() {
    SongNode *nodes[numSongs];
    SongNode *current = songsHead;
    for (int index = 0; index < numSongs; index++) {
        nodes[index] = current;
        current = current->next;
    }
    SongNode *tempList[numSongs];
    sort(nodes, tempList, 0, numSongs - 1);
    copyList(nodes);
}

void UTPod::sort(SongNode *list[], SongNode *tempList[], int low, int high) {   //helper for sortSongList
    if (low < high) {
        int center = (low + high) / 2;
		sort(list, tempList, low, center);
		sort(list, tempList, center + 1, high);
		merge(list, tempList, low, center + 1, high);
    }
}

void UTPod::merge(SongNode *list[], SongNode *tempList[],
                int leftPosition, int rightPosition, int rightEnd) {    //helper for sort
    int leftEnd = rightPosition - 1;
    int tempPosition = leftPosition;
	int numElements = rightEnd - leftPosition + 1;
    while (leftPosition <= leftEnd && rightPosition <= rightEnd) {
		SongNode *leftNode = list[leftPosition];
		SongNode *rightNode = list[rightPosition];
		if (leftNode->song < rightNode->song) {
			tempList[tempPosition] = leftNode;
			leftPosition++;
		} else {
			tempList[tempPosition] = rightNode;
			rightPosition++;
		}
        tempPosition++;
	}
    // add back the remaining elements
	while (leftPosition <= leftEnd) {
        tempList[tempPosition] = list[leftPosition];
        tempPosition++;
		leftPosition++;
	}
	while (rightPosition <= rightEnd) {
        tempList[tempPosition] = list[rightPosition];
        tempPosition++;
		rightPosition++;
	}
    for (int index = 0; index < numElements; index++, rightEnd--) {
        list[rightEnd] = tempList[rightEnd];
    }
}

void UTPod::clearMemory() {
    SongNode *current = songsHead;
    while (current != NULL) {
        SongNode *next = current->next;
        delete(current);
        current = next;
    }
    songsHead = NULL;
    songsTail = NULL;
    numSongs = 0;
}

int UTPod::getTotalMemory(){
    if (numSongs < 2){
        return 0;
    }
    else return memSize;
}
int UTPod::getRemainingMemory() {
    SongNode *current = songsHead;
    int remaining = memSize;
    while (current != NULL) {
        Song song = current->song;
        remaining -= song.getSize();
        current = current->next;
    }
    return remaining;
}

UTPod::~UTPod() {
    clearMemory();
}

