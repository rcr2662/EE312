/* mathStuff_xxxxxx.c

Programmer: Roberto Reyes
EE312  10/16/2020

Finish comments here
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);

//This takes the information from isPrime and checks if the number is prime.
bool check(int number, int divisor);


//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n);


//This takes the information from printPrimes and manages checking and printing the numbers.
void print(int n, int currNum);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//This function does the work for find Fibo
int Fibo (int numTimes, int Fib, int nMinusTwo, int nMinusOne);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);



void Factors (int number, int divisor);


//******************  MAIN  *****************************

int main () {
    
    
    int testNum;
    
    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);
    
    if (isPrime(testNum))  
       printf("%d is prime\n",testNum);
    else
       printf("%d is not prime.\n", testNum);
    
    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);
    
    printPrimes(testNum);
    
    printf("\n");
    
    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);
   
    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum)); 
    
    
    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);
    
    findFactors(testNum);
    
    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) {
   const int START_DIVISOR = 2; //HINT: You may want a helper function
   int divisor = START_DIVISOR;

   if(number < 2){                              //Any # less than 2 is not a prime number
      return false;
}
   else if ((number == 2) || (number == 3)){    //If # is 2 or 3, return true 
      return true;
   }
   else{
      return check(number, divisor);            
   }
}

bool check (int number, int divisor){            //Checks if number is fully divisible by all the numbers from 2 - number/2

   if(number % divisor == 0){
      return false;
   }

   else if(divisor == number/2){                  //If divisor is now half of the number then max divisors have been reached, number must be prime
      return true;
   }
   else{
      return check(number, divisor + 1);          //Number was not divisible by current divisor so check with next number
   }
}



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n) {                         
   int currNum = 2;

   print(n, currNum);
   return;
}

void print(int n, int currNum){
   
   if(n < currNum){                                //if number is less than currNum, it is either less than 2 or all numbers in range have been checked
      return;
   }
   else if(isPrime(currNum)){                      //If current number being checked is prime, print it.
      printf("%d ", currNum);

   }
   print(n, currNum + 1);                           //check next number.
}



//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
   int numTimes = n;
   int Fib = 0;
   int nMinusTwo = 0;
   int nMinusOne = 1;

   if(n == 0){                                         //0th term of Fibo sequence is 0
      return 0;
   }
   else if(n == 1){                                    //1st term is 1.
      return 1;
   }
   else {
      return Fibo (numTimes, Fib, nMinusTwo, nMinusOne);
   }
}

int Fibo(int numTimes, int Fib, int nMinusTwo, int nMinusOne){
   if(numTimes == 1){                                    //computation for nth term has finished.
      return Fib;
   }
   else{
      Fib = nMinusTwo + nMinusOne;                        //Fib is the sum of the previous two terms.
      nMinusTwo = nMinusOne;                              //Update terms to compute next sum.
      nMinusOne = Fib;
      return Fibo(numTimes-1, Fib, nMinusTwo, nMinusOne); //Decrement the number of sums that need to be computed.
   }  
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    int divisor = START_DIVISOR;

    if(isPrime(number)){                                      //If number is prime, print out that its prime.
       printf("%d=prime\n", number);
    }
    else{
       printf("%d=", number);
       Factors(number, divisor);
    }
}
    
void Factors(int number, int divisor){
      
   if((isPrime(divisor) == false) || (number % divisor != 0)){       //If divisor is not prime or the number is not fully  divisible by it, check next divisor.
      divisor++;
   }
   else {
      printf("%d", divisor);                                            
      number = number / divisor;                                      //Update number 
      divisor = 2;                                                    //restart divisor to check next number

      if(number != 1){                                                //If number is not one, last factor not found yet
         printf("*");
      }
      else{                                                           //Last factor has been found
         printf("\n");
         return;
      }
   }
   Factors(number, divisor);                                          //check with new number or divisor
}
