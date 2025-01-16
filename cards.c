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

void renderCards(int cards, int* cols, int* nums, int wild)
{
	int* secure = cols;
	for(int i = 0; i<cards+wild; i++)
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
	printf("\e[0m\n");
}
