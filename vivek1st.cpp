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
	int i,p[10],h,n,tat[10],run,repeat,j,sum_burst=0,k=0,wat[10];
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
	printf("\n\n repaet %d",repeat);
      for(i=0;i<repeat;i++){
	  
         for(j=0;j<n;j++)
         {
           if(p[j]<run)
           {
           
            for(k=j-1;k>=0;k--)
            {
                if(p[k]!=0)
                {
                	wat[k]+=p[j];
				}
			}
		    tat[j]+=p[j];
		   	p[j]=0;
		   }
		   else{
		   	            for(k=j-1;k>=0;k--)
            {
                if(p[k]!=0)
                {
                     wat[k]+=run;
				}
			}
		   	tat[j]+=run; 
		   	p[j]=p[j]-run;
		   	
		   }
			}
		 
}
	for(i=0;i<n;i++)
	{
		printf("\n turn around time of process %d == %d \t\t %d",i,tat[i],wat[i]);
	}

}



