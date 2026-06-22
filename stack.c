/**

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 04  (2 digits)

    CHENG, DERK SIMONE C. S04
    CORTEZ, PAUL HAVEN C. S09
    SORILLA, JOSHUA DEL F. S09
    

    PURPOSE OF THIS FILE: to show an example of a C source file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!

*/

#include <stdio.h>
#include <stdlib.h>

// include your own stack header file
#include "stack.h"


/*
    EACH FUNCTION DEFINITION MUST BE PRECEDED BY A INLINE DOCUMENTATION CONTAINING THE FOLLOWING:

    a. Name of Programmer(s)
    b. Name of Tester(s) -- for an unbiased black box testing, the tester should NOT be the same person as the programmer.
    c. Code Type -- indicate EXPLICITLY if the code is one of the following: 100% Human Generated code, 100% AI Generated code
       or a modified AI generated code.  If it is a modified AI generated code, indicate explicitly which lines were 
       modified and the reason why a line of code had to be modified.
    d. Purpose -- indicate the purpose of the function
    e. Return -- indicate what will be returned (type None for void functions)
    f. Parameters -- indicate the nature of the parameters

    An example is shown below.  

    Remove the Sample() function in your own C source code.
*/


/*
    1. CREATE
    a. Name of Programmer(s):  CORTEZ, PAUL HAVEN C.
    b. Name of Tester(s)    :  SORILLA, JOSHUA DEL F.
    c. Code Type -- 100% Human Generated 
    d. Purpose: Creates an empty stack
    e. Return: void
    f. Parameters: pointer to a stack struct variable
*/
void CREATE(Stack *S)
{
   S->count = 0;
}

/*  
    2. PUSH
    a. Name of Programmer(s):  CORTEZ, PAUL HAVEN C.
    b. Name of Tester(s)    :  SORILLA, JOSHUA DEL F.
    c. Code Type -- 100% Human Generated 
    d. Purpose: Checks if the stack is not full and pushes/inserts a point to the stack and updates the count of the stack.
    e. Return: void
    f. Parameters: pointer to a stack struct variable, point to be pushed/inserted
*/

void PUSH(Stack *S, Point elem)
{
   if (S->count < MAX_SIZE) {
      S->points[S->count] = elem;
      S->count++;
   } else {
      printf("Error: Can't push to a full stack\n");
   }
}

/*
    3. POP
    a. Name of Programmer(s):  CORTEZ, PAUL HAVEN C.
    b. Name of Tester(s)    :  SORILLA, JOSHUA DEL F.
    c. Code Type -- 100% Human Generated 
    d. Purpose: Checks if the stack is not empty and pops/deletes the top point from the stack and updates the count of the stack.  
    e. Return: elem the top in the stack
    f. Parameters: pointer to a stack struct variable
*/
Point POP(Stack *S)
{
   if (S->count > 0) {
      S->count--;
      return S->points[S->count];
   } else {
      printf("Error: Can't pop an empty stack\n");
      exit(1);
   }
}



/*
    4. TOP
    a. Name of Programmer(s):  CORTEZ, PAUL HAVEN C.
    b. Name of Tester(s)    :  SORILLA, JOSHUA DEL F.
    c. Code Type -- 100% Human Generated 
    d. Purpose: Gets the top element from the stack and returns it
    e. Return: elem (the top in the stack)
    f. Parameters: pointer to a stack struct variable, pointer to a point variable where the popped/deleted point will be stored
*/
Point TOP(Stack *S)
{
   if (S->count > 0) {
      return S->points[S->count - 1];
   } else {
      printf("Error: Can't access top of an empty stack\n");
      exit(1);
   }
}

/*
    5. ISFULL
    a. Name of Programmer(s):  CORTEZ, PAUL HAVEN C.
    b. Name of Tester(s)    :  SORILLA, JOSHUA DEL F.
    c. Code Type -- 100% Human Generated 
    d. Purpose: Checks if the stack is full
    e. Return: int (1 if full, 0 otherwise)
    f. Parameters: pointer to a stack struct variable
*/
int ISFULL(Stack *S)
{
   if (S->count >= MAX_SIZE) {
      return 1;
   } else {
      return 0;
   }
}

/*
    5. ISEMPTY
    a. Name of Programmer(s):  CORTEZ, PAUL HAVEN C.
    b. Name of Tester(s)    :  CHENG, DERK SIMONE C.
    c. Code Type -- 100% Human Generated 
    d. Purpose: Checks if the stack is empty
    e. Return: int (1 if empty, 0 otherwise)
    f. Parameters: pointer to a stack struct variable
*/
int ISEMPTY(Stack *S)
{
   if (S->count == 0) {
      return 1;
   } else {
      return 0;
   }
}

/*
    7. NEXT_TO_TOP
    a. Name of Programmer(s): Cortez, Paul Haven C.
    b. Name of Tester(s)    : Cheng, Derk Simone C.
    c. Code Type -- 100% Human Generated 
    d. Purpose: Gets the element immediately below the top element of the stack.
    e. Return: elem (the second-to-top point in the stack)
    f. Parameters: pointer to a stack struct variable
*/
Point NEXT_TO_TOP(Stack *S)
{
   if (S->count >= 2) {
      return S->points[S->count - 2];
   } else {
      printf("Error: Stack needs at least 2 elements for NEXT_TO_TOP\n");
      exit(1);
   }
}

