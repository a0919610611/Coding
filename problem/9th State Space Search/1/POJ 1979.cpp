
#include<cstdio>
#include<cstring>
using namespace std;


typedef long long LL;
//typedef pair<int,int> pii;
char g[21][21]={};
bool visited[21][21]={};
int hm[5]={0,1,-1,0,0};
int vm[5]={0,0,0,-1,1};
int n,m;
int ans;
void dfs(int x,int y)
{
	visited[x][y]=true;
	int i;
	for(i=1;i<=4;i++)
	{
		int tx=x+vm[i];
		int ty=y+hm[i];
		if(tx>0 && ty>0 && tx<=m && ty<=n && g[tx][ty]=='.' &&!visited[tx][ty])
		{
			ans++;
			dfs(tx,ty);
		}
	}
}
int main()
{


	while(scanf("%d%d",&n,&m) &&(n||m))
	{
			getchar();
			memset(g,0,sizeof(g));
			memset(visited,0,sizeof(visited));
			int i,j ,sx,sy;
			for(i=1;i<=m;i++)
				{
					for(j=1;j<=n;j++)
					{
						g[i][j]=getchar();
						if(g[i][j]=='@') sx=i,sy=j;
					}
					getchar();
				}
			ans=1;
			//printf("%d %d",sx,sy);
			dfs(sx,sy);
		printf("%d\n",ans);
	}
	return 0;
}
