#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pieces.h"
#include "cards.h"

//reset the character input area
//idk how it works copied off a forum
void cleanChar()
{
    while(getchar() != '\n') //actually, it just slurps up the characters in input until there are none left
        continue;
}


int main()
{

    system("clear");
    int tmp = 1;
    int tmp1 = 1;
    int tmpchar = ' ';

    printf("---------------Code Game Reference/tutorial-----------------\n");
    printf("This tutorial has the following sections:\n"
    "1 - Table of Contents (aka this)\n"
    "2 - Introduction\n"
    "3 - System Check\n"
    "4 - Basic layout\n"
    "5 - Types of cards\n"
    "6 - Guessing and examples\n"
    );
    printf("\nThis game involves typing numbers to access commands. If you can't do this you're going to have some problems. For the sake of this tutorial, you can type a section number to go to that section, 0 to simply advance to the next step (it will loop back around after the last step). To leave the tutorial type 9. This will always be the key to quit.\n");
    printf("\nAction: ");
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
    while(tmp != 9)
    {
        system("clear");
        switch(tmp)
        {
            case 1:
                printf("This tutorial has the following sections:\n"
                    "1 - Table of Contents (aka this)\n"
                    "2 - Introduction\n"
                    "3 - System Check\n"
                    "4 - Basic layout\n"
                    "5 - Types of cards\n"
                    "6 - Guessing and examples\n"
                );
                break;
            case 2:
                printf("This is the code game. It's called that becuase it's a game about codes, not because it's written in code (even though it is). The objective is to crack the code by matching cards by color and number to a given code. The game is played in turns. \n\nEach turn has the following steps:\n"
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

                    "\nAlso, if you need to answer a yes or no question, 1 is always yes and 0 is always no.\n"
                );
                break;

            case 3:
                printf("This is a system check to make sure your window can render the game correctly. If your system fails the test, the game can still run, it's just going to be difficult.\n");
                printf("Also note that this tutorial requires a slightly larger terminal to be fully displayed than the game does. Therefore, your system may pass the test and look weird in the tutorial. This problem can be solved by scrolling.\n");
                printf("Begin?(1/0): ");
                tmpchar = getchar();
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
                printf("1\n|"
                "\n|"
                "\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|"
                "\n| resize your window until you can see the 1"
                "\n| and the 2 (on the same line as the ----- line)"
                "\n| If you can't get the 1,"
                "\n| you'll have to scroll"
                "\n| If you can't get the 2,"
                "\n| looking at the cards will be very very hard."
                "\n"
                "-----------------------------------------------------------------------------------------2\n"

                    );
                printf("Keep checking?(1/0): ");
                tmpchar = getchar();
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
                printf("\e[0m*** \e[30;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m***\n",RED,YELLOW,GREEN,BLUE);
                printf("\e[0m*** \e[30;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m***\n",RED,YELLOW,GREEN,BLUE);
                printf("\e[0m*** \e[30;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m*** \e[%d;1m***\n\e[0m",RED,YELLOW,GREEN,BLUE);
                printf("The squares above should of the following colors: default (often white), gray, red, yellow, green, blue\n");
                printf("If the squares are not of those colors but you can tell the difference between them, the game might look a little wonky but should still be playable.\n");
                printf("If you can't tell the difference between some of the colors you might have some difficulties because color matching is important to the game. It is highly recommended to obtain a terminal that can do colors.\n");
                break;



            case 4:
                system("clear");
                printf("This is what the game set up looks like:\n\n");
                printf("Turns: %d\tStep: %d\n",0,1);
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
                printf("\e[0m\e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||    \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||    5    ||  \e[%d;1m||    2    ||  \e[%d;1m||    0    ||  \e[%d;1m||    3    ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||  \e[%d;1m||         ||   \e[0m\n",BLUE,GREEN,YELLOW,RED);
                printf("\e[0m\e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||   \e[%d;1m |||||||||||    \e[0m\n\n",BLUE,GREEN,YELLOW,RED);

                printf("Action (0 for help): \n");

                printf("\nWould you like to see an explanation of the parts?(1/0): ");
                tmpchar = getchar();
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
                printf("* * * * * * * * * * * * *\n");
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
                printf(" <------- This is the prompt where you type commands\n");
                break;

            case 5:
                printf("The following types of cards exist:\n\n");
                printf("Normal card:\nMost cards are this way. It has a number and a color that can be matched.\n");
                printf(" \e[%d;1m||||||||||| \n"
                        "||         ||  \n"
                        "||         ||  \n"
                        "||    1    ||  \n"
                        "||         ||  \n"
                        "||         ||  \n"
                        " ||||||||||| \e[0m\n\n",BLUE);
                printf("Wild card:\nThey can be played as any number and/or color. Some have a given number or color. Those cards must be played on anything.\nCards that say 'any' on them are for any number. Cards with four colors on them are for any color.\n");
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
                /*printf("Wild card:\nThis card can be used as a card of any color and number. It can be matched on anything.\n");
                printf(" \e[%d;1m|||||\e[%d;1m|||||| \n"
                "\e[%d;1m||         \e[%d;1m||  \n"
                "\e[%d;1m||         \e[%d;1m||  \n"
                "\e[%d;1m||   \e[0many   \e[%d;1m||  \n"
                "\e[%d;1m||         \e[%d;1m||  \n"
                "\e[%d;1m||         \e[%d;1m||  \n"
                " \e[%d;1m||||||\e[%d;1m||||| \e[0m\n\n",RED,YELLOW,RED,YELLOW,RED,YELLOW,RED,GREEN,BLUE,GREEN,BLUE,GREEN,BLUE,GREEN,BLUE,GREEN);
                printf("Wild card:\nThis card can be used as a card of any color but must be the number shown on the card (in this case 3)\n");
                printf(" \e[%d;1m|||||\e[%d;1m|||||| \n"
                "\e[%d;1m||         \e[%d;1m||  \n"
                "\e[%d;1m||         \e[%d;1m||  \n"
                "\e[%d;1m||    3    \e[%d;1m||  \n"
                "\e[%d;1m||         \e[%d;1m||  \n"
                "\e[%d;1m||         \e[%d;1m||  \n"
                " \e[%d;1m||||||\e[%d;1m||||| \e[0m\n\n",RED,YELLOW,RED,YELLOW,RED,YELLOW,RED,GREEN,BLUE,GREEN,BLUE,GREEN,BLUE,GREEN,BLUE,GREEN);
                printf("Wild card:\nThis card can be used as a card of any number but must be the color shown on the card (in this case yellow)\n");
                printf(" \e[%d;1m||||||||||| \n"
                "||         ||  \n"
                "||         ||  \n"
                "||   any   ||  \n"
                "||         ||  \n"
                "||         ||  \n"
                " ||||||||||| \e[0m\n\n",YELLOW);*/
                printf("Action card:\nThis card is used to draw two cards. It cannot be used for guessing and only one can be used per turn.\n");
                printf(" \e[%d;1m||||||||||| \n"
                "||         ||  \n"
                "||         ||  \n"
                "||  add 2  ||  \n"
                "||         ||  \n"
                "||         ||  \n"
                " ||||||||||| \e[0m\n",0);
                break;

            case 6:
                printf(" \e[%d;1m|||||||\n",GREEN);
                for(int i = 0; i<3; i++)
                {
                    printf("||  *  ||\n");
                }
                printf(" |||||||\e[0m\n");
                printf("NOTE: if part of the code looks like the thing depicted above, any number can be matched with it\n\n");
                printf("To match a card, it must have the same color as the code and one of the numbers of the code. For instance:\n");
                printf("\e[0m    MATCH           |         NOT MATCH         |         NOT MATCH         |           MATCH           |         NOT MATCH\n");
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
                printf("That is not a valid number.\n");
                break;






        }

        printf("\nAction: ");
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


    printf("To view the tutorial again run './tutorial'. To play the game run './game'\n\e[0m");


    return 0;
}
