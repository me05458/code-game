#include <stdio.h>
#include <stdlib.h>
#include "pieces.h"
#include "bar.h"

// |||||||
//||  0  ||
//||  1  ||
//||  2  ||
//||  3  ||
//||  4  ||
//||  5  ||
// |||||||

void renderBar(int tmp, puzzlePiece p1, puzzlePiece p2, puzzlePiece p3, puzzlePiece p4,int turns, int step)
{
    system("clear");
    printf("Turns: %d\tStep: %d\n",turns,step);
    printf("------------------------------------------------\n");
    printf("\e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m ||||||| \n",p1.col, p2.col,p3.col,p4.col);
    for(int i = 0; i<tmp; i++) //wanna do each of the possible numbers
    {
        printf("\e[%d;1m||  %d  ||    \e[%d;1m||  %d  ||    \e[%d;1m||  %d  ||    \e[%d;1m",p1.col, p1.nums[i], p2.col, p2.nums[i], p3.col, p3.nums[i], p4.col);
        if(p4.nums[i] != -1)
            printf("||  %d  || \n", p4.nums[i]);
        else
            printf("||  *  ||\n");
    }
    printf("\e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m ||||||| \n\e[0m",p1.col, p2.col,p3.col,p4.col);
    printf("------------------------------------------------\n");
}

//check if a card matches a puzzlePiece
int compareCard(puzzlePiece p, int tmp, int col, int num)
{
    if(num == -1) //wild card (any number works)
    { //so return if color matches
        if(col == 0)
        {
            return TRUE;
        }
        if(p.col != col)
        {
            return FALSE;
        }
        return TRUE;
    }
    if(col == 0) //wild card
    {
        return TRUE;
    }
    if(p.col != col) //must have same color
    {
        return FALSE;
    }
    if(p.nums[0] == -1) //one of those wild card pieces that can be any number
    {
        return TRUE;
    }
    if(num == -2) //it's an action card!
    {
        printf("You cannot guess an action card\n");
        return FALSE;
    }
    for(int i = 0; i<tmp; i++) //any of the numbers must match
    {
        if(p.nums[i] == num)
            return TRUE;
    }
    return FALSE; //if all else fails it's false
}
