#include <stdio.h>
#include "cards.h"
#define RED 31
#define YELLOW 33
#define GREEN 32
#define BLUE 36

// ||||||||||| 
//||         ||
//||         ||
//||    n    ||
//||         ||
//||         ||
// |||||||||||
//
// ||||||\\\\\
//||         \\
//||         \\
//\\   any   \\
//\\         ||
//\\         ||
// \\\\\|||||| 

// |||||||||||
//||         ||
//||         ||
//||  add 2  ||
//||         ||
//||         ||
// |||||||||||
void renderCards(int cards, int* cols, int* nums, int wild, int draw)
{
	int* secure = cols;
	for(int i = 0; i<cards+wild+draw; i++)
	{
		printf("      %d        ", i);
	}
	printf("\n");
	for(int i = 0; i<cards; i++)
	{
		printf("\e[%dm |||||||||||   ",cols[i]);
	}
	for(int i = 0; i<wild; i++)
	{
		printf("\e[%dm ||||||\e[%dm|||||   ",RED, YELLOW);
	}
	for(int i = 0; i<draw; i++)
	{
		printf("\e[0m |||||||||||   ");
	}
	printf("\n");
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<cards; j++)
		{
			printf("\e[%dm||         ||  ",cols[j]);
		}
		for(int j = 0; j<wild; j++)
		{
			printf("\e[%dm||         \e[%dm||  ",RED,YELLOW);
		}
		for(int j = 0; j<draw; j++)
		{
			printf("\e[0m||         ||  ");
		}
		printf("\n");
	}
	for(int i=0; i<cards; i++)
	{
		printf("\e[%dm||    %d    ||  ",cols[i],nums[i]);
	}
	for(int i=0; i<wild; i++)
	{
		printf("\e[%dm||  \e[0m 123   \e[%dm||  ",BLUE,YELLOW);
	}
	for(int i = 0; i<draw; i++)
	{
		printf("\e[0m||  add 2  ||  ");
	}
	printf("\n");
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<cards; j++)
		{
			printf("\e[%dm||         ||  ",cols[j]);
		}
		for(int j = 0; j<wild; j++)
		{
			printf("\e[%dm||         \e[%dm||  ",BLUE,GREEN);
		}
		for(int j = 0; j<draw; j++)
		{
			printf("\e[0m||         ||  ");
		}
		printf("\n");
	}
	for(int i = 0; i<cards; i++)
	{
		printf("\e[%dm |||||||||||   ",cols[i]);
	}
	for(int i = 0; i<wild; i++)
	{
		printf("\e[%dm |||||\e[%dm||||||   ",BLUE,GREEN);
	}
	for(int i = 0; i<draw; i++)
	{
		printf("\e[0m |||||||||||   ");
	}
	printf("\e[0m\n\n");
}
