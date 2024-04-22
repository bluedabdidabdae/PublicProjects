void InitData(data vect[], data vect2[]);
void ResetData(data vect[], data vect2[], float *algtime);
int CheckOrder(data vect[]);                // returns 0 if it ended with no errors, 1 for user interrupt and -1 for list order error
void Initalgs(alg vect[]);
void ResetVectColor(data vect[]);

void ResetVectColor(data vect[])
{
    for(int i=0; i<ELENUM; i++)
        vect[i].color=sortColor;
}

void Initalgs(alg vect[])
{
    int algRows = ALGNUMBER;
    int algCols = 1;
    int nOfAlgs = ALGNUMBER;
    
    for(int i=0; i<ALGNUMBER; i++)
        strcpy(*vect[i].algName, "NULL");
    
    for(int i=1; i<=algCols && nOfAlgs > 0; i++)
    {
        for(int j=1; j<=algRows && nOfAlgs > 0; j++)
        {
            vect[j-1].x=50*i+ALGWIDTH;
            vect[j-1].y=50*j+ALGHEIGHT;
            nOfAlgs--;
        }
    }
    
    strcpy(*vect[0].algName, "Recursive mergesort\0");
    vect[0].algFunc = RecursiveMergeSortCaller;
    strcpy(*vect[1].algName, "Lsd radix sort\0");
    vect[1].algFunc = RadixSortLsd;
    strcpy(*vect[2].algName, "Odd even sort\0");
    vect[2].algFunc = OddEvenSort;
    strcpy(*vect[3].algName, "Cocktail shaker sort\0");
    vect[3].algFunc = CocktailShakerSort;
    strcpy(*vect[4].algName, "Selection sort\0");
    vect[4].algFunc = SelectionSort;
    strcpy(*vect[5].algName, "Double selection sort\0");
    vect[5].algFunc = DoubleSelectionSort;
}

void InitData(data vect[])
{
    for(int i=0; i<ELENUM; i++)
    {
        vect[i].value=rand()%(MAX-MIN)+MIN;
        vect[i].color=sortColor;
    }
    
    for(int i=ELENUM; i<BENCHELENUM; i++)
    {
        vect[i].value=rand()%(BENCHELENUM-MIN)+MIN;
        vect[i].color=sortColor;
    }
}

void ResetData(data vect[], data vect2[], float *algtime)
{
    for(int i=0; i<arrLen; i++)
        vect[i]=vect2[i];
    
    arrLen=ELENUM;
    *algtime=0;
    fcycles=0;
    swaps=0;
    comps=0;
    marr=0;
    secarr=0;
}

int CheckOrder(data vect[])
{
    SetTargetFPS(MAXRAYLIBFPS);
    for(int i=0; i<arrLen-1; i++)
    {
        if(vect[i].value <= vect[i+1].value)
            vect[i].color = orderCheckerColor;
        else
            return -1;
        if(WindowShouldClose())
            return 1;
        if(!benchmark)
            HandleGraphic(vect);
    }
    return 0;
}