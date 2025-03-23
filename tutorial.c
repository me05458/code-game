#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pieces.h"
#include "cards.h"

//reset the character input area
void cleanChar()
{
    while(getchar() != '\n') //it just slurps up the characters in input until there are none left
        continue;
}


int main()
{
    system("clear");
    int tmp = 1; //this is the actual stage things are on, sort of stores user input after some ~processing~
    int tmp1 = 1; //stores user input once converted to int
    int tmpchar = ' '; //stores the user input to advance through tutorial

    //very first page (includes table of contents)
    printf("---------------Code Game Reference/tutorial-----------------\n");
    printf("This tutorial has the following sections:\n"
    "1 - Table of Contents\n"
    "2 - Introduction\n"
    "3 - System Check\n"
    "4 - Basic layout\n"
    "5 - Types of cards\n"
    "6 - Guessing and examples\n"
    );
    //I honestly don't know how the user got to this point if they can't type numbers.
    printf("\nThis game involves typing numbers to access commands. If you can't do this you're going to have some problems. For the sake of this tutorial, you can type a section number to go to that section, 0 to simply advance to the next step (it will loop back around after the last step). To leave the tutorial type 9. This will always be the key to quit.\n");
    printf("\nAction: ");
    tmpchar = getchar(); //slurp up the very first user input!
    if(tmpchar == '\n') //if enter, default  = 1
    {
        tmp1 = 0;
    }
    else
    {
        tmp1 = charEater(tmpchar); //convert inputted character into an int for usage
        cleanChar();
    }
    if(tmp1 == 0 && tmp <6) //this means that default (enter) is just cycling through the table of contents
    {
        tmp++; //go to next one
    }
    else //further action is needed if at last item (6), one needs to cycle back to 1.
    {
        if(tmp1 == 0) //if it was default, go to 1 (table of contents)
        {
            tmp = 1;
        }
        else //otherwise everything is fine, no funny defaults
        { //I don't know why I did it this way it seems kinda ugly
            tmp = tmp1;
        }
    }
    while(tmp != 9) //if tmp == 9 that means exit!
    {
        system("clear");
        switch(tmp) //different menu options
        {
            case 1: //regular table of contents
                printf("This tutorial has the following sections:\n"
                    "1 - Table of Contents (aka this)\n"
                    "2 - Introduction\n"
                    "3 - System Check\n"
                    "4 - Basic layout\n"
                    "5 - Types of cards\n"
                    "6 - Guessing and examples\n\n"
                );
                break;
            case 2: //introduction
                printf("This is the code game. It's called that becuase it's a game about codes, not because it's written in code (even though it is). The objective is to crack the code by matching cards by color and number to a given code. The game is played in turns. \nNOTE: the game comes with a colorless mode that uses shapes instead of colors. This tutorial, however, does not support colorless mode.\n\nEach turn has the following steps:\n"
                "1: Draw a card. You always draw a card first, even if you can already guess the code.\n"
                "2: Play an action card. This step is omitted if there are no action cards. You can only play one action card per turn.\n"
                "3: Guess a sequence\n"
                "4: Discard cards down to 4. You can only have 4 cards in your hand at the start of each round. Also note that discarding cards is one step. Once you start discarding you may not guess.\n"
                "If you need help, type 0. It will display all available commands at any given step. Not all commands are always available at all times due to the step-based nature of the game.       \n"
                "You can also just press enter, which will take you to a default (usually help, sometimes yes or a specified default in the game or advance in the tutorial)\n"
                    "\nThe commands for the actions are as follows:\n"
                    "0: Help (view available commands)\n"
                    "1: Draw a card\n"
                    "2: Make a guess\n"
                    "3: Discard\n"
                    "4: Use an action card\n"
                    "9: Quit\n"

                    "\nAlso, if you need to answer a yes or no question, 1 is always yes and 0 is always no.\n\n"
                );
                break;

            case 3: //system check (mostly to align window!)
                printf("This is a system check to make sure your window can render the game correctly. If your system fails the test, the game can still run, it's just going to be difficult.\n");
                printf("Also note that this tutorial requires a slightly larger terminal to be fully displayed than the game does. Therefore, your system may pass the test and look weird in the tutorial. This problem can be solved by scrolling.\n\n"); //this is actually very inconvenient. oops.
                printf("Begin?(1/0): ");
                tmpchar = getchar();
                if(tmpchar == '\n') //default = continue
                {
                    tmp1 = 1;
                }
                else //otherwise slurp up whatever the user wanted
                {
                    tmp1 = charEater(tmpchar);
                    cleanChar();
                }
                if(tmp1 != 1) //there's no error handling for not entering a 1 or 0 just exit for you
                {
                    system("clear");
                    break;
                }
                system("clear");
                printf("1\n|" //this is designed to fit correctly WITH THE KEEP CHECKING PROMPT
                "\n|"
                "\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|"
                "\n| resize your window until you can see the 1"
                "\n| and the 2 (on the same line as the ----- line)"
                "\n| If you can't get the 1,"
                "\n| you'll have to scroll"
                "\n| If you can't get the 2,"
                "\n| looking at the cards will be very very hard."
                "\n"
                "-----------------------------------------------------------------------------------------2\n"

                    );
                printf("\nKeep checking?(1/0): ");
                tmpchar = getchar(); //repeat the whole thing with the slorpery
                if(tmpchar == '\n')
                {
                    tmp1 = 1;
                }
                else
                {
                    tmp1 = charEater(tmpchar);
                    cleanChar();
                }
                if(tmp1 != 1)
                {
                    system("clear");
                    break;
                }
                system("clear");
                printf("\e[0m*** \e[30;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m***\n",RED,YELLOW,GREEN,BLUE); //this is boxes of assorted colors
                printf("\e[0m*** \e[30;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m***\n",RED,YELLOW,GREEN,BLUE);
                printf("\e[0m*** \e[30;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m***\n\e[0m",RED,YELLOW,GREEN,BLUE);
                printf("The squares above should of the following colors: default (often white), gray, red, yellow, green, blue\n");
                printf("If the squares are not of those colors but you can tell the difference between them, the game might look a little wonky but should still be playable.\n");
                printf("If you cannot differentiate between the squares, not all is lost! Play the game in colorless mode.\nTo do this, run 'make clean' and then 'make colorless'. If you want to go back to normal mode, run 'make clean' and 'make'. It is recommended to always clean when switching between modes.\nNOTE: tutorial is not designed to support colorless mode so things are just going to look weird.\n\n");
                break;
            case 4: //game set up!
                system("clear");
                printf("This is what the game set up looks like:\n\n");
                printf("Turns: %d\tStep: %d\n",0,1); //I'm pretty sure this part is just renderbar
                printf("------------------------------------------------\n");
                printf("\e[0m\e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||  \e[0m\n",RED, YELLOW,GREEN,BLUE);
                for(int i = 0; i<3; i++) //wanna do each of the possible numbers
                {
                    printf("\e[0m\e[%d;1m||  %d  ||    \e[%d;1m||  %d  ||    \e[%d;1m||  %d  ||    \e[%d;1m",RED, i, YELLOW, i, GREEN, i, BLUE);
                    printf("||  %d  || \e[0m\n", i);

                }
                printf("\e[0m\e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||  \e[0m\n",RED, YELLOW,GREEN,BLUE);
                printf("------------------------------------------------\n");
                for(int i = 0; i<4; i++)
                {
                    printf("\e[0m      %d        ", i);
                }
                printf("\n");
                printf("\e[0m\e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||    \e[0m\n",BLUE,GREEN,YELLOW,RED); //haha brute force
                printf("\e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||    5    ||  \e[%d;1m||    2    ||  \e[%d;1m||    0    ||  \e[%d;1m||    3    ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[0m\e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||    \e[0m\n\n",BLUE,GREEN,YELLOW,RED);

                printf("Action (0 for help): \n"); //this is what the game looks like, not tutorial prompt.

                printf("\nWould you like to see an explanation of the parts?(1/0): ");
                tmpchar = getchar(); //good old slorpery
                if(tmpchar == '\n')
                {
                    tmp1 = 1;
                }
                else
                {
                    tmp1 = charEater(tmpchar);
                    cleanChar();
                }
                if(tmp1 != 1)
                {
                    system("clear");
                    break;
                }

                system("clear");
                printf("* * * * * * * * * * * * *\n"); //stars outline the different possible things should make them highlighted?
                printf("* Turns: %d\tStep: %d *\n",0,1);
                printf("* * * * * * * * * * * * *");
                printf(" <------- This keeps track of the turn and step you are on\n");
                printf("\n");
                printf("* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("* ------------------------------------------------  *\n");
                printf("\e[0m* \e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||  \e[0m *\n",RED, YELLOW,GREEN,BLUE);
                for(int i = 0; i<3; i++) //wanna do each of the possible numbers
                {
                    printf("\e[0m* \e[%d;1m||  %d  ||    \e[%d;1m||  %d  ||    \e[%d;1m||  %d  ||    \e[%d;1m",RED, i, YELLOW, i, GREEN, i, BLUE);
                        printf("||  %d  || \e[0m *\n", i);

                }
                printf("\e[0m* \e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||     \e[%d;1m |||||||  \e[0m *\n",RED, YELLOW,GREEN,BLUE);
                printf("* ------------------------------------------------  *\n");
                printf("* * * * * * * * * * * * * * * * * * * * * * * * * * *");
                printf(" <------- This is your code. In order for a card to match, it must have the same color as one of the collumns, and one of the numbers in the collumn.\n");
                printf("\n");
                printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
                printf("* ");
                for(int i = 0; i<4; i++)
                {
                    printf("\e[0m      %d        ", i);
                }
                printf("  *\n");
                printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                printf(" <------- These are your card numbers. Whenever you work with your cards, you will use these numbers to refer to them.\n");
                printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

                printf("\e[0m* \e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||    \e[0m *\n",BLUE,GREEN,YELLOW,RED);
                printf("* \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m *\n",BLUE,GREEN,YELLOW,RED);
                printf("* \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m *\n",BLUE,GREEN,YELLOW,RED);
                printf("* \e[%d;1m||    5    ||  \e[%d;1m||    2    ||  \e[%d;1m||    0    ||  \e[%d;1m||    3    ||   \e[0m *\n",BLUE,GREEN,YELLOW,RED);
                printf("* \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m *\n",BLUE,GREEN,YELLOW,RED);
                printf("* \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m *\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[0m* \e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||    \e[0m *\n",BLUE,GREEN,YELLOW,RED);
                printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                printf(" <------- These are the cards in your hand. You want to match them to the code.\n\n");

                printf("* * * * * * * * * * * * *\n");
                printf("* Action (0 for help):  *\n");
                printf("* * * * * * * * * * * * *");
                printf(" <------- This is the prompt where you type commands\n\n");
                break;

            case 5: //card types!
                printf("The following types of cards exist:\n\n");
                printf("Normal card:\nMost cards are this way. It has a number and a color that can be matched.\n"); //regular normal card
                printf(" \e[%d;1m||||||||||| \n"
                        "||         ||  \n"
                        "||         ||  \n"
                        "||    1    ||  \n"
                        "||         ||  \n"
                        "||         ||  \n"
                        " ||||||||||| \e[0m\n\n",BLUE);
                printf("Wild card:\nThey can be played as any number and/or color. Some have a given number or color. Those cards must be played on anything.\nCards that say 'any' on them are for any number. Cards with four colors on them are for any color.\n"); //wild cards (all 3 types)
                printf(" \e[%d;1m||||||\e[%d;1m||||| \t \e[%d;1m||||||\e[%d;1m||||| \t \e[%d;1m|||||||||||\n"
                       "\e[%d;1m||         \e[%d;1m||\t\e[%d;1m||         \e[%d;1m||\t\e[%d;1m||         ||\n"
                       "\e[%d;1m||         \e[%d;1m||\t\e[%d;1m||         \e[%d;1m||\t\e[%d;1m||         ||\n"
                       "\e[%d;1m||   \e[0m 2    \e[%d;1m||\t\e[%d;1m||   \e[0many   \e[%d;1m||\t\e[%d;1m||   123   ||\n"
                       "\e[%d;1m||         \e[%d;1m||\t\e[%d;1m||         \e[%d;1m||\t\e[%d;1m||         ||\n"
                       "\e[%d;1m||         \e[%d;1m||\t\e[%d;1m||         \e[%d;1m||\t\e[%d;1m||         ||\n"
                       " \e[%d;1m|||||\e[%d;1m|||||| \t \e[%d;1m|||||\e[%d;1m|||||| \t \e[%d;1m|||||||||||\n\n\e[0m",
                    RED,YELLOW,RED,YELLOW,GREEN,
                    RED,YELLOW,RED,YELLOW,GREEN,
                    RED,YELLOW,RED,YELLOW,GREEN,
                    BLUE,YELLOW,BLUE,YELLOW,GREEN,
                    BLUE,GREEN,BLUE,GREEN,GREEN,
                    BLUE,GREEN,BLUE,GREEN,GREEN,
                    BLUE,GREEN,BLUE,GREEN,GREEN
                );
                printf("Action card:\nThis card is used to draw two cards. It cannot be used for guessing and only one can be used per turn.\n"); //+2 card
                printf(" \e[%d;1m||||||||||| \n"
                "||         ||  \n"
                "||         ||  \n"
                "||  add 2  ||  \n"
                "||         ||  \n"
                "||         ||  \n"
                " ||||||||||| \e[0m\n\n",0);
                break;

            case 6: //examples and how guessing works
                printf(" \e[%d;1m|||||||\n",GREEN); //displays a wild peice
                for(int i = 0; i<3; i++)
                {
                    printf("||  *  ||\n");
                }
                printf(" |||||||\e[0m\n");
                printf("NOTE: if part of the code looks like the thing depicted above, any number can be matched with it\n\n");
                printf("To match a card, it must have the same color as the code and one of the numbers of the code. For instance:\n");
                printf("\e[0m    MATCH           |         NOT MATCH         |         NOT MATCH         |           MATCH           |         NOT MATCH\n"); //just a couple cases
                printf("\e[0m                    |                           |                           |                           |\n");

            printf(" \e[%d;1m  |||||||          \e[0m|          \e[%d;1m|||||||          \e[0m|          \e[%d;1m|||||||          \e[0m|          \e[%d;1m|||||||          \e[0m|          \e[%d;1m||||||| \n"
                   "\e[%d;1m  ||  0  ||         \e[0m|         \e[%d;1m||  0  ||         \e[0m|         \e[%d;1m||  0  ||         \e[0m|         \e[%d;1m||  *  ||         \e[0m|         \e[%d;1m||  *  ||\n"
                   "\e[%d;1m  ||  3  ||         \e[0m|         \e[%d;1m||  3  ||         \e[0m|         \e[%d;1m||  3  ||         \e[0m|         \e[%d;1m||  *  ||         \e[0m|         \e[%d;1m||  *  || \n"
                   "\e[%d;1m  ||  5  ||         \e[0m|         \e[%d;1m||  5  ||         \e[0m|         \e[%d;1m||  5  ||         \e[0m|         \e[%d;1m||  *  ||         \e[0m|         \e[%d;1m||  *  || \n"
                   " \e[%d;1m  |||||||          \e[0m|          \e[%d;1m|||||||          \e[0m|          \e[%d;1m|||||||          \e[0m|          \e[%d;1m|||||||          \e[0m|          \e[%d;1m||||||| \n",
                    GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN,GREEN);
            printf("\e[0m                    |                           |                           |                           |\n");
            printf(" \e[%d;1m|||||||||||        \e[0m|        \e[%d;1m|||||||||||        \e[0m|        \e[%d;1m|||||||||||        \e[0m|        \e[%d;1m|||||||||||        \e[0m|        \e[%d;1m|||||||||||\n"
                   "\e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||\n"
                   "\e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||\n"
                   "\e[%d;1m||    3    ||       \e[0m|       \e[%d;1m||    2    ||       \e[0m|       \e[%d;1m||    3    ||       \e[0m|       \e[%d;1m||    2    ||       \e[0m|       \e[%d;1m||    2    ||\n"
                   "\e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||\n"
                   "\e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||       \e[0m|       \e[%d;1m||         ||\n"
                   " \e[%d;1m|||||||||||        \e[0m|        \e[%d;1m|||||||||||       \e[0m |        \e[%d;1m|||||||||||       \e[0m |        \e[%d;1m|||||||||||       \e[0m |        \e[%d;1m|||||||||||\e[0m\n",
                GREEN,GREEN,YELLOW,GREEN,YELLOW,GREEN,GREEN,YELLOW,GREEN,YELLOW,GREEN,GREEN,YELLOW,GREEN,YELLOW,GREEN,GREEN,YELLOW,GREEN,YELLOW,GREEN,GREEN,YELLOW,GREEN,YELLOW,GREEN,GREEN,YELLOW,GREEN,YELLOW,GREEN,GREEN,YELLOW,GREEN,YELLOW);
            break;


            default:
                printf("That is not a valid number.\n\n"); //uh oh user entered an unreasonable number
                break;
        }

        printf("Action: "); //reuptake action to go to next item
        tmpchar = getchar();
        if(tmpchar == '\n')
        {
            tmp1 = 0;
        }
        else
        {
            tmp1 = charEater(tmpchar);
            cleanChar();
        }
        if(tmp1 == 0 && tmp <5)
        {
            tmp++;
        }
        else
        {
            if(tmp1 == 0)
            {
                tmp = 1;
            }
            else
            {
                tmp = tmp1;
            }
        }
    }


    system("clear");
    printf("You have exited the tutorial. To view it again run './tutorial'. To play the game run './game'\n\e[0m"); //line at very end to confirm escape


    return 0;
}
