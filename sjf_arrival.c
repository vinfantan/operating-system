#include<stdio.h>
main()
{
	int i,n,flag=0,res,ind,m;
	float sum=0.0;
	printf("****************************** Shortest  Remaining time First *****************************************\n");
	printf("enter no of process\n");
	scanf("%d",&n);
	int burst[n],bcopy[n],k,h,tat[n],wait[n],maint[3][n],arr[n],j,out[n];
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
	i=0;
	do{

     k=0;
	 for(j=0;j<n;j++)
	 {
	 	if(arr[j]<=i && bcopy[j]>0)
	 	{
	 		maint[0][k]=bcopy[j];
	 		maint[1][k]=j;
	 		k++;
		 }
	 }
    if(k>0){
	 if(k>1){
        do{
		res=0;
	   for(j=0;j<k-1;j++)
	{
	   if(maint[0][j]>maint[0][j+1])
	   {
	    m=maint[0][j+1];
	    ind=maint[1][j+1];
        maint[0][j+1]=maint[0][j];
		maint[1][j+1]=maint[1][j];
		maint[0][j]=m;
		maint[1][j]=ind;
	    res=res+1;
	    }
    }

	}while(res!=0);
	 }

	      h=maint[1][0];
	        	out[h]=i+1;
	        	flag++;
	        	i=i+bcopy[h];
	        	bcopy[h]=0;
	        	//bcopy[0][k]=1000;
			printf("\n process %d \t %d\n",h+1,out[h]);
			tat[h]=out[h]-arr[h];
			wait[h]=tat[h]-burst[h];

   }//k!=0 close
 i++;
}while(flag!=n);
printf("\n proceess \t\t tat \t\t waiting time \t\t completion time\n");
sum=0;
for(i=0;i<n;i++)
{
	printf("\n \t%d \t\t %d \t\t %d \t\t\t %d",i+1,tat[i],wait[i],out[i]);
    sum+=wait[i];
}
printf("\n average waiting time is ==   %f ",sum/n);
}
