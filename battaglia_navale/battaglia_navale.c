#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h> // necessaria solo per qualche while(true){...}

#define lenght 12 //dimensione x board
#define height 12 //dimensione y board
#define navex2 43 // +
#define navex3 120 // x
#define navex4 79 // O
#define navex5 64 // @
#define miss 248 // ø in teoria, in pratica è ° (se sistemo i caratteri su dev si sminchiano su vscode e viceversa, li tengo che sono giusti su vscode)
#define hit 35 // #
#define voidchar 32 //void
#define hittowin 30 //hit necessari per vincere
#define RNGLIMIT 100 //limite tentativi rng iashotv2

void menu();
void regole();
void gamevsia();
void gamevsplayer();
void resetboard(int board1[lenght][height]);
void printboard(int board1[lenght][height]);
void fillplayerboard(int fillboard[lenght][height]);
void filliaboard(int fillboard[lenght][height]);
void positionboat(int board1[lenght][height], int orientamento, int x, int y, int lunghezza);
int checkclip(int board1[lenght][height], int x, int y, int orientamento, int lunghezza);
int playershot(int board1[lenght][height],int otherboard[lenght][height]);
//int iashot(int board1[lenght][height],int otherboard[lenght][height]);
int drawshot(int logboard[lenght][height],int otherplayerboard[lenght][height],int y,int x);
int drawiashot(int logboard[lenght][height],int otherplayerboard[lenght][height],int y,int x, int *lastx, int *lasty);
int iashotv2(int board1[lenght][height],int otherboard[lenght][height], int *oldx, int *oldy);

// RICHIAMA SOLO IL MENU PER FARE CONTENTO ANTONACI
int main(){
    menu();
    return 0;
}

// BRUH LEGGI IL NOME DELLA FUNZIONE
void menu(){
	int scelta=9999;
    while(true){
        printf("             MENU");
        printf("\n\nScelte:\n1)Visualizza regole ed istruzioni per giocare\n2)Inizia una partita contro l'ia\n3)Inizia una partita contro un giocatore\n4)Termina il programma\n\nScelta: ");
        scanf("%d",&scelta);
        
        switch(scelta){
            case 1:
                system("cls");
                regole();
            break;
            case 2:
                printf("Si e' scelto di iniziare una partita contro l'ia.");
                sleep(3);
                system("cls");
                gamevsia();
            break;
            case 3:
                printf("Si e' scelto di iniziare una partita contro un giocatore.");
                sleep(3);
                system("cls");
                gamevsplayer();
            break;
            case 4:
                printf("Si e' deciso di terminare il programma.");
                sleep(3);
                return;
            break;
            default:
                printf("Scelta non valida");
                sleep(2);
                system("cls");
            break;
        }
    }
    return;
}

// STAMPA LE REGOLE
void regole(){
    printf("Regole:\n- Il simbolo %c indica una posizione dove e' stata colpita una nave\n- il simbolo %c indica una posizione dove non e' stata colpita alcuna nave\n- il simbolo %c indica una posizione occupata da una nave 1x2\n- il simbolo %c indica una posizione occupata da una nave 1x3\n- il simbolo %c indica una posziione occupata da una nave 1x4\n- il simbolo %c indica una posizione occupata da una nave 1x5\n\n",hit,miss,navex2,navex3,navex4,navex5);
    system("pause");
    system("cls");
    return;
}

// GIOCO PvE
void gamevsia(){
    struct game{
        int board[lenght][height];
        int enemyboard[lenght][height];
        int nhit;
    } p1,ia;
    int lastx=0, lasty=0;
    srand(time(NULL));

    resetboard(p1.board);
    resetboard(p1.enemyboard);
    fillplayerboard(p1.board);
    
    // printf("                                      YOUR BOARD\n\n");
    // printboard(p1.board);

    resetboard(ia.board);
    resetboard(ia.enemyboard);
    filliaboard(ia.board);

    // printf("                                       IA BOARD\n\n");
    // printboard(ia.board);

    p1.nhit=0;
    ia.nhit=0;
    while(p1.nhit<hittowin&&ia.nhit<hittowin){
        printf("                                      YOUR BOARD\n\n");
        printboard(p1.board);

        printf("                                       IA BOARD\n\n");
        printboard(p1.enemyboard);
        p1.nhit=p1.nhit+playershot(p1.enemyboard,ia.board);
        if(p1.nhit>=hittowin){
            printf("\nComplimenti, hai vinto contro l'ia!\n\n");
            system("pause");
            system("cls");
            return;
        }
        //ia.nhit=ia.nhit+iashot(ia.enemyboard,p1.board);       VECCHIO RICHIAMO ALLA PRIMA VERSIONE DI iashot
        ia.nhit=ia.nhit+iashotv2(ia.enemyboard,p1.board,&lastx,&lasty);
        if(ia.nhit>=hittowin){
            printf("\nPeccato, hai perso e ha vinto l'ia.\n\n");
            system("pause");
            system("cls");
            return;
        }
    }
    printf("<<ERRORE INTERNO DEL PROGRAMMA, SARAI RIPORTATO AL MENU>>");    // LEGGE DI MURPHY
    sleep(4);
    system("cls");
    return;
}

// GIOCO PvP
void gamevsplayer(){
	struct game{
        int board[lenght][height];
        int enemyboard[lenght][height];
        int nhit;

    } p1,p2;
    system("cls");
	printf("Turno del giocatore 1, riempimento board.\n\n");
    system("pause");
   	system("cls");
    resetboard(p1.board);
    resetboard(p1.enemyboard);
    fillplayerboard(p1.board);
    
    // printf("                                      PLAYER 1 BOARD\n\n");
    // printboard(p1.board);
	
	system("cls");
	printf("Turno del giocatore 2, riempimento board.\n\n");
   	system("pause");
    system("cls");
    resetboard(p2.board);
    resetboard(p2.enemyboard);
    fillplayerboard(p2.board);

    // printf("                                      PLAYER 2 BOARD\n\n");
    // printboard(p2.board);

    p1.nhit=0;
    p2.nhit=0;
    while(p1.nhit<hittowin&&p2.nhit<hittowin){
    	system("cls");
		printf("\nTurno del giocatore 1.\n\n");
    	system("pause");
    	system("cls");
        printf("                                      PLAYER 1 BOARD\n\n");
        printboard(p1.board);

        printf("                                   PLAYER 2 (enemy) BOARD\n\n");
        printboard(p1.enemyboard);
        p1.nhit=p1.nhit+playershot(p1.enemyboard,p2.board);
        if(p1.nhit==hittowin){
            printf("\nComplimenti giocatore 1, hai vinto!\n\n");
            system("pause");
            system("cls");
            return;
        }
        system("cls");
        printf("\nTurno del giocatore 2.\n\n");
        system("pause");
        system("cls");
        printf("                                      PLAYER 2 BOARD\n\n");
        printboard(p2.board);

        printf("                                   PLAYER 1 (enemy) BOARD\n\n");
        printboard(p2.enemyboard);
        p2.nhit=p2.nhit+playershot(p2.enemyboard,p1.board);
        if(p2.nhit==hittowin){
            printf("\nComplimenti giocatore 2, hai vinto!\n\n");
            system("pause");
            system("cls");
            return;
        }
    }
    printf("<<ERRORE INTERNO DEL PROGRAMMA, SARAI RIPORTATO AL MENU>>");    // LEGGE DI MURPHY PT.2
    sleep(4);
    system("cls");
    return;
}

// RESETTA LA GRIGLIA CHE GLI VIENE DATA RIASSEGNANDO TUTTI I CARATTERI (ANCHE LE LEGENDE PER SICUREZZA, LEGGE DI MURPY PT.3)
void resetboard(int board1[lenght][height]){
    int c,i,p=1,j=1;
    for(c=0;c<height;c++){
        for(i=0;i<lenght;i++){
            if(c>11||i>11){
            	board1[i][c]=hit;
			}
			else if(c==0&&i==0){
                board1[i][c]=voidchar;
            }
            else if(c==0){
                board1[i][c]=j;
                j++;
            }
            else if(i==0){
                board1[i][c]=p;
                p++;
            }
            else{
                board1[i][c]=voidchar;
            }
        }
    }
    return;
}

// STAMPA LA GRIGLIA CHE GLI VIENE DATA
void printboard(int board1[lenght][height]){
    int c,i;
    printf("  ");
    for(c=0;c<height-1;c++){
        for(i=0;i<lenght-1;i++){
        	if(i==0&&c==0)                             		 //stampa l'angolo in alto a sx
                printf("%c\t",board1[i][c]);
            else if(i==0||c==0)                              //stampa gli indici
                printf("%d\t",board1[i][c]);
            else                                        	//stampa interno tabella
                printf("%c\t",board1[i][c]);
        }
        printf("\n\n");
    }
    return;
}

// RICHIEDE AL GIOCATORE LE COORDINATE ED ORIENTAMENTO DELLE NAVI
void fillplayerboard(int fillboard[lenght][height]){
    int tmpx,tmpy,c,i,l=2,orient,clip=1;

    for(i=4;i>0;i--){
        for(c=0;c<i;c++){
            while(clip==1){
                printf("                                     PLAYER BOARD\n\n");
                printboard(fillboard);
                printf("Inserire 0 per posizionare la nave da %d slot n.%d in orizzontale o 1 per posizionarla in verticale: ",l,c+1);
                scanf("%d",&orient);
                while(orient!=0&&orient!=1){
                    printf("Carattere non valido, inserire 0 o 1: ");
                    scanf("%d",&orient);
                }
                printf("Inserire coordinate X della nave da %d slot n.%d: ",l,c+1);
                scanf("%d",&tmpx);
                while(((orient==0)&&(tmpx>11-l))||tmpx<1||tmpx>10){
                    printf("Valore non valido, inserire coordinate X della nave: ");
                    scanf("%d",&tmpx);
                }
                printf("Inserire coordinate Y della nave da %d slot n.%d: ",l,c+1);
                scanf("%d",&tmpy);
                while(((orient==1)&&(tmpy>11-l))||tmpy<1||tmpy>10){
                    printf("Valore non valido, inserire coordinate Y della nave: ");
                    scanf("%d",&tmpy);
                }
                printf("orientamento: %d    coordx: %d    coordy: %d\n\n",orient,tmpx,tmpy);
                clip=checkclip(fillboard, tmpx, tmpy, orient, l);
                if(clip==1)
                    printf("Posizione non valida, la posizione e' gia' occupata da un'altra nave alleata.\n\n");
                system("pause");
                system("cls");
            }
            clip=1;
            positionboat(fillboard,orient,tmpx,tmpy,l);
        }
        l++;
    } 
    return;
}

// RIEMPIE LA GRIGLIA DELL'IA GENERANDO COORDINATE ED ORIENTAMENTO IN MODO CASUALE PER TENTATIVI, SI PUO' OTTIMIZZARE
void filliaboard(int fillboard[lenght][height]){
    int i,c,l=2,limit,tmpx,tmpy,orient,clip=1;

    for(i=4;i>0;i--){
        for(c=0;c<i;c++){
            while(clip==1){
                orient=rand()%2+0;
                limit=11-l;
                if(orient==0){
                    tmpy=rand()%10+1;
                    tmpx=rand()%limit+1;
                }
                else{
                    tmpy=rand()%limit+1;
                    tmpx=rand()%10+1;
                }
                clip=checkclip(fillboard,tmpx,tmpy,orient,l);
            }
            clip=1;
            positionboat(fillboard,orient,tmpx,tmpy,l);
        }
        l++;
    }
    return;
}

// "DISEGNA" LA BARCA SULLA GRIGLIA (USATO SOLO IN FASE DI RIEMPIMENTO DELLE GRIGLIE)
void positionboat(int board1[lenght][height], int orientamento, int x, int y, int lunghezza){
    int c,tmpx=x,tmpy=y;

    for(c=0;c<lunghezza;c++){
        if(lunghezza==2)
            board1[tmpx][tmpy]=navex2;
        else if(lunghezza==3)
            board1[tmpx][tmpy]=navex3;
        else if(lunghezza==4)
            board1[tmpx][tmpy]=navex4;
        else if(lunghezza==5)
            board1[tmpx][tmpy]=navex5;
        if(orientamento==0)
            tmpx++;
        else
            tmpy++;
    }
    return;
}

// CONTROLLA SE LE COORDINATE SONO GIA' OCCUPATE DA UNA NAVE
int checkclip(int board1[lenght][height], int x, int y, int orientamento, int lunghezza){
    int c,tmpx=x,tmpy=y;

    for(c=0;c<lunghezza;c++){
        if(board1[tmpx][tmpy]!=voidchar)
            return 1;
        if(orientamento==0)
            tmpx++;
        else
            tmpy++;
    }
    return 0;
}

// RICHIEDE LE COORDINATE DA COLPIRE AL GICATORE E NE VERIFICA LA CORRETTEZZA
int playershot(int board1[lenght][height],int otherboard[lenght][height]){
    int flag,tmpy,tmpx;
    flag=0;
    while(flag==0){
        printf("Inserire coordinate y da colpire: ");
        scanf("%d",&tmpy);
        if(tmpy<11&&tmpy>0)
            flag=1;
        else{
            printf("Coordinate non valide.\n");
        }
    }
    flag=0;
    while(flag==0){
        printf("Inserire coordinate x da colpire: ");
        scanf("%d",&tmpx);
        if(tmpx<11&&tmpx>0)
            flag=1;
        else{
            printf("Coordinate non valide.\n");
        }
    }
    return drawshot(board1,otherboard,tmpy,tmpx);
}

/* VERSIONE INIZIALE SECONDO CUI L'IA SPARA TOTALMENTE A CASO

int iashot(int board1[lenght][height],int otherboard[lenght][height]){
    int tmpx,tmpy;
    srand(time(NULL));

    do{
        tmpx=rand()%10+1;
        tmpy=rand()%10+1;
    }while(otherboard[tmpx][tmpy]==miss||otherboard[tmpx][tmpy]==hit);

    return drawshot(board1,otherboard,tmpy,tmpx);
}
*/

// DISEGNA SULLE GRIGLIE UN COLPO SPARATO DA UN GIOCATORE
int drawshot(int logboard[lenght][height],int otherplayerboard[lenght][height],int y,int x){
    if(otherplayerboard[x][y]==voidchar){
        logboard[x][y]=miss;
        return 0;
    }
    else if(logboard[x][y]!=hit&&logboard[x][y]!=miss){
        logboard[x][y]=hit;
        otherplayerboard[x][y]=hit;
        return 1;
    }
    return 0;
}

// DISEGNA SULLE GRIGLIE UN COLPO SPARATO DALL'IA, POTREBBE ESSERE INTEGRATO A QUELLO PER I COLPI DEI GIOCATORI
int drawiashot(int logboard[lenght][height],int otherplayerboard[lenght][height],int y,int x, int *lastx, int *lasty){
    if(otherplayerboard[x][y]==voidchar){
        logboard[x][y]=miss;
        return 0;
    }
    else if(logboard[x][y]!=hit&&logboard[x][y]!=miss){
        logboard[x][y]=hit;
        otherplayerboard[x][y]=hit;
        *lastx=x;
        *lasty=y;
        return 1;
    }
    return 0;
}

/*
VERSIONE MIGLIORATA, L'IA SPARA A CASO FINCHE' NON TROVA UNA NAVE, DOPO PROCEDE A CONTROLLARE
TUTTE LE CASELLE PROCEDENDO IN SENSO ORARIO, SE COLPISCE UNA NAVE RICOMINCIA A CONTROLLARE LE
CASELLE ADIACENTI DA QUELLE COORDINATE
*/
int iashotv2(int board1[lenght][height],int otherboard[lenght][height], int *oldx, int *oldy){
    int tmpx,tmpy;
    int c=0;        //nel caso l'ia fa troppi tentativi non validi passa alla seconda griglia (risolve un bug dove l'ia non verifica delle coordinate, legge di murphy pt.4)

    while(true){
    	if(*oldx==0&&*oldy==0){
    		
    		do{
     			tmpx=rand()%10+1;
     			tmpy=rand()%10+1;
     			if(tmpx%2==0&&tmpy%2!=0){
     		   		tmpx--;
				}
				if(tmpx%2!=0&&tmpy%2==0){
					tmpy--;
				}
				c++;
    		}while(board1[tmpx][tmpy]!=voidchar&&c<RNGLIMIT);
    		if(board1[tmpx][tmpy]==voidchar)
            	return drawiashot(board1,otherboard,tmpy,tmpx,oldx,oldy);

        	c=0;

    		do{
     			tmpx=rand()%10+1;
     			tmpy=rand()%10+1;
     			if(tmpx%2==0&&tmpy%2!=0){
     		   		tmpx--;
				}
				if(tmpx%2!=0&&tmpy%2==0){
					tmpy--;
				}
				c++;
    		}while(board1[tmpx][tmpy]!=voidchar&&c<RNGLIMIT);
    		if(board1[tmpx][tmpy]==voidchar)
            	return drawiashot(board1,otherboard,tmpy,tmpx,oldx,oldy);
		
			c=0;
		}
		else{
			tmpx=*oldx;
        	tmpy=*oldy;
        	if(board1[tmpx][tmpy-1]==voidchar&&tmpy>1){
        	    return drawiashot(board1,otherboard,tmpy-1,tmpx,oldx,oldy);
			}
			if(board1[tmpx+1][tmpy]==voidchar&&tmpx<11){
        	    return drawiashot(board1,otherboard,tmpy,tmpx+1,oldx,oldy);
			}
			if(board1[tmpx][tmpy+1]==voidchar&&tmpy<11){
        	    return drawiashot(board1,otherboard,tmpy+1,tmpx,oldx,oldy);
			}
			if(board1[tmpx-1][tmpy]==voidchar&&tmpx>1){
        	    return drawiashot(board1,otherboard,tmpy,tmpx-1,oldx,oldy);
			}
			*oldx=0;
			*oldy=0;
		}
	}
}

