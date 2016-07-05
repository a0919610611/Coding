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
typedef long long LL;
typedef pair<int,int> pii;
LL gcd(LL a,LL b)
{
	LL aa=a,bb=b;
	if(aa<bb) swap(aa,bb);
	while(1)
	{
		LL mod=aa%bb;
		if(mod==0) return bb;
		aa=bb;
		bb=mod;

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
	int a[201]={};
	LL step[201]={};
	bool visited[201]={false};
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",a+i);

	for(i=1;i<=n;i++)
	{
		//printf("%dFuck",i);
		memset(visited,0,sizeof(visited));


		step[i]=0;
		//visited[i]=true;
		for(j=i;!visited[j];j=a[j])
		{
			visited[j]=true;
			step[i]++;

			//printf("i=%d step=%d\n",i,step[i]);
		}
		if(a[j]==a[a[j]])step[i]--;
		if(!step[i]) step[i]=1;

	}
	for (i=1;i<=n;i++)
	{
		printf("%d\n",step[i]);
	}
	LL ans=step[1];
	for (i=2;i<=n;i++)
	{
		ans=ans/gcd(ans,step[i])*step[i];
	}
	printf("%I64d",ans);
	return 0;
}
