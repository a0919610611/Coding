#define txt     //use freopen
//#pragma comment(linker, "/STACK:1024000000,1024000000")  //op

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
int c[30001];
int t[30001];
int find(int a)
{
	if(c[a]==a) return a;
	else return c[a]=find(c[a]);
}
int main()
{
	#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif
	op_io;
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int i;
		for(i=1;i<=n;i++) //initialize
		{
			c[i]=i;
		}
		for(i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
			int f_a=find(a);
			int f_b=find(b);
			if(f_a<f_b)
			{
				c[f_b]=f_a;
			}else
			{
				c[f_a]=f_b;
			}
		}
		int ans=0;
	memset(t,0,sizeof(t));
	for(i=1;i<=n;i++)
	{
		int x=find(i);
		t[x]++;
		ans=max(ans,t[x]);
	}
	cout<<ans<<endl;
	}

	return 0;
}
