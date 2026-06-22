/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 04 (2 digits)

    CHENG, DERK SIMONE C. S04
    CORTEZ, PAUL HAVEN C. S09
    SORILLA, JOSHUA DEL F.

    PURPOSE OF THIS FILE: to show an example of a test driver program.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/

#include <stdio.h>
#include <stdlib.h>

// include your own stack C source file
#include "stack.c"

int main()
{
    // 1. Initialize the stack and test CREATE
    Stack S;
    CREATE(&S);
    printf("--- INITIALIZATION ---\n");
    printf("Stack created.\n");

    // 2. Test ISEMPTY
    if (ISEMPTY(&S)) {
        printf("ISEMPTY check: Stack is currently empty (Correct).\n\n");
    }

    // Create some dummy points for testing
    Point p1 = {1.5, 2.5};
    Point p2 = {3.0, 4.0};
    Point p3 = {5.5, 6.5};

    // 3. Test PUSH
    printf("--- PUSHING POINTS ---\n");
    PUSH(&S, p1);
    printf("Pushed Point 1: (%.2lf, %.2lf)\n", p1.x, p1.y);
    PUSH(&S, p2);
    printf("Pushed Point 2: (%.2lf, %.2lf)\n", p2.x, p2.y);
    PUSH(&S, p3);
    printf("Pushed Point 3: (%.2lf, %.2lf)\n\n", p3.x, p3.y);

    // 4. Test ISFULL
    if (!ISFULL(&S)) {
        printf("ISFULL check: Stack is NOT full (Correct). Current count: %d\n\n", S.count);
    }

    // 5. Test TOP
    Point topPoint = TOP(&S);
    printf("--- TESTING TOP AND NEXT-TO-TOP ---\n");
    printf("Expected Top: (5.50, 6.50)\n");
    printf("Actual Top  : (%.2lf, %.2lf)\n\n", topPoint.x, topPoint.y);

    // 6. Test NEXT_TO_TOP
    Point nextToTopPoint = NEXT_TO_TOP(&S);
    printf("Expected Next-to-Top: (3.00, 4.00)\n");
    printf("Actual Next-to-Top  : (%.2lf, %.2lf)\n\n", nextToTopPoint.x, nextToTopPoint.y);

    // 7. Test POP
    printf("--- TESTING POP ---\n");
    Point poppedPoint = POP(&S);
    printf("Popped Point: (%.2lf, %.2lf)\n", poppedPoint.x, poppedPoint.y);
    
    // Check what the new top is after popping
    topPoint = TOP(&S);
    printf("New Top after POP should be Point 2: (%.2lf, %.2lf)\n\n", topPoint.x, topPoint.y);

    // Empty the rest of the stack
    printf("--- POPPING REMAINING ELEMENTS ---\n");
    POP(&S);
    POP(&S);
    
    if (ISEMPTY(&S)) {
        printf("Stack is now empty again. All tests passed successfully!\n");
    }

    /* NOTE TO TESTERS: 
       If you want to test the exit(1) safety mechanism, uncomment the line below. 
       The program should intentionally halt and print "Error: Can't pop an empty stack"
       
       // POP(&S); 
    */

    return 0;
}

