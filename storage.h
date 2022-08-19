
#ifndef TYPES_H
#define TYPES_H
#include "types.h"
#endif

void save(struct board *myboard)
{
    FILE *filePtr;
    filePtr = fopen("db.bin", "wb+");
    if (filePtr)
    {
        if (fwrite(myboard, sizeof(struct board), 1, filePtr))
        {
            system("cls");
            printf("saved successfully\n");
            system("pause");
        }
    }
}

void load(struct board *myboard)
{
    FILE *filePtr;
    filePtr = fopen("db.bin", "rb+");
    if (filePtr == NULL)
    {
        system("cls");
        printf("ERORR \n -------------------------\n no saved game to load !\n");
        system("pause");
        system("cls");
        exit(0); 
    }
    else
    {
        fread(myboard, sizeof(struct board), 1, filePtr); 
    }
}