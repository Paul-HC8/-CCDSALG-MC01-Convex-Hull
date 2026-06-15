/*

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 00 (2 digits)

    CHENG, DERK SIMONE 
    CORTEZ, PAUL HAVEN C. S09
    SORILLA, JOSHUA DEL F.  

    PURPOSE OF THIS FILE: to show an example of a C header file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS:
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    3. Do NOT use global variables!  NON-COMPLIANCE WILL RESULT INTO A 10 POINT DEDUCTION!
*/

/*
    You may encode any of the following below this comment the following:   
    1. #define directives
    2. typedef alias(es) 
    3. declaration of your user-defined struct data type(s)
    4. typedef alias(es) for your struct data type(s) -- you have to put an inline comment 
       for each struct member as part of the documentation. 

    The header should NOT include the codes for any function definitions.  

    Function definitions should be encoded in your C source file only!
*/

#include <stdio.h>
#include <stdlib.h>

// you may include other header files

// example FUNCTION PROTOTYPE -- remove this and the next line in your own codes
void Sample(int x);

// 2 Max size of stack of elements 
#define MAX_SIZE 32768

// 1. Struct for the x and y coordinates of a point
typedef struct Point {
    double x;  
    double y;  
} Point;

typedef struct Stack {
    Point points[MAX_SIZE]; // Location of all the points in the stack
    int count;             // index of the top element in the stack
} Stack;


