


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

bool run = true;
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

    srand((unsigned)time(NULL));

    while (currentMines > 0) {
        int randomX = rand() % SIDE;

        int randomY = rand() % SIDE;
      
        //checks if there's a mine placed already
        if (board[randomX][randomY] != 'M')
        {
            
//            printf("placing mine at  %d , %d", randomX, randomY);
  //          printf("\n");
            //using M to represent a mine
            board[randomX][randomY] = 'M';
            currentMines--;

        }
       
    }
}


void init(char board[][MAXSIDE], char board2[][MAXSIDE])
{
   

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            board[i][j] = ' ';
            board2[i][j] = '-';

        }
    }

    return;
}

//checks all the square's neighbors, all combinations of + & - 1 from 
//x & y to see if they are mines
int countNeighboringMines(char board[][MAXSIDE], int x, int y) {
    int neighboring = 0;

    if (x - 1 >= 0) {
        if (board[x - 1][y] == 'M')
            neighboring++;
        if (y - 1 >= 0) {
            if (board[x-1][y-1] == 'M')
                neighboring++;
        }
        if (y +1 < SIDE)
        {
            if (board[x - 1][y+1] == 'M')
                neighboring++;
        }
   }

    if (x + 1< SIDE) {
        if (board[x + 1][y] == 'M')
            neighboring++;
        if (y - 1 >= 0) {
            if (board[x + 1][y - 1] == 'M')
                neighboring++;
        }
        if (y + 1 < SIDE)
        {
            if (board[x+1][y+1] == 'M')
                neighboring++;
        }
    }

    if (y - 1 >= 0) {
        if (board[x][y - 1] == 'M')
            neighboring++;
    }
    if (y + 1 < SIDE)
    {
        if (board[x][y + 1] == 'M')
            neighboring++;
    }
    return neighboring;
}


void makeMove(char board[][MAXSIDE], char board2[][MAXSIDE], int x, int y, bool open) {
    if (x < 0 || y<0 || x>SIDE - 1 || y>SIDE - 1) {
        printf("invalid move at: %d %d", x, y);
        return;
    }
    if (board2[x][y] != '-')
        return;


   // printf("reveal square at %d , %d", x, y);
    
    if (board[x][y] == 'M')
    {
        if (!open)
            return;
        board2[x][y] = board[x][y];
        printf(" you lost! ");
        run = false;
        printf("\n");
        printBoard(board);
    }


    int mines = countNeighboringMines(board, x, y);
    board2[x][y] = ' ';
    
    if (mines > 0) {
        
        string s = to_string(mines);
        board2[x][y] = s[0];
        return;
    }
  
    //only open adjacent squares if the neighbors aren't mines
    //boolean use to prevent opening mines in the recursive calls
    if (x - 1 >= 0)
        makeMove(board, board2, x-1, y, false);
    if (x - 1 >= 0 && y-1 >= 0)
        makeMove(board, board2, x - 1, y-1, false);
    if (x - 1 >= 0 && y+1 < SIDE)
        makeMove(board, board2, x - 1, y + 1, false);
    if (y - 1 >= 0)
        makeMove(board, board2, x, y - 1, false);
    if (y + 1 < SIDE)
        makeMove(board, board2, x, y+1, false);
    if (x + 1 < SIDE)
        makeMove(board, board2, x + 1, y, false);
    if (x + 1 < SIDE && y - 1 >= 0)
        makeMove(board, board2, x + 1, y - 1, false);
    if (x + 1 < SIDE && y + 1 < SIDE)
        makeMove(board, board2, x + 1, y + 1, false);


}


int main()
{

   // printf("test");
    printf("\n");
//neeed two boards one for playing, one for displaying
    char mineSweep[MAXSIDE][MAXSIDE];
    char displayBoard[MAXSIDE][MAXSIDE];
    init(mineSweep, displayBoard);
    setMine(mineSweep);
   
   int x = 0; 
   int y = 0;
      printf("\n");
   while (run) {
       printBoard(displayBoard);
       printf("type 2 numbers for your move ");
       printf("Please enter two integers  ");
       scanf("%d %d", &x, &y);
       makeMove(mineSweep, displayBoard, x, y, true);
      
   }
}
