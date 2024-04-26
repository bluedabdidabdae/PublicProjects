int AlgsMenuHandler(alg element_list[]);
int CheckAlgsMenuCollisions(alg vect[]);
int MainMenuHandler();
int CheckMainMenuCollisions();
int CheckSettingsMenuCollisions();
void SettingsHandler();
void RecapScreen(char algName[][40], float algtime, int sorted);

void SettingsHandler()
{
    while(!WindowShouldClose())
    {
        DrawSettings();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            switch(CheckSettingsMenuCollisions())
            {
                // light theme
                case 1:
                    backgColor = RAYWHITE;
                    secondaryColor = BLACK;
                    sortColor = BLACK;
                    visualIndicatorColor = RED;
                    orderCheckerColor = GREEN;
                break;
                // dark theme
                case 2:
                    backgColor = BLACK;
                    secondaryColor = RAYWHITE;
                    sortColor = RAYWHITE;
                    visualIndicatorColor = RED;
                    orderCheckerColor = GREEN;
                break;
                // blood theme
                case 3:
                    backgColor = BLACK;
                    secondaryColor = RED;
                    sortColor = RED;
                    visualIndicatorColor = BLUE;
                    orderCheckerColor = MAROON;
                break;
                // hack theme
                case 4:
                    backgColor = BLACK;
                    secondaryColor = GREEN;
                    sortColor = GREEN;
                    visualIndicatorColor = RED;
                    orderCheckerColor = DARKGREEN;
                break;
                // ocean theme
                case 5:
                    backgColor = RAYWHITE;
                    secondaryColor = BLUE;
                    sortColor = BLUE;
                    visualIndicatorColor = RED;
                    orderCheckerColor = DARKBLUE;
                break;
                // donut theme
                case 6:
                    backgColor = RAYWHITE;
                    secondaryColor = PINK;
                    sortColor = PINK;
                    visualIndicatorColor = BLUE;
                    orderCheckerColor = PURPLE;
                break;
                
                default: continue;
            }
        }
    }
}

int CheckSettingsMenuCollisions()
{
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    if(mouseY > 210 && mouseY < 260)
    {
        if(mouseX > 600  && mouseX < 730)   return 1;
        if(mouseX > 750  && mouseX < 880)   return 2;
        if(mouseX > 900  && mouseX < 1030)  return 3;
        if(mouseX > 1050 && mouseX < 1180)  return 4;
        if(mouseX > 1200 && mouseX < 1330)  return 5;
        if(mouseX > 1350 && mouseX < 1580)  return 6;
    }
    return 0;
}

void RecapScreen(char algName[][40], float algtime, int sorted)
{
    SetTargetFPS(IDLEFPS);
    while(!WindowShouldClose())
    {
        DrawRecapScreen(algName, algtime, sorted);
    }
}

int MainMenuHandler()
{
    int choice;
    while(!WindowShouldClose())
    {
        DrawMainMenu();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            choice = CheckMainMenuCollisions();
            if(choice >= 0)
                return choice;
       }
    }
    return -1;
}

int CheckMainMenuCollisions()
{
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    // god also forgive me for this shit
    if(mouseX > MAINALGX && mouseY > 400 && mouseX < MAINALGX+MAINBUTTONWIDTH && mouseY < 400+MAINALGHEIGHT) return 0; //normal mode
    if(mouseX > MAINALGX && mouseY > 500 && mouseX < MAINALGX+MAINBUTTONWIDTH && mouseY < 500+MAINALGHEIGHT) return 1; //benchmark mode
    if(mouseX > MAINALGX && mouseY > 600 && mouseX < MAINALGX+MAINBUTTONWIDTH && mouseY < 600+MAINALGHEIGHT) return 2; //settings
    if(mouseX > MAINALGX && mouseY > 700 && mouseX < MAINALGX+MAINBUTTONWIDTH && mouseY < 700+MAINALGHEIGHT) return 3; //exit
    return -1;
}

int AlgsMenuHandler(alg element_list[])
{
    int choice;
    while(!WindowShouldClose())
    {
        DrawAlgsMenu(element_list);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            choice = CheckAlgsMenuCollisions(element_list);
            if(choice >= 0)
            {
                return choice;
            }
        }
    }
    return -1;
}

int CheckAlgsMenuCollisions(alg vect[])
{
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
    for(int i=0; i<ALGNUMBER; i++)
        if(mouseX > vect[i].x && mouseY > vect[i].y && mouseX < vect[i].x+ALGWIDTH && mouseY < vect[i].y+ALGHEIGHT)
            return i;
    return -1;
}