#include<stdio.h>
int main()
{
	int i,j,burst[20],arr[20],pcopy[20],n,response[20],wait[20],tat[20],sum,out[20];
	printf("enter no of process\n");
	scanf("%d",&n);
	printf("\nenter arrival time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n enter burst time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);
	    
	}
     sum=burst[0];
     out[0]=sum;
	 for(i=0;i<n-1;i++)
     {
     	if(sum<arr[i+1])
     	{
     		sum=arr[i+1];
		 }
	sum+=burst[i+1];
    out[i+1]=sum;
     }
     
     for(i=0;i<n;i++)
     {
     	tat[i]=out[i]-arr[i];
	    wait[i]=tat[i]-burst[i];
	    response[i]=out[i]-burst[i];    
	 }
printf("\n \tprocess \ttat \t\t waiting time \t\tresponse time \n");
for(i=0;i<n;i++)
{
	printf("\n\t %d \t\t %d\t \t \t %d \t\t\t %d\n",i+1,tat[i],wait[i],response[i]);
	  } 	 
   


}
