#include<stdio.h>
#define inf 999999

/*
** Program to find minimum no. of multiplications required to find product of n matrices using Dynamic Programming
** Made by - Abhishek Chand
*/


long int D[41]={100,50,10,15,25,20,40,30,20,50,100,15,20,25,45,75,65,5,25,15,100,50,15,25,20,40,35,35,45,25,25,20,5,5,20,25,15,35,40,100,20};
long int M[41][41],S[41][41];

void MatChainMult(int n)
{
	int i,j,k,l;
	long int q;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=(n-l+1);i++)
		{
			j=i+l-1;
			for(k=i;k<j;k++)
			{
				q=M[i][k]+M[k+1][j]+D[i-1]*D[k]*D[j];
				if(q<M[i][j])
				{
					M[i][j]=q;
					S[i][j]=k;
				}	
			}
		}
		
	}
}

void SplitPrint(int i, int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		SplitPrint(i,S[i][j]);
		SplitPrint(S[i][j]+1,j);
		printf(")");
	}
}


int main()
{
	int i,j,n;
	long int ans;
	printf("Enter the no. of matrices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				M[i][j]=0;
			else
				M[i][j]=inf;
			
			S[i][j]=0;
		}
	}
	
	MatChainMult(n);
	printf("\nMinimum no. of multiplications = %ld",M[1][n]);
	printf("\n");
	SplitPrint(1,n);
	return 0;
}
