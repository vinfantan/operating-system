#include<stdio.h>
struct node
{
    int pid;
    struct node *next;
};
void main()
{
	int flag=0,b,i,j,k,l,out[20],b_copy[20],burst[20],n,p_id[10],fl[10],arr[20],quant,p,tat[20],wait[20];
	struct node *start=NULL,*temp,*rear,*run;
	printf("enter no of process\n");
	scanf("%d",&n);
	printf("\n enter arrival time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
    }
	printf("\n enter burst time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);
		b_copy[i]=burst[i];
		fl[i]=0;
    }
	printf("\n enter time quantum\n");
	scanf("%d",&quant);
    i=0;k=0;
         do{
            for(j=0;j<n;j++)
            {
                if(arr[j]>=i && burst[j]!=0 && fl[j]!=1)
                {
                    temp=(struct node *)malloc(sizeof(struct node));
                    temp->next=NULL;
                    temp->pid=j;
                    fl[j]=1;
                    if(start==NULL)
                    {
                        start=temp;
                    }
                    else{
                        run=start;
                        while(run->next!=NULL)
                        {
                            run=run->next;
                        }
                        run->next=temp;
                    }
                    rear=temp;
                }
            }

            run=start;
            while(run!=NULL)
            {
                if(burst[run->pid]>quant)
                {
                burst[run->pid]-=quant;
                i+=quant;
                  for(t=0;t<n;t++)
                  {
                       if(arr[t]>=i && burst[j]!=0 && fl[j]!=1)
                      {
                    temp=(struct node *)malloc(sizeof(struct node));
                    temp->next=NULL;
                    temp->pid=j;
                    fl[j]=1;
                     }
                }
                else{
                   i+=burst[run->pid];
                   burst[run->pid]=0; flag++;
                   out[run->pid]=i;
                   printf("\n%d out ==>> %d\n",run->pid,i);
                }
                run=run->next;
            }
            start=NULL;
            i++;
	}while(flag!=n);
	for(i=0;i<n;i++)
	{
		tat[i]=out[i]-arr[i];
		wait[i]=tat[i]-b_copy[i];
		}

	printf("\n\nprocess \t\t complition \t\t tat \t\t\t wait \n");
	for(i=0;i<n;i++)
	{
		printf(" %d == \t\t\t %d \t\t\t %d \t\t\t%d\n",i+1,out[i],tat[i],wait[i]);
		}

}

