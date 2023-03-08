// life.h
// -- EE 312 Project 2

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Roberto Reyes, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name:Roberto Reyes
 * email address:robertoreyes@utexas.edu
 * UTEID:rcr2662
 * Section 5 digit ID:16025
 *
 *///
// Created by priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H


#endif //UNTITLED1_LIFE_H

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);

void showWorld(char *grid[], int numRows, int numCols);

void iterateGeneration(char *grid[], int numRows, int numCols);

int numNeighbors(int row, int column, char *grid[], int numRows, int numCols);

bool inBounds(int row, int column, int numRows, int numCols);