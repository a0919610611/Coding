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
using namespace std;
typedef long long lld;
int main()
{
	int n;
	int s[10000+1];
	int sum[10000+1];
	int i,j;
	int dis,max;
	while(scanf("%d",&n) && n)
	{
		sum[0]=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			sum[i]=sum[i-1]+s[i];
		}
		max=0;
		for (i=1;i<=n;i++)
		{
			for (j=0;j<=i;j++)
			{
				dis=sum[i]-sum[j];
				if (dis>0 && dis>max) max=dis;
			}
		}
		if(max) printf("The maximum winning streak is %d.\n",max);
		else printf("Losing streak.\n");
	}
	return 0;
}
