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
int gcd(int a,int b)
{
	if(a<b) swap(a,b);
		if(b==0) return a;
	else
		return gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
int nlcm(int *a,int n)
{
	if(n==1) return *a;
	else
		return lcm(a[n-1],nlcm(a,n-1));
}
int main()
{
	op_io;
	int n;
	cin>>n;
	int *s=new int[n+1];
	int i,j,k;
	for(i=1;i<=n;i++) cin>>s[i];
	//for(i=1;i<=n;i++) cout<<s[i]<<endl;
	int *d=new int[n+1]();
	int times;
	for(i=1;i<=n;i++)
	{

		 times=0;
		for(j=s[i];;j=s[j])
		{
			times++;
			int tt=times;
			int q=j;
			while(tt--)
			{
				q=s[q];
			}
			if(q==j)
			printf("q=%d j=%d times=%d\n",q,j,times);
			if(q==j) break;
		}
		d[i]=times;
		//cout<<i<<times<<endl;
	}
	int ans=nlcm(d+1,n);
	//for(i=1;i<=n;i++) cout<<d[i];
	cout<<ans;

	return 0;
}
