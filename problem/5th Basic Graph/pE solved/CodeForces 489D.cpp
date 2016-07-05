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

typedef long long LL;
typedef pair<int,int> pii;
bool g[3001][3001]={};
int c[3001][3001]={};
int main()
{
	op_io;
	//cout<<"hi";

	//memset(g,0,sizeof(g));

	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a][b]=true;
	}
	int j,k;
	for (i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(j!=i && g[i][j])
		{
			for(k=1;k<=n;k++)
			{
				if(k!=i && k!=j && g[j][k])
				{
					c[i][k]++;
				}
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			ans+=(c[i][j])*(c[i][j]-1)/2;
			cout<<ans<<endl;
	return 0;
}
