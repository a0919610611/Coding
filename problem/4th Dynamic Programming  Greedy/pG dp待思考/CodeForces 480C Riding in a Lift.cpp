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
/////////////////////////////////
#define F first
#define S second
#define MOD 1000000007
using namespace std;
typedef long long lld;
typedef pair<int,int> pii;
int n,a,b,k,i,j;
lld dp[5000+1][5000+1]={0};
lld sum[5000+1];
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	//printf("%d\n",sum[b-1]);
	if(a>b){a=n-a+1,b=n-b+1;} //a!=0 b!=0; change
	//if(a>b){swap(a,b);}
		//printf("a=%d b=%d\n",a,b);
		dp[0][a]=1;
		//for (i=1;i<b;i++)
		for (i=1;i<b;i++) sum[i]=sum[i-1]+dp[0][i];
		//for (i=1;i<b;i++) printf("sum[%d]=%d\n",i,sum[i]);
		for (i=1;i<=k;i++)
		{
			//printf("%d\n",i);
			for (j=1;j<b;j++)
			{
				dp[i][j]=(sum[(b+j-1)/2]-dp[i-1][j]+MOD)%MOD; //>0
			}
			sum[0]=0;
			for (j=1;j<b;j++)
				//printf("dp=%d\n",dp[i][j]);
			for (j=1;j<b;j++)
			sum[j]=(sum[j-1]+dp[i][j])%MOD;
			//for (j=0;j<b;j++) printf("j=%d sum=%d\n",j,sum[j]);
		}
		printf("%d\n",sum[b-1]);//max=b-1;(b>a)


	return 0;
}
