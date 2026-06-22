/*
    Group #: 04

    CHENG, DERK SIMONE C.        S04
    CORTEZ, PAUL HAVEN C.        S09
    SORILLA, JOSHUA DEL F.       S09

    PURPOSE OF THIS FILE: the SLOW version of Graham's Scan. It computes the convex
    hull of a set of 2D points, using Bubble sort for the polar-angle sorting step.
    There is no main() here; the driver test_slow.c supplies main().

    GENERAL INSTRUCTIONS observed: no global variables, no goto, no return in a void function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>    /* for clock() */

#include "stack.c"   /* stack operations */
#include "sort.c"    /* Bubble/Quick sorts + geometric helpers */

/*
    a. Programmer(s): CORTEZ, PAUL HAVEN C.
    b. Tester(s)    : 
    c. Code Type    : AI-generated draft
    d. Purpose      : compute the convex hull of pts[0..n-1] with Graham's Scan, using
                      the SLOW (Bubble) sort. Steps: pick the anchor (lowest y, then
                      lowest x) and move it to index 0; sort the rest by polar angle
                      about the anchor; walk the points keeping only counterclockwise
                      turns on a stack. The resulting stack, read bottom to top, is the
                      hull in counterclockwise order starting at the anchor. The elapsed
                      time of the whole computation is printed in milliseconds.
    e. Return       : m, the number of points on the convex hull.
    f. Parameters   : pts is the input array of points (reordered in place); n is the
                      number of input points; hull is an output array (caller-allocated)
                      that receives the m hull points.
*/
int grahamScanSlow(Point *pts, int n, Point *hull)
{
    Stack   S;          // stack of candidate hull points
    Point   anchor;     // the anchor point
    Point   temp;       // scratch for the anchor swap
    int     anchorIdx;  // index of the anchor
    int     i;          // loop index
    int     m;          // number of hull points produced
    clock_t start;      // start time
    clock_t end;        // end time
    double  elapsedMs;  // elapsed time in milliseconds

    start = clock();

    /* 1. Locate the anchor: minimum y, ties broken by minimum x. */
    anchorIdx = 0;
    for (i = 1; i < n; i++)
        if (pts[i].y < pts[anchorIdx].y ||
            (pts[i].y == pts[anchorIdx].y && pts[i].x < pts[anchorIdx].x))
            anchorIdx = i;

    temp           = pts[0];
    pts[0]         = pts[anchorIdx];
    pts[anchorIdx] = temp;
    anchor         = pts[0];

    /* 2. Sort the remaining points by polar angle about the anchor (Bubble sort). */
    bubbleSort(pts + 1, n - 1, anchor);

    /* 3. Graham's Scan. Keep popping while the last turn is not counterclockwise
          (clockwise or collinear), so collinear points on a hull edge are removed. */
    CREATE(&S);
    PUSH(&S, pts[0]);
    PUSH(&S, pts[1]);
    for (i = 2; i < n; i++)
    {
        while (S.count >= 2 &&
               crossProduct(NEXT_TO_TOP(&S), TOP(&S), pts[i]) <= 0.0)
            POP(&S);
        PUSH(&S, pts[i]);
    }

    /* 4. The stack bottom-to-top is the hull in counterclockwise order. */
    m = S.count;
    for (i = 0; i < m; i++)
        hull[i] = S.points[i];

    end       = clock();
    elapsedMs = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("[SLOW / Bubble sort] elapsed time: %.3f ms\n", elapsedMs);

    return m;
}

