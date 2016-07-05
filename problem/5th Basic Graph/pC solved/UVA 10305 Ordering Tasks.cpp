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
int n,m;
int in[101]={};
bool visited[101]={};
bool graph[101][101]={};
vector<int> ans;
void dfs(int k)
{

	for (int i=1;i<=n;i++)
	{
		if(graph[k][i] &&visited[i]==false)
		{
			graph[k][i]=false;

			dfs(i);
		}


	}
	visited[k]=true;
	ans.push_back(k);
}



int main()
{
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif

	while(scanf("%d%d",&n,&m) && (n||m))
	{
		memset(visited,0,sizeof(visited));
		memset(in,0,404);
		memset(graph,0,sizeof(graph));
		while(!ans.empty())ans.pop_back();
	for(int i=1;i<=m;i++)
	{

		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=true;
		in[b]++;
	}
	for (int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{

			dfs(i);
		}
	}
	//printf("%d\n",ans.size());
	for (int i=ans.size()-1;i>=0;i--)
	{

		printf("%d",ans[i]);
		if(i) printf(" ");

	}
	printf("\n");
	}
	return 0;
}
