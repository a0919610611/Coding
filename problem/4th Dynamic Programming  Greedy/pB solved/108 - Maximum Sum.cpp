#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include<climits>
using namespace std;
typedef long long lld;
int m[100+1][100+1];
int sum[100+1][100+1];
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		memset(m,0,sizeof(m));
		for (i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&m[i][j]);
				//printf("i=%d j=%d\n",i,j);
			}

		}
		memset(sum,0,sizeof(sum));
		for (i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+m[i][j];
			}
		}
		int max_num=INT_MIN;


		int k,l;
		for (i=1;i<=n;i++){
			for (j=i;j<=n;j++)

			{
				int row[101]={0};
				for(k=1;k<=n;k++){
					row[k]=row[k-1]+sum[k][j]-sum[k-1][j]-sum[k][i-1]+sum[k-1][i-1];
				}

				for(k=1;k<=n;k++){
					for(l=0;l<k;l++){

						max_num=max(max_num,row[k]-row[l]);
					}
				}
			}
		}

		printf("%d\n",max_num);
	}
	return 0;
}
