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

//corners (clockwise from top left): red, yellow, green, blue
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
				printf("\e[%d;1m ||||||\e[%d;1m|||||   ",RED, YELLOW);
				break;

			case -2:
				printf("\e[0m |||||||||||   ");
				break;

			default:
				printf("\e[%d;1m |||||||||||   ",cols[i]);
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
					printf("\e[%d;1m||         \e[%d;1m||  ",RED,YELLOW);
					break;

				case -2:
					printf("\e[0m||         ||  ");
					break;

				default:
					printf("\e[%d;1m||         ||  ",cols[j]);
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
				printf("\e[%d;1m||  \e[0m 123   \e[%d;1m||  ",BLUE,YELLOW);
				break;

			case -2:
				printf("\e[0m||  add 2  ||  ");
				break;

			default:
				printf("\e[%d;1m||    %d    ||  ",cols[i],nums[i]);
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
					printf("\e[%d;1m||         \e[%d;1m||  ",BLUE,GREEN);
					break;

				case -2:
					printf("\e[0m||         ||  ");
					break;

				default:
					printf("\e[%d;1m||         ||  ",cols[j]);
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
				printf("\e[%d;1m |||||\e[%d;1m||||||   ",BLUE,GREEN);
				break;

			case -2:
				printf("\e[0m |||||||||||   ");
				break;

			default:
				printf("\e[%d;1m |||||||||||   ",cols[i]);
				break;
		}
	}
	printf("\e[0m\n\n");
}
