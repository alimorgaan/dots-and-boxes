#include<stdio.h> 
#include<stdlib.h> 
#include "funcs.c" 

int main()
{
    struct board * myboard = malloc(sizeof(struct board));
    printf("welcome to dots and boxes\n");
    initboard(myboard) ; 
    system("cls"); 
    char input ; 
    while (myboard->gamestats == 'c')
    {
        printscores(myboard);
        printf("-----------------------------------------------\n\n");
        drawboard(myboard);
        printf("\n");
        printf("-----------------------------------------------\n\n");
        printf("%s's turn\n", myboard->players[myboard->playerturn].name) ; 
        printf("enter a letter to draw a line instaed ");
        scanf(" %c" , &input);
        system("cls");
        if (checkinput(input , myboard))
        {
            handle(input , myboard);
            if (!checkboxes(myboard))
            {
                myboard->playerturn = !myboard->playerturn ; 
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
        printf("congratulations %s you are the winner\n" , myboard->players[0].name);
    }
    else if(myboard->gamestats == 1)
    {
        printf("congratulations %s you are the winner\n" , myboard->players[1].name);
    }
    else if(myboard->gamestats == 'd')
    {
        printf("DRAW !!");
    }
    return 0;
}
