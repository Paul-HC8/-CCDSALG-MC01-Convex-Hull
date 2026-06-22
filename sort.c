/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 04  (2 digits)

    CHENG, DERK SIMONE C. S04
    CORTEZ, PAUL HAVEN C. S09
    SORILLA, JOSHUA DEL F. 

    PURPOSE OF THIS FILE: Implementation of the math helpers, Bubble Sort, and Quick Sort.
*/

#include <stdio.h>
#include "sort.h"


/* Anchor point -- the reference for polar angle computations.
   Must be set with setAnchor() before calling either sort. */
Point anchor;

/*
    a. Name of Programmer(s): Cheng, Derk Simone
    b. Name of Tester(s)    : LASTNAME3, FIRSTNAME3
    c. Code Type: 100% Human Generated
    d. Purpose: Sets the module-level anchor point used by polarAngle().
    e. Return: None
    f. Parameters: p is the anchor point (lowest y, leftmost if tie).
*/
void setAnchor(Point p)
{
    anchor = p;  /* store anchor for use in polar angle comparisons */
}

/*
    a. Name of Programmer(s): Cheng, Derk Simone 
    b. Name of Tester(s)    : LASTNAME3, FIRSTNAME3
    c. Code Type: 100% Human Generated
    d. Purpose: Computes the polar angle (in radians) from the anchor to p,
               measured counterclockwise from the positive x-axis direction.
               Uses atan2(dy, dx) which returns values in [-pi, pi].
    e. Return: double -- the polar angle in radians.
    f. Parameters: p is the point whose polar angle is computed.
*/
double polarAngle(Point p)
{
    double dx = p.x - anchor.x;  /* horizontal distance from anchor */
    double dy = p.y - anchor.y;  /* vertical distance from anchor */
    return atan2(dy, dx);         /* angle in radians */
}

/*
    a. Name of Programmer(s): Cheng, Derk Simone
    b. Name of Tester(s)    : LASTNAME1, FIRSTNAME1
    c. Code Type: 100% Human Generated
    d. Purpose: Computes the 2D cross product of vectors OA and OB.
               Positive result -> counterclockwise (left) turn.
               Zero result     -> collinear.
               Negative result -> clockwise (right) turn.
    e. Return: double -- the cross product value.
    f. Parameters: O is the origin point; A and B are the two endpoint points.
*/
double crossProduct(Point O, Point A, Point B)
{
    /* (A - O) x (B - O) */
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

/*
    a. Name of Programmer(s): LASTNAME2, FIRSTNAME2
    b. Name of Tester(s)    : LASTNAME3, FIRSTNAME3
    c. Code Type: 100% Human Generated
    d. Purpose: Compares two points by polar angle relative to the anchor.
               If angles are equal (collinear), the closer point comes first.
    e. Return: 1 if angle(a) > angle(b) (a should come after b), else 0.
    f. Parameters: a and b are the two Points to compare.
*/
static int comparePoints(Point a, Point b)
{
    double angleA = polarAngle(a);  /* polar angle of a */
    double angleB = polarAngle(b);  /* polar angle of b */

    if (angleA != angleB)
        return (angleA > angleB);  /* sort by ascending polar angle */

    /* collinear -- sort by distance from anchor (closer first) */
    double distA = (a.x - anchor.x) * (a.x - anchor.x)
                 + (a.y - anchor.y) * (a.y - anchor.y);
    double distB = (b.x - anchor.x) * (b.x - anchor.x)
                 + (b.y - anchor.y) * (b.y - anchor.y);
    return (distA > distB);
}

/*
    a. Name of Programmer(s): LASTNAME2, FIRSTNAME2
    b. Name of Tester(s)    : LASTNAME3, FIRSTNAME3
    c. Code Type: 100% Human Generated
    d. Purpose: Swaps two Point values in place.
    e. Return: None
    f. Parameters: a and b are pointers to the two Points to swap.
*/
static void swapPoints(Point *a, Point *b)
{
    Point tmp = *a;  /* save a */
    *a = *b;          /* overwrite a with b */
    *b = tmp;         /* overwrite b with saved a */
}

/*
    a. Name of Programmer(s): LASTNAME2, FIRSTNAME2
    b. Name of Tester(s)    : LASTNAME3, FIRSTNAME3
    c. Code Type: 100% Human Generated
    d. Purpose: Sorts pts[0..n-1] by polar angle relative to the anchor using
               Bubble Sort (the assigned "slow" algorithm for Group 04).
               Time complexity: O(n^2).
    e. Return: None
    f. Parameters: pts is the array of Points; n is the number of points.
*/
void bubbleSort(Point pts[], int n)
{
    int i, j;         /* loop counters */
    int swapped;      /* flag to detect early termination */

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            /* if pts[j] should come after pts[j+1], swap them */
            if (comparePoints(pts[j], pts[j + 1])) {
                swapPoints(&pts[j], &pts[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;  /* array is already sorted; exit early */
    }
}

/*
    a. Name of Programmer(s): LASTNAME3, FIRSTNAME3
    b. Name of Tester(s)    : LASTNAME2, FIRSTNAME2
    c. Code Type: 100% Human Generated
    d. Purpose: Partitions pts[left..right] around a pivot (rightmost element)
               for use in Quick Sort. Returns the final pivot index.
    e. Return: int -- the index of the pivot after partitioning.
    f. Parameters: pts is the array of Points; left and right are the bounds.
*/
static int partition(Point pts[], int left, int right)
{
    Point pivot = pts[right];  /* choose the rightmost element as pivot */
    int   i     = left - 1;    /* index of the last element <= pivot */
    int   j;                   /* loop counter */

    for (j = left; j < right; j++) {
        /* if pts[j] should come before or at the pivot position */
        if (!comparePoints(pts[j], pivot)) {
            i++;
            swapPoints(&pts[i], &pts[j]);  /* move pts[j] to the left side */
        }
    }
    swapPoints(&pts[i + 1], &pts[right]);  /* place pivot in its final spot */
    return i + 1;                           /* return pivot index */
}

/*
    a. Name of Programmer(s): LASTNAME3, FIRSTNAME3
    b. Name of Tester(s)    : LASTNAME2, FIRSTNAME2
    c. Code Type: 100% Human Generated
    d. Purpose: Sorts pts[left..right] by polar angle relative to the anchor
               using Quick Sort (the assigned "fast" algorithm for Group 04).
               Average time complexity: O(n log n).
    e. Return: None
    f. Parameters: pts is the array of Points; left and right are the bounds.
*/
void quickSort(Point pts[], int left, int right)
{
    int pivotIdx;  /* index of the pivot after partitioning */

    if (left < right) {
        pivotIdx = partition(pts, left, right);  /* partition the array */
        quickSort(pts, left, pivotIdx - 1);       /* sort left sub-array */
        quickSort(pts, pivotIdx + 1, right);      /* sort right sub-array */
    }
}

#endif /* SORT_C */
