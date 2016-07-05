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
typedef pair<lld  ,lld > pll;

struct cmp{
bool operator () (const pll& p, const pll& q) {
		return p.first > q.first;
}
};
lld n,m;
lld d[MAXN]={};
lld parent[MAXN]={};
vector<pll > graph[MAXN];
vector<lld> ans;
priority_queue<pll,vector<pll>,cmp > pq;
void output(lld i)
{
	if(i==1){printf("1 "); return;}
	output(parent[i]);
	printf("%I64d",i);
	if(i!=n)
	{
		printf(" ");
	}else printf("\n");
}
int main()
{
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif

	scanf("%I64d%I64d",&n,&m);
	lld a,b,c;
	for (lld i=1;i<=m;i++)
	{

		scanf("%I64d%I64d%I64d",&a,&b,&c);
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));
	}
	fill(d,d+MAXN+1,1e18);
	d[1]=0;
	pq.push(pll(0,1));
	long long p;
	while(!pq.empty())
	{
		p=pq.top().S;
		pq.pop();
		for(lld i=0;i<graph[p].size();i++)
		{
			if(graph[p][i].S+d[p]<d[graph[p][i].F])
			{
				d[graph[p][i].F]=graph[p][i].S+d[p];
				pq.push(pll(d[graph[p][i].F],graph[p][i].F));
				parent[graph[p][i].F]=p;
			}
		}
	}
	if (parent[n]==0)printf("-1\n");
	else
	{

		output(n);
	}

	return 0;
}

