#include <stdio.h>
#include <stdlib.h>

char Check_if_win(char arr[][3]);
char Check_if_taken(char arr[][3],char position);
void insert(char arr[][3],char position,char x);

char Player1='x' , Player2='o';

int main()
{
    char flag=0 , pos, alt=0;
    char arr[3][3]={'1','2','3','4','5','6','7','8','9'};
    while(flag==0)
    {
        if(alt==0)
        {
            printf("Enter pos player1\n");
            scanf("%c",&pos);
            fflush(stdin);
            alt=1;
        }
        else
        {
            printf("Enter pos player2\n");
            scanf("%c",&pos);
            fflush(stdin);
            alt=0;
        }

        if(Check_if_taken(arr,pos))
           {
               printf("Try again taken..\n");
               continue;
           }
        else
        {
            insert(arr,pos,alt);

        }
    }

}

char Check_if_taken(char arr[][3],char position)
{
    char i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]==position)
            {
                if(arr[i][j]=='x' || arr[i][j]=='o')
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void insert(char arr[][3],char position,char x)
{
    char i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]==position)
            {
                if(x==0)
                    arr[i][j]=Player2;
                else if(x==1)
                    arr[i][j]=Player1;
            }
        }
    }
}


char Check_if_win(char arr[][3])
{
    char i , j, count_row_x=0 , count_row_o=0 , count_col_x=0 , count_col_o=0 , count_diag_o=0, count_diag_x=0 ;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]=='x')
            {
                count_row_x++;
            }
            else{}

            if(arr[j][i]=='x')
            {
                count_col_x++;
            }
            else{}

            if(arr[i][j]=='o')
            {
                count_row_o++;
            }
            else{}

            if(arr[j][i]=='o')
            {
                count_col_o++;
            }
            else{}

            if(count_row_x==2 || count_col_x==2)
            {
                return 1;

            }
            else if(count_row_o==2 || count_col_o==2)
            {
                return 2;
            }
            else{}
        }
    }

    j=0,i=0;
    for(i=0;i<3;i++)
    {
        j++;
        if(arr[i][j]=='x')
        {
            count_diag_x++;
        }
        else{}

        if( arr[i][j]=='o')
        {
            count_diag_o++;
        }
        else{}

        if(count_diag_x==2)
        {
            return 1;
        }
        else if(count_diag_o==2)
        {
            return 2;
        }
        else{}
    }

    count_diag_o=0 ,count_diag_x=0;
    j=3,i=0;
    for(i=0;i<3;i++)
    {
        j--;
        if(arr[i][j]=='x')
        {
            count_diag_x++;
        }
        else{}

        if(arr[i][j]=='o')
        {
            count_diag_o++;
        }
        else{}

        if(count_diag_x==2)
        {
            return 1;
        }
        else if(count_diag_o==2)
        {
            return 2;
        }
        else{}
    }

    return 0;
}
