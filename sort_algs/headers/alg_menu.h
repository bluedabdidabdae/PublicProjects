#ifndef ALG_MENU_H
#define ALG_MENU_H

int AlgsMenuHandler(alg element_list[]);
void DrawAlgsMenu(alg vect[]);
int CheckAlgsMenuCollisions(alg vect[]);
void RecapScreen(char algName[][40], float algtime, data element_list[]);
void DrawRecapScreen(char algName[][40], float algtime, int sorted);
void DrawWaitSortingScreen();

#endif