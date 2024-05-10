#ifndef VARIABLES_CONSTANTS_H
#define VARIABLES_CONSTANTS_H

#define WINDOWNAME "Sorting Algs"
#define WIDTH 1600
#define HEIGHT 900
#define RATIO 1
#define MAX HEIGHT
#define MIN 0
#define STDFPS 360
#define IDLEFPS 30
#define MAXRAYLIBFPS 915285505
#define ALGWIDTH 250
#define ALGHEIGHT 40
#define MAINBUTTONWIDTH 700
#define MAINALGHEIGHT 80
#define ALGNUMBER 14
#define VALIDALGNUMBER 6
#define BUTTONFADEVALUE 0.2f
// Windows can't handle more than this, at least
// on the pc i tested it on.
#define BENCHELENUM 85000

#define MAINALGX WIDTH/2-MAINBUTTONWIDTH/2
#define ELENUM WIDTH/RATIO
#define RECTWIDTH WIDTH/ELENUM
#define HALFWIDTH WIDTH/2
#define HALFHEIGHT HEIGHT/2

// Light theme is set as default theme at variable declaration.
extern Color backgColor;              // Background default color.
extern Color secondaryColor;          // UI default color.
extern Color sortColor;               // Sorting default color.
extern Color visualIndicatorColor;    // Array access cursor default color.
extern Color orderCheckerColor;       // Order-checker default color.

extern bool benchmark;                        // Tells the program if you're benchmarking an alg, (no graphic and bigger array).
extern int arrLen;                            // Logic lenght of the array to sort.
extern unsigned long long swaps;              // == element-swaps.
extern unsigned long long comps;              // == comparisons.
extern unsigned long long fcycles;            // == for-cycles.
extern unsigned long long marr;               // == main-array-access.
extern unsigned long long secarr;             // == secondary-array-access.

#endif