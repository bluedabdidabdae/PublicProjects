int AlgsMenuHandler(alg element_list[]);
int CheckAlgsMenuCollisions(alg vect[]);
int MainMenuHandler();
int CheckMainMenuCollisions();
int CheckSettingsMenuCollisions();
int SettingsHandler();
void RecapScreen(char algName[][40], float algtime, int sorted);

int SettingsHandler()
{
    int retVal = 0;
    while(!WindowShouldClose())
    {
        DrawSettings();
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            switch(CheckSettingsMenuCollisions())
            {
                case 1:  backgColor = RAYWHITE;  break;
                case 2:  backgColor = BLACK;     break;
                
                case 11:  secondaryColor = RAYWHITE;  break;
                case 12:  secondaryColor = BLACK;     break;
                case 13:  secondaryColor = BLUE;      break;
                case 14:  secondaryColor = PINK;      break;
                case 15:  secondaryColor = GREEN;     break;
                
                case 21:  sortColor = RAYWHITE;  retVal = 1;  break;
                case 22:  sortColor = BLACK;     retVal = 1;  break;
                case 23:  sortColor = BLUE;      retVal = 1;  break;
                case 24:  sortColor = PINK;      retVal = 1;  break;
                case 25:  sortColor = GREEN;    retVal = 1;   break;
                
                case 31: visualIndicatorColor = RAYWHITE; break;
                case 32: visualIndicatorColor = BLACK;    break;
                case 33: visualIndicatorColor = BLUE;     break;
                case 34: visualIndicatorColor = PINK;     break;
                case 35: visualIndicatorColor = GREEN;    break;
                
                case 41: orderCheckerColor = RAYWHITE; break;
                case 42: orderCheckerColor = BLACK;    break;
                case 43: orderCheckerColor = BLUE;     break;
                case 44: orderCheckerColor = PINK;     break;
                case 45: orderCheckerColor = GREEN;    break;
                
                default: continue;
            }
        }
    }
    return retVal;
}

int CheckSettingsMenuCollisions()
{
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    if(mouseY > 210 && mouseY < 260)
    {
        if(mouseX > 590 && mouseX < 720)   return 1;
        if(mouseX > 760 && mouseX < 890)   return 2;
    }
    if(mouseY > 280 && mouseY < 330)
    {
        if(mouseX > 590 && mouseX < 720)   return 11;
        if(mouseX > 760 && mouseX < 890)   return 12;
        if(mouseX > 910 && mouseX < 1040)  return 13;
        if(mouseX > 1060 && mouseX < 1190) return 14;
        if(mouseX > 1210 && mouseX < 1340) return 15;
    }
    if(mouseY > 350 && mouseY < 400)
    {
        if(mouseX > 590 && mouseX < 720)   return 21;
        if(mouseX > 760 && mouseX < 890)   return 22;
        if(mouseX > 910 && mouseX < 1040)  return 23;
        if(mouseX > 1060 && mouseX < 1190) return 24;
        if(mouseX > 1210 && mouseX < 1340) return 25;
    }
    if(mouseY > 420 && mouseY < 470)
    {
        if(mouseX > 590 && mouseX < 720)   return 31;
        if(mouseX > 760 && mouseX < 890)   return 32;
        if(mouseX > 910 && mouseX < 1040)  return 33;
        if(mouseX > 1060 && mouseX < 1190) return 34;
        if(mouseX > 1210 && mouseX < 1340) return 35;
    }
    if(mouseY > 490 && mouseY < 540)
    {   if(mouseX > 590 && mouseX < 720)   return 41;
        if(mouseX > 760 && mouseX < 890)   return 42;
        if(mouseX > 910 && mouseX < 1040)  return 43;
        if(mouseX > 1060 && mouseX < 1190) return 44;
        if(mouseX > 1210 && mouseX < 1340) return 45;
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