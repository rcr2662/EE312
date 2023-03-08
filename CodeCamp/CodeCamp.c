#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

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
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
  int count = 0;
  for(int i = 0; i < len; i++) {
      if (aList[i] != bList[i]) count++;
  }
    return count;
      }





/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {
 int ld1 = abs(num1 % 10);
 int ld2 = abs(num2 % 10);

 if(ld1 != ld2)return false;
 else return true;

}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {
    int total = 0;
    for(int i = 3; i < 1000; i += 3) total += i;
    for(int i = 5; i < 1000; i += 5){
        if(i % 3 != 0)total +=i;
    }
return total;


}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {
    int reverse = 0;
    while(num != 0){
        reverse *= 10;
        reverse += num % 10;
        num /= 10;
    }
    num = reverse;
    if(num >= -2147483648 && num <= 2147483647)return num;
    else return 0;
}

  

