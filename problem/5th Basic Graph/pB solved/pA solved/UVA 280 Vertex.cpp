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
bool graph[101][101];
bool visited[101];
int num=0;
void dfs(int start)
{
	int i;
	for (i=1;i<=n;i++)
	{
		if(graph[start][i] && visited[i]==false)
		{
			num++;
			visited[i]=true;
			dfs(i);
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

	while(scanf("%d",&n) && n)
	{
		memset(graph,0,sizeof(graph));
		int from,to;
		while(scanf("%d",&from) && from)
		{
			while(scanf("%d",&to) && to)
			{
				graph[from][to]=true;
			}
		}
		int m;
		scanf("%d",&m);
		while(m--)
		{
			int start;
			scanf("%d",&start);
			memset(visited,0,sizeof(visited));
			num=0;
			dfs(start);
			num=n-num;
			printf("%d",num);
			for(int i=1;i<=n;i++)
			{
				if(visited[i]==false)
				{
					if(num>1)
					{
						printf(" %d",i);
						num--;
					}else
					{
						printf(" %d",i);
						num--;
					}
				}
			}
			puts("");
		}
	}

	return 0;
}
