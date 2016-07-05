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
int  graph[101][101]; //0:can 1:can't 2:king 3:princess
bool visited[101][101];

int hvm[8]={2,2,1,1,-1,-1,-2,-2};
int hhm[8]={-1,1,-2,2,-2,2,-1,1};
int kvm[8]={1,1,1,0,0,-1,-1,-1};
int khm[8]={-1,0,1,-1,1,-1,0,1};
struct p
{
	int x,y;
	p(int x0,int y0){x=x0,y=y0;}
};
int dis;
int n,sx,sy,ex,ey;
int a,b;
void bfs()
{
	queue<p> q;
	memset(visited,0,sizeof(visited));
	q.push(p(sx,sy));
	int step=0;
	visited[sx][sy]=true;
	while(!q.empty())
	{
		int num=q.size();
		for (int i=1;i<=num;i++)
		{
			int x=q.front().x;
			int y=q.front().y;
			q.pop();
			for (int j=0;j<8;j++)
			{
				int  tx=x+kvm[j];
				int ty=y+khm[j];
				if(tx>=1 && tx<=a && ty>=1 && ty<=b && visited[tx][ty]==false && graph[tx][ty]!=1)
						{
							if(tx==ex && ty==ey){dis=step+1; return;}
							visited[tx][ty]=true;
							q.push(p(tx,ty));
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

	scanf("%d",&n);
	while(n--)
	{
		memset(graph,0,sizeof(graph));

		scanf("%d%d\n",&a,&b);
		for (int i=1;i<=a;i++)
		{
			for (int j=1;j<=b;j++)
			{
				char ch;
				ch=getchar();
				if(ch=='.' && graph[i][j]!=1) graph[i][j]=0;
				else if(ch=='Z')
				{
					graph[i][j]=1;
					int tx,ty;
					for(int k=0;k<8;k++)
					{
						tx=i+hvm[k];
						ty=j+hhm[k];
						if(tx>=1 && tx<=a && ty>=1 && ty<=b && graph[tx][ty]!=3 && graph[tx][ty]!=2)
						{

							graph[tx][ty]=1;
						}
					}
				}else if(ch=='B') {graph[i][j]=3; ex=i,ey=j;}
				else if(ch=='A')
				{
					sx=i,sy=j;
					graph[i][j]=2;
				}
			}
			getchar();
		}

			dis=0;
			bfs();
			if(dis)
			{
				printf("Minimal possible length of a trip is %d\n",dis);
			}else
			{
				printf("King Peter, you can't go now!\n");
			}
	}

	return 0;
}
