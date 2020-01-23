#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int largest_burst_time(int p[])
{
	int h,i,l;
	h=p[0];
	l=sizeof(p)/sizeof(int);
	for(i=0;i<(l-1);i++)
	{
		if(h>p[i+1])
		{
			h=p[i+1];
		}
	}
   return(h);
}
int main()
{
	int i,p[n],h,s;
	printf("enter no of processes\n");
	scanf("%d",&s);
	printf("enter burst time of each process\n");
	for(i=0;i<s;i++)
	{
		scanf("%d",&p[i]);
	}
	
    h=largest_burst_time(p);
    printf("\n\n h==%d",h);
}

