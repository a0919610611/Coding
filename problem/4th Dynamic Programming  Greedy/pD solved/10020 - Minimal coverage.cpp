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
bool cmp(pii a,pii b)
{
	if (a.F<b.F) return true;
	else
	{
		if(a.F==b.F)
		{
			if(a.S<b.S)return true;
			else return false;
		}
	}
}
int l;
int main()
{
	int n,m,i,j,k;

	while(scanf("%d",&n)!=EOF)
	{



	while(n--)
	{
		//printf("m=%d\n",m);


		scanf("%d",&m);
		pii p[100000+1];

		int a,b;
		int num=1;
		while(scanf("%d%d",&a,&b) )
		{
			if(a==0 & b==0) break;
			p[num].F=a,p[num].S=b;
			num++;
		}
		num--;
		sort(p+1,p+1+(num));
		for (i=1;i<=num;i++)
		//{
			//printf("%d %d\n",p[i].F,p[i].S);
		//}



		l=0;
		int right=0;
		int count=0;
		int now=1;
		int List[100001],l_index=0;
		while(right<m)
		{

			int max=0;
			int index;
			int flag=1;
			for(i=l;p[i].F<=right&&i<=num;i++)
			{

				if( p[i].S>max)
				{
					max=p[i].S;
					index=i;
					flag=0;
				}

			}
			if(flag) {count=0; break;}
			l=i;
			right=p[index].S;
			List[l_index++]=index;
			count ++;
		}
		printf("%d\n",count);
		if(count)
		{
			for(i=0;i<l_index;i++)
                printf("%d %d\n",p[List[i]].F,p[List[i]].S);
		}
		if (n)printf("\n");
	}
	}
	return 0;
}
