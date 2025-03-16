#include <stdio.h>
#include "cards.h"
#include "pieces.h"

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
void renderCards(int cards, int* cols, int* nums) //draws all of the cards
{
	for(int i = 0; i<cards; i++)
	{
		printf("\e[0m      %d        ", i); //the numbers so you know which number is each card in hand
	}
	printf("\n");

	for(int i = 0; i<cards; i++)
	{
		switch(nums[i])
		{
			case -1:
				if(cols[i] == 0)
				{
					printf("\e[%d;1m ||||||\e[%d;1m|||||   ",RED, YELLOW);
				}
				else
				{
					printf("\e[%d;1m |||||||||||   ",cols[i]);
				}
				break;

			case -2:
				printf("\e[0m |||||||||||   ");
				break;

			default:
				if(cols[i] == 0)
				{
					printf("\e[%d;1m ||||||\e[%d;1m|||||   ",RED, YELLOW);
				}
				else
				{
					printf("\e[%d;1m |||||||||||   ",cols[i]);
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
					if(cols[j] == 0)
					{
						printf("\e[%d;1m||         \e[%d;1m||  ",RED,YELLOW);
					}
					else
					{
						printf("\e[%d;1m||         ||  ",cols[j]);
					}
					break;

				case -2:
					printf("\e[0m||         ||  ");
					break;

				default:
					if(cols[j] == 0)
					{
						printf("\e[%d;1m||         \e[%d;1m||  ",RED,YELLOW);
					}
					else
					{
						printf("\e[%d;1m||         ||  ",cols[j]);
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
				if(cols[i] == 0)
				{
					printf("\e[%d;1m||  \e[0m 123   \e[%d;1m||  ",BLUE,YELLOW);
				}
				else
				{
					printf("\e[%d;1m||   123   ||  ",cols[i]);
				}
				break;

			case -2:
				printf("\e[0m||  add 2  ||  ");
				break;

			default:
				if(cols[i] == 0)
				{
					printf("\e[%d;1m||    \e[0m%d    \e[%d;1m||  ",BLUE,nums[i],YELLOW);
				}
				else
				{
					printf("\e[%d;1m||    %d    ||  ",cols[i],nums[i]);
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
					if(cols[j] == 0)
					{
						printf("\e[%d;1m||         \e[%d;1m||  ",BLUE,GREEN);
					}
					else
					{
						printf("\e[%d;1m||         ||  ",cols[j]);
					}
					break;

				case -2:
					printf("\e[0m||         ||  ");
					break;

				default:
					if(cols[j] == 0)
					{
						printf("\e[%d;1m||         \e[%d;1m||  ",BLUE,GREEN);
					}
					else
					{
						printf("\e[%d;1m||         ||  ",cols[j]);
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
				if(cols[i] == 0)
				{
					printf("\e[%d;1m ||||||\e[%d;1m|||||   ",BLUE, GREEN);
				}
				else
				{
					printf("\e[%d;1m |||||||||||   ",cols[i]);
				}
				break;

			case -2:
				printf("\e[0m |||||||||||   ");
				break;

			default:
				if(cols[i] == 0)
				{
					printf("\e[%d;1m ||||||\e[%d;1m|||||   ",BLUE, GREEN);
				}
				else
				{
					printf("\e[%d;1m |||||||||||   ",cols[i]);
				}
				break;
		}
	}
	printf("\e[0m\n\n");
}
