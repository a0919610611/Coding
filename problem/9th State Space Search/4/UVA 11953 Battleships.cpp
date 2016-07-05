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
#define op_io ios_base::sync_with_stdio(0);
#else
#define op_io ios_base::sync_with_stdio(0);cin.tie(0);
#endif
#define endl "\n"
#define F first
#define S second
#define MAXN 200005
#define clean(a) memset(a,0,sizeof(a))
typedef long long LL;
typedef pair<int,int> pii;
char board[101][101]={};
bool visited[101][101]={};
int vm[4]={0,0,1,-1};
int hm[4]={1,-1,0,0};
int N;
void dfs(int x,int y)
{
    visited[x][y]=true;
    int i;
    for(i=0;i<4;i++)
    {
        int tmpx=x+vm[i];
        int tmpy=y+hm[i];
        if(tmpx>=1 && tmpx<=N && tmpy>=1 && tmpy<=N && board[tmpx][tmpy]!='.' && !visited[tmpx][tmpy] )
        {
            dfs(tmpx,tmpy);
        }
    }
}
int main()
{
	op_io;
    int T;
    cin>>T;
    int cases=1;
    while(T--)
    {
        clean(board);
        clean(visited);
        int ans=0;
        cin>>N;
        cin.ignore();
        int i,j;
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                cin>>board[i][j];
            }
            cin.ignore();
        }
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                if(!visited[i][j])
                {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }

	return 0;
}
