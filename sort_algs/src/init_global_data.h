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

#define WINDOWNAME "Sorting Algs"
#define BENCHELENUM 85000

const int MAINALGX = WIDTH/2-MAINBUTTONWIDTH/2;
const int ELENUM = WIDTH/RATIO;
const int RECTWIDTH = WIDTH/ELENUM;
const int HALFWIDTH = WIDTH/2;
const int HALFHEIGHT = HEIGHT/2;

typedef struct data_model{
    int value;
    Color color;
}data;

typedef struct alg_model{
    int x;                          // posizione x del bottone
    int y;                          // posizione y del bottone
    char algName[ALGNUMBER][40];    // nome dell'algoritmo
    int (*algFunc)(data[]);         // indirizzo dell'algoritmo di sort
}alg;

// light theme is set as default theme
Color backgColor = RAYWHITE;           // colore background default
Color secondaryColor = BLACK;    // colore ui default
Color sortColor = BLACK;         // colore sorting default
Color visualIndicatorColor = RED;   // colore accessi array default
Color orderCheckerColor = GREEN;    // colore order-checker default

bool benchmark;              // indica se si sta testando l'algoritmo con un array superiore a ELENUM
int arrLen;                  // lunghezza dell'array da considerare per l'algoritmo
unsigned long long swaps;    // == element swaps
unsigned long long comps;    // == comparisons
unsigned long long fcycles;  // == for-cycles
unsigned long long marr;     // == main-array
unsigned long long secarr;   // == secondary-array