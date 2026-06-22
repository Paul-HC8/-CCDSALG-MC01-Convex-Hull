/*
    Group #: 04

    CHENG, DERK SIMONE C. S04
    CORTEZ, PAUL HAVEN C. S09
    SORILLA, JOSHUA D.    S09

    PURPOSE OF THIS FILE: header file for the sorting module. Group 4 is assigned
    Bubble sort (the "slow" quadratic algorithm) and Quick sort (the "fast"
    O(n log n) algorithm). Both sort an array of Point values by the polar angle
    each point makes with a given anchor point (ties broken by distance from the
    anchor). It also declares the geometric helper functions. Bodies live in sort.c.

    GENERAL INSTRUCTIONS observed: no global variables, no goto, no return in a void function.
*/

#ifndef SORT_H
#define SORT_H

#include "stack.h"   /* for the Point type */

/* Geometric helpers used both by the comparator and by Graham's Scan. */
double crossProduct(Point o, Point a, Point b);  // signed area * 2 of triangle o-a-b
double distSquared(Point a, Point b);            // squared Euclidean distance a..b

/* Ordering predicate for the polar-angle sort.
   Returns -1 if a should come before b, 1 if after, 0 if equal in order. */
int comparePoints(Point a, Point b, Point anchor);

/* The two assigned sorting algorithms. Both sort arr[0..n-1] in place. */
void bubbleSort(Point *arr, int n, Point anchor);              // SLOW: Bubble sort
void quickSort(Point *arr, int low, int high, Point anchor);   // FAST: Quick sort

#endif
