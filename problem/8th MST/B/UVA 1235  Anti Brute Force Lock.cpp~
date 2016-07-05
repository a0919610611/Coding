/****************************************************************************/
/*                  code by a0919610611/fuyu0425                            */
/****************************************************************************/
//#define txt     //use freopen
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define op_io ios_base::sync_with_stdio(0);
#else
#define op_io ios_base::sync_with_stdio(0);cin.tie(0);
#endif
#define endl "\n"
#define F first
#define S second
#define MAXN 200005

typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
    int to,cost;
    bool operator <(const Edge & a) const
    {
        return cost>a.cost;
    }
};
int cal(string a,string b)
{
    int i;
    int ans=0;
    for(i=0;i<4;i++)
    {

        ans+=min(abs(a[i]-b[i]),9-abs(a[i]-b[i])+1);
    }

    return ans;
}
int main()
{
	op_io;
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string s[501];
        vector<Edge> e[501];
        int i,j;
        for(i=1;i<=n;i++)
        {
            cin>>s[i];
           // cout<<s[i];
        }

      // s[0].clear();
       s[0]="0000";
     //  cout<<s[0];
       priority_queue<Edge> q;
       int min_num,min_cost;
       min_num=INT_MAX;
       min_cost=INT_MAX;
        for(i=1;i<=n;i++)
        {
            //e[0].push_back((Edge){i,cal(s[0],s[i])});
            if(cal(s[0],s[i])<min_cost)
            {
                min_num=i;
                min_cost=cal(s[0],s[i]);
            }

        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                e[i].push_back((Edge){j,cal(s[i],s[j])});
                e[j].push_back((Edge){i,cal(s[i],s[j])});


            }
        }

        int point =1;
        bool visited[501]={};
        visited[min_num]=true;
        int ans=min_cost;
         for(i=0;i<e[min_num].size();i++)
            {

                q.push(e[min_num][i]);

            }
        while(point < n)
        {
            Edge a;

            while(1)
            {
                a=q.top();
                if(!visited[a.to])
                {
                    ans+=a.cost;
             //  printf("ans=%d %d %d\n",ans,a.to,a.cost);
                   visited[a.to]=true;
                    point++;
                    break;
                }else
                {
                    q.pop();
                }

            }
            for(i=0;i<e[a.to].size();i++)
            {
                if(!visited[e[a.to][i].to])
                q.push(e[a.to][i]);
                //printf("%d %d %d\n",a.to,e[a.to][i].to,e[a.to][i].cost);
            }
        }
        cout<<ans<<endl;
    }

	return 0;
}
