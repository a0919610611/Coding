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
int graph[1001][1001]={};
int gdis[1001][1001]={};
int hm[]={1,-1,0,0};
int vm[]={0,0,1,-1};
bool visited[1001][1001]={};
int n,m;
int sx,sy,ex,ey;
int visit_num=0;
struct point
{
	int x,y;
	point(int x0,int y0){x=x0,y=y0;};
};
queue<point> p;
void bfs()
{
	int step=0;
	p.push(point(ex,ey));
	gdis[ex][ey]=0;
	int i,j;
	int x,y;
	while(!p.empty())
	{
	int num=p.size();
	for (i=1;i<=num;i++)
	{
		x=p.front().x;
		y=p.front().y;
		//printf("xx=%d yy=%d\n",x,y);
		p.pop();
		gdis[x][y]=step;
		//printf("hi\n");
		for (j=0;j<=3;j++)
		{
			int tempx=x+hm[j];
			int tempy=y+vm[j];
			if(tempx>0 && tempx<=n&&tempy>0 &&tempy<=m &&visited[tempx][tempy]==false &&graph[tempx][tempy]!=-1)
			{
				visited[tempx][tempy]=true;
				p.push(point(tempx,tempy));
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

	scanf("%d%d\n",&n,&m);
	int i,j;
	char ch;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch=='E'){graph[i][j]=-2;ex=i,ey=j; visit_num++;}
			else if(ch=='T') {graph[i][j]=-1; visit_num++;}
			else if (ch=='S') {sx=i;sy=j;}
			else {graph[i][j]=ch-'0';}
		}
		getchar();
	}
	//for (i=1;i<=n;i++)
	//{
		//for(j=1;j<=m;j++)
		//{
			//printf("%d",graph[i][j]);
		//}
		//printf("\n");
	//}

	//printf("sx=%d sy=%d\n",sx,sy);
	//printf("%d",gdis[sx][sy]);
	int ans=0;

	bfs();
	//for (i=1;i<=n;i++)
	//{
		//for(j=1;j<=m;j++)
		//{
			//printf("x=%d y=%d dis=%d val=%d\n",i,j,gdis[i][j],graph[i][j]);
		//}
	//}
	for (i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(graph[i][j]>0 && gdis[i][j]<=gdis[sx][sy] && gdis[i][j]>0)
			{
				ans+=graph[i][j];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
