#include <stdio.h>
#include <stdlib.h>
#include "funcs.c"

int main()
{
    struct board *myboard = malloc(sizeof(struct board));
    printf("welcome to dots and boxes\n");

    char mode = 0;
    printf("please select playing mode : \n");
    printf("1-single player \n");
    printf("2-multiplayer  \n");
    scanf("%c", &mode);

    initboard(myboard, mode);
    system("cls");

    if (mode == 50) // 50 is the ascii code of 2
    {
        char input;
        while (myboard->gamestats == 'c')
        {
            printscores(myboard);
            printf("-----------------------------------------------\n\n");
            drawboard(myboard);
            printf("\n");
            printf("-----------------------------------------------\n\n");
            printf("%s's turn\n", myboard->players[myboard->playerturn].name);
            printf("enter a letter to draw a line instaed ");
            scanf(" %c", &input);
            system("cls");
            if (checkinput(input, myboard))
            {
                handle(input, myboard);
                if (!checkboxes(myboard))
                {
                    myboard->playerturn = !myboard->playerturn;
                }
                myboard->gamestats = updatestats(myboard);
            }
            else
            {
                printf("please enter a valid input\n");
            }
        }

        printscores(myboard);
        printf("-----------------------------------------------\n\n");
        drawboard(myboard);
        printf("\n");
        printf("-----------------------------------------------\n\n");
        if (myboard->gamestats == 0)
        {
            printf("congratulations %s you are the winner\n", myboard->players[0].name);
        }
        else if (myboard->gamestats == 1)
        {
            printf("congratulations %s you are the winner\n", myboard->players[1].name);
        }
        else if (myboard->gamestats == 'd')
        {
            printf("DRAW !!");
        }
    }
    else
    {
        char input;
        int myRand;
        while (myboard->gamestats == 'c')
        {
            if (myboard->playerturn == 0)
            {
                printscores(myboard);
                printf("-----------------------------------------------\n\n");
                drawboard(myboard);
                printf("\n-----------------------------------------------\n\n");
                printf("your turn \n");
                printf("enter a letter to draw a line instaed ");
                scanf(" %c", &input);
                system("cls");
                if (checkinput(input, myboard))
                {
                    handle(input, myboard);
                    if (!checkboxes(myboard))
                    {
                        myboard->playerturn = !myboard->playerturn;
                    }
                    myboard->gamestats = updatestats(myboard);
                }
                else
                {
                    printf("please enter a valid input\n");
                }
            }
            else
            {
                while (1)
                {
                    myRand = rand() % 17;
                    if (checkRandInput(myRand, myboard))
                    {
                        break;
                    }
                }
                handleRand(myRand, myboard);
                if (!checkboxes(myboard))
                {
                    myboard->playerturn = !myboard->playerturn;
                }
                myboard->gamestats = updatestats(myboard);
                
            }
        }

        printscores(myboard);
        printf("-----------------------------------------------\n\n");
        drawboard(myboard);
        printf("\n");
        printf("-----------------------------------------------\n\n");
        if (myboard->gamestats == 0)
        {
            printf("congratulations %s you are the winner\n", myboard->players[0].name);
        }
        else if (myboard->gamestats == 1)
        {
            printf("congratulations %s you are the winner\n", myboard->players[1].name);
        }
        else if (myboard->gamestats == 'd')
        {
            printf("DRAW !!");
        }
    }

    system("pause");
    return 0;
}
