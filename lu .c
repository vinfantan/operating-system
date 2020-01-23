#include<stdio.h>
int main()
{
    int size,row,column,ctr1,ctr2;
    printf("ENTER THE SIZE OF THE MATRIX(size<10)\n");
    scanf("%d",&size);
    float matrix[10][10];
    printf("ENTER THE MATRIX\n");
    for(row=0;row<size;row++)
        for(column=0;column<size;column++)
            scanf("%f",&matrix[row][column]);
    float lowertriangle[10][10];//matrices for lower and uppper triangle
    float uppertriangle[10][10];
    for(row=0;row<size;row++)
        for(column=0;column<size;column++)
            {
                if(row>column)//initialise all elements of lower triangle in upper triangular matrix as 0
                     uppertriangle[row][column]=0.0;
                if(row<column)//initialise all elements of upper triangle in lower triangular matix as 0
                    lowertriangle[row][column]=0.0;
                if(row==column)//initialise all diagonal elements of lower triangular matrix as 1
                    lowertriangle[row][column]=1.0;
            }
			
for(ctr1=0;ctr1<size;ctr1++)
    {
        uppertriangle[ctr1][ctr1]=matrix[ctr1][ctr1];
            for(ctr2=ctr1+1;ctr2<size;ctr2++)
            {
                uppertriangle[ctr1][ctr2]=matrix[ctr1][ctr2];
                lowertriangle[ctr2][ctr1]=matrix[ctr2][ctr1]/uppertriangle[ctr1][ctr1];
            }
             for(row=ctr1+1;row<size;row++)
                for(column=ctr1+1;column<size;column++)
                    matrix[row][column]=matrix[row][column]-lowertriangle[row][ctr1]*uppertriangle[ctr1][column];
    }
    printf("UPPER TRIANGULAR MATRIX\n");
    for(row=0;row<size;row++)
    {//displays upper triangular matrix
        for(column=0;column<size;column++)
            printf("%.2f ",uppertriangle[row][column]);
        printf("\n");
    }
        printf("LOWER TRIANGULAR MATRIX\n");
    for(row=0;row<size;row++)
    {//displays lower triangular matrix
        for(column=0;column<size;column++)
            printf("%.2f ",lowertriangle[row][column]);
        printf("\n");
    }
    getch();
}			
