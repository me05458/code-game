#include <stdio.h>
#include <stdlib.h>
#include "pieces.h"
#include "bar.h"
void renderBar(int tmp, puzzlePiece p1, puzzlePiece p2, puzzlePiece p3, puzzlePiece p4,int turns, int step)
{
    system("clear"); //I know, I know, I'm working on it
    printf("Turns: %d\tStep: %d\n",turns,step);
    printf("------------------------------------------------\n");
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",p1.col, p2.col,p3.col,p4.col);
    for(int i = 0; i<tmp; i++) //wanna do each of the possible numbers
    {
        printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",p1.col, p1.nums[i], p2.col, p2.nums[i], p3.col, p3.nums[i], p4.col);
        if(p4.nums[i] != -1)
            printf("||  %d  || \n", p4.nums[i]);
        else
            printf("||  *  ||\n");

    }
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",p1.col, p2.col,p3.col,p4.col);
    printf("------------------------------------------------\n");
}

//check if a card matches a puzzlePiece
int compareCard(puzzlePiece p, int tmp, int col, int num)
{
    if(p.col != col) //must have same color
    {
        return FALSE;
    }
    if(p.nums[0] == -1)
    {
        return TRUE;
    }
    for(int i = 0; i<tmp; i++) //any of the numbers must match
    {
        if(p.nums[i] == num)
            return TRUE;
    }
    return FALSE;
}
