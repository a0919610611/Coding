#include <bits/stdc++.h>
using namespace std;
const double Eps=1e-6;
int id;
int p[10000];
int S,T;
int n;
vector<string>ans;
map<string,int>idx;
map<int,string>sidx;
struct Edge
{
    int  v,cap,next;
}e[1000*1000];
int dis[10000];
void init()
{
    memset(e,0,sizeof(e));
    memset(p,-1,sizeof(p));
    id=0;
}
void add(int u,int v,int c)
{
    e[id].v=v,e[id].cap=c,e[id].next=p[u],p[u]=id;
    id++;
    e[id].v=u,e[id].cap=0,e[id].next=p[v],p[v]=id;
    id++;
}
bool BFS(int s,int t)
{
    memset(dis,-1,sizeof(dis));
    queue<int>q;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int top=q.front();q.pop();
        for(int i=p[top];i!=-1;i=e[i].next)
        {
            int v=e[i].v;
            if(dis[v]==-1 && e[i].cap)
            {
                dis[v]=dis[top]+1;
                q.push(v);
            }
        }
    }
    return dis[t]>=0;
}
int DFS(int x,int low)
{
    if(x==T) return low;
    for(int i=p[x];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(dis[v]>0 && dis[v]==dis[x]+1 && e[i].cap)
        {
            int a=DFS(v,min(low,e[i].cap));
            if(a>0)
            {
                e[i].cap-=a;
                e[i^1].cap+=a;
                return a;
            }
        }
    }
    return 0;
}
int dicnic()
{
    int flow=0;
    while(BFS())
    {
        int mind;
        while(mind=DFS(S,INT_MAX)) flow+=mind;
    }
    return flow;
}

