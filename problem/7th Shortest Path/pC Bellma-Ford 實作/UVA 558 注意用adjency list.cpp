//#define txt     //use freopen
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <climits>
#include <cctype>
/////////////////////////////////
#define F first
#define S second
#define MAXN 200005
using namespace std;
typedef long long lld;
typedef pair<int,int> pii;
int n,m;
int f[2001],t[2001],w[2001];
int d[1001];
int main()
{
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d%d",&n,&m);

		fill(d,d+n,INT_MAX);
		d[0]=0;
		int i,j,k;
		for (i=1;i<=m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			f[i]=a,t[i]=b,w[i]=c; //dont use matrix
		}

			for (i=1;i<n;i++)
			{

			for(j=1;j<=m;j++)
			{

					int x=f[j],y=t[j];
					if(d[x]+w[j]<d[y])
					{
					d[y]=d[x]+w[j];
					}


			}
			}


		int flag=0;
		for(j=1;j<=n;j++)
			{
				int x=f[j],y=t[j];
					if(d[x]+w[j]<d[y])
					{
					flag=1;
					}
				if(flag) break;
			}
			if(flag) printf("possible\n");
			else printf("not possible\n");
	}

	return 0;
}
