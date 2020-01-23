#include<stdio.h>
#define n 10
main()
{
	int j,k=0,a[n][n],size,i;
	int b[n][n];
	int res[n][n];
	printf("Enter size of matrix:");
	scanf("%d",&size);
	
	printf("Enter 1st Matrix:\n");
	for(i=0;i<size;i++)
	for(j=0;j<size;j++)
	scanf("%d",&a[i][j]);
	
	printf("Enter 2nd Matrix:\n");
    for(i=0;i<size;i++)
    for(j=0;j<size;j++)
	scanf("%d",&b[i][j]);
	
	for(i=0;i<size;i++)
{
	for(j=0;j<size;j++){
	
	res[i][j]=0;
	for(k=0;k<size;k++)
	res[i][j]+=a[i][k]*b[j][k];
}
}

	printf("mat 1 *mat 2 =\n ");
	for(i=0;i<size;i++)
{
		for(j=0;j<size;j++)
	printf("%d\n",res[i][j]);
}
}
