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
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{

	int f[103];
	int cover[103];
		int now=1;
		while(n--)
		{

		int i,j;

		memset(f,0,sizeof(f));
		int ln;
		scanf("%d\n",&ln);

		memset(cover,0,sizeof(cover));
		char ch;
		for (i=1;i<=ln;i++)
		{

			scanf("%c",&ch);
			if(ch=='.') f[i]=1;


		}
			scanf("%c",&ch);
		//for (i=1;i<=ln;i++) printf("f=%d\n",f[i]);
		int count=0;
		for (i=1;i<=ln;i++){
			if(f[i]==1 && cover[i]==0)
			{
				cover[i]=cover[i+1]=cover[i+2]=1;
				//printf("i=%d\n",i);
				count++;
			}
		}
		printf("Case %d: %d\n",now++,count);
		}
	}
	return 0;
}
