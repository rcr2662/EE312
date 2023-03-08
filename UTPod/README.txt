UTPod
This program acts like a small version of an iPod, with the capability of songs being added to it and removed from it,
sorting the songs it has, and shuffling them. Currently running this program will cause it to go through several tests
to prove its capabilities.

Implementation:
I implemented a Song class to store the details of a Song object and to overload
the operators to define the relationship between two Song objects. In my UTPod class, I 
added a listTail variable to efficiently add a new SongNode to the end of the linked list
structure. I also added a numSongs variable to be able to efficiently get the size of the
linked list. As for the shuffling and sorting algorithms, I implemented a merge sort algorithm
which is O(NlogN) complexity, the most efficient possible of the sorting algorithms. 
To shuffle, I implemented a simple iterative approach by getting a random integer and 
swapping the current index with the song at the random integer. This would be an O(N) approach. 
For both algorithms, I converted the list into an array structure to allow for O(1) access of songs.
Once done with the processing, I copied the array back into the list structure.

Building and Running:
1. Download the zip file.
2. Extract the files from the compressed zip file.
3. Pass the extracted files on to a Linux machine using programs such as FileZilla
or the command prompt.
4. On the Linux machine, type "make" to compile the program, producing an executable
called "tests".
5. Run the program by typing ./sdriver.
6. All test cases will be then be run and you can examine the output.