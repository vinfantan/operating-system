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
	int time,i,p[10],h,n,tat[10],run,repeat,j,sum_burst=0,k=0,wat[10],pro,array[30];
	printf("enter no of processes\n");
	scanf("%d",&n);
	printf("enter burst time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}

    h=largest_burst_time(p,n);
    printf("n enter running time\n");
    scanf("%d",&run);

    for(i=0;i<n;i++)
    {
        sum_burst+=p[i];
		tat[i]=0;
		wat[i]=0;
	}

    if(h%run==0)
    {
    repeat=h/run;
	}
	else
	{
		  repeat=h/run+1;
	}
	printf("\n\n sumburst %d",sum_burst);

     for(i=0;i<sum_burst;i++)
     {
     	pro=i%n;

     	if(p[pro]<run){
     	tat[pro]=tat[pro]+p[pro];
                	//printf(" \n tat %d",tat[pro]);

		 printf(" \n process %d \t \t %d",pro,p[pro]);
		 time=time+p[pro];
		 array[i]=p[pro];
		 tat[pro]=i;
		 p[pro]=0;
		 }
		 else
		 {

		 	 p[pro]=p[pro]-run;
               array[i]=run;
		     time=time+run;
		     if(p[pro]==0)
		     {
		     	tat[pro]=i;
			 }
		 printf(" \n process %d \t \t %d\t\t %d   ",pro,run,time);
		 }


	 }


	for(i=0;i<n;i++)
	{
		printf("\n turn around time of process %d == %d \t\t %d",i,tat[i]);
	}
for(i=0;i<sum_burst;i++)
	{
		printf("\n turn around time of process %d == %d \t\t %d",i,array[i]);
	}
}



