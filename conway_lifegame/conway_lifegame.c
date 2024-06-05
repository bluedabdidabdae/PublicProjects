/*
    ENG
    Conway's Game of Life is a cellular automaton that is played on a 2D square grid. Each square (or "cell") on the grid can be
    either alive or dead, and they evolve according to the following rules:

        Any live cell with fewer than two live neighbours dies (referred to as underpopulation).
        Any live cell with more than three live neighbours dies (referred to as overpopulation).
        Any live cell with two or three live neighbours lives, unchanged, to the next generation.
        Any dead cell with exactly three live neighbours comes to life.

    The initial configuration of cells can be created by a human, but all generations thereafter are completely
    determined by the above rules. The goal of the game is to find patterns that evolve in interesting ways – something that
    people have now been doing for over 50 years.

    ITA
    Conway's Game of Life è un automa cellulare che si gioca su una griglia quadrata 2D. Ogni quadrato (o "cella") sulla griglia può essere
    vivo o morto, e si evolvono secondo le seguenti regole:

        Qualsiasi cella viva con meno di due vicini vivi muore (indicato come sottopopolazione).
        Qualsiasi cella viva con più di tre vicini vivi muore (indicato come sovrappopolazione).
        Qualsiasi cella viva con due o tre vicini vivi vive, immutata, fino alla generazione successiva.
        Qualsiasi cella morta con esattamente tre vicini vivi prende vita.

    La configurazione iniziale delle cellule può essere creata da un essere umano, ma tutte le generazioni successive sono completamente
    determinate dalle regole di cui sopra. L'obiettivo del gioco è trovare schemi che si evolvono in modi interessanti, qualcosa che le
    persone fanno ormai da oltre 50 anni.


    http://www.cuug.ab.ca/dewara/life/life.html
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define LENGHT 31
#define HEIGHT 31

typedef struct lifegame_cell{
	bool alive;
	int nearCells;
}cell;

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

void LifeGame();
void regole();
void BoardSetup(cell board[LENGHT][HEIGHT], int f);
void PrintBoard(cell board[LENGHT][HEIGHT]);
void UserInit(cell board[LENGHT][HEIGHT]);
void CalcNearCells(cell board[LENGHT][HEIGHT]);
void UpdateBoard(cell board[LENGHT][HEIGHT]);
bool IndexIsValid(int x, int y);

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int choice;
	system("cls");
	printf("Si consiglia caldamente di utilizzare una finestra a schermo interlo per la corretta visualizzazione delle istruzioni, delle regole e dei dati.\n\n");
	system("pause");
	while(true)
	{
		system("cls");
		printf("Menu:\n 1)Visualizza le regole della simulazione.\n 2)Inizializza ed avvia una simulazione.\n\nScelta: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				regole();
			break;
			case 2:
				LifeGame();
			break;
		}
	}
}

void regole()
{
	system("cls");
	printf("Regole della simulazione:\n 1)Qualsiasi cella viva con meno di due vicini vivi muore (indicato come sottopopolazione).\n 2)Qualsiasi cella viva con più di tre vicini vivi muore (indicato come sovrappopolazione).\n 3)Qualsiasi cella viva con due o tre vicini vivi vive, immutata, fino alla generazione successiva.\n 4)Qualsiasi cella morta con esattamente tre vicini vivi prende vita.\n 5)Le generazioni hanno un deelay preimpostato e non modificabile di 1 secondo tra una e l'altra.\n\n");
	system("pause");
}

void LifeGame()
{
	system("cls");
	cell gameBoard[LENGHT][HEIGHT];
	BoardSetup(gameBoard, 1);
	PrintBoard(gameBoard);
	UserInit(gameBoard);
	while(true)
	{
		CalcNearCells(gameBoard);
		UpdateBoard(gameBoard);
		PrintBoard(gameBoard);
		sleep(1);
		BoardSetup(gameBoard, 0);
	}
}

void UpdateBoard(cell board[LENGHT][HEIGHT])
{
	int i,c;
	
	for(i=1;i<HEIGHT-1;i++)
		for(c=1;c<LENGHT-1;c++)
		{
			if(board[c][i].alive&&board[c][i].nearCells<2)
				board[c][i].alive=false;
			else if(board[c][i].alive&&board[c][i].nearCells>3)
				board[c][i].alive=false;
			else if(!board[c][i].alive&&board[c][i].nearCells==3)
				board[c][i].alive=true;
		}
}

void CalcNearCells(cell board[LENGHT][HEIGHT])
{
	int c,i,j,q,aux1,aux2, m=1;
	
	for(i=1;i<HEIGHT-1;i++)
		for(c=1;c<LENGHT-1;c++)

			for(j=-1;j<2;j++)
				for(q=-1;q<2;q++)
				{
					aux2=i+j;
					aux1=c+q;
					if(board[aux1][aux2].alive&&(j!=0||q!=0))
					{
						board[c][i].nearCells=board[c][i].nearCells+1;
						//printf("\noutput n:%d  coord: %d %d  vicini: %d", m, c, i, board[c][i].nearCells);
						//m++;
						//sleep(1);
					}
				}
	//system("pause");
}

bool IndexIsValid(int x, int y)
{
	return x>=0&&y>=0&&x<LENGHT&&y<HEIGHT;
}

void UserInit(cell board[LENGHT][HEIGHT])
{
	int x,y;
	while(true)
	{
		printf("Inserire le coordinate di una cella da attivare/disattivare, le coordinate 0-0 indicano il termine dell'inserimento ed iniziano la simulazione: ");
		scanf("%d %d",&x, &y);
		if(x==0&&y==0)
			return;
		board[x][y].alive=!board[x][y].alive;
		system("cls");
		PrintBoard(board);
	}
}

void BoardSetup(cell board[LENGHT][HEIGHT], int f)
{
	int i,c;
	
	for(i=0;i<LENGHT;i++)
		for(c=0;c<LENGHT;c++)
		{
			if(f==1)
				board[c][i].alive=false;
			board[c][i].nearCells=0;
		}		
}

void PrintBoard(cell board[LENGHT][HEIGHT])
{
	int c,i;
	system("cls");
	for(i=0;i<HEIGHT-1;i++)
	{
		for(c=0;c<LENGHT-1;c++)
		{
			if(c==0&&i==0)
				printf("%c\t",32);
			else if(i==0)
				printf("%d\t",c);
			else if(c==0)
				printf("%d\t",i);
			else if(board[c][i].alive)
				printf("@\t");
			else
				printf("-\t",32);
		}
		printf("\n\n");
	}
}
