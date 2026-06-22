/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 04 (2 digits)

    CHENG, DERK SIMONE C.  S04
    CORTEZ, PAUL HAVEN C.  S09
    SORILLA, JOSHUA D.     S09

    PURPOSE OF THIS FILE: to show an example of a test driver program.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/
#include <stdio.h>
#include <stdlib.h>
#include "sort.c"   /* include source so the sort functions are defined */

/* Helper function to print an array of points.
*/
void printPoints(Point *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("  Point %d: (%6.2lf, %6.2lf)\n", i, arr[i].x, arr[i].y);
    }
    printf("\n");
}

int main()
{
    int n = 6;
    Point anchor = {0.0, 0.0}; // Anchor point (lowest y, leftmost if tie)

    /* Test data: mixed points around the anchor */
    Point pointsBubble[6] = {
        {2.0, 5.0}, {4.0, 1.0}, {-1.0, 3.0},
        {-3.0, -1.0}, {3.0, 2.0}, {-2.0, 5.0}
    };

    /* Duplicate array to test Quick Sort cleanly */
    Point pointsQuick[6] = {
        {2.0, 5.0}, {4.0, 1.0}, {-1.0, 3.0},
        {-3.0, -1.0}, {3.0, 2.0}, {-2.0, 5.0}
    };

    printf("--- SORTING MODULE TEST DRIVER ---\n\n");
    printf("Anchor Point: (%.2lf, %.2lf)\n\n", anchor.x, anchor.y);

    /* 1. Test Bubble Sort (SLOW) */
    printf("--- TESTING BUBBLE SORT (SLOW) ---\n");
    printf("Before Sorting:\n");
    printPoints(pointsBubble, n);

    bubbleSort(pointsBubble, n, anchor);

    printf("After Bubble Sort (Ordered by Polar Angle):\n");
    printPoints(pointsBubble, n);

    /* 2. Test Quick Sort (FAST) */
    printf("--- TESTING QUICK SORT (FAST) ---\n");
    printf("Before Sorting:\n");
    printPoints(pointsQuick, n);

    quickSort(pointsQuick, 0, n - 1, anchor);

    printf("After Quick Sort (Ordered by Polar Angle):\n");
    printPoints(pointsQuick, n);

    return 0;
}
