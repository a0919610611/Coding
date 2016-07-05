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
#include <climits>
////////////////////////////////////
#define sc scanf
#define pr printf
using namespace std;
typedef long long lld;
int main()
{
	int s[100+1][100+1];
	int sum[101][101];
	int n,m;
	while(sc("%d%d",&n,&m) &&n&&m)
	{
		memset(s,0,sizeof(s));
		memset(sum,0,sizeof(sum));
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			sc("%d",&s[i][j]);
			if(s[i][j]) s[i][j]=-10001;
			else s[i][j]=1;
		}
	}
	//for (i=1;i<=n;i++)
	//{
		//for(j=1;j<=m;j++)
			//printf("%d\n",s[i][j]);
	//}
	for (i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+s[i][j];
	}
	//for (i=1;i<=n;i++)
	//{
		//for(j=1;j<=m;j++)
			//printf("sum=%d\n",sum[i][j]);
	//}
		int max_num=0;
		int l;
	for(i=1;i<=n;i++){ //down
		for(j=i;j<=n;j++) //up
		{
				//printf("m=%d",m);
				int row[101]={0};
				for(k=1;k<=m;k++){
					row[k]=row[k-1]+sum[j][k]-sum[j][k-1]-sum[i-1][k]+sum[i-1][k-1];
					//printf("row%d=%d\n",k,row[k]);
				}

				for(k=1;k<=m;k++){
					for( l=0;l<k;l++){
						//if(row[k]-row[l]>=0)
						max_num=max(max_num,row[k]-row[l]);
						//printf("k=%d l=%d row=%d\n",k,l,row[k]-row[l]);
					}
				}
		}
	}
	printf("%d\n",max_num);
	}
	return 0;
}
