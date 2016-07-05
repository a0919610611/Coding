#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;
#define endl '\n'

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        int i,j;
        cin>>n>>m;
        int edge[101][101]={};
       // memset(edge,-1,sizeof(edge));
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=n;j++)
           {
               edge[i][j]=INT_MAX;
           }
       }
        for(i=1;i<=m;i++)
        {
            int v1,v2,dis;
            cin>>v1>>v2>>dis;
            edge[v1][v2]=edge[v2][v1]=dis;
        }
        int d[101];
        fill(d,d+n+1,INT_MAX);
        bool visited[101]={};
        d[1]=0;
        int parent[101]={};
        parent[1]=1;
        int maxd[101][101]={};
        memset(maxd,-1,sizeof(maxd));
        int point=0;
        vector<int> point_set;
        int min_dis=0;
        while(point<n)
        {
            int p=-1,min_d=INT_MAX;
            for(i=1;i<=n;i++)
            {
                if(!visited[i] && d[i]<min_d)
                {
                    p=i;
                    min_d=d[i];
                }
            }
            if(p==-1 ) break;
            min_dis+=min_d;
            point++;
            visited[p]=true;
            for(i=0;i<point_set.size();i++)
            {
               maxd[p][point_set[i]]=maxd[point_set[i]][p]=max(min_d,maxd[parent[p]][point_set[i]]);

            }
            point_set.push_back(p);
            for(i=1;i<=n;i++)
            {
                if(!visited[i]&&edge[p][i]<d[i])
                {
                    d[i]=edge[p][i];
                    parent[i]=p;
                }
            }
        }
      //  cout<<min_dis<<endl;
        int second_min=INT_MAX;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(parent[i]!=j && parent[j]!=i && edge[i][j]!=INT_MAX )
                second_min=min(second_min,min_dis+edge[i][j]-maxd[i][j]);
            }
        }
        //cout<<second_min<<endl;
        if(min_dis==second_min) cout<<"Not Unique!"<<endl;
        else cout<<min_dis<<endl;
    }
    return 0;
}
