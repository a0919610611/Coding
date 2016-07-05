/*************************************************************************
	> File Name: uva_11418.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/06/13 13:48:30
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
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
    idx.clear();
    sidx.clear();
    ans.clear();
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
int names;
void solve()
{
    for(int i=n+1;i<=2*n;i++)
    {
        for(int j=p[i];j!=-1;j=e[j].next)
        {
            int v=e[j].v;
            if(v==T) continue;
            if(e[j].cap==1)
            {
                ans.push_back(sidx[v]);
                break;
            }
        }
    }
}
int main()
{
    op_io;
    int t;
    cin>>t;
    int times=0;
    while(t--)
    {
        cout<<"Case #"<<++times<<":"<<endl;
        cin>>n;
        init();
        S=0;
        for(int i=1;i<=n;i++)
        {
            add(0,i,1);
        } 
        T=2*n+1;
        for(int i=1;i<=n;i++)
        {
            add(i+n,T,1);
        }
        int idd=T;
        names=0;
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            string in;
            for(int j=0;j<k;j++)
            {
                cin>>in;
                for(int t=0;t<in.size();t++)
                {
                    in[t]=tolower(in[t]);
                }
                int first=in[0]-'a'+1;
                if(idx.count(in)==0)
                {
                    names++;
                    idx[in]=++idd;
                    sidx[idd]=in;
                    add(first,idd,1);
                    add(idd,n+i,1);
                    
                }else
                {
                    int ID=idx[in];
                    add(ID,n+i,1);
                }
            }
        }
        while(BFS(S,T))
        {
            while(DFS(S,INT_MAX));
        }
        solve();
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            ans[i][0]=toupper(ans[i][0]);
            cout<<ans[i]<<endl;
        }
    }

    return 0;
}
