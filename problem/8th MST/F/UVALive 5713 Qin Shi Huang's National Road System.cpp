/****************************************************************************/
/*                  code by a0919610611/fuyu0425                            */
/****************************************************************************/
//#define txt     //use freopen
//#pragma comment(linker, "/STACK:1024000000,1024000000")  //op
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define op_io
#else
#define op_io ios_base::sync_with_stdio(0);cin.tie(0);
#endif
#define endl "\n"
#define F first
#define S second
#define MAXN 200005

typedef long long LL;
typedef pair<int,int> pii;
struct Edge2
{
    int to;
    double dis;
    Edge2 (int too=0 ,double diss=0)
    {
        to=too;
        dis=diss;
    }
};
int g[1001];
int d[1001];
 vector<Edge2> used[1001];
void init(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        g[i]=i;
        d[i]=1;
        used[i].clear();
    }
}
int found(int x)
{
    return (g[x]==x)?x:g[x]=found(g[x]);
}
void Union (int x,int y)
{
    x=found(x);
    y=found(y);
    if(x==y) return ;
    if(d[x]<d[y])
    {
        g[x]=y;
        d[y]+=d[x];
    }else
    {
        g[y]=x;
        d[x]+=d[y];
    }
}
struct Edge
{
    int v1,v2;
    double dis;
    bool used=0;
    Edge (int v11,int v22 ,double diss)
    {
        v1=v11;
        v2=v22;
        dis=diss;
    }
    bool operator < (const Edge &a) const
    {
        return dis<a.dis;
    }
};

struct P
{
    int x,y,people;
};
double cdis(P a ,P b)
{
    double ans=0;
    ans+=(a.x-b.x) * (a.x-b.x);
    ans+=(a.y-b.y) * (a.y-b.y);
    return sqrt(ans);
}
bool visited[1001];
double maxd[1001][1001];
  int n;
  int parent[1001]={};
void dfs(int root ,int now)
{
    visited[now]=true;
    int i;
    for(i=0;i<used[now].size();i++)
    {
        int to=used[now][i].to;
        if(!visited[to])
        {
            maxd[root][to]=max(used[now][i].dis,maxd[root][now]);
            dfs(root,to);
        }
    }
}
int main()
{
	op_io;
    int T;
    cin>>T;
    while(T--)
    {

        cin>>n;
        init(n);
        int i,j;
        P point[1001];
        for(i=1;i<=n;i++)
        {
            cin>>point[i].x>>point[i].y>>point[i].people;
        }
        vector<Edge> e;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                e.push_back(Edge(i,j,cdis(point[i],point[j])));
            }
        }
        sort(e.begin(),e.end());
        double min_dis=0;
        int group=n;

        for(i=0;i<e.size() &&group>1;i++)
        {
            int x=e[i].v1;
            int y=e[i].v2;
            if(found(x)!=found(y))
            {
                Union(x,y);
                min_dis+=e[i].dis;
                e[i].used=1;
                used[x].push_back(Edge2(y,e[i].dis));
                used[y].push_back(Edge2(x,e[i].dis));
                group--;
            }
        }
        memset(maxd,-1,sizeof(maxd));
        for(i=1;i<=n;i++)
        {
            memset(visited,0,sizeof(visited));
            dfs(i,i);
        }
        double max_ratio=0;
        for(i=1;i<=n;i++)
        {
           for(j=i+1;j<=n;j++)
           {
               max_ratio=max(max_ratio,(double) (point[i].people+point[j].people)/(min_dis-maxd[i][j]));
           }
        }
        printf("%.2f\n",max_ratio);
    }

	return 0;
}
