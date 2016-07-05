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
#define MAXN 200005
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Ran
{
	LL no,l,r;
};
struct brg
{
	LL l,no;

};
int n,m;
bool operator < ( brg a, brg b) {return a.l<b.l;}
bool operator < (Ran r1, Ran r2)
{
    return r1.r < r2.r;
}
Ran ran[MAXN];
brg b[MAXN];
multiset<brg> Brg;
int main()
{

	scanf("%d%d",&n,&m);
	int i,j;
	LL x,y,x2,y2;
	scanf("%I64d%I64d",&x2,&y2);
	for (i=0;i<n-1;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		ran[i].no=i;
		ran[i].l=x-y2;
		ran[i].r=y-x2;
		x2=x;
		y2=y;
	}
	for(i=0;i<m;i++)
	{
		scanf("%I64d",&b[i].l);
		b[i].no=i;
	}
	sort (ran,ran+n-1);
	sort(b,b+m);


	LL ans[MAXN];
	Brg.clear();
	for (i=0;i<m;i++)
	{
		Brg.insert(b[i]);
	}
	int flag=1;
	for (i=0;i<n-1;i++)
	{
		brg value;
		value.l=ran[i].l;
		multiset<brg>::iterator it =Brg.lower_bound(value);
		//printf("%I64d\n",(*it).l);
		if((*it).l<value.l ||(*it).l>ran[i].r)
		{
			//printf("%I64d %I64d i=%d",(*it).l,p[i+1].r-p[i].l,i);
			printf("No\n");
			flag=0;
			break;
		}
		ans[ran[i].no]=(*it).no;
		Brg.erase(it);
	}
	if(flag)
	{
		printf("Yes\n");
		for(i=0;i<n-1;i++)
		{
			if(i>0)
				printf(" ");
			printf("%I64d",ans[i]+1);
		}
		printf("\n");
	}
	return 0;
}
