#include "comp.c" 
#include <string.h>
#include <ctype.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void initline(struct board * myboard , int index )
{
    char mychar ; 
    if(index <= 8)
    {
        for (int i = 0; i < 7; i++)
        {
            if (i == 3)
            {
                mychar = 'A' + index;  
            } 
            else 
            {
                mychar = ' ' ; 
            }
            myboard->gamelines[index].content[i] = mychar ;  
            myboard->gamelines[index].drawstats = 0 ;  
         }
    }
    if(index > 8 )
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 1)
            {
                mychar = 'A' + index  ;  
            } 
            else 
            {
                mychar = ' ' ; 
            }
            myboard->gamelines[index].content[i] = mychar ;  
            myboard->gamelines[index].drawstats = 0 ;
         }
    }
    
}
void initboxes(struct board * myboard)
{
  char temp[6][4] = {{0,3,9,11},{1,4,11,13},{2,5,13,15},{3,6,10,12},{4,7,12,14},{5,8,14,16}};
  for (int i = 0; i < 6 ; i++)
  {
      memcpy(myboard->boxes[i].boxlines , temp[i] , sizeof(myboard->boxes[0].boxlines));
      myboard->boxes[i].centersym = ' ';
      myboard->boxes[i].point = 0;
      
  }  
}
void initplayer(struct board * myboard , char index )
{
    printf("please enter player %d name \n", index+1); 
    scanf("%s" , myboard->players[index].name);
    myboard->players[index].score = 0 ; 
}
void initboard(struct board * myboard , char mode) 
{
    
    if(mode == 50){
        for (int i = 0; i < 17; i++)
        {
            initline(myboard , i);     
        }
        myboard->gamestats = 'c';
        myboard->playerturn = 0 ; 
        for (int i = 0; i < 2; i++)
        {
            initplayer(myboard , i ) ; 
        }
        initboxes(myboard);
    }
     else
    {
        for (int i = 0; i < 17; i++)
        {
            initline(myboard , i);     
        }
        myboard->gamestats = 'c';
        myboard->playerturn = 0 ; 
        initplayer(myboard , 0 );
        strcpy(myboard->players[1].name, "computer");
        myboard->players[1].score = 0;
        initboxes(myboard);
    }
        
}
void drawboard(struct board * myboard)
{
    //first line in the board
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            if(i == 0) printf("\u2022");
            printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,  myboard->gamelines[j].content[i] ) ; 
            
        }          
    }
    printf("\u2022\n") ; 
    //-----------------------------------------------------
    //box raw 1 
       
    for (int j = 9; j < 14; j = j +2)
    {
        for (int i = 0; i < 8 ; i++)
        {
         if(i == 0) printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,myboard->gamelines[j].content[i]) ;
         else printf(" ");  
        }
    }
    printf(ANSI_COLOR_RED "%c\n" ANSI_COLOR_RESET, myboard->gamelines[15].content[0] ) ;
    char temp = 0 ;  
    for (int j = 9; j < 14; j = j +2)
    {
        for (int i = 0; i < 8 ; i++)
        {
         if(i == 0) printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,myboard->gamelines[j].content[1]) ;
         else if (i == 4)
         {
             if (myboard->boxes[j - 9 - temp].centersym == 1)
             {
                 printf( ANSI_COLOR_GREEN "\xE2\x9C\x93" ANSI_COLOR_RESET);
             }
             else
             {
                 printf(" ");
             }
           temp++ ;   
         } 
         else printf(" ");  
        }
    }
    temp = 0 ; 
    printf(ANSI_COLOR_RED "%c\n" ANSI_COLOR_RESET, myboard->gamelines[15].content[1] ) ;
    for (int j = 9; j < 14; j = j +2)
    {
        for (int i = 0; i < 8 ; i++)
        {
         if(i == 0) printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,myboard->gamelines[j].content[2]) ;
         else printf(" ");  
        }
    }
    printf(ANSI_COLOR_RED "%c\n" ANSI_COLOR_RESET, myboard->gamelines[15].content[2] ) ;
    //--------------------------------------------------------------
    //second line 
    for (int j = 3; j < 6; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            if(i == 0) printf("\u2022");
            printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,  myboard->gamelines[j].content[i] ) ; 
        }          
    }
    printf("\u2022\n") ;    
    //-------------------------------------------------------------
    for (int j = 10; j < 15; j = j +2)
    {
        for (int i = 0; i < 8 ; i++)
        {
         if(i == 0) printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,myboard->gamelines[j].content[i]) ;
         else printf(" ");  
        }
    }
    printf(ANSI_COLOR_RED "%c\n" ANSI_COLOR_RESET, myboard->gamelines[16].content[0] ) ; 
    for (int j = 10; j < 15; j = j +2)
    {
        for (int i = 0; i < 8 ; i++)
        {
         if(i == 0) printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,myboard->gamelines[j].content[1]) ;
         else if (i == 4)
         {
             if (myboard->boxes[j - 7 - temp].centersym == 1)
             {
                 printf( ANSI_COLOR_GREEN "\xE2\x9C\x93" ANSI_COLOR_RESET);
             }
             else
             {
                 printf(" ");
             }
           temp++ ;   
         } 
         else printf(" ");  
        }
    }
    printf(ANSI_COLOR_RED "%c\n" ANSI_COLOR_RESET, myboard->gamelines[16].content[1] ) ;
    for (int j = 10; j < 15; j = j +2)
    {
        for (int i = 0; i < 8 ; i++)
        {
         if(i == 0) printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,myboard->gamelines[j].content[2]) ;
         else printf(" ");  
        }
    }
    printf(ANSI_COLOR_RED "%c\n" ANSI_COLOR_RESET, myboard->gamelines[16].content[2] ) ;
      
    //----------------------------------------------------------------
    for (int j = 6; j < 9; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            if(i == 0) printf("\u2022");
            printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,  myboard->gamelines[j].content[i] ) ; 
        }          
    }
    printf("\u2022\n") ;

}

char checkRandInput(int myRand , struct board * myboard){
    if(myboard->gamelines[myRand].drawstats == 0){
        return 1; 
    }else{
        return 0; 
    }
}

char checkinput(char input , struct board * myboard)
{
    for (int i = 0; i < 17; i++)
    {
        if (!myboard->gamelines[i].drawstats)
        {
            if (toupper(input) == myboard->gamelines[i].content[3] || toupper(input) == myboard->gamelines[i].content[1] )
            {
                return 1 ;    
            } 
        }
    }
    return 0 ; 
}


void handleRand(int input , struct board * myboard)
{
    if (input <= 8)
    {
        for (int i = 0; i < 7; i++)
        {
            myboard->gamelines[input].content[i] = '-' ;
            myboard->gamelines[input].drawstats = 1 ;  
        }
    }
    if (input > 8)
    {
        for (int i = 0; i < 3; i++)
        {
            myboard->gamelines[input].content[i] = '|' ;
            myboard->gamelines[input].drawstats = 1 ;  
        }
    }
    
}


void handle(char input , struct board * myboard)
{
    input = toupper(input) - 'A' ; 
    if (input <= 8)
    {
        for (int i = 0; i < 7; i++)
        {
            myboard->gamelines[input].content[i] = '-' ;
            myboard->gamelines[input].drawstats = 1 ;  
        }
    }
    if (input > 8)
    {
        for (int i = 0; i < 3; i++)
        {
            myboard->gamelines[input].content[i] = '|' ;
            myboard->gamelines[input].drawstats = 1 ;  
        }
    }
    
}

char checkboxes(struct board * myboard)
{
    char scored = 0 ; 
    for (int i = 0; i < 6; i++)
    {
        if (myboard->boxes[i].point == 1)
        {
            continue ;            
        }
        
        char boxstats = 1 ;
        char temp ; 
        char player ; 
        for (int j = 0; j < 4; j++)
        {
            temp  = myboard->boxes[i].boxlines[j];
            if (!myboard->gamelines[temp].drawstats)
            {
                boxstats = 0 ;
            }
        }
        if (boxstats)
        {
            myboard->boxes[i].point = 1 ;        
            myboard->players[myboard->playerturn].score++ ; 
            myboard->boxes[i].centersym = 1 ; 
            scored= 1 ;  
        }
    }
    return scored ; 
}

void printscores(struct board * myboard)
{
    printf("%s's score : %d       " , myboard->players[0].name , myboard->players[0].score);
    printf("%s's score : %d\n" , myboard->players[1].name , myboard->players[1].score);
}

char updatestats(struct board * myboard)
{
    char stats  = 'd'; 
    for (int i = 0; i < 17; i++)
    {
        if (myboard->gamelines[i].drawstats == 0)
        {
            stats = 'c';
        }
        
    }
    if (stats == 'd')
    {
        if (myboard->players[0].score > myboard->players[1].score)
        {
            stats = 0 ; 
        }
        else if (myboard->players[0].score < myboard->players[1].score)
        {
            stats = 1 ; 
        }
           
    }
    return stats ;
}