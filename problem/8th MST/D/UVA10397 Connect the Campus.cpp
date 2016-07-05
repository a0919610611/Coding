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
struct P
{
    int x,y;
    P(int x0=0,int y0=0)
    {
        x=x0,y=y0;
    }
};
struct Edge
{
    int v1,v2;
    double dis;
    Edge (int v11=0,int v22=0,double diss=0)
    {
        v1=v11,v2=v22,dis=diss;
    }
    bool operator < (const Edge & a) const
    {
        return dis<a.dis;
    }
};
inline double cdis(P a,P b)
{
    double ans=0;
    ans+=(a.x-b.x)*(a.x-b.x);
    ans+=(a.y-b.y)*(a.y-b.y);
    return sqrt(ans);
}
int group[751];
int depth[751];
inline void init (int n)
{
    for(int i=1;i<=n;i++)
        group[i]=i;
    fill(depth,depth+751,1);

}
inline int find_group(int x)
{
    return group[x]==x?x:group[x]=find_group(group[x]);
}
inline void Union(int x,int y)
{
    x=find_group(x);
    y=find_group(y);
    if(depth[x]<depth[y])
    {
        group[x]=y;
        depth[y]+=depth[x];

    }else
    {
         group[y]=x;
        depth[x]+=depth[y];
    }
}
int main()
{
	op_io;
    int n;
    int i,j;
    while(cin>>n)
    {
        P point [755]={};
        for(i=1;i<=n;i++)
        {
            cin>>point[i].x>>point[i].y;
        }
        int m;
        cin>>m;
        init(n);
        int group_num=n;
        for(i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            if(find_group(a)!=find_group(b))
            {
            Union(a,b);
            group_num--;
            }
        }
        vector<Edge> e;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(find_group(i)!=find_group(j))
                {
                    e.push_back(Edge(i,j,cdis(point[i],point[j])));
                }
            }
        }
        sort(e.begin(),e.end());
        double ans=0;
        for(i=0;i<e.size() && group_num>1;i++)
        {
            if(find_group(e[i].v1)==find_group(e[i].v2))continue;
            ans+=e[i].dis;
            Union(e[i].v1,e[i].v2);
            group_num--;
        }
       printf("%.2f\n",ans);
    }

	return 0;
}
