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
int main()
{
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif

	int n;
	while(scanf("%d",&n) && n!=-1)
	{
		lld m=1,f=0,now=1;
		for (int i=1;i<=n;i++)
		{
			lld m_now=f+1;
			lld f_now=m+f;
			m=m_now;
			f=f_now;
		}
		printf("%lld %lld\n",f,m+f);
	}
	return 0;
}
