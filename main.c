#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<time.h>


 char board[3][3];
 const char player='X';
 const char computer='O';

 void resetBoard()
 {
     int i,j;
     for(i=0;i<3;i++)
     {
         for(j=0; j<3;j++)
         {
             board[i][j]=' ';
         }
     }
 }

 void printBoard()
 {
     int i,j;
     for(i=0;i<3;i++)
     {
         for(j=0; j<3;j++)
         {
             if(j==2)
                printf("%c ", board[i][j]);
            else
              printf("%c  |", board[i][j]);

         }
         printf("\n---|---|---\n");
     }
 }

 int checkFreeSpace()
 {
     int free=9;
     int i,j;
     for(i=0;i<3;i++)
     {
         for(j=0; j<3;j++)
         {
             if(board[i][j]!=' ')
                free--;

         }
     }
     return free;
 }

 void playerMove()
 {
     int x,y;

    do
    {
         do
             {
                 printf("Entrer la ligne (1 ou 2 ou 3): ");
                 scanf("%d",&x);
                 if(x>3)
                    printf("on a seulement 3 lignes.\n");
                 else if(x<1)
                 {
                     printf("le numero de la ligne doit etre positif.\n");
                 }

             }while(x>3 || x<1);
             x--;

     do
         {
             printf("Entrer la colonne (1 ou 2 ou 3): ");
             scanf("%d",&y);
             if(y>3)
                printf("on a seulement 3 colonnes.\n");
             else if(y<1)
             {
                 printf("le numero de la colonne doit etre positif.\n");
             }

         }while(y>3 || y<1);
         y--;

     if(board[x][y]!=' ')
     {
         printf("case deja occupe.\n ");
     }
     else
        {
          board[x][y]=player;
          break;
        }

    }while(board[x][y]!=' ');

 }

 void computerMove()
 {

     int x,y;

     if(checkFreeSpace()>0)
     {
         do
         {
             x=rand()%3;
             y=rand()%3;
         }while(board[x][y]!=' ');
         board[x][y]=computer;
     }
     else
        {
          printWinner(' ');
        }

 }

 char checkWinner()
 {
     // verif des lignes
     for(int i=0;i<3;i++)
     {
         if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
            return board[i][0];
     }

     //verif des colonnes
     for(int i=0;i<3;i++)
     {
         if(board[0][i]==board[1][i] && board[0][i]==board[2][i])
            return board[0][i];
     }

     // verif des diagonales

         if(board[0][0]==board[1][1]&& board[0][0]==board[2][2])
            return board[0][0];

         if(board[0][2]==board[1][1]&& board[0][2]==board[2][0])
            return board[0][2];


   return ' ';
 }

 void printWinner(char reponse)
 {
     if(reponse==' ')
     {
         printf("le match est Nulle.\n");
     }
     else if(reponse=='X')
        {
            printf("Bravo! vous avez gagnez.\n");

        }
     else if(reponse=='O')
     {
         printf("Oops! vous avez perdu.\n");
     }
 }


int main()
{
char response;
    do
    {
        //response=' ';
        char winner=' ';
        resetBoard();
            while(winner==' ' && checkFreeSpace()!=0)
            {
                printBoard();
                playerMove();

                winner=checkWinner();
                if(winner!=' ' || checkFreeSpace()==0)
                 {
                    break;

                 }

                 computerMove();

                 winner=checkWinner();
                 if(winner!=' ' || checkFreeSpace()==0)
                 {
                    break;

                 }

            }
            printBoard();
            printWinner(winner);
            do
            {
               printf("Voulez-vous rejouer? (Y:yes|N:no): ");
               scanf("%c");
               scanf("%c",&response);
                if(response!='Y'&& response!='N')
                {
                    printf("reponse invalide.\n");
                }
            }while(response!='Y'&& response!='N');



    }while(response=='Y');
    if(response=='N')
    {
        printf("Thanks for playing.\n");
    }


return 0;


}
