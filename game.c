#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>
#include "pieces.h"
#include "cards.h"
#include "bar.h"




//reset the character input area
//idk how it works copied off a forum
void cleanChar()
{
	while(getchar() != '\n')
		continue;
}

//Insertion sort to make the peices pretty
void sort(int arraySize, int* array)
{
	for(int i = 1; i<arraySize; i++)
	{
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}


int main()
{
	//this is so that I can give random colors (to map them onto consecutive ints)
	int colStore[4];
	colStore[0] = RED;
	colStore[1] = YELLOW;
	colStore[2] = GREEN;
	colStore[3] = BLUE;
	//these guys store the cards in hand
	int handcol[9];
	int handnum[9];
	int cardnum = 0;
	int wildnum = 0;
	//this is some initialization nonsense
	char randString[32];
	if(sodium_init() <0){ //random library died! Oh no!
		printf("A Catastrophic Faliure Occured (EXIT CODE 2)");
		return 2;
	}
	randombytes_buf(randString, 32);
	//	int t = randombytes_uniform(10);
	//this guy's gonna be the number of difficulty used
	int tmp = -1;
	while(tmp <=0) //make user give number
	{
		printf("How many numbers do you want? (can't be more than 6):");
		int input;
		scanf(" %d",&input);
		tmp = input;
		cleanChar();
		if(tmp <=0)
			printf("Not a suitable number\n");
		if(tmp >6)//character? gross (Also I don't like 7 8 9)
		{
			printf("I refuse to use that number\n");
			tmp = -1;
		}
	}
	while(4 != FALSE) //in other words, FOREVER (I didn't remember exact val of FALSE)
	{
		cardnum = 4; //cards in hand
		wildnum = 0;
		for(int i = 0; i<cardnum; i++)//random initial hand
		{
			handcol[i] = colStore[randombytes_uniform(4)];
			handnum[i] = randombytes_uniform(6);
		}
		//initial pieces
		puzzlePiece p1;
		puzzlePiece p2;
		puzzlePiece p3;
		puzzlePiece p4;
		int wildpiece = randombytes_uniform(3);
		for(int i = 0; i<tmp; i++)
		{
			p1.nums[i] = randombytes_uniform(6);
			p2.nums[i] = randombytes_uniform(6);
			p3.nums[i] = randombytes_uniform(6);
			if(wildpiece != 2)
				p4.nums[i] = randombytes_uniform(6);
			else
				p4.nums[i] = -1;
		}
		int thing = 0;
		while(thing != 1)
		{
			thing = 1;
			for(int i=0; i<tmp; i++)
			{
				for(int j = 0; j<tmp; j++)
				{
					if((p1.nums[i] == p1.nums[j])&&j!=i)
					{
						printf("%d|%d\n",i,j);
						p1.nums[i] = randombytes_uniform(6);
						thing = 0;
						break;
					}
				}
			}
		}
		thing = 0;
		if(p4.nums[0] != -1)
		{
			while(thing != 1)
			{
				thing = 1;
				for(int i=0; i<tmp; i++)
				{
					for(int j = 0; j<tmp; j++)
					{
						if((p4.nums[i] == p4.nums[j])&&j!=i)
						{
							printf("%d|%d\n",i,j);
							p4.nums[i] = randombytes_uniform(6);
							thing = 0;
							break;
						}
					}
				}
			}
		}
		thing = 0;
		while(thing != 1)
		{
			thing = 1;
			for(int i=0; i<tmp; i++)
			{
				for(int j = 0; j<tmp; j++)
				{
					if((p3.nums[i] == p3.nums[j])&&j!=i)
					{
						printf("%d|%d\n",i,j);
						p3.nums[i] = randombytes_uniform(6);
						thing = 0;
						break;
					}
				}
			}
		}
		thing = 0;
		while(thing != 1)
		{
			thing = 1;
			for(int i=0; i<tmp; i++)
			{
				for(int j = 0; j<tmp; j++)
				{
					if((p2.nums[i] == p2.nums[j])&&j!=i)
					{
						printf("%d|%d\n",i,j);
						p2.nums[i] = randombytes_uniform(6);
						thing = 0;
						break;
					}
				}
			}
		}
		p1.nums[tmp+1] = -1;
		sort(tmp, p1.nums);
		sort(tmp, p2.nums);
		sort(tmp, p3.nums);
		sort(tmp, p4.nums);
		p1.col = colStore[randombytes_uniform(4)];
		p2.col = colStore[randombytes_uniform(4)];
		p3.col = colStore[randombytes_uniform(4)];
		p4.col = colStore[randombytes_uniform(4)];
		renderBar(tmp, p1, p2, p3, p4);
		//has the user got it yet?
		int solved = FALSE;
		renderCards(cardnum,handcol, handnum, wildnum); //show cards
		while(solved == FALSE) //until the user gets it...
		{
			int tmp1 = 0; //I'm gonna put characters in here
first_step: //part when user says to draw card
			printf("Action (0 for help):");
			scanf(" %d",&tmp1);
			cleanChar();
			switch (tmp1) {
				case 0: //help
					printf("Available actions:\n0:this list\n1:new card\n9:quit\n");
					goto first_step;
				case 1: //draw card
					int something = randombytes_uniform(10);
					if(something == 7) //1 in 10 chance of wild card
					{
						wildnum++; //wow more wildcards
						renderBar(tmp,p1,p2,p3,p4); //draw
						renderCards(cardnum,handcol,handnum,wildnum);
						goto second_step; //proceed (don't draw another card!)
					}
					cardnum++; //wow, more cards now
					if(cardnum>9) //oh no too many cards why?
					{
						printf("Something mildly bad happened (EXIT CODE 3)");
						return 3; //perish
					}
					//make it a random card
					handcol[cardnum -1] = colStore[randombytes_uniform(4)];
					handnum[cardnum -1] = randombytes_uniform(6);
					renderBar(tmp, p1, p2, p3, p4); //draw
					renderCards(cardnum, handcol, handnum,wildnum);
					goto second_step; //okay cool advance
				case 9: //quit
					return 0;
				default: //user did something weird
					printf("That is not a valid action.\n");
					goto first_step;
			}
second_step: //user gueses or discards
			printf("Action (0 for help):");
			scanf(" %d",&tmp1);
			cleanChar();
			switch(tmp1){
				case 0: //help
					printf("Available actions:\n0:this list\n1:make a guess\n2:discard\n9:quit\n");
					goto second_step;
				case 1://guess
					renderBar(tmp,p1,p2,p3,p4);
					renderCards(cardnum,handcol,handnum,wildnum);
					//painstakingly gather guesses
					printf("First card:");
					int a, b, c, d;
					scanf("%d", &a);
					cleanChar();
					printf("Second card:");
					scanf("%d", &b);
					cleanChar();
					printf("Third card:");
					scanf("%d", &c);
					cleanChar();
					printf("Fourth card:");
					scanf("%d", &d);
					cleanChar();
					//are the guesses right?
					if (a == b || a == c || a == d || b == c || b == d || c == d)
					{
						printf("you may not use a card more than once!\n");
						goto second_step;
					}
					int ch1, ch2, ch3, ch4;
					if(a >= cardnum)
					{
						if(cardnum+wildnum <= a) {
							printf("Not a real card!\n");
							goto second_step;
						}
						else
						{
							ch1 = TRUE;
						}
					}
					else{
						ch1 = compareCard(p1,tmp,handcol[a],handnum[a]);
					}
					if(b >= cardnum)
					{
						if(cardnum+wildnum <= b) {
							printf("Not a real card!\n");
							goto second_step;
						}
						else
						{
							ch2 = TRUE;
						}
					}
					else{
						ch2 = compareCard(p2,tmp,handcol[b],handnum[b]);
					}
					if(c >= cardnum)
					{
						if(cardnum+wildnum <= c) {
							printf("Not a real card!\n");
							goto second_step;
						}
						else
						{
							ch3 = TRUE;
						}
					}
					else{
						ch3 = compareCard(p3,tmp,handcol[c],handnum[c]);
					}
					if(d >= cardnum)
					{
						if(cardnum+wildnum <= d) {
							printf("Not a real card!\n");
							goto second_step;
						}
						else
						{
							ch4 = TRUE;
						}
					}
					else{
						ch4 = compareCard(p4,tmp,handcol[d],handnum[d]);
					}
					if(ch1 == 1 && ch2 == 1 && ch3 == 1 && ch4 == 1)
					{
						printf("You guessed it! Another round?(1/0)");
						solved = TRUE; //okay they got it
						int thing; //put some characters here
						scanf("%d",&thing);
						cleanChar();
						if(thing == 0)
							return 0; //oh the user wants to quit
						goto last_step;
					}
					printf("Nope, wrong\n"); //haha didn't get it
					goto second_step; //make them guess/discard
				case 2: //discard
					printf("Type a number:");//which one?
					int store; //we put numbers in here
					scanf("%d",&store);
					cleanChar();
					if(store >= cardnum+wildnum||store<0) //what? Nonsense!
					{
						printf("Not a valid card\n");
						goto second_step; //make em do it again
					}
					if(store >= cardnum)
					{
						wildnum--;
						renderBar(tmp,p1,p2,p3,p4);
						renderCards(cardnum,handcol,handnum,wildnum);
						goto last_step;
					}
					if(store == cardnum-1){ //last card, nice!
						cardnum--; //just remove one of everything
						handnum[store] = -1;
						handcol[store] = -1;
					}
					else //dang it, not last card
					{
						cardnum--; //less cards now
						for(int i = store; i<cardnum; i++)
						{//scoot all cards along
							handnum[i] = handnum[i+1];
							handcol[i] = handcol[i+1];
						}
						//kill the (now redundant) last one
						handnum[cardnum+1] = -1;
						handcol[cardnum+1] = -1;
					}
					//draw
					renderBar(tmp,p1,p2,p3,p4);
					renderCards(cardnum,handcol,handnum,wildnum);
					goto last_step; //okay done
				case 9:
					return 0; //quit
				default: //weird
					printf("That is not a valid action.\n");
					goto second_step;
			}
last_step: // just the end

		}
	}
	return 0;
}
