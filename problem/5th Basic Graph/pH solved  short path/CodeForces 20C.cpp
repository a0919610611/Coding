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
#define MAXN 100010
using namespace std;

typedef long long lld;
typedef pair<int   ,int   > pii;
typedef pair<lld  ,int  > pli;


lld d[100010]={};
int parent[100010]={};
vector<pii > graph[100010];
vector<int > ans;
priority_queue<pli,vector<pli>,greater<pli> > pq;
int i;
int main()
{
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif
	int  n,m;
	scanf("%d%d",&n,&m);
	//printf("n=%d\n",n);
	int  a,b,c;
	for (i=1;i<=m;i++)
	{

		scanf("%d%d%d",&a,&b,&c);
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));
	}
	fill(d,d+MAXN+1,1e18);
	d[1]=0;
	pq.push(make_pair(0,1));
	long long p,q;
	while(!pq.empty())
	{
		p=pq.top().S;
		q=pq.top().F;
		pq.pop();
		//if(d[p]<q) continue; //updated dont need to change
		for( i=0;i<graph[p].size();i++)
		{
			if(graph[p][i].S+d[p]<d[graph[p][i].F])
			{
				d[graph[p][i].F]=graph[p][i].S+d[p];
				pq.push(make_pair(d[graph[p][i].F],graph[p][i].F));
				parent[graph[p][i].F]=p;
			}
		}
		//printf("hi");
	}
	//printf("fuck");
	//printf("%d\n",n);
	//printf("%d\n",parent[5]);
	//printf("%d",parent[n]);
	if (parent[n]==0)printf("-1\n");
	else
	{
		//printf("fuck");
		ans.push_back(n);
		int x=n;
		while(parent[x]>0)
		{

			//1printf("%d\n",x);
			ans.push_back(parent[x]);
			x=parent[x];

		}


		for(i=ans.size()-1;i>=0;i--)
		{
			printf("%d",ans[i]);
			if(i) printf(" ");
			else printf("\n");
		}
	}

	return 0;
}

