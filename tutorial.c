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
    int tmp; //for inputs
    int tracker; //because I'm lazy. Let it be known that this is not a particularly elegant tutorial.
    system("clear");
    printf("------This is the code game tutorial-------\nBy the way, it's called the code game because it's a game about breaking codes, not because it's written in code (although it is).\nThis game involves writing numbers to perform actions. Can you do this? (Type a number, a 1 indicates yes, a 0 indicates no): ");
    scanf("%d",&tmp);
    cleanChar();
    if(tmp == 0) //uh....
    {
        printf("uh... okay? You can always play the tutorial again with ./tutorial or the game with ./game\n"); //oops...
        return 0;
    }
    while(tmp != 1) //user can't enter numbers I guess
    {
        printf("That's not a valid option. You must type either 0 or 1. Please do so now: ");
        scanf("%d",&tmp);
        cleanChar();
        if(tmp == 0)
            return 0;
    }
    system("clear"); //I know, I know, I'm working on it
    printf("This is the code. It is your objective to crack it by matching the right cards. To match a card, it must have the same color and one of the numbers shown in the corresponding collumn of the code.\nIn the game, you will be able to select how many numbers there are in each collumn. stars indicate a 'wild card' (more on that later)\n");
    printf("------------------------------------------------\n");
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE); //yes I just repeat this over and over
    for(int i = 0; i<3; i++) //wanna do each of the possible numbers
    {
        printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
        printf("||  *  ||\n");

    }
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
    printf("------------------------------------------------\n");

    printf("These are your cards. Each card has a number and color. To win, you must match the numbers and colors of cards to the code.\n");
    int cols[5] = {RED,YELLOW,GREEN,BLUE,YELLOW}; //this is the "hand"
    int nums[5] = {1,5,3,5,4}; //note that the drawn card is alreaady in the set
    renderCards(4,cols,nums,0);
    printf("However, the first action of the game is always to draw a card.\n");
step_zero:
    printf("Action (0 will open a menu that tells you of the available actions which vary at different steps): ");
    scanf(" %d",&tmp);
    cleanChar();
    if(tmp == 0)
    {
        printf("These are the actions you can use:\n0:this list (remember that it varies at different actions)\n1:draw a card (you want this!)\n9:quit\n");
        goto first_step;
    }
    if(tmp == 1)
    {
        goto onepointfive_step;
    }
    if(tmp == 9)
    {
        printf("9 is always the command to quit. Are you sure?(0/1): ");
        scanf(" %d",&tmp);
        if(tmp == 0)
        {
            goto step_zero;
        }
        return 0;
    }
    else
    {
        printf("That is not a valid action, please type 0 to access the help menu.\n");
    }
first_step:
    printf("Action (0 for help):");
    scanf(" %d",&tmp);
    cleanChar();
    switch (tmp){
        case 0:
            printf("Available actions:\n0:this list\n1:new card\n9:quit\n");
            goto first_step;
        case 1:
            system("clear");
            printf("------------------------------------------------\n");
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
            for(int i = 0; i<3; i++) //wanna do each of the possible numbers
            {
                printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
                printf("||  *  ||\n");

            }
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
            printf("------------------------------------------------\n");
            renderCards(5,cols, nums,0);
            break;
        case 9:
            return 0;
        default:
            printf("That is not a valid action.\n");
            goto first_step;
    }
onepointfive_step:
    system("clear");
    printf("At this point, you may need to guess a sequence to crack the code and win the game.You can play a card with any number on a code card with stars as long as it's the same color\n");
    printf("------------------------------------------------\n");
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
    for(int i = 0; i<3; i++) //wanna do each of the possible numbers
    {
        printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
        printf("||  *  ||\n");

    }
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
    printf("------------------------------------------------\n");
    renderCards(5,cols,nums,0);
    printf("Unfortunately, you cannot guess the sequence right now. While you do have the right colors, neither card 1 nor 4 have the numbers shown on the yellow puzzle card, however, you are welcome to try.\n");
    printf("Otherwise you need to discard a card because you can only have 4 cards in your hand at the start of each round.\n");
    printf("Action (0 for help): ");
    scanf(" %d",&tmp);
    cleanChar();
    if(tmp == 0)
    {
            printf("Available actions:\n0:this list\n1:make a guess\n2:discard a card (You want this)\n9:quit\n");
            goto second_step;
    }
    if(tmp == 9)
    {
        return 0;
    }
    if(tmp == 1)
    {
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
        printf("Nope, wrong\n"); //listen, I'm lazy and this isn't a real game. If it should be right, too bad. Something went wrong.
        goto second_step;
    }
    if(tmp == 2)
    {
        printf("Type the number of the card you wish to discard (get rid of one of the yellow ones): ");
        scanf(" %d",&tmp);
        cleanChar();
        if(tmp == 4)
        {
            tracker = 1;
            system("clear");
            printf("------------------------------------------------\n");
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
            for(int i = 0; i<3; i++) //wanna do each of the possible numbers
            {
                printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
                printf("||  *  ||\n");

            }
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
            printf("------------------------------------------------\n");
            renderCards(4,cols,nums,0);
            goto twoptfive_step;
        }
        if(tmp == 1)
        {
            tracker = 2;
            cols[1] = GREEN;
            cols[2] = BLUE;
            cols[3] = YELLOW;
            nums[1] = 3;
            nums[2] = 5;
            nums[3] = 4;
            system("clear");
            printf("------------------------------------------------\n");
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
            for(int i = 0; i<3; i++) //wanna do each of the possible numbers
            {
                printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
                printf("||  *  ||\n");

            }
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
            printf("------------------------------------------------\n");
            renderCards(4,cols,nums,0);
            goto twoptfive_step;
        }
        else
        { //this is called the illusion of free will :3
            printf("That card is useful to you, are you sure you want to discard it?(0/1): ");
            scanf(" %d",&tmp);
            cleanChar();
            if(tmp == 0)
            {
                goto second_step;
            }
            if(tmp == 1)
            {
                printf("This tutorial is not a full game and cannot be played as such. Try again.\n");
                goto second_step;
            }
            printf("You have to write a 0 or a 1\n");
            goto second_step;
        }
    }
    else
    {
        printf("That is not a valid action.\n");
        goto second_step;

    }

second_step:
    printf("Action (0 for help):");
    scanf(" %d",&tmp);
    cleanChar();
    switch(tmp){
        case 0:
            printf("Available actions:\n0:this list\n1:make a guess\n2:discard a card\n9:quit\n");
            goto second_step;
        case 1:
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
            printf("Nope, wrong"); //listen, I'm lazy and this isn't a real game. If it should be right, too bad. Something went wrong.
            goto second_step;
        case 2:
            printf("Type the number of the card you wish to discard (get rid of one of the yellow ones): ");
            scanf(" %d",&tmp);
            cleanChar();
            if(tmp == 4)
            {
                tracker = 1;
                system("clear");
                printf("------------------------------------------------\n");
                printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
                for(int i = 0; i<3; i++) //wanna do each of the possible numbers
                {
                    printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
                    printf("||  *  ||\n");

                }
                printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
                printf("------------------------------------------------\n");
                renderCards(4,cols,nums,0);
                goto twoptfive_step;
            }
            if(tmp == 1)
            {
                tracker = 2;
                cols[1] = GREEN;
                cols[2] = BLUE;
                cols[3] = YELLOW;
                nums[1] = 3;
                nums[2] = 5;
                nums[3] = 4;
                system("clear");
                printf("------------------------------------------------\n");
                printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
                for(int i = 0; i<3; i++) //wanna do each of the possible numbers
                {
                    printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
                    printf("||  *  ||\n");

                }
                printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
                printf("------------------------------------------------\n");
                renderCards(4,cols,nums,0);
                goto twoptfive_step;
            }
            else
            { //this is called the illusion of free will :3
                printf("That card is useful to you, are you sure you want to discard it?(0/1): \n");
                scanf(" %d",&tmp);
                cleanChar();
                if(tmp == 0)
                {
                    goto second_step;
                }
                if(tmp == 1)
                {
                    printf("This tutorial is not a full game and cannot be played as such. Try again.\n"); //I'm lazy'
                    goto second_step;
                }
                printf("You have to write a 0 or a 1\n");
                goto second_step;
            }
        case 9:
            return 0;
        default:
            printf("That is not a valid action.\n");
            goto second_step;
    }
twoptfive_step:
    system("clear");
    printf("It is now the begining of the second round! You know what to do\n");
    printf("------------------------------------------------\n");
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
    for(int i = 0; i<3; i++) //wanna do each of the possible numbers
    {
        printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
        printf("||  *  ||\n");

    }
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
    printf("------------------------------------------------\n");
    renderCards(4,cols,nums,0);
third_step:
    printf("Action (0 for help): ");
    scanf(" %d",&tmp);
    cleanChar();
    switch(tmp){
        case 0:
            printf("Available actions:\n0:this list\n1:new card\n9:quit\n");
            goto third_step;
        case 1:
            system("clear");
            printf("------------------------------------------------\n");
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
            for(int i = 0; i<3; i++) //wanna do each of the possible numbers
            {
                printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
                printf("||  *  ||\n");

            }
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
            printf("------------------------------------------------\n");
            renderCards(4,cols,nums,1);
            printf("Congradulations! You drew a wild card! This kind of card can be considered as any color and any number.\n");
            goto fourth_step;
        case 9:
            return 0;
        default:
            printf("That is not a valid action\n");
            goto third_step;
    }

    system("clear");
    printf("It's time to guess again. You can win this time!\n");
    printf("------------------------------------------------\n");
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
    for(int i = 0; i<3; i++) //wanna do each of the possible numbers
    {
        printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
        printf("||  *  ||\n");

    }
    printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
    printf("------------------------------------------------\n");
    renderCards(4,cols,nums,1);
fourth_step:
    printf("Action (0 for help): ");
    scanf(" %d",&tmp);
    cleanChar();
    switch(tmp)
    {
        case 0:
            printf("Available actions:\n0:this list\n1:make a guess (You want this now)\n2:discard a card\n9:quit\n");
            goto fourth_step;
        case 1:
            system("clear");
            printf("------------------------------------------------\n");
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n",RED, YELLOW,GREEN,BLUE);
            for(int i = 0; i<3; i++) //wanna do each of the possible numbers
            {
                printf("\e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm||  %d  ||    \e[%dm",RED, i+1, YELLOW, i+1, GREEN,i+1, BLUE);
                printf("||  *  ||\n");

            }
            printf("\e[%dm |||||||     \e[%dm |||||||     \e[%dm |||||||     \e[%dm ||||||| \n\e[0m",RED, YELLOW,GREEN,BLUE);
            printf("------------------------------------------------\n");
            renderCards(4,cols,nums,1);
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
            if(a == b || a==c || a==d || b==c||b==d||c==d)
            {
                printf("You can't guess one card twice\n");
                goto fourth_step;
            }
            if(tracker == 1) //discarded 4
            {
                if(a == 0 && b == 4 && c == 2 && d == 3)
                {
                    printf("You guessed it!\n");
                    goto last_step;
                }
                else
                {
                    printf("Nope, wrong. (Maybe check the order)\n");
                    goto fourth_step;
                }
            }
            if(tracker == 2) //discarded 1
            {
                if(a == 0 && b == 4 && c == 1 && d == 2)
                {
                    printf("You guessed it!\n");
                    goto last_step;
                }
                else
                {
                    printf("Nope, wrong. (Maybe check the order)\n");
                    goto fourth_step;
                }
            }
            goto last_step;
        case 2:
            printf("This tutorial is not a full game and will not be played as such. Keep guessing until you get it.\n");
            goto fourth_step;
        case 9:
            return 0;
        default:
            printf("That is not a valid action\n");
            goto fourth_step;

    }

last_step:
    printf("Want to play a real game?(0/1): ");
    scanf("%d",&tmp);
    cleanChar();
    if(tmp == 1)
    {
        char *args[]={"./game",NULL};
        execv(args[0],args);
        return 1;
    }
    else
    {
        return 0;
    }
}
