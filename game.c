#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>
#include "pieces.h"
#include "cards.h"
#include "bar.h"

//global variables:
int colStore[4];
int handcol[9];
int handnum[9]; //number  = -1 means wold card, -2 means action card
int cardnum = 0;
int tmp;
int turns = 0;
int step = 0;
puzzlePiece p1;
puzzlePiece p2;
puzzlePiece p3;
puzzlePiece p4;


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


int draw() //returns:
			//1 - regular card, proceed to discard/guess
			//2 - action card! proceed to action card
{
	cardnum++; //wow more cards now
	int something = randombytes_uniform(10);
	if(something == 7) //1 in 10 chance of draw card
	{
		handcol[cardnum -1] = 0;
		handnum[cardnum -1] = -2;
		renderBar(tmp,p1,p2,p3,p4,turns,step); //draw
		renderCards(cardnum,handcol,handnum);
		return 1;
	}
	if(something ==4) //1 in 10 chance of wild card
	{
		handcol[cardnum -1] = 0;
		handnum[cardnum -1] = -1;
		renderBar(tmp, p1,p2,p3,p4,turns,step);
		renderCards(cardnum,handcol,handnum);
		return 2;
	}
	if(cardnum>9) //oh no too many cards why?
	{
		printf("Something mildly bad happened (EXIT CODE 3)\n");
		return 3; //perish
	}
	//make it a random card
	handcol[cardnum -1] = colStore[randombytes_uniform(4)];
	handnum[cardnum -1] = randombytes_uniform(6);
	renderBar(tmp, p1, p2, p3, p4,turns,step); //draw
	renderCards(cardnum, handcol, handnum);
	return 1;
}
int guess() //returns:
			//1 - Did not guess it
			//2 - guessed it
			//0 - user wants to quit! (after guessing it)
{
	renderBar(tmp,p1,p2,p3,p4,turns,step);
	renderCards(cardnum, handcol, handnum);
	//painstakingly gather guesses
	printf("First card: ");
	int a, b, c, d;
	scanf("%d", &a);
	cleanChar();
	printf("Second card: ");
	scanf("%d", &b);
	cleanChar();
	printf("Third card: ");
	scanf("%d", &c);
	cleanChar();
	printf("Fourth card: ");
	scanf("%d", &d);
	cleanChar();
	//are the guesses right?
	if (a == b || a == c || a == d || b == c || b == d || c == d)
	{
		printf("you may not use a card more than once!\n");
		return 1;
	}
	int ch1, ch2, ch3, ch4;
	if(a >= cardnum || b >=cardnum || c >= cardnum || d>=cardnum)
	{
		printf("Not a valid card!\n");
	}
	ch1 = compareCard(p1,tmp,handcol[a],handnum[a]);
	ch2 = compareCard(p2,tmp,handcol[b],handnum[b]);
	ch3 = compareCard(p3,tmp,handcol[c],handnum[c]);
	ch4 = compareCard(p4,tmp,handcol[d],handnum[d]);
	if(ch1 == 1 && ch2 == 1 && ch3 == 1 && ch4 == 1)
	{
		if(turns == 1)
			printf("You guessed it after %d turn! Another round?(1/0): ",turns);
		else
			printf("You guessed it after %d turns! Another round?(1/0): ",turns);
		//solved = TRUE; //okay they got it
		int thing; //put some characters here
		scanf("%d",&thing);
		cleanChar();
		if(thing == 0)
			return 0; //oh the user wants to quit
		return 2;
	}
	printf("Nope, wrong\n"); //haha didn't get it
	return 1; //make them guess/discard
}

int discard() //returns:
				//1 - not valid return
				//0 - all is fine
{
	renderBar(tmp,p1,p2,p3,p4,turns,step);
	renderCards(cardnum, handcol, handnum);
	printf("Card to discard: ");//which one?
	int store; //we put numbers in here
	scanf("%d",&store);
	cleanChar();
	if(store >= cardnum||store<0) //what? Nonsense!
	{
		printf("Not a valid card\n");
		return 1; //make em do it again
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
	renderBar(tmp,p1,p2,p3,p4,turns,step);
	renderCards(cardnum, handcol, handnum);
	return 0; //okay done
}
int discardGiven(int card) //returns:
//1 - not valid return
//0 - all is fine
{
	renderBar(tmp,p1,p2,p3,p4,turns,step);
	renderCards(cardnum, handcol, handnum);
	if(card >= cardnum||card<0) //what? Nonsense!
	{
		return 1; //make em do it again
	}
	if(card == cardnum-1){ //last card, nice!
		cardnum--; //just remove one of everything
		handnum[card] = -1;
		handcol[card] = -1;
	}
	else //dang it, not last card
	{
		cardnum--; //less cards now
		for(int i = card; i<cardnum; i++)
		{//scoot all cards along
			handnum[i] = handnum[i+1];
			handcol[i] = handcol[i+1];
		}
		//kill the (now redundant) last one
		handnum[cardnum+1] = -1;
		handcol[cardnum+1] = -1;
	}
	//draw
	renderBar(tmp,p1,p2,p3,p4,turns,step);
	renderCards(cardnum, handcol, handnum);
	return 0; //okay done
}

int main()
{
	system("clear");
	//this is so that I can give random colors (to map them onto consecutive ints)
	colStore[0] = RED;
	colStore[1] = YELLOW;
	colStore[2] = GREEN;
	colStore[3] = BLUE;
	//these guys store the cards in hand
	//this is some initialization nonsense
	char randString[32];
	if(sodium_init() <0){ //random library died! Oh no!
		printf("A Catastrophic Faliure Occured (EXIT CODE 2)\n");
		return 2;
	}
	randombytes_buf(randString, 32);
	//this guy's gonna be the number of difficulty used
	tmp = -1;
	while(tmp <=0) //make user give number
	{
		printf("How many numbers do you want? (can't be more than 6): ");
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
		step = 0;
		turns = 0;
		cardnum = 4; //cards in hand
		for(int i = 0; i<cardnum; i++)//random initial hand
		{
			handcol[i] = colStore[randombytes_uniform(4)];
			handnum[i] = randombytes_uniform(6);
		}
		//initial pieces
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
		//has the user got it yet?
		int solved = FALSE;
		while(solved == FALSE) //until the user gets it...
		{
			step = 1;
			renderBar(tmp, p1, p2, p3, p4, turns,step);
			renderCards(cardnum, handcol, handnum);
			int tmp1 = 0; //I'm gonna put characters in here
first_step: //part when user says to draw card
			printf("Action (0 for help): ");
			scanf(" %d",&tmp1);
			cleanChar();
			switch (tmp1) {
				case 0: //help
					renderBar(tmp,p1,p2,p3,p4,turns,step);
					renderCards(cardnum, handcol, handnum);
					printf("Available actions:\n\e[0m0:this list\n1:new card\n\e[30;1m2:use action card [UNAVAILABLE]\n\e[30;1m3:make a guess [UNAVIALABLE]\n\e[30;1m4:discard [UNAVAILABLE]\n\e[0m9:quit\n");
					goto first_step;
				case 1: //draw card
					renderBar(tmp,p1,p2,p3,p4,turns,step);
					renderCards(cardnum, handcol, handnum);
					tmp1 = draw();
					for(int i = 0; i<cardnum; i++)
					{
						if(handnum[i] == -2)
						{
							step = 2;
							renderBar(tmp,p1,p2,p3,p4,turns,step);
							renderCards(cardnum, handcol, handnum);
							goto onepttwo_step;
						}
					}
					step = 3;
					renderBar(tmp,p1,p2,p3,p4,turns,step);
					renderCards(cardnum, handcol, handnum);
					goto second_step; //otherwise it's normal
				case 9: //quit
					return 0;
				default: //user did something weird
					printf("That is not a valid action.\n");
					goto first_step;
			}
onepttwo_step: //you can only do this once! (I could've written it without the goto onepttwo_step but it's neater this way)
	step = 2;
	printf("Action (0 for help): ");
	scanf(" %d",&tmp1);
	cleanChar();
	switch(tmp1){
		case 0: //help
			renderBar(tmp,p1,p2,p3,p4,turns,step);
			renderCards(cardnum, handcol, handnum);
			printf("\e[0mAvailable actions:\n0:this list\n\e[30;1m1:new card [UNAVAILABLE]\n\e[0m2:use action card\n3:make a guess\n4:discard\n9:quit\n");
			goto onepttwo_step;
		case 3: // make a guess
			renderBar(tmp,p1,p2,p3,p4,turns,step);
			renderCards(cardnum, handcol, handnum);
			tmp1 = guess();
			if(tmp1 == 0)
				return 0;
			if(tmp1 == 2)
			{
				solved = TRUE;
				goto last_step;
			}
			goto second_step;
		case 4: // discard
			step = 4;
			renderBar(tmp,p1,p2,p3,p4,turns,step);
			renderCards(cardnum, handcol, handnum);
			tmp1 = discard();
			if(tmp1 == 1)
			{
				step = 3;
				renderBar(tmp,p1,p2,p3,p4,turns,step);
				renderCards(cardnum, handcol, handnum);
				goto second_step;
			}
			if(cardnum > 4)
			{
				step = 4;
				renderBar(tmp,p1,p2,p3,p4,turns,step);
				renderCards(cardnum, handcol, handnum);
				goto third_step;
			}
			goto last_step;
		case 2: //use action card
			renderBar(tmp,p1,p2,p3,p4,turns,step);
			renderCards(cardnum, handcol, handnum);
			printf("Card to use: ");
			scanf(" %d",&tmp1);
			cleanChar();
			if(handnum[tmp1]!=-2)
			{
				printf("That is not a valid action card.\n");
				goto onepttwo_step;
			}
			int test = discardGiven(tmp1);
			if(test == 1)
			{
				printf("Something went mildly wrong please try again\n");
				goto onepttwo_step;
			}
			draw();
			draw();
			step = 3;
			renderBar(tmp,p1,p2,p3,p4,turns,step);
			renderCards(cardnum, handcol, handnum);
			goto second_step;
		case 9: //quit
			return 0;
		default: //everything else
			printf("That is not a valid action.\n");
			goto onepttwo_step;
	}
second_step: //user gueses or discards
			step = 3;
			printf("Action (0 for help): ");
			scanf(" %d",&tmp1);
			cleanChar();
			switch(tmp1){
				case 0: //help
					renderBar(tmp,p1,p2,p3,p4,turns,step);
					renderCards(cardnum, handcol, handnum);
					printf("\e[0mAvailable actions:\n0:this list\n\e[30;1m1:new card [UNAVAILABLE]\n2:use action card [UNAVAILABLE]\n\e[0m3:make a guess\n4:discard\n9:quit\n");
					goto second_step;
				case 3://guess
					renderBar(tmp,p1,p2,p3,p4,turns,step);
					renderCards(cardnum, handcol, handnum);
					tmp1 = guess();
					if(tmp1 == 0)
						return 0;
					if(tmp1 == 2)
					{
						solved = TRUE;
						goto last_step;
					}
					goto second_step;
				case 4: //discard
					step = 4;
					renderBar(tmp,p1,p2,p3,p4,turns,step);
					renderCards(cardnum, handcol, handnum);
					tmp1 = discard();
					if(tmp1 == 1)
						goto second_step;
					if(cardnum > 4)
					{
						step = 4;
						renderBar(tmp,p1,p2,p3,p4,turns,step);
						renderCards(cardnum, handcol, handnum);
						goto third_step;
					}
					goto last_step;
				case 9:
					return 0; //quit
				default: //weird
					printf("That is not a valid action.\n");
					goto second_step;
			}
third_step:
			step = 4;
			tmp1 = discard();
			if(tmp1 == 1)
				goto third_step;
			if(cardnum > 4)
			{
				goto third_step;
			}
			goto last_step;

last_step: // just the end
	turns++;

		}
	}
	return 0;
}
