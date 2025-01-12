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

void renderCards(int cards, int* cols, int* nums)
{
	int* secure = cols;
	for(int i = 0; i<cards; i++)
	{
		printf("      %d        ", i);
	}
	printf("\n");
	for(int i = 0; i<cards; i++)
	{
		printf("\e[%dm |||||||||||   ",cols[i]);
	}
	printf("\n");
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<cards; j++)
		{
			printf("\e[%dm||         ||  ",cols[j]);
		}
		printf("\n");
	}
	for(int i=0; i<cards; i++)
	{
		printf("\e[%dm||    %d    ||  ",cols[i],nums[i]);
	}
	printf("\n");
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<cards; j++)
		{
			printf("\e[%dm||         ||  ",cols[j]);
		}
		printf("\n");
	}
	for(int i = 0; i<cards; i++)
	{
		printf("\e[%dm |||||||||||   ",cols[i]);
	}
	printf("\e[0m\n");
}
