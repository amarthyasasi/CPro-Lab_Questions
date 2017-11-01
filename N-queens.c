#include <stdio.h>
int n,a[105][105];
int check(int i,int j)
{
	int x,y;
	for(x=i-1;x>=0;x--)
		if(a[x][j]==1)
			return 0;
	 for(x=i-1,y=j-1;x>=0 && y>=0;x--,y--)
                if(a[x][y]==1)
                        return 0;
	 for(x=i-1,y=j+1;x>=0 && y<n;x--,y++)
		 if(a[x][y]==1)
			return 0;
	 return 1;
}
int rec(int rn)
{
	if(rn==n)
		return 1;
	for(int i=0;i<n;i++)
	{
		int x = check(rn,i);
		if(x==1)
		{
			a[rn][i]=1;
			int y=rec(rn+1);
			if (y==1)
				return 1;
			a[rn][i]=0;
		}
        }
	return 0;
}
int main ()
{
	int i,j;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			a[i][j]=0;

	}
	int x=rec(0);
	if(x==0)
		printf("Not Possible");
	else
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d",a[i][j]);
			printf("\n");
		}

}
