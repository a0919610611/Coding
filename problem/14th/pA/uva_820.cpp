/*************************************************************************
	> File Name: uva_820.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/06/13 02:02:20
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
const double Eps=1e-6;
int f[104][104];
int dis[104];
int N,S,T,C;
int BFS()
{
    memset(dis,-1,sizeof(dis));
    dis[S]=0;
    queue<int>q;
    q.push(S);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=1;i<=N;i++)
        {
            if(dis[i]<0 && f[t][i]>0)
            {
                dis[i]=dis[t]+1;
                q.push(i);
            }
        }
    }
    if(dis[T]>0) return 1;
    else 
    return 0;
}
int find(int x,int low)
{
    if(x==T) return low;
    int a;
    for(int i=1;i<=N;i++)
    {
        if(f[x][i]>0 && dis[i]==dis[x]+1 && (a=find(i,min(low,f[x][i]))))
        {
                f[x][i]-=a;
                f[i][x]+=a;
                return a;
        }            
    }
    return 0;

}
int main()
{
    op_io;
    int times=1;
    while(cin>>N && N)
    {
        memset(f,0,sizeof(f));
        cin>>S>>T>>C;
        for(int i=1;i<=C;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            f[u][v]+=c;
            f[v][u]+=c;
        }
        int ans=0;
        while(BFS())
        {
            int mind;
            while(mind=find(S,INT_MAX))ans+=mind;
        }
        cout<<"Network "<<times++<<endl;
        cout<<"The bandwidth is "<<ans<<"."<<endl<<endl;
    }
    return 0;
}
