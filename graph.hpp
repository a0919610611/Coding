#include<bits/stdc++.h>
const int MAXN=10000;
vector<int>e[MAXN] //Edge
int d[MAXN];
bool visited[MAXN];
void BFS(int root)
{   
    memset(d,-1,sizeof(d));
    queue<int>q;
    q.push(root);
    d[root]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[u][i];
            if(dis[v]!=-1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
void DFS(int root)
{
   memset(visited,0,sizeof(visited));
   stack<int>s;
   s.push(root);
   visited[root]=true;
   while(!s.empty())
   {
       int u=s.top();
       s.pop();
       for(int i=0;i<e[u].size();i++)
       {
           int v=e[u][i];
           if(!visited[v])
           {
                visited[v]=true;
                s.push(v);
           }

        }    

    }
}
