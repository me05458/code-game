#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "pieces.h"

// ||||||||||| //red
//||         ||
//||         ||
//||    n    ||
//||         ||
//||         ||
// |||||||||||

// :::::::::::
//::         ::
//::         ::
//::    n    ::
//::         :: //yellow
//::         ::
// :::::::::::

// 88888888888
//88         88
//88         88 //green
//88    n    88
//88         88
//88         88
// 88888888888

// [[][][][][]
//[]         []
//[]         []
//[]    n    [] //blue
//[]         []
//[]         []
// [[][][][][]
//


//corners (clockwise from top left): red, yellow, green, blue
// [][][]|||||
//[]         ||
//[]         ||
//88   any   ||
//88         ::
//88         ::
// 88888::::::

// 22222222222
//22         22
//22         22
//22  add 2  22
//22         22
//22         22
// 22222222222

void renderCards(int cards, int* cols, int* nums)
{
	for(int i = 0; i<cards; i++)
	{
		printf("\e[0m      %d        ", i);
	}
	printf("\n");

	for(int i = 0; i<cards; i++)
	{
		switch(nums[i])
		{
			case -1:
				printf(" [][][]|||||   ");
				break;

			case -2:
				printf("\e[0m 22222222222   ");
				break;

			default:
				switch(cols[i])
				{
					case RED:
						printf("\e[%d;1m |||||||||||   ");
						break;

					case YELLOW:
						printf("\e[%d;1m :::::::::::   ");
						break;

					case BLUE:
						printf("\e[%d;1m [[][][][][]   ");
						break;

					case GREEN:
						printf("\e[%d;1m 88888888888   ");
						break;
				}
				break;
		}
	}
	printf("\n");
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<cards; j++)
		{
			switch(nums[j])
			{
				case -1:
					printf("[]         ||  ");
					break;

				case -2:
					printf("22         22  ");
					break;

				default:
					switch(cols[j])
					{
						case RED:
							printf("\e[%d;1m||         ||  ");
							break;

						case YELLOW:
							printf("\e[%d;1m::         ::  ");
							break;

						case BLUE:
							printf("\e[%d;1m[]         []  ");
							break;

						case GREEN:
							printf("\e[%d;1m88         88  ");
						break;
					}
				break;
			}
		}
		printf("\n");
	}
	for(int i=0; i<cards; i++)
	{
		switch(nums[i])
		{
			case -1:
				printf("88   123   ||  ");
				break;

			case -2:
				printf("22  add 2  22  ");
				break;

			default:
				switch(cols[i])
				{
					case RED:
						printf("||    %d    ||  ",nums[i]);
						break;

					case YELLOW:
						printf("::    %d    ::  ",nums[i]);
						break;

					case BLUE:
						printf("[]    %d    []  ",nums[i]);
						break;

					case GREEN:
						printf("88    %d    88  ",nums[i]);
						break;
				}
				break;
		}
	}
	printf("\n");
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<cards; j++)
		{
			switch(nums[j])
			{
				case -1:
					printf("88         ::  ");
					break;

				case -2:
					printf("22         22  ");
					break;

				default:
					switch(cols[j])
					{
						case RED:
							printf("||         ||  ");
							break;

						case YELLOW:
							printf("::         ::  ");
							break;

						case BLUE:
							printf("[]         []  ");
							break;

						case GREEN:
							printf("88         88  ");
							break;
					}
					break;
			}
		}
		printf("\n");
	}
	for(int i = 0; i<cards; i++)
	{
		switch(nums[i])
		{
			case -1:
				printf(" 88888::::::   ");
				break;

			case -2:
				printf("\e[0m 22222222222   ");
				break;

			default:
				switch(cols[i])
				{
					case RED:
						printf("\e[%d;1m |||||||||||   ");
						break;

					case YELLOW:
						printf("\e[%d;1m :::::::::::   ");
						break;

					case BLUE:
						printf("\e[%d;1m [][][][][]]   ");
						break;

					case GREEN:
						printf("\e[%d;1m 88888888888   ");
						break;
				}
				break;
		}
	}
	printf("\e[0m\n\n");
}

void renderBar(int tmp, puzzlePiece p1, puzzlePiece p2, puzzlePiece p3, puzzlePiece p4,int turns, int step)
{
	system("clear");
	printf("Turns: %d\tStep: %d\n",turns,step);
	printf("------------------------------------------------\n");
	switch(p1.col)
	{
		case RED:
			printf(" |||||||     ");
			break;
		case YELLOW:
			printf(" :::::::     ");
			break;
		case BLUE:
			printf(" [[][][]     ");
			break;
		case GREEN:
			printf(" 8888888     ");
			break;
	}
	switch(p2.col)
	{
		case RED:
			printf(" |||||||     ");
			break;
		case YELLOW:
			printf(" :::::::     ");
			break;
		case BLUE:
			printf(" [[][][]     ");
			break;
		case GREEN:
			printf(" 8888888     ");
			break;
	}
	switch(p3.col)
	{
		case RED:
			printf(" |||||||     ");
			break;
		case YELLOW:
			printf(" :::::::     ");
			break;
		case BLUE:
			printf(" [[][][]     ");
			break;
		case GREEN:
			printf(" 8888888     ");
			break;
	}
	switch(p4.col)
	{
		case RED:
			printf(" ||||||| \n");
			break;
		case YELLOW:
			printf(" ::::::: \n");
			break;
		case BLUE:
			printf(" [[][][] \n");
			break;
		case GREEN:
			printf(" 8888888 \n");
			break;
	}
	for(int i = 0; i<tmp; i++) //wanna do each of the possible numbers
	{
		switch(p1.col)
		{
			case RED:
				printf("||  %d  ||    ",p1.nums[i]);
				break;
			case YELLOW:
				printf("::  %d  ::    ",p1.nums[i]);
				break;
			case BLUE:
				printf("[]  %d  []    ",p1.nums[i]);
				break;
			case GREEN:
				printf("88  %d  88    ",p1.nums[i]);
				break;
		}
		switch(p2.col)
		{
			case RED:
				printf("||  %d  ||    ",p1.nums[i]);
				break;
			case YELLOW:
				printf("::  %d  ::    ",p1.nums[i]);
				break;
			case BLUE:
				printf("[]  %d  []    ",p1.nums[i]);
				break;
			case GREEN:
				printf("88  %d  88    ",p1.nums[i]);
				break;
		}
		switch(p3.col)
		{
			case RED:
				printf("||  %d  ||    ",p1.nums[i]);
				break;
			case YELLOW:
				printf("::  %d  ::    ",p1.nums[i]);
				break;
			case BLUE:
				printf("[]  %d  []    ",p1.nums[i]);
				break;
			case GREEN:
				printf("88  %d  88    ",p1.nums[i]);
				break;
		}
		if(p4.nums[i] != -1)
		{
			switch(p4.col)
			{
				case RED:
					printf("||  %d  ||\n",p1.nums[i]);
					break;
				case YELLOW:
					printf("::  %d  ::\n",p1.nums[i]);
					break;
				case BLUE:
					printf("[]  %d  []\n",p1.nums[i]);
					break;
				case GREEN:
					printf("88  %d  88\n",p1.nums[i]);
					break;
			}
		}
		else
		{
			switch(p4.col)
			{
				case RED:
					printf("||  *  ||\n");
					break;
				case YELLOW:
					printf("::  *  ::]\n");
					break;
				case BLUE:
					printf("[]  *  []\n");
					break;
				case GREEN:
					printf("88  *  88\n");
					break;
			}
		}

	}
	switch(p1.col)
	{
		case RED:
			printf(" |||||||     ");
			break;
		case YELLOW:
			printf(" :::::::     ");
			break;
		case BLUE:
			printf(" [[][][]     ");
			break;
		case GREEN:
			printf(" 8888888     ");
			break;
	}
	switch(p2.col)
	{
		case RED:
			printf(" |||||||     ");
			break;
		case YELLOW:
			printf(" :::::::     ");
			break;
		case BLUE:
			printf(" [[][][]     ");
			break;
		case GREEN:
			printf(" 8888888     ");
			break;
	}
	switch(p3.col)
	{
		case RED:
			printf(" |||||||     ");
			break;
		case YELLOW:
			printf(" :::::::     ");
			break;
		case BLUE:
			printf(" [[][][]     ");
			break;
		case GREEN:
			printf(" 8888888     ");
			break;
	}
	switch(p4.col)
	{
		case RED:
			printf(" ||||||| \n");
			break;
		case YELLOW:
			printf(" ::::::: \n");
			break;
		case BLUE:
			printf(" [[][][] \n");
			break;
		case GREEN:
			printf(" 8888888 \n");
			break;
	}	printf("------------------------------------------------\n");
}

//check if a card matches a puzzlePiece
int compareCard(puzzlePiece p, int tmp, int col, int num)
{
	if(num == -1)
	{
		return TRUE;
	}
	if(p.col != col) //must have same color
	{
		return FALSE;
	}
	if(p.nums[0] == -1)
	{
		return TRUE;
	}
	if(num == -2)
	{
		printf("You cannot guess an action card\n");
		return FALSE;
	}
	for(int i = 0; i<tmp; i++) //any of the numbers must match
	{
		if(p.nums[i] == num)
			return TRUE;
	}
	return FALSE;
}
