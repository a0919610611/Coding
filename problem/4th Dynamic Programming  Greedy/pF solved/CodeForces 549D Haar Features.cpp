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
using namespace std;
typedef long long lld;
typedef pair<int,int> pii;
int p[105][105]={};
int ans[105][105]={};
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	getchar();
	int i,j;
	for( i=1;i<=n;i++)
	{
		for ( j=1;j<=m;j++)
		{
			char ch;
			scanf("%c",&ch);
			p[i][j]=(ch=='W')?1:-1;
		}
		getchar();
	}
	//for( i=1;i<=n;i++)
	//{
	//	for ( j=1;j<=m;j++)
	//	{
	//		printf("%d",p[i][j]);
	//	}
	//	printf("\n");
	//}
	int count=0;
	int k,l,o;
	for (i=n,j=m;;)
	{
		for (k=j;k>=1;k--){
			if(ans[i][k]!=p[i][k])
			{
				count ++;
				for (l=1;l<=i;l++){
					for (o=1;o<=k;o++){
						ans[l][o]+=(p[i][k]-ans[i][k]);
					}
				}
			}
		}
		for (k=i;k>=1;k--){
			if(ans[k][j]!=p[k][j])
			{
				count ++;
				for (l=1;l<=k;l++){
					for (o=1;o<=j;o++){
						ans[l][o]+=(p[k][j]-ans[k][j]);
					}
				}
			}
		}
		if(j==1 && i==1) break;
		if(i>1) i--;
		if(j>1) j--;

	}
	//for( i=1;i<=n;i++)
	//{
		//for ( j=1;j<=m;j++)
		//{
		//	printf("%d",ans[i][j]);
		//}
		//printf("\n");

	//}
	printf("%d\n",count);
	return 0;
}
