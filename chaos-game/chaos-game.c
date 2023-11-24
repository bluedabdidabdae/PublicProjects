#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>

#include "raylib.h"
#include "raymath.h"
//#include "mtwister.h"

#define screenWidth 1920
#define screenHeight 1080

#define mLeft 1.7320508
#define mRight -1.7320508

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

double Init(double side_lenght, double originX, double originY, double *top_vertexX, double *top_vertexY);
double GetMaxYLeft(double X1, double Y1, double X);
double GetMaxYRight(double X1, double Y1, double X);
void RandomNumber(double *number, double max, double min);
//void RandomNumber(double *number, double max, double min, MTRand seed);

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

int main (){
    double side_lenght=900, randX, randY, aux, aux2, originX, originY;
    double top_vertexX, top_vertexY;
    double vOffsetL, vOffsetR;
    int counter;
    
    originX=(screenWidth/2)-(side_lenght/2);
    originY=(screenHeight/2)+(side_lenght/2);
    
    srand(time(NULL));
    //MTRand randSeed = seedRand(10469);
    
    InitWindow(screenWidth, screenHeight, "Chaos game"); //chaos pe da vero, nse capisce un cazzo de sto codice e non aspettatevi altri commenti >:)
    
    Init(side_lenght, originX, originY, &top_vertexX, &top_vertexY);
    
    vOffsetL=originY+(originY-top_vertexY);
    vOffsetR=top_vertexY*2;
    
    aux=originX+side_lenght;
    RandomNumber(&randX, aux, originX);
    //RandomNumber(&randX, aux, originX, randSeed);
    
    if(randX<=originX+(side_lenght/2))
        aux=vOffsetL+GetMaxYLeft(originX, originY, randX)+top_vertexY;
    else
        aux=vOffsetR+GetMaxYRight(originX, originY, randX);
    RandomNumber(&randY, originY, aux);
    //RandomNumber(&randY, originY, aux, randSeed);
    
    aux2=0;
    aux=originX+side_lenght;
    
    for(counter=0;counter<4;counter++)
    {
        RandomNumber(&aux2, 30, 0);
        //RandomNumber(&aux, 0, 2, randSeed);

        if(aux2<10)
        {
            randX=(randX+aux)/2;
            randY=(randY+originY)/2;
        }
        else if(aux2<=20)
        {
            randX=(randX+top_vertexX)/2;
            randY=(randY+top_vertexY)/2;
        }
        else if(aux2<=30)
        {
            randX=(randX+originX)/2;
            randY=(randY+originY)/2;
        }
    }
    
    while(true)
    {
        BeginDrawing();
            DrawPixel(randX, randY, WHITE);
        EndDrawing();
        
        RandomNumber(&aux2, 30, 0);
        //RandomNumber(&aux, 0, 2, randSeed);

        if(aux2<10)
        {
            randX=(randX+aux)/2;
            randY=(randY+originY)/2;
        }
        else if(aux2<=20)
        {
            randX=(randX+top_vertexX)/2;
            randY=(randY+top_vertexY)/2;
        }
        else if(aux2<=30)
        {
            randX=(randX+originX)/2;
            randY=(randY+originY)/2;
        }
        //somma delle coord/2
        
        if(IsKeyDown(KEY_C))
        {
            CloseWindow();
            return 0;
        }
    }
    CloseWindow();
    return 0;
}

// rand(max-min)+min;

void RandomNumber(double *number, double max, double min)
//void RandomNumber(double *number, double max, double min, MTRand seed)
{
    *number=(fmod((double)rand(), max-min+1))+min;
    //*number=(fmod((double)genRand(&seed), max-min+1))+min;
    return;
}

double GetMaxYLeft(double X1, double Y1, double X)
{
    int Q;
    
    Q=-mLeft*X1+Y1;

    return -(mLeft*X+Q);
}

double GetMaxYRight(double X1, double Y1, double X)
{
    int Q;
    
    Q=-mRight*X1+Y1;

    return -(mRight*X+Q);
}

double Init(double side_lenght, double originX, double originY, double *top_vertexX, double *top_vertexY)
{
    *top_vertexY=originY-sqrt((side_lenght*side_lenght)-((side_lenght/2)*(side_lenght/2)));
    *top_vertexX=originX+(side_lenght/2);
    
    ClearBackground(BLACK);
    
    BeginDrawing();
        DrawLine(originX, originY, originX+side_lenght, originY, WHITE);
        DrawLine(originX, originY, *top_vertexX, *top_vertexY, WHITE);
        DrawLine(originX+side_lenght, originY, *top_vertexX, *top_vertexY, WHITE);
    EndDrawing();
    
    return 0;
}