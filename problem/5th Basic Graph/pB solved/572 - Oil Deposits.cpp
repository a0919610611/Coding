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
/////////////////////////////////
#define F first
#define S second
using namespace std;
typedef long long lld;
typedef pair<int,int> pii;
int g[101][101];
int n,m;
void solve(int i,int j)
{
	if(g[i][j]!=1){g[i][j]=2; return;}
	else
	{
		g[i][j]=2;
		if((i+1)<=n && (j+1)<=m)
		{
			solve(i+1,j+1);
		}
		if((i+1)<=n && j<=m)
		{
			solve(i+1,j);
		}
		if((i+1)<=n && (j-1)>=1){solve(i+1,j-1);}
		if(i<=n &&(j+1)<=m) solve(i,j+1);
		if(i<=n && (j-1)>=1) solve(i,j-1);
		if((i-1)>=1 && j<=m) solve(i-1,j);
		if((i-1)>=1 && (j+1)<=m) solve(i-1,j+1);
		if((i-1)>=1 && (j-1)>=1) solve(i-1,j-1);
	}

}
int main()
{

	int i,j;
	char ch;
	while(scanf("%d%d\n",&n,&m) && m &&n)
	{
		memset(g,0,sizeof(g));
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
		{
			ch=getchar();
			g[i][j]=(ch=='*')?0:1;
		}
			getchar();
		}
		int cnt=0;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				if(g[i][j]==1)
				{
					cnt++;
					solve(i,j);
				}
			}
		}
		printf("%d\n",cnt);
		//for (i=1;i<=n;i++)
		//{
			//for (j=1;j<=m;j++)
		//{

			//printf("%d",g[i][j]);
		//}
			//puts("");
		//}
	}
	return 0;
}
