#include<stdio.h>
main()
{
	int i,n,res,m;
    float sum=0.0;
    printf("\n************************************ First Come First Serve *****************************************\n");
	printf("enter no of process\n");
	scanf("%d",&n);
  	int burst[n],bcopy[n],k,h,tat[n],wait[n],maint[3][n],s_pro,s_burst,arr[n],j,out[n];
	printf("\nenter arrival time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n enter burst time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);
		bcopy[i]=burst[i];
	      out[i]=0;
	}

	sum=burst[0];

	for(i=0;i<n-1;i++)
	{
		if(sum<arr[i+1])
		{
			sum=arr[i+1];
		}
	    sum+=burst[i+1];
	}
//	printf("\n %d",sum);
//	scanf("%d",&sum);
for(i=0;i<sum;i++)
{
	 k=0;
	 for(j=0;j<n;j++)
	 {
	 	if(arr[j]<=i && bcopy[j]!=0)
	 	{
	 		maint[0][k]=bcopy[j];
	 		maint[1][k]=j;
	 		k++;
	 		//printf("\n pro %d \n",j);
		 }
	 }

	 if(k!=0){

	        for(j=0;j<k;j++)
	        {
	            h=maint[1][j];
			    i=i+bcopy[h];
	        bcopy[h]=0;
	        out[h]=i;
		   //printf("\nprocess %d== out\t %d\n",h+1,out[h]);
			tat[h]=out[h]-arr[h];
			wait[h]=tat[h]-burst[h];

		}
		i=i-k;

}
}


printf("\n proceess \t\t tat \t\t waiting time \n");
sum=0;
for(i=0;i<n;i++)
{
	printf("\n \t%d \t\t %d \t\t %d",i+1,tat[i],wait[i]);
    sum+=wait[i];
}
printf("\n average waiting time is ==   %f ",sum/n);

}
