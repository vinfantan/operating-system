#include<stdio.h>
int pri[2][20],n;
void main()
{
	int flag,l,i,j,loop,b_copy[20],burst[20],arr[20],out[20],tat[20],wait[20];
	printf("enter no of processes\n");
	scanf("%d",&n);
	printf("\nenter arrival time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		
	}
	printf("\nenter burst time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);
		b_copy[i]=burst[i];
		
	}
    printf("\nenter priority of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pri[0][i]);
		pri[1][i]=i;
		
	}
	i=0;
	loop=100;
    do{
    	
    	p_sort();
    	for(j=0;j<n;j++)
    	{
    		l=pri[1][j];
    		if((arr[l]<=i) && (burst[l]>0))
    		{
    		    flag=1;
           // printf("%d\n",i);
				goto jump;
			}
			else{
			}
		}
		jump:
			 if(flag==1)
			 {
			 	burst[l]=burst[l]-1;
			 	if(burst[l]==0)
			 	{
			 		out[l]=i+1;
		//		  printf("%d== %d\n",l,i);
				 }
			 }
			 //loop=loop+1;
			 i=i+1;
			 flag=0;
	}while(i<loop);
		
for(i=0;i<n;i++)
{
	tat[i]=out[i]-arr[i];
	wait[i]=tat[i]-b_copy[i];
	
	//printf(" %d\t ==\t %d\n",i+1,out[i]);
}		
printf("process\t \t tat\t wait\t complition\n");
for(i=0;i<n;i++)
{
	printf(" %d\t ==\t%d\t %d \t %d\n",i+1,tat[i],wait[i],out[i]);
}
}

void p_sort()
{ 
  int ret,i,temp;
do{
	
	ret=0;
	for(i=0;i<n-1;i++)
	{
		if(pri[0][i]<pri[0][i+1])
		{
			temp=pri[0][i];
			pri[0][i]=pri[0][i+1];
		    pri[0][i+1]=temp;
		
		    temp=pri[1][i];
		    pri[1][i]=pri[1][i+1];
		    pri[1][i+1]=temp;
		    ret=ret+1;
		}
	}
}while(ret!=0);
}
