#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int largest_burst_time(int p[],int l)
{
	int h,i;
	h=p[0];

	for(i=0;i<(l-1);i++)
	{
		if(h<p[i+1])
		{
			h=p[i+1];
		}
	}
   return(h);
}
int main()
{
    int i,j,k,n,n1,sum_burst,repeat,pro;
    printf("***************************************** Round Robbin Without Arrival Time ***************************************\n");
    printf("enter no of processes\n");
    scanf("%d",&n);
    int p[n],wait[n],response[n],tat[n],run,array[n],out[n],h,pcopy[n];
    printf("\nenter burst time of each process\n");
    for(i=0;i<n;i++)
    {

        scanf("%d",&p[i]);
        pcopy[i]=p[i];
         out[i]=0;
         tat[i]=0;
         response[i]=0;
         wait[i]=0;
    }
    printf("\n enter quantum time \n");
    scanf("%d",&run);

     h=largest_burst_time(p,n);
     if(h%run==0)
    {
    repeat=h/run*n;
	}
	else
	{
		  repeat=((h/run)+1)*n;
	}
     printf("\nlargest %d\n",h);

    for(i=0;i<repeat;i++)
    {

         pro=i%n;
         if(p[pro]==0)
         {
             array[i]=0;
         }
         if(p[pro]<run&&p[pro]!=0)
         {
            array[i]=p[pro];
            p[pro]=0;
            out[pro]=i;
          }
         if(p[pro]>=run)
         {
             array[i]=run;
             p[pro]=p[pro]-run;
         if(p[pro]==0)
             {
                out[pro]=i;
             }

       }

    }
    printf("\n\t\tprocess\t \t tat \t wait_time\tresponse_time\n");
    for(i=0;i<n;i++)
    {
    	for(j=i;j<=out[i];j++)
    	{
    		tat[i]+=array[j];
         }
         for(j=0;j<i;j++)
         {
         	response[i]+=array[j];
		 }
		wait[i]=tat[i]-pcopy[i];
    	printf("\n  \t\t%d \t\t %d\t \t%d\t\t %d\n",i+1,tat[i],wait[i],response[i]);
	}
}
