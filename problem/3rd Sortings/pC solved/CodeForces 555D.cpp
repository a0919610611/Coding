#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>
//#include <pair>
#define F first
#define S second
using namespace std;
pair<int,int> peg[200000+1];
int x[200000+1],idx[200000+1],mp[200000+1];
int main()
{	int n,m,i,j;
	scanf("%d %d",&n,&m);

	for (i=1;i<=n;i++) {
			scanf("%d",&peg[i].F);
			peg[i].S=i;
			}

	sort(peg+1,peg+1+n);
	for (i=1;i<=n;i++){
		x[i]=peg[i].F;
		idx[i]=peg[i].S;
		mp[peg[i].S]=i;
	}
	int p,l;
	for (i=1;i<=m;i++){
		if(n==1) {printf("1\n");continue;}
		scanf("%d %d",&p,&l);
		int start,end;
		int type=1;
		start=mp[p];
		end=n;
		int ans;
		//printf("hi\n");
		int id=upper_bound(x+1,x+n+1,x[start]+l)-x-1;
		l-=x[id]-x[start];
		type=2; end=id;
		if (l>=x[n]-x[1]){
			int q=l/(x[n]-x[1]);
			if (q%2) start=1,type=1;
			else end=n,type=2;
			l-=q*(x[n]-x[1]);
		}

		while(1){

			if (type==1){

				id=upper_bound(x+1,x+n+1,x[start]+l)-x-1;


				if (id==start||x[id]==x[start]+l){ans=id; break;}
				if (x[id]-x[start]>=l/2)
				{
					l=l-(x[id]-x[start]);
					end=id;
					type=2;
					continue;
				}
				int temp=x[id]-x[start];
				int q=l/temp;
				if (q%2) end=id,type=2,l-=q*temp;
				else l-=q*temp;

			}
			else
			{
				id=lower_bound(x+1,x+n+1,x[end]-l)-x;

				if (id==end||x[id]==x[end]-l){ans=id; break;}
				if (x[end]-x[id]>=l/2)
				{
					l=l-(x[end]-x[id]);
					start=id;
					type=1;
					continue;
				}
				int temp=x[end]-x[id];
				int q=l/temp;
				if (q%2) start=id,type=1,l-=q*temp;
				else l-=q*temp;
			}
		}
		printf("%d\n",idx[ans]);
	}
    return 0;
}
