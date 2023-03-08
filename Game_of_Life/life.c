//
// Created by reyes on 9/16/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

#include "life.h"

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {
    FILE *fp = fopen(fname, "r");   //Make file pointer and open file for reading
    *numCols = 0;
    while (fgetc(fp) != '\n') {     //Count number of columns that don't have /n character
        (*numCols)++;
    }
    fclose(fp);

    fp = fopen(fname, "r");         //Reset pointer to top of file
    char *input = (char *) malloc(*numCols + 2);
    *numRows = 0;
    while (fgets(input, *numCols + 2, fp)) {        //While input from file is true, malloc space for rows
        grid[*numRows] = (char *) malloc(*numCols + 1);
        input[*numCols] = '\0';
        strcpy(grid[*numRows], input);
        for (int i = 0; i < *numCols; i++) {        //Replace 0 '.'
            if (grid[*numRows][i] == '0') {
                grid[*numRows][i] = '.';
            } else if (grid[*numRows][i] == '1') {  //Replace 1 '*'
                grid[*numRows][i] = '*';
            }
        }
        (*numRows)++;
    }
    free(input);
    fclose(fp);
}

void showWorld(char *grid[], int numRows, int numCols) {          //Print grid
    for (int r = 0; r < numRows; r++) {
        printf("%s\n", grid[r]);
    }
}

void iterateGeneration(char *grid[], int numRows, int numCols) {    //Update grid with new generation
    char *newGrid[numRows];
    for (int r = 0; r < numRows; r++) {                             //Make copy of grid and malloc space
        newGrid[r] = malloc(numCols + 1);
        strcpy(newGrid[r], grid[r]);
    }
    for (int r = 0; r < numRows; r++) {                                //Different checks for new generation
        for (int c = 0; c < numCols; c++) {
            if (grid[r][c] == '.' && numNeighbors(r, c, grid, numRows, numCols) == 3) {
                newGrid[r][c] = '*';
            } else if (grid[r][c] == '*' && numNeighbors(r, c, grid, numRows, numCols) >= 4) {
                newGrid[r][c] = '.';
            } else if (grid[r][c] == '*' && numNeighbors(r, c, grid, numRows, numCols) <= 1) {
                newGrid[r][c] = '.';
            }
        }
    }
    for (int r = 0; r < numRows; r++) {                         //Update grid and free newGrid
        strcpy(grid[r], newGrid[r]);
        free(newGrid[r]);
    }
}

int numNeighbors(int row, int column, char *grid[], int numRows, int numCols) {           //Count number of cell neighbors
    int numNeighbors = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = column - 1; c <= column + 1; c++) {
            if (inBounds(r, c, numRows, numCols) && grid[r][c] == '*' && !(r == row && c == column)) {
                numNeighbors++;
            }
        }
    }
    return numNeighbors;
}

bool inBounds(int row, int column, int numRows, int numCols) {             //Check to make sure current position is in bounds
    return row >= 0 && row < numRows && column >= 0 && column < numCols;
}

