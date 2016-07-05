/*************************************************************************
	> File Name: uva_10480.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/06/13 20:15:41
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
const double Eps=1e-6;
#define int long long 
int n,m;
int f[55][55];
int dis[55];
int S,T;
bool visit[100];
void init()
{
    memset(f,0,sizeof(f));

}
bool BFS()
{
    memset(dis,-1,sizeof(dis));
    queue<int>q;
    q.push(S);
    dis[S]=0;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==-1 && f[top][i])
            {
                dis[i]=dis[top]+1;
                q.push(i);
            }
        }
    }
    return dis[T]>=0;
}
int DFS(int x,int low)
{
    if(x==T) return low;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]!=-1 && dis[i]==dis[x]+1 && f[x][i]>=0)
        {
            int a=DFS(i,min(low,f[x][i]));
            if(a>0)
            {
                f[x][i]-=a;
                f[i][x]+=a;
                return a;
            }
        }
    }
    return 0;
}
void solve()
{
    memset(visit,0,sizeof(visit));
    queue<int>q;
    q.push(S);
    visit[S]=true;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(!visit[i] && f[top][i])
            {
                q.push(i);
                visit[i]=true;
            }
        }
    }
}
#undef int
int main()
{
#define int long long 
    op_io;
    S=1,T=2;
    while(cin>>n>>m && (n || m))
    {
        init();
        vector<pair<int,int> > edge;
        for(int i=1;i<=m;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            edge.push_back(make_pair(u,v));
            f[u][v]=c;
            f[v][u]=c;
        }
        while(BFS())
        {
            while(DFS(S,INT_MAX));
        }
        solve();
        for(int i=0;i<edge.size();i++)
        {
            int u=edge[i].first;
            int v=edge[i].second;
            if(visit[u] ^ visit[v])
            {
                cout<<u<<" "<<v<<endl;
            }
        }
        cout<<endl;
    }

    return 0;
}
