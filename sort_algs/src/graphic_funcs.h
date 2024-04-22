void HandleGraphic(data vect[]);
void DrawAlgsMenu(alg vect[]);
void DrawMainMenu();
void DrawRecapScreen(char algName[][40], float algtime, int sorted);
void DrawSettings();
void DrawWaitSortingScreen();

// fking bs function
void DrawSettings()
{
    BeginDrawing();
        ClearBackground(backgColor);
        DrawText(TextFormat("Settings"),              120, 100, 60, secondaryColor);
    
        DrawRectangle(                                100, 210, 400, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("- Background color"),    120, 220, 30, secondaryColor);
        
        DrawRectangle(                                590, 210, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("White"),                 610, 220, 30, secondaryColor);
        DrawRectangle(                                760, 210, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Black"),                 780, 220, 30, secondaryColor);
        
        DrawRectangle(                                100, 280, 400, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("- Secondary color"),     120, 290, 30, secondaryColor);
        
        DrawRectangle(                                590, 280, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("White"),                 610, 290, 30, secondaryColor);
        DrawRectangle(                                760, 280, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Black"),                 780, 290, 30, secondaryColor);
        DrawRectangle(                                910, 280, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Blue"),                  930, 290, 30, secondaryColor);
        DrawRectangle(                                1060, 280, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Pink"),                  1080, 290, 30, secondaryColor);
        DrawRectangle(                                1210, 280, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Green"),                 1230, 290, 30, secondaryColor);
        
        DrawRectangle(                                100, 350, 400, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("- Sort color"),          120, 360, 30, secondaryColor);
        
        DrawRectangle(                                590, 350, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("White"),                 610, 360, 30, secondaryColor);
        DrawRectangle(                                760, 350, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Black"),                 780, 360, 30, secondaryColor);
        DrawRectangle(                                910, 350, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Blue"),                  930, 360, 30, secondaryColor);
        DrawRectangle(                                1060, 350, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Pink"),                  1080, 360, 30, secondaryColor);
        DrawRectangle(                                1210, 350, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Green"),                 1230, 360, 30, secondaryColor);
        
        DrawRectangle(                                100, 420, 400, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("- Array Access Color"),  120, 430, 30, secondaryColor);
        
        DrawRectangle(                                590, 420, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("White"),                 610, 430, 30, secondaryColor);
        DrawRectangle(                                760, 420, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Black"),                 780, 430, 30, secondaryColor);
        DrawRectangle(                                910, 420, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Blue"),                  930, 430, 30, secondaryColor);
        DrawRectangle(                                1060, 420, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Pink"),                  1080, 430, 30, secondaryColor);
        DrawRectangle(                                1210, 420, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Green"),                 1230, 430, 30, secondaryColor);
        
        DrawRectangle(                                100, 490, 400, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("- Order Check Color"),   120, 500, 30, secondaryColor);
        
        DrawRectangle(                                590, 490, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("White"),                 610, 500, 30, secondaryColor);
        DrawRectangle(                                760, 490, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Black"),                 780, 500, 30, secondaryColor);
        DrawRectangle(                                910, 490, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Blue"),                  930, 500, 30, secondaryColor);
        DrawRectangle(                                1060, 490, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Pink"),                  1080, 500, 30, secondaryColor);
        DrawRectangle(                                1210, 490, 130, 50, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Green"),                 1230, 500, 30, secondaryColor);
        
    EndDrawing();
}

void DrawWaitSortingScreen()
{
    BeginDrawing();
        ClearBackground(backgColor);

        DrawText(TextFormat("We sorting bro..."), HALFWIDTH-200, HALFHEIGHT-50, 50, secondaryColor);
    EndDrawing();
}

void DrawRecapScreen(char algName[][40], float algtime, int sorted)
{
    BeginDrawing();
        ClearBackground(backgColor);
        
        DrawRectangle(                                         HALFWIDTH-500, HALFHEIGHT-300, 1000, 600, Fade(secondaryColor, 0.3f));
        DrawText(TextFormat(*algName),                         HALFWIDTH-460, HALFHEIGHT-270, 70, secondaryColor);
        DrawText(TextFormat("Swaps: %lli", swaps),             HALFWIDTH-420, HALFHEIGHT-170, 30, secondaryColor);
        DrawText(TextFormat("Comparisons: %lli", comps),       HALFWIDTH-420, HALFHEIGHT-120, 30, secondaryColor);
        DrawText(TextFormat("For Cycles: %lli", fcycles),      HALFWIDTH-420, HALFHEIGHT-70, 30, secondaryColor);
        DrawText(TextFormat("Main arr acc: %lli", marr),       HALFWIDTH-420, HALFHEIGHT-20, 30, secondaryColor);
        DrawText(TextFormat("Second arr acc: %lli", secarr),   HALFWIDTH-420, HALFHEIGHT+30, 30, secondaryColor);
        DrawText(TextFormat("Alg work time: %f s", algtime),   HALFWIDTH-420, HALFHEIGHT+80, 30, secondaryColor);
        if(sorted == 0)
            DrawText(TextFormat("Sorted: True"),               HALFWIDTH-420, HALFHEIGHT+130, 30, secondaryColor);
        else
            DrawText(TextFormat("Sorted: False"),              HALFWIDTH-420, HALFHEIGHT+130, 30, secondaryColor);
        
    EndDrawing();
}

void DrawMainMenu()
{
    // god forgive me for this shit
    BeginDrawing();
        ClearBackground(backgColor);
        DrawText(TextFormat("Sorting Algorythms Visualizer"), 300, 200+MAINALGHEIGHT/2-20, 70, secondaryColor);
    
        DrawRectangle(MAINALGX, 400, MAINBUTTONWIDTH, MAINALGHEIGHT, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Normal Sort Algorythms"), MAINALGX+30, 400+MAINALGHEIGHT/2-20, 40, secondaryColor);
        
        DrawRectangle(MAINALGX, 500, MAINBUTTONWIDTH, MAINALGHEIGHT, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Benchmark Sort Algorythms"), MAINALGX+30, 500+MAINALGHEIGHT/2-20, 40, secondaryColor);
        
        DrawRectangle(MAINALGX, 600, MAINBUTTONWIDTH, MAINALGHEIGHT, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Settings"), MAINALGX+30, 600+MAINALGHEIGHT/2-20, 40, secondaryColor);
        
        DrawRectangle(MAINALGX, 700, MAINBUTTONWIDTH, MAINALGHEIGHT, Fade(secondaryColor, 0.2f));
        DrawText(TextFormat("Exit Program"), MAINALGX+30, 700+MAINALGHEIGHT/2-20, 40, secondaryColor);
        
    EndDrawing();
}

void DrawAlgsMenu(alg vect[])
{
    BeginDrawing();
        ClearBackground(backgColor);
        for(int i=0; i<ALGNUMBER; i++)
        {
            DrawRectangle(vect[i].x, vect[i].y, ALGWIDTH, ALGHEIGHT, Fade(secondaryColor, 0.2f));
            DrawText(TextFormat(*vect[i].algName), vect[i].x+10, vect[i].y+10, 20, secondaryColor);
        }
    EndDrawing();
}

void HandleGraphic(data vect[])
{
    int offset = 0;
    BeginDrawing();
    
        ClearBackground(backgColor);
        for(int i=0; i<ELENUM; i++)
        {
            DrawRectangle(offset, HEIGHT-vect[i].value, RECTWIDTH, vect[i].value, vect[i].color);
            offset+=RECTWIDTH;
        }
     // DrawText(TextFormat("Integer value: %d", val), x, y, size, BLACK);
        
        DrawRectangle(0, 0, 150, 95, Fade(secondaryColor, 0.3f));
        DrawText(TextFormat("Swaps: %lli", swaps), 10, 10, 10, secondaryColor);
        DrawText(TextFormat("Comparisons: %lli", comps), 10, 25, 10, secondaryColor);
        DrawText(TextFormat("For Cycles: %lli", fcycles), 10, 40, 10, secondaryColor);
        DrawText(TextFormat("Main arr acc: %lli", marr), 10, 55, 10, secondaryColor);
        DrawText(TextFormat("Second arr acc: %lli", secarr), 10, 70, 10, secondaryColor);
        
    EndDrawing();
}