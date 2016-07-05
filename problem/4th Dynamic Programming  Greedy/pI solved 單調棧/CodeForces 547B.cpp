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
using namespace std;
typedef long long lld;
int s[200000+1]={};
	int l[200000+1]={};
	int r[200000+1]={};
	int res[200000+1]={};
int main()
{
	int n;
	scanf("%d",&n);

	int i,j,k;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	s[0]=s[n+1]=-1;
	for (i=1;i<=n;i++){
			int j=i-1;
		while(s[j]>=s[i]) j=l[j];
			l[i]=j;
	}
	for (i=n;i>0;i--){
		int j=i+1;
		while(s[j]>=s[i]) j=r[j];
		r[i]=j;
	}
	for(int i = 1; i <= n; i++) {
            int x = r[i] - l[i] -1;
            res[x] = max(res[x],s[i]);
        }
	  for(i=n-1;i>=1;i--){
           res[i]=max(res[i+1],res[i]);
        }
	for(i=1;i<=n;i++){
		if(i==n) printf("%d\n",res[i]);
		else printf("%d ",res[i]);
	}
	return 0;
}
