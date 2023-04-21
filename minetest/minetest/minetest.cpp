


#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;


#define MAXSIDE 25
#define MAXMINES 99



//board side length 
int SIDE = 12;
//number of mines
int MINES = 10; 

void printBoard(char board[][MAXSIDE])
{
    int i, j;

    printf("    ");

    for (i = 0; i < SIDE; i++)
        printf("%d ", i);

    printf("\n\n");

    for (i = 0; i < SIDE; i++)
    {
        printf("%d   ", i);

        for (j = 0; j < SIDE; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    return;
}
void setMine(char board[][MAXSIDE]) {
     int currentMines = MINES;
     printf("set mines: %d", currentMines);
   //  cout << " setMines: ";
    //cout << currentMines;
    srand((unsigned)time(NULL));

    while (currentMines > 0) {
        int randomX = rand() % SIDE;

        int randomY = rand() % SIDE;
      
        //checks if there's a mine placed already
        if (board[randomX][randomY] != 'M')
        {
            
            printf("placing mine at  %d , %d", randomX, randomY);
            printf("\n");
            //using M to represent a mine
            board[randomX][randomY] = 'M';
            currentMines--;

        }
       
    }
}

//initializes board with just Xs
void init(char board[][MAXSIDE])
{
   

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            board[i][j] = '-';
        }
    }

    return;
}

void checkMoveTrue(int x, int y) {
    if (x < 0 || y<0 || x>SIDE-1 || y>SIDE-1)
        printf("invalid move at: %d %d", x, y);

    else
        printf("valid");
}


void makeMove(char board[][MAXSIDE], int x, int y) {
    if (x < 0 || y<0 || x>SIDE - 1 || y>SIDE - 1) {
        printf("invalid move at: %d %d", x, y);
        return;
    }


    printf("reveal square at %d , %d", x, y);
    printf("%c ", board[x][y]);
    if (board[x][y] == 'M') {
        printf(" you lost! ");
    }
    printf("\n");

}

int main()
{

    printf("test");
    printf("\n");
    char mineSweep[MAXSIDE][MAXSIDE];
    init(mineSweep);
    setMine(mineSweep);
   printBoard(mineSweep);
   int x = 0; 
   int y = 0;
   printf("type 2 numbers for your move ");
   printf("Please enter two integers  ");
   scanf("%d %d", &x, &y);
   makeMove(mineSweep, x, y);

}
