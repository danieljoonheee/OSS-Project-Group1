#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define row 6
#define col 10

#define TOKEN_COUNT 1024

typedef enum _TOKEN_TYPE {
   UNDEFINED = 0,
   OBJECT = 1,
   ARRAY = 2,
   STRING = 3,
   PRIMITIVE = 4
} TOKEN_TYPE;

typedef struct _TOKEN {
   TOKEN_TYPE type;
   int start;
   int end;
   int size;
   char* string;
} TOKEN;


TOKEN* jparse(char* first, int size, TOKEN* o, int f);
void put(char* first, TOKEN* tokens);

int count = 0;

int main(int argc, char **argv)
{
    FILE* fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Open file is needed\n");
        return -1;
    }

    int size = 0;
    char* doc = NULL;
    TOKEN* tokens = NULL;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    doc = malloc(sizeof(char)*(size + 1));
    fseek(fp, 0, SEEK_SET);

    fread(doc, size, sizeof(char), fp);
    doc[size] = '\0';

    fclose(fp);

    tokens = jparse(doc, size, tokens, 0);

    if (tokens != NULL)
    {
      put(doc, tokens);
    }

    int tokans1, tokans2, tokans3, tokans4, tokans5, tokans6;
    int seatInfo[row][col];
    int k = 1;

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++){
         seatInfo[i][j] = k;
      k++;
      }
    }

    printf("\n\n****************************************************************************\n");
    printf("===================================THEATER==================================\n\n");
    
    printf("                                 WELCOME TO CGV         \n\n");
    
    printf("============================================================================\n");
    printf("****************************************************************************\n\n");

    printf("Choose the place: \n1. %s\n2. %s\nEnter: ", tokens[1].string, tokens[701].string);
    int answer1=0;
    scanf("%d", &answer1);
    if(answer1==1)  //if Pohang
    {
        tokans1=1;
        printf("\nChoose the date: \n1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\nEnter: ", tokens[3].string, tokens[93].string, tokens[205].string, tokens[333].string, tokens[467].string, tokens[595].string);
        int answer2=0;
        scanf("%d", &answer2);
        if(answer2==1)      //date 6/3
        {
            tokans2=3;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[5].string, tokens[15].string, tokens[39].string, tokens[77].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/3movie1
            {
                tokans3=5;
                printf("\n%s: %s\n", tokens[5].string, tokens[8].string);
                printf("\nChoose the time: \n1. %s: %s\nEnter: ", tokens[13].string, tokens[14].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=13;
                    tokans5=14;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2) //6/3 movie2
            {
                tokans3=15;
                printf("\n%s: %s\n", tokens[15].string, tokens[18].string);
                printf("\nChoose the time: \nCinema5\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\n5. %s: %s\n6. %s: %s\n\nCinema 7\n7. %s: %s\nEnter: ", tokens[23].string, tokens[24].string, tokens[25].string, tokens[26].string, tokens[27].string, tokens[28].string, tokens[29].string, tokens[30].string, tokens[31].string, tokens[32].string, tokens[33].string, tokens[34].string, tokens[37].string, tokens[38].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1) //6/3 movie2 time1
                {
                    tokans4=23;
                    tokans5=24;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2) //6/3 movie2 time2
                {
                    tokans4=25;
                    tokans5=26;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3) //6/3 movie2 time3
                {
                    tokans4=27;
                    tokans5=28;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4) //6/3 movie2 time4
                {
                    tokans4=29;
                    tokans5=30;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5) //6/3 movie2 time5
                {
                    tokans4=31;
                    tokans5=32;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==6) //6/3 movie2 time6
                {
                    tokans4=33;
                    tokans5=34;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else
                {
                    tokans4=37;
                    tokans5=38;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                
            }
            else if(answer3==3)      //6/3 movie3
            {
                tokans3=39;
                printf("\n%s: %s\n", tokens[39].string, tokens[42].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4%s: %s\n\nCinema 6\n5. %s: %s\n 6. %s: %s\nEnter: ", tokens[47].string, tokens[48].string, tokens[49].string, tokens[50].string, tokens[59].string, tokens[60].string, tokens[61].string, tokens[62].string, tokens[73].string, tokens[74].string, tokens[75].string, tokens[76].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=47;
                    tokans5=48;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=49;
                    tokans5=50;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=59;
                    tokans5=60;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=61;
                    tokans5=62;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=73;
                    tokans5=74;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=75;
                    tokans5=76;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }   
            }
            else      //6/3 movie4
            {
                tokans3=77;
                printf("\n%s: %s\n", tokens[77].string, tokens[80].string);
                printf("\nChoose the time: \nCinema 7\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[85].string, tokens[86].string, tokens[87].string, tokens[88].string, tokens[89].string, tokens[90].string, tokens[91].string, tokens[92].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=85;
                    tokans5=86;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=87;
                    tokans5=88;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=89;
                    tokans5=90;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=91;
                    tokans5=92;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }
        else if(answer2==2)      //date 6/4
        {
            tokans2=93;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[95].string, tokens[107].string, tokens[127].string, tokens[145].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/4 movie1
            {
                tokans3=95;
                printf("\n%s: %s\n", tokens[95].string, tokens[98].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[103].string, tokens[104].string, tokens[105].string, tokens[106].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=103;
                    tokans5=104;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=105;
                    tokans5=106;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/4 movie2
            {
                tokans3=107;
                printf("\n%s: %s\n", tokens[107].string, tokens[110].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[115].string, tokens[116].string, tokens[117].string, tokens[118].string, tokens[119].string, tokens[120].string, tokens[121].string, tokens[122].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=115;
                    tokans5=116;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=117;
                    tokans5=118;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=119;
                    tokans5=120;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=121;
                    tokans5=122;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/4 movie3
            {
                tokans3=127;
                printf("\n%s: %s\n", tokens[127].string, tokens[130].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[135].string, tokens[136].string, tokens[137].string, tokens[138].string, tokens[139].string, tokens[140].string, tokens[141].string, tokens[142].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=135;
                    tokans5=136;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=137;
                    tokans5=138;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=139;
                    tokans5=140;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=141;
                    tokans5=142;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/4 movie4
            {
                tokans3=145;
                printf("\n%s: %s\n", tokens[145].string, tokens[148].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[153].string, tokens[154].string, tokens[155].string, tokens[156].string, tokens[167].string, tokens[168].string, tokens[169].string, tokens[170].string, tokens[181].string, tokens[182].string, tokens[183].string, tokens[184].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=153;
                    tokans5=154;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=155;
                    tokans5=156;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=167;
                    tokans5=168;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=169;
                    tokans5=170;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=181;
                    tokans5=182;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=183;
                    tokans5=184;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            
        }

        else if(answer2==3)      //date 6/5
        {
            tokans2=205;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[207].string, tokens[219].string, tokens[239].string, tokens[257].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/5 movie1
            {
                tokans3=207;
                printf("\n%s: %s\n", tokens[207].string, tokens[210].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[215].string, tokens[216].string, tokens[217].string, tokens[218].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=215;
                    tokans5=216;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=217;
                    tokans5=218;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/5 movie2
            {
                tokans3=219;
                printf("\n%s: %s\n", tokens[219].string, tokens[222].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[227].string, tokens[228].string, tokens[229].string, tokens[230].string, tokens[231].string, tokens[232].string, tokens[233].string, tokens[234].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=227;
                    tokans5=228;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=229;
                    tokans5=230;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=231;
                    tokans5=232;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=233;
                    tokans5=234;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/5 movie3
            {
                tokans3=239;
                printf("\n%s: %s\n", tokens[239].string, tokens[242].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[247].string, tokens[248].string, tokens[249].string, tokens[250].string, tokens[251].string, tokens[252].string, tokens[253].string, tokens[254].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=247;
                    tokans5=248;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=249;
                    tokans5=250;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=251;
                    tokans5=252;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=253;
                    tokans5=254;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/5 movie4
            {
                tokans3=257;
                printf("\n%s: %s\n", tokens[257].string, tokens[260].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[265].string, tokens[266].string, tokens[267].string, tokens[268].string, tokens[279].string, tokens[280].string, tokens[281].string, tokens[282].string, tokens[293].string, tokens[294].string, tokens[295].string, tokens[296].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=265;
                    tokans5=266;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=267;
                    tokans5=268;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=279;
                    tokans5=280;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=281;
                    tokans5=282;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=293;
                    tokans5=294;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=295;
                    tokans5=296;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }

        else if(answer2==4)      //date 6/6
        {
            tokans2=333;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[335].string, tokens[347].string, tokens[367].string, tokens[385].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/6 movie1
            {
                tokans3=335;
                printf("\n%s: %s\n", tokens[335].string, tokens[338].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[343].string, tokens[344].string, tokens[345].string, tokens[346].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=343;
                    tokans5=344;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=345;
                    tokans5=346;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/6 movie2
            {
                tokans3=347;
                printf("\n%s: %s\n", tokens[347].string, tokens[350].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[355].string, tokens[356].string, tokens[357].string, tokens[358].string, tokens[359].string, tokens[360].string, tokens[361].string, tokens[362].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=355;
                    tokans5=356;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=357;
                    tokans5=358;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=359;
                    tokans5=360;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=361;
                    tokans5=362;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/5 movie3
            {
                tokans3=367;
                printf("\n%s: %s\n", tokens[367].string, tokens[370].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[375].string, tokens[376].string, tokens[377].string, tokens[378].string, tokens[379].string, tokens[380].string, tokens[381].string, tokens[382].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=375;
                    tokans5=376;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=377;
                    tokans5=378;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=379;
                    tokans5=380;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=381;
                    tokans5=382;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/6 movie4
            {
                tokans3=385;
                printf("\n%s: %s\n", tokens[385].string, tokens[388].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[393].string, tokens[394].string, tokens[395].string, tokens[396].string, tokens[407].string, tokens[408].string, tokens[409].string, tokens[410].string, tokens[421].string, tokens[422].string, tokens[423].string, tokens[424].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=393;
                    tokans5=394;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=395;
                    tokans5=396;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=407;
                    tokans5=408;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=409;
                    tokans5=410;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=421;
                    tokans5=422;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=423;
                    tokans5=424;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }
        else if(answer2==5)      //date 6/7
        {
            tokans2=467;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[469].string, tokens[481].string, tokens[501].string, tokens[519].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/7 movie1
            {
                tokans3=469;
                printf("\n%s: %s\n", tokens[469].string, tokens[472].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[477].string, tokens[478].string, tokens[479].string, tokens[480].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=477;
                    tokans5=478;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=479;
                    tokans5=480;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/7 movie2
            {
                tokans3=481;
                printf("\n%s: %s\n", tokens[481].string, tokens[484].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[489].string, tokens[490].string, tokens[491].string, tokens[492].string, tokens[493].string, tokens[494].string, tokens[495].string, tokens[496].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=489;
                    tokans5=490;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=491;
                    tokans5=492;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=493;
                    tokans5=494;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=495;
                    tokans5=496;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/7 movie3
            {
                tokans3=501;
                printf("\n%s: %s\n", tokens[501].string, tokens[504].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[509].string, tokens[510].string, tokens[511].string, tokens[512].string, tokens[513].string, tokens[514].string, tokens[515].string, tokens[516].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=509;
                    tokans5=510;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=511;
                    tokans5=512;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=513;
                    tokans5=514;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=515;
                    tokans5=516;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/7 movie4
            {
                tokans3=519;
                printf("\n%s: %s\n", tokens[519].string, tokens[522].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[527].string, tokens[528].string, tokens[529].string, tokens[530].string, tokens[541].string, tokens[542].string, tokens[543].string, tokens[544].string, tokens[555].string, tokens[556].string, tokens[557].string, tokens[558].string);
                int answer4=0;
                scanf("%d", &answer4);
  
                if(answer4==1)      //time
                {
                    tokans4=527;
                    tokans5=528;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=529;
                    tokans5=530;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=541;
                    tokans5=542;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=543;
                    tokans5=544;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=555;
                    tokans5=556;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=557;
                    tokans5=558;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }
        else      //date 6/8
        {
            tokans2=595;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[597].string, tokens[609].string, tokens[627].string, tokens[641].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/8 movie1
            {
                tokans3=597;
                printf("\n%s: %s\n", tokens[597].string, tokens[600].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[605].string, tokens[606].string, tokens[607].string, tokens[608].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=605;
                    tokans5=606;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=607;
                    tokans5=608;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/8 movie3
            {
                tokans3=609;
                printf("\n%s: %s\n", tokens[609].string, tokens[612].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[617].string, tokens[618].string, tokens[619].string, tokens[620].string, tokens[621].string, tokens[622].string, tokens[623].string, tokens[624].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=617;
                    tokans5=618;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=619;
                    tokans5=620;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=621;
                    tokans5=622;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=623;
                    tokans5=624;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/8 movie3
            {
                tokans3=627;
                printf("\n%s: %s\n", tokens[627].string, tokens[630].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\nEnter: ", tokens[635].string, tokens[636].string, tokens[637].string, tokens[638].string, tokens[639].string, tokens[640].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokens[515].string, tokens[516].string;       tokans4=635;
                    tokans5=636;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=637;
                    tokans5=638;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=639;
                    tokans5=640;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/8 movie4
            {
                tokans3=641;
                printf("\n%s: %s\n", tokens[641].string, tokens[644].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[649].string, tokens[650].string, tokens[651].string, tokens[652].string, tokens[663].string, tokens[664].string, tokens[665].string, tokens[666].string, tokens[677].string, tokens[678].string, tokens[679].string, tokens[680].string);
                int answer4=0;
                scanf("%d", &answer4);
  
                if(answer4==1)      //time
                {
                    tokans4=649;
                    tokans5=650;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=651;
                    tokans5=652;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=663;
                    tokans5=664;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=665;
                    tokans5=666;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=677;
                    tokans5=678;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=679;
                    tokans5=680;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }
    }

    else           //if N.Pohang
    {
        tokans1=701;
        printf("\nChoose the date: \n1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\nEnter: ", tokens[3].string, tokens[93].string, tokens[205].string, tokens[333].string, tokens[467].string, tokens[595].string);
        int answer2=0;
        scanf("%d", &answer2);
        if(answer2==1)      //date 6/3
        {
            tokans2=3;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[5].string, tokens[15].string, tokens[39].string, tokens[77].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/3movie1
            {
                tokans3=5;
                printf("\n%s: %s\n", tokens[5].string, tokens[8].string);
                printf("\nChoose the time: \n1. %s: %s\nEnter: ", tokens[13].string, tokens[14].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=13;
                    tokans5=14;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2) //6/3 movie2
            {
                tokans3=15;
                printf("\n%s: %s\n", tokens[15].string, tokens[18].string);
                printf("\nChoose the time: \nCinema5\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\n5. %s: %s\n6. %s: %s\n\nCinema 7\n7. %s: %s\nEnter: ", tokens[23].string, tokens[24].string, tokens[25].string, tokens[26].string, tokens[27].string, tokens[28].string, tokens[29].string, tokens[30].string, tokens[31].string, tokens[32].string, tokens[33].string, tokens[34].string, tokens[37].string, tokens[38].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1) //6/3 movie2 time1
                {
                    tokans4=23;
                    tokans5=24;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2) //6/3 movie2 time2
                {
                    tokans4=25;
                    tokans5=26;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3) //6/3 movie2 time3
                {
                    tokans4=27;
                    tokans5=28;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4) //6/3 movie2 time4
                {
                    tokans4=29;
                    tokans5=30;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5) //6/3 movie2 time5
                {
                    tokans4=31;
                    tokans5=32;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==6) //6/3 movie2 time6
                {
                    tokans4=33;
                    tokans5=34;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else
                {
                    tokans4=37;
                    tokans5=38;

                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                
            }
            else if(answer3==3)      //6/3 movie3
            {
                tokans3=39;
                printf("\n%s: %s\n", tokens[39].string, tokens[42].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4%s: %s\n\nCinema 6\n5. %s: %s\n 6. %s: %s\nEnter: ", tokens[47].string, tokens[48].string, tokens[49].string, tokens[50].string, tokens[59].string, tokens[60].string, tokens[61].string, tokens[62].string, tokens[73].string, tokens[74].string, tokens[75].string, tokens[76].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=47;
                    tokans5=48;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=49;
                    tokans5=50;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=59;
                    tokans5=60;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=61;
                    tokans5=62;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=73;
                    tokans5=74;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=75;
                    tokans5=76;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }   
            }
            else      //6/3 movie4
            {
                tokans3=77;
                printf("\n%s: %s\n", tokens[77].string, tokens[80].string);
                printf("\nChoose the time: \nCinema 7\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[85].string, tokens[86].string, tokens[87].string, tokens[88].string, tokens[89].string, tokens[90].string, tokens[91].string, tokens[92].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=85;
                    tokans5=86;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=87;
                    tokans5=88;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=89;
                    tokans5=90;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=91;
                    tokans5=92;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }
        else if(answer2==2)      //date 6/4
        {
            tokans2=93;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[95].string, tokens[107].string, tokens[127].string, tokens[145].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/4 movie1
            {
                tokans3=95;
                printf("\n%s: %s\n", tokens[95].string, tokens[98].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[103].string, tokens[104].string, tokens[105].string, tokens[106].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=103;
                    tokans5=104;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=105;
                    tokans5=106;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/4 movie2
            {
                tokans3=107;
                printf("\n%s: %s\n", tokens[107].string, tokens[110].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[115].string, tokens[116].string, tokens[117].string, tokens[118].string, tokens[119].string, tokens[120].string, tokens[121].string, tokens[122].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=115;
                    tokans5=116;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=117;
                    tokans5=118;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=119;
                    tokans5=120;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=121;
                    tokans5=122;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/4 movie3
            {
                tokans3=127;
                printf("\n%s: %s\n", tokens[127].string, tokens[130].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[135].string, tokens[136].string, tokens[137].string, tokens[138].string, tokens[139].string, tokens[140].string, tokens[141].string, tokens[142].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=135;
                    tokans5=136;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=137;
                    tokans5=138;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=139;
                    tokans5=140;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=141;
                    tokans5=142;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/4 movie4
            {
                tokans3=145;
                printf("\n%s: %s\n", tokens[145].string, tokens[148].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[153].string, tokens[154].string, tokens[155].string, tokens[156].string, tokens[167].string, tokens[168].string, tokens[169].string, tokens[170].string, tokens[181].string, tokens[182].string, tokens[183].string, tokens[184].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=153;
                    tokans5=154;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=155;
                    tokans5=156;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=167;
                    tokans5=168;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=169;
                    tokans5=170;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=181;
                    tokans5=182;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=183;
                    tokans5=184;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            
        }

        else if(answer2==3)      //date 6/5
        {
            tokans2=205;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[207].string, tokens[219].string, tokens[239].string, tokens[257].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/5 movie1
            {
                tokans3=207;
                printf("\n%s: %s\n", tokens[207].string, tokens[210].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[215].string, tokens[216].string, tokens[217].string, tokens[218].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=215;
                    tokans5=216;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=217;
                    tokans5=218;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/5 movie2
            {
                tokans3=219;
                printf("\n%s: %s\n", tokens[219].string, tokens[222].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[227].string, tokens[228].string, tokens[229].string, tokens[230].string, tokens[231].string, tokens[232].string, tokens[233].string, tokens[234].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=227;
                    tokans5=228;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=229;
                    tokans5=230;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=231;
                    tokans5=232;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=233;
                    tokans5=234;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/5 movie3
            {
                tokans3=239;
                printf("\n%s: %s\n", tokens[239].string, tokens[242].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[247].string, tokens[248].string, tokens[249].string, tokens[250].string, tokens[251].string, tokens[252].string, tokens[253].string, tokens[254].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=247;
                    tokans5=248;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=249;
                    tokans5=250;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=251;
                    tokans5=252;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=253;
                    tokans5=254;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/5 movie4
            {
                tokans3=257;
                printf("\n%s: %s\n", tokens[257].string, tokens[260].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[265].string, tokens[266].string, tokens[267].string, tokens[268].string, tokens[279].string, tokens[280].string, tokens[281].string, tokens[282].string, tokens[293].string, tokens[294].string, tokens[295].string, tokens[296].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=265;
                    tokans5=266;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=267;
                    tokans5=268;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=279;
                    tokans5=280;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=281;
                    tokans5=282;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=293;
                    tokans5=294;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=295;
                    tokans5=296;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }

        else if(answer2==4)      //date 6/6
        {
            tokans2=333;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[335].string, tokens[347].string, tokens[367].string, tokens[385].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/6 movie1
            {
                tokans3=335;
                printf("\n%s: %s\n", tokens[335].string, tokens[338].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[343].string, tokens[344].string, tokens[345].string, tokens[346].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=343;
                    tokans5=344;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=345;
                    tokans5=346;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/6 movie2
            {
                tokans3=347;
                printf("\n%s: %s\n", tokens[347].string, tokens[350].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[355].string, tokens[356].string, tokens[357].string, tokens[358].string, tokens[359].string, tokens[360].string, tokens[361].string, tokens[362].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=355;
                    tokans5=356;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=357;
                    tokans5=358;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=359;
                    tokans5=360;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=361;
                    tokans5=362;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/5 movie3
            {
                tokans3=367;
                printf("\n%s: %s\n", tokens[367].string, tokens[370].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[375].string, tokens[376].string, tokens[377].string, tokens[378].string, tokens[379].string, tokens[380].string, tokens[381].string, tokens[382].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=375;
                    tokans5=376;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=377;
                    tokans5=378;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=379;
                    tokans5=380;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=381;
                    tokans5=382;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/6 movie4
            {
                tokans3=385;
                printf("\n%s: %s\n", tokens[385].string, tokens[388].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[393].string, tokens[394].string, tokens[395].string, tokens[396].string, tokens[407].string, tokens[408].string, tokens[409].string, tokens[410].string, tokens[421].string, tokens[422].string, tokens[423].string, tokens[424].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=393;
                    tokans5=394;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=395;
                    tokans5=396;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=407;
                    tokans5=408;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=409;
                    tokans5=410;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=421;
                    tokans5=422;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=423;
                    tokans5=424;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }
        else if(answer2==5)      //date 6/7
        {
            tokans2=467;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[469].string, tokens[481].string, tokens[501].string, tokens[519].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/7 movie1
            {
                tokans3=469;
                printf("\n%s: %s\n", tokens[469].string, tokens[472].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[477].string, tokens[478].string, tokens[479].string, tokens[480].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=477;
                    tokans5=478;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=479;
                    tokans5=480;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/7 movie2
            {
                tokans3=481;
                printf("\n%s: %s\n", tokens[481].string, tokens[484].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[489].string, tokens[490].string, tokens[491].string, tokens[492].string, tokens[493].string, tokens[494].string, tokens[495].string, tokens[496].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=489;
                    tokans5=490;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=491;
                    tokans5=492;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=493;
                    tokans5=494;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=495;
                    tokans5=496;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/7 movie3
            {
                tokans3=501;
                printf("\n%s: %s\n", tokens[501].string, tokens[504].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[509].string, tokens[510].string, tokens[511].string, tokens[512].string, tokens[513].string, tokens[514].string, tokens[515].string, tokens[516].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=509;
                    tokans5=510;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=511;
                    tokans5=512;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=513;
                    tokans5=514;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=515;
                    tokans5=516;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/7 movie4
            {
                tokans3=519;
                printf("\n%s: %s\n", tokens[519].string, tokens[522].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[527].string, tokens[528].string, tokens[529].string, tokens[530].string, tokens[541].string, tokens[542].string, tokens[543].string, tokens[544].string, tokens[555].string, tokens[556].string, tokens[557].string, tokens[558].string);
                int answer4=0;
                scanf("%d", &answer4);
  
                if(answer4==1)      //time
                {
                    tokans4=527;
                    tokans5=528;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=529;
                    tokans5=530;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=541;
                    tokans5=542;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=543;
                    tokans5=544;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=555;
                    tokans5=556;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=557;
                    tokans5=558;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }
        else      //date 6/8
        {
            tokans2=595;
            printf("\nChoose the movie: \n1. %s\n2. %s\n3. %s\n4. %s\nEnter: ", tokens[597].string, tokens[609].string, tokens[627].string, tokens[641].string);
            int answer3=0;
            scanf("%d", &answer3);

            if(answer3==1)      //6/8 movie1
            {
                tokans3=597;
                printf("\n%s: %s\n", tokens[597].string, tokens[600].string);
                printf("\nChoose the time: \nCinema 6\n1. %s: %s\n2. %s: %s\nEnter: ", tokens[605].string, tokens[606].string, tokens[607].string, tokens[608].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=605;
                    tokans5=606;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=607;
                    tokans5=608;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==2)      //6/8 movie3
            {
                tokans3=609;
                printf("\n%s: %s\n", tokens[609].string, tokens[612].string);
                printf("\nChoose the time: \nCinema 9\n1. %s: %s\n2. %s: %s\n3. %s: %s\n4. %s: %s\nEnter: ", tokens[617].string, tokens[618].string, tokens[619].string, tokens[620].string, tokens[621].string, tokens[622].string, tokens[623].string, tokens[624].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokans4=617;
                    tokans5=618;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=619;
                    tokans5=620;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=621;
                    tokans5=622;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=623;
                    tokans5=624;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else if(answer3==3)      //6/8 movie3
            {
                tokans3=627;
                printf("\n%s: %s\n", tokens[627].string, tokens[630].string);
                printf("\nChoose the time: \nCinema 2, SCREENX 2D\n1. %s: %s\n2. %s: %s\n3. %s: %s\nEnter: ", tokens[635].string, tokens[636].string, tokens[637].string, tokens[638].string, tokens[639].string, tokens[640].string);
                int answer4=0;
                scanf("%d", &answer4);

                if(answer4==1)      //time
                {
                    tokens[515].string, tokens[516].string;       tokans4=635;
                    tokans5=636;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=637;
                    tokans5=638;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=639;
                    tokans5=640;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
            else      //6/8 movie4
            {
                tokans3=641;
                printf("\n%s: %s\n", tokens[641].string, tokens[644].string);
                printf("\nChoose the time: \nCinema 1, SCREENX 2D\n1. %s: %s\n2. %s: %s\n\nCinema 3\n3. %s: %s\n4. %s: %s\n\nCinema 5\n5. %s: %s\n6. %s: %s\nEnter: ", tokens[649].string, tokens[650].string, tokens[651].string, tokens[652].string, tokens[663].string, tokens[664].string, tokens[665].string, tokens[666].string, tokens[677].string, tokens[678].string, tokens[679].string, tokens[680].string);
                int answer4=0;
                scanf("%d", &answer4);
  
                if(answer4==1)      //time
                {
                    tokans4=649;
                    tokans5=650;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==2)      //time
                {
                    tokans4=651;
                    tokans5=652;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==3)      //time
                {
                    tokans4=663;
                    tokans5=664;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==4)      //time
                {
                    tokans4=665;
                    tokans5=666;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else if(answer4==5)      //time
                {
                    tokans4=677;
                    tokans5=678;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
                else      //time
                {
                    tokans4=679;
                    tokans5=680;
                    
                    printf("---------------SCREEN--------------\n");
                    printf("-----------------------------------\n");
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[0][0], seatInfo[0][1], seatInfo[0][2], seatInfo[0][3], seatInfo[0][4], seatInfo[0][5], seatInfo[0][6], seatInfo[0][7], seatInfo[0][8], seatInfo[0][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[1][0], seatInfo[1][1], seatInfo[1][2], seatInfo[1][3], seatInfo[1][4], seatInfo[1][5], seatInfo[1][6], seatInfo[1][7], seatInfo[1][8], seatInfo[1][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[2][0], seatInfo[2][1], seatInfo[2][2], seatInfo[2][3], seatInfo[2][4], seatInfo[2][5], seatInfo[2][6], seatInfo[2][7], seatInfo[2][8], seatInfo[2][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[3][0], seatInfo[3][1], seatInfo[3][2], seatInfo[3][3], seatInfo[3][4], seatInfo[3][5], seatInfo[3][6], seatInfo[3][7], seatInfo[3][8], seatInfo[3][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[4][0], seatInfo[4][1], seatInfo[4][2], seatInfo[4][3], seatInfo[4][4], seatInfo[4][5], seatInfo[4][6], seatInfo[4][7], seatInfo[4][8], seatInfo[4][9]);
                    printf("|  %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d  |\n", seatInfo[5][0], seatInfo[5][1], seatInfo[5][2], seatInfo[5][3], seatInfo[5][4], seatInfo[5][5], seatInfo[5][6], seatInfo[5][7], seatInfo[5][8], seatInfo[5][9]);
                    printf("-----------------------------------\n");


                    printf("\nChoose your seat: ");
                    scanf("%d", &tokans6);

                    printf("\n\n----------------------------------------------------------------------------\n");
                    printf("\n     Ticket Information: %s(%s) [%s] %s  SEAT: %d\n", tokens[tokans1].string, tokens[tokans2].string, tokens[tokans3].string, tokens[tokans4].string, tokans6);
                    printf("\n----------------------------------------------------------------------------\n");
                }
            }
        }
    }




   for (int i = 0; i < count; i++)
   {
      free(tokens[i].string);
   }
   free(tokens);
   free(doc);
}

TOKEN* jparse(char* first, int size, TOKEN* o, int f)
{
    int start = 0;

    if (count == 0)
        start = 0;
    else
        start = count - 1;

   TOKEN* tokens = o;
   for (int i = 0 + f; i < size; i++)
   {
      int index = count;

      switch (first[i])
      {
      case '"':
      {
         tokens = realloc(tokens, sizeof(TOKEN)*(count + 1));
         
         tokens[index].type = STRING;
         tokens[index].start = i + 1;

         tokens[index].size = 0;


         if (strchr(first + tokens[index].start, '"') == NULL)

         {
            free(&tokens[index]);
            printf("ERROR");
            return NULL;
         }

         if (strchr(first + tokens[index].start, '\\') == NULL || strchr(first + tokens[index].start, '\\') > strchr(first + tokens[index].start, '"'))
         {
            tokens[index].end = strchr(first + tokens[index].start, '"') - first - 1;
         }

         else
         {
            int n = tokens[index].start;
            while (strchr(first + n, '\\') + 1 == strchr(first + n + 1, '\"'))
            {
               n++;
            }
            tokens[index].end = strchr(first + n + 2, '"') - first - 1;
         }

         count++;

         i = tokens[index].end + 1;
      }
      break;

      case '{':
      {
         tokens = realloc(tokens, sizeof(TOKEN)*(count + 1));
         
         tokens[index].type = OBJECT;
         tokens[index].start = i;
         
         tokens[index].size = 0;


         if (strchr(first + i, '}') == NULL)
         {
            free(tokens);
            printf("ERROR");
            return NULL;
         }
         count++;

         tokens = jparse(first, size, tokens, tokens[index].start + 1);
         if (tokens == NULL)
         {
            free(tokens);
            printf("ERROR");
            return NULL;
         }
         i = tokens[index].end;
         if (index == 0)
            return tokens;
         break;
      }
      break;
      case '}':
      {
         for (int k = start + 1; k < count; k++)
         {
            tokens[start].size += tokens[k].size;
         }
         tokens[start].end = i;
         return tokens;
      }
      
      case '[':
      {
        tokens = realloc(tokens, sizeof(TOKEN)*(count + 1));
         
        tokens[index].type = ARRAY;
        tokens[index].start = i;
         
        tokens[index].size = 0;


         if (strchr(first + i, ']') == NULL)
         {
            free(tokens);
            printf("ERROR");
            return NULL;
         }
         count++;

         tokens = jparse(first, size, tokens, tokens[index].start + 1);
         if (tokens == NULL)
         {
            free(tokens);
            printf("ERROR");
            return NULL;
         }
         i = tokens[index].end;
         tokens[index].size = count - index - 1;
         if (index == 0)
            return tokens;
      }
      break;

      case ']':
      {
         for (int k = start + 1; k < count; k++)
         {
            tokens[start].size += tokens[k].size;
         }
         tokens[start].end = i;
         return tokens;
      }
      
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '-':
      {
         tokens = realloc(tokens, sizeof(TOKEN)*(count + 1));
         tokens[index].type = PRIMITIVE;
         tokens[index].start = i;
         tokens[index].end = 0;
         tokens[index].size = 0;

         if (strchr(first + tokens[index].start, ',') == NULL && strchr(first + tokens[index].start, ']') == NULL && strchr(first + tokens[index].start, '}') == NULL)
         {
            free(tokens);
            printf("ERROR");
            return NULL;
         }

         if (strchr(first + tokens[index].start, ',') != NULL && strchr(first + tokens[index].start, ',') < strchr(first + tokens[index].start, ']') && strchr(first + tokens[index].start, ',') < strchr(first + tokens[index].start, '}'))
         {
            tokens[index].end = strchr(first + tokens[index].start, ',') - first - 1;
            i = tokens[index].end;
         }
         
         if(strchr(first + tokens[index].start, ',') == NULL || (strchr(first + tokens[index].start, ',') != NULL && strchr(first + tokens[index].start, ',') > strchr(first + tokens[index].start, ']')) || (strchr(first + tokens[index].start, ',') != NULL && strchr(first + tokens[index].start, ',') > strchr(first + tokens[index].start, '}')))
         {
            while (1)
            {
               switch (first[++i])
               {
               case '0': case '1': case '2': case '3': case '4': case '5':
               case '6': case '7': case '8': case '9': case '-': case '.':
               break;

               default:
               {
                  tokens[index].end = i - 1;
               }
            }

               if (tokens[index].end == i - 1)
               {
                  break;
               }
            }
            i -= 1;
         }
         count++;
      }
      break;

      case ':':
      {
         if (tokens[count - 1].type == STRING || tokens[count - 1].type == PRIMITIVE) 
            tokens[count - 1].size += 1;
      }
      break;
      }
   }
}

void put(char* first, TOKEN* tokens)
{
   for (int i = 0; i < count; i++)
   {
      tokens[i].string = malloc(sizeof(char)*(tokens[i].end - tokens[i].start + 2));

      strncpy(tokens[i].string, first + tokens[i].start, tokens[i].end - tokens[i].start + 1);
      
      tokens[i].string[tokens[i].end - tokens[i].start + 1] = '\0';
   }
}