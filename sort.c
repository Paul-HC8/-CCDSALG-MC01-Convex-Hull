/*
    Group #: 04

    CHENG, DERK SIMONE C.        S04
    CORTEZ, PAUL HAVEN C.        S09
    SORILLA, JOSHUA DEL F.       S__

    PURPOSE OF THIS FILE: implementation of the sorting module. It contains the
    geometric helper functions, the polar-angle comparator, and the two assigned
    sorting algorithms for Group 4: Bubble sort (slow) and Quick sort (fast).

    GENERAL INSTRUCTIONS observed: no global variables, no goto, no return in a void function.
*/

#include "sort.h"

/*
    a. Programmer(s): CHENG, DERK SIMONE C.
    b. Tester(s)    : 
    c. Code Type    : 100% Human Generated
    d. Purpose      : compute the cross product (b-o) x (a... actually (a-o) x (b-o)).
                      A positive value means o->a->b makes a counterclockwise turn,
                      a negative value a clockwise turn, and zero means collinear.
    e. Return       : the signed cross product value.
    f. Parameters   : o is the reference (origin) point; a and b are the two points
                      whose orientation about o is being measured.
*/
double crossProduct(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

/*
    a. Programmer(s): CHENG, DERK SIMONE C.
    b. Tester(s)    : 
    c. Code Type    : 100% Human Generated
    d. Purpose      : compute the squared Euclidean distance between two points.
                      Squared distance is enough for comparing distances, so no
                      sqrt() is needed.
    e. Return       : the squared distance between a and b.
    f. Parameters   : a and b are the two points.
*/
double distSquared(Point a, Point b)
{
    double dx;   // difference in x
    double dy;   // difference in y

    dx = a.x - b.x;
    dy = a.y - b.y;

    return dx * dx + dy * dy;
}

/*
    a. Programmer(s): CHENG, DERK SIMONE C.
    b. Tester(s)    : 
    c. Code Type    : 100% Human Generated
    d. Purpose      : decide the relative order of two points a and b for the polar
                      sort about the anchor. A point with a smaller polar angle comes
                      first; if the polar angles are equal (collinear with the anchor),
                      the point closer to the anchor comes first.
    e. Return       : -1 if a precedes b, 1 if a follows b, 0 if equal in order.
    f. Parameters   : a and b are the points being compared; anchor is the pivot point.
*/
int comparePoints(Point a, Point b, Point anchor)
{
    double turn;     // orientation of anchor -> a -> b
    int    result;   // ordering verdict

    turn = crossProduct(anchor, a, b);

    if (turn > 0.0)
        result = -1;                 // a is more clockwise => smaller polar angle => a first
    else if (turn < 0.0)
        result = 1;                  // a has the larger polar angle => a later
    else if (distSquared(anchor, a) < distSquared(anchor, b))
        result = -1;                 // collinear: nearer point first
    else if (distSquared(anchor, a) > distSquared(anchor, b))
        result = 1;
    else
        result = 0;                  // same point/distance

    return result;
}

/*
    a. Programmer(s): CHENG, DERK SIMONE C.
    b. Tester(s)    : 
    c. Code Type    : 100% Human Generated
    d. Purpose      : SLOW algorithm. Sort arr[0..n-1] by polar angle about the anchor
                      using Bubble sort. Adjacent out-of-order points are repeatedly
                      swapped; the largest element "bubbles" to the end each pass.
    e. Return       : None
    f. Parameters   : arr is the array of points to sort; n is its length;
                      anchor is the pivot point for the comparison.
*/
void bubbleSort(Point *arr, int n, Point anchor)
{
    int   i;       // pass counter
    int   j;       // index within a pass
    Point temp;    // scratch for swapping

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (comparePoints(arr[j], arr[j + 1], anchor) > 0)
            {
                temp       = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
}

/*
    a. Programmer(s): CHENG, DERK SIMONE C.
    b. Tester(s)    : 
    c. Code Type    : 100% Human Generated
    d. Purpose      : partition helper for Quick sort using the Hoare scheme. The
                      middle element is chosen as the pivot (which keeps performance
                      good even when the data is already sorted by angle). Elements
                      smaller than the pivot are moved to the left side and larger
                      ones to the right side.
    e. Return       : the split index; the left part is [low..index], right is [index+1..high].
    f. Parameters   : arr is the array; low and high bound the section to partition;
                      anchor is the pivot point for the comparison.
*/
static int partition(Point *arr, int low, int high, Point anchor)
{
    Point pivot;    // pivot value (middle element)
    Point temp;     // scratch for swapping
    int   i;        // left scanning index
    int   j;        // right scanning index
    int   split;    // resulting split position

    pivot = arr[low + (high - low) / 2];
    i     = low - 1;
    j     = high + 1;
    split = -1;     // set once the two indices cross

    while (split == -1)
    {
        do
            i++;
        while (comparePoints(arr[i], pivot, anchor) < 0);

        do
            j--;
        while (comparePoints(arr[j], pivot, anchor) > 0);

        if (i >= j)
            split = j;
        else
        {
            temp   = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    return split;
}

/*
    a. Programmer(s): CHENG, DERK SIMONE C.
    b. Tester(s)    : 
    c. Code Type    : 100% Human Generated
    d. Purpose      : FAST algorithm. Sort arr[low..high] by polar angle about the
                      anchor using Quick sort. The array is partitioned about a pivot,
                      then each side is sorted recursively.
    e. Return       : None
    f. Parameters   : arr is the array of points; low and high are the inclusive
                      bounds of the section to sort; anchor is the pivot point.
*/
void quickSort(Point *arr, int low, int high, Point anchor)
{
    int split;   // partition split index

    if (low < high)
    {
        split = partition(arr, low, high, anchor);
        quickSort(arr, low, split, anchor);
        quickSort(arr, split + 1, high, anchor);
    }
}
