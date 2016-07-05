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
int hm[]={0,0,1,-1};
int vm[]={1,-1,0,0};
int land[1001][1001]={};
//bool visited[1001][1001]={};
//int dis[1001][1001]={};
int R,C;
int sx,sy,ex,ey;
struct p
{
	int x,y;
	p(int x0,int y0){x=x0,y=y0;}
};
queue<p> q;
void bfs()
{
	int step=0;
	int num;
	while(!q.empty()) q.pop();
	q.push(p(sx,sy));
	//visited[sx][sy]=true;
	//dis[sx][sy]=0;

	while(!q.empty() )
	{

			num=q.size();
			while(num--)
			{

			int x=q.front().x;
			int y=q.front().y;
			q.pop();
			for (int j=0;j<4;j++)
			{
				int tempx=x+vm[j];
				int tempy=y+hm[j];

				if(tempx>=0 && tempx<R && tempy>=0 && tempy<C && land[tempx][tempy]==0 )
				{

					q.push(p(tempx,tempy));
					land[tempx][tempy]=step+1;


				}
			}

			}
			step++;

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

	while(scanf("%d%d",&R,&C) && (R||C))
	{
		memset(land,0,sizeof(land));
		//memset(visited,0,sizeof(visited));
		//memset(dis,0,sizeof(dis));
		int n;
		scanf("%d",&n);
		while(n--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			for (int i=0;i<b;i++)
			{
				int c;
				scanf("%d",&c);
				land[a][c]=1;
			}
		}

		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		bfs();
		printf("%d\n",land[ex][ey]);
	}
	return 0;
}
