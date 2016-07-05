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
int main()
{
	op_io;
	int n;
	cin>>n;
	int d[301][301]={};
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>d[i][j];
	cin>>k;
	int a,b,c;
	while(k--)
	{
		cin>>a>>b>>c;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
			d[i][j]=min(d[i][j],min(d[i][a]+c+d[b][j],d[i][b]+c+d[a][j]));
			d[j][i]=d[i][j];
			}
		}

		LL ans=0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			ans+=d[i][j];

		cout<<ans;
		if(k)cout<<" ";
	}

	return 0;
}
