//#define txt     //use freopen
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
#include <cctype>
/////////////////////////////////
#define F first
#define S second
#define MAXN 200005
using namespace std;
typedef long long lld;
typedef pair<int,int> pii;
int n;
bool graph[2001][2001]={};
int in[2001]={};
int ans=0;
void dfs(int a,int depth)
{
	ans=max(ans,depth);
	for (int i=1;i<=n;i++)
	{
		if(graph[a][i])
		{

			dfs(i,depth+1);
		}
	}
}
int main()
{
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif

	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(t!=-1)
		{
			graph[t][i]=true;
			in[i]++;
		}
	}
	ans=0;
	for (int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			dfs(i,1);

		}
	}
	printf("%d\n",ans);
	return 0;
}
