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

