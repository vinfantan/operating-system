#include<stdio.h>
int main()
{
	int i,j,n,m,res,k;
	printf("*********************************************** Shortest Job First *****************************************\n");
	printf("enter no of process\n");
	scanf("%d",&n);
	int burst[n],v[n],response[n],bcopy[n],out[n];
	printf("\n enter burst time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);
	    bcopy[i]=burst[i];
	    //bcopy2[i]=burst[i];
	    //sum_burst+=burst[i];
	    v[i]=0;
	    response[i]=0;
	}
    do{
		res=0;
	for(i=0;i<n-1;i++)
	{
	   if(bcopy[i]>bcopy[i+1])
	   {
	    m=bcopy[i+1];
        bcopy[i+1]=bcopy[i];
		bcopy[i]=m;
	    res=res+1;
	    }
	  }
	}while(res!=0);
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(burst[j]==bcopy[i])
			{
				k+=burst[j];
				burst[j]=0;

				v[i]=j;
				response[i+1]=k;
				//printf("\n %d",v[i]);
			}
		}
	 }



	 printf("\n process no \t\t burst time\t\t response time\n");
	 for(i=0;i<n;i++)
	 {
	 	 printf("\n %d\t \t \t %d\t\t\t\t%d",v[i]+1,bcopy[i],response[i]);
	 }
}
