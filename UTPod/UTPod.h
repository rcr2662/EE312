/* UTPod.h
Header file for UTPod.cpp

Roberto Reyes
EE 312 10/31/20

*/

#ifndef UTPod_H
#define UTPod_H
#include "Song.h"

//UTPod class declaration
class UTPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;
      
      struct SongNode
      {
         Song song;
         SongNode *next;
         SongNode *prev;
      };
      
      SongNode *songsHead;  //the head pointer
      SongNode *songsTail; // the tail pointer
      int numSongs;
      int memSize;

      // declare private helper functions
      void updateList(SongNode *current);
      int getLongestArtist();
      int getLongestSong();
      void copyList(SongNode* list[]);
      void sort(SongNode *list[], SongNode *tempList[],int low, int high);
      void merge(SongNode *list[], SongNode *tempList[], int leftPosition, int rightPosition, int rightEnd);
   
   public:
      //Default constructor
      //set the memory size to MAX_MEMORY
      UTPod();

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UTPod(int size);

      /* FUNCTION - int addSong
       * attempts to add a new song to the UTPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms -

       output parms -
      */

      int addSong(Song const &s);


      /* FUNCTION - int removeSong
       * attempts to remove a song from the UTPod
       * removes the first instance of a song that is in the the UTPod multiple times
           o returns 0 if successful
           o returns -1 if nothing is removed


         input parms -

         output parms -
      */

      int removeSong(Song const &s);


      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void shuffle();


      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -

         output parms -
      */

      void showSongList();


      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void sortSongList();


      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms -

         output parms -
      */
      void clearMemory();


      /* FUNCTION - int getTotalMemory
       *  returns the total amount of memory in the UTPod
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      int getTotalMemory();



      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -

         output parms -
      */

      int getRemainingMemory();


      ~UTPod();
};



#endif
