#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

#include "raylib.h"
#include "raymath.h"

#include "src/init_global_data.h"
#include "src/graphic_funcs.h"
#include "src/base_sorts.h"
#include "src/data_handle.h"
#include "src/util_funcs.h"

/*
    timer functioning (need a fucking phd)

    struct timeval stop, start;
    gettimeofday(&start, NULL);
    do stuff
    gettimeofday(&stop, NULL);

    us/usec == microseconds == sec*10^-6
    printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
*/

int main()
{
    //main data initialization
    data element_list[BENCHELENUM+1], default_list[BENCHELENUM+1];
    float algtime;
    int algId;
    struct timeval stop, start;
    alg algInfo_list[ALGNUMBER];
    
    srand(time(NULL));
    InitData(default_list);
    Initalgs(algInfo_list);
    
    ResetData(element_list, default_list, &algtime);
    
    InitWindow(WIDTH, HEIGHT, WINDOWNAME);
    SetTargetFPS(IDLEFPS);
    
    //SetTargetFPS(MAXRAYLIBFPS);
    
    while(1)
    {
        benchmark = false;
        
        switch(MainMenuHandler())
        {
            case 0: break;
            case 1:
                benchmark = true;
                arrLen=BENCHELENUM;
            break;
            case 2:
                if(SettingsHandler())
                    ResetVectColor(default_list);
                continue;
                //haven't done shit about it for now
            break;
            case 3:
                CloseWindow();
                return 0;
            break;
            default:
                continue;
        }
        
        algId = AlgsMenuHandler(algInfo_list);
        ResetData(element_list, default_list, &algtime);
        
        if(algId >= 0 && algId < VALIDALGNUMBER)
        {
            if(benchmark)
                DrawWaitSortingScreen();
            else
                SetTargetFPS(STDFPS);
            
            gettimeofday(&start, NULL);
            algInfo_list[algId].algFunc(element_list);
            gettimeofday(&stop, NULL);
            
            if(algId < VALIDALGNUMBER)
            {
                // separating sec from usec and adding them together
                algtime+=stop.tv_sec - start.tv_sec;
                algtime+=(float)(stop.tv_usec - start.tv_usec) / 1000000;
            }
            
            RecapScreen(algInfo_list[algId].algName, algtime, CheckOrder(element_list));
        }
        continue;
    }
    
    
    /*
    random debugging shit
    
    SetTargetFPS(STDFPS);
    
    while(!WindowShouldClose())
    {
        
        InitData(default_list);
        
        ResetData(element_list, default_list);
        RecursiveMergeSort(element_list, 0, ELENUM);
        CheckOrder(element_list);
        if(WindowShouldClose())
            CloseWindow();
        
        ResetData(element_list, default_list);
        RadixSortLsd(element_list);
        CheckOrder(element_list);
        if(WindowShouldClose())
            CloseWindow();
        
        SetTargetFPS(MAXRAYLIBFPS);
        ResetData(element_list, default_list);
        OddEvenSort(element_list);
        CheckOrder(element_list);
        if(WindowShouldClose())
            CloseWindow();
        
        SetTargetFPS(STDFPS);
        ResetData(element_list, default_list);
        SelectionSort(element_list);
        CheckOrder(element_list);
        if(WindowShouldClose())
            CloseWindow();
        
        SetTargetFPS(MAXRAYLIBFPS);
        ResetData(element_list, default_list);
        CocktailShakerSort(element_list);
        CheckOrder(element_list);
        if(WindowShouldClose())
            CloseWindow();
        
        SetTargetFPS(STDFPS);
        ResetData(element_list, default_list);
        DoubleSelectionSort(element_list);
        CheckOrder(element_list);
        if(WindowShouldClose())
            CloseWindow();
    }
    */
}