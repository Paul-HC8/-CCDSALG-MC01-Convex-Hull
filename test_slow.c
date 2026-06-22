
    /*
        Group #: 04

        CHENG, DERK SIMONE C.        S04
        CORTEZ, PAUL HAVEN C.        S09
        SORILLA, JOSHUA DEL F.       S09

        PURPOSE OF THIS FILE: driver for the SLOW (Bubble-sort) version of Graham's Scan.
        It asks for the input and output filenames, reads the points, computes the convex
        hull, and writes the hull to the output file.

        GENERAL INSTRUCTIONS observed: no global variables, no goto, no return in a void function.

        HOW TO COMPILE & RUN:
            gcc test_slow.c -o test_slow
            ./test_slow
    */

    #include <stdio.h>
    #include <stdlib.h>
    #include "graham_slow.c"   /* brings in the slow Graham's Scan (and stack + sort) */

    int main(void)
    {
        static Point pts[MAX_SIZE];   // input points (static keeps the 0.5 MB off the call stack)
        static Point hull[MAX_SIZE];  // resulting hull points
        char  inName[256];              // input filename
        char  outName[256];             // output filename
        FILE *fin;                      // input file pointer
        FILE *fout;                     // output file pointer
        int   n;                        // number of input points
        int   m;                        // number of hull points
        int   i;                        // loop index

        printf("Enter input filename : ");
        scanf("%s", inName);
        printf("Enter output filename: ");
        scanf("%s", outName);

        fin = fopen(inName, "r");
        if (fin == NULL)
        {
            printf("Could not open input file: %s\n", inName);
            return 1;
        }

        fscanf(fin, "%d", &n);
        for (i = 0; i < n; i++)
            fscanf(fin, "%lf %lf", &pts[i].x, &pts[i].y);
        fclose(fin);

        m = grahamScanSlow(pts, n, hull);

        fout = fopen(outName, "w");
        if (fout == NULL)
        {
            printf("Could not open output file: %s\n", outName);
            return 1;
        }

        fprintf(fout, "%d\n", m);
        for (i = 0; i < m; i++)
            fprintf(fout, "%.6lf  %.6lf\n", hull[i].x, hull[i].y);
        fclose(fout);

        printf("Convex hull has %d points. Written to %s\n", m, outName);

        return 0;
    }
