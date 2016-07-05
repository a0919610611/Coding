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
int c[10000*2+100];
int find(int a)
{
	return c[a]==a?a:c[a]=find(c[a]);
}
void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a<b)
	c[b]=a;
	else
	{
		c[a]=b;
	}

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
	int n;
	cin>>n;
	int q,a,b;
	int i;
	for(i=0;i<=2*n;i++)
	{
		c[i]=i;
	}
	int pa,pb,pa2,pb2;
	while(cin>>q>>a>>b)
	{
		if(q==0 && a==0 &&b==0) break;
		if(q==1)
		{
			pa=find(a);
			pa2=find(a+n);
			pb=find(b);
			pb2=find(b+n);

			if( pa==pb2)
			{
				printf("-1\n");
				continue;
			}
			Union(a,b);
			Union(a+n,b+n);
		}else if(q==2)
		{

			pa=find(a);
			pa2=find(a+n);
			pb=find(b);
			pb2=find(b+n);
			if(pa==pb)
			{
				printf("-1\n");
				continue;
			}
			Union(a+n,b);
			Union(a,b+n);
		}else if(q==3)
		{
			pa=find(a);
			pb=find(b);



			if(pa==pb)
			{
				printf("1\n");
			}else
			{
				printf("0\n");
			}
		}else
		{
			if(find(a+n)==find(b) ||find(a)==find(b+n))
			{
				printf("1\n");
			}else
			{
				printf("0\n");
			}
		}
	}

	return 0;
}
