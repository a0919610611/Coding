#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int a[100000+1]={0};
int total[100000+1]={0};
int ans(int q);
int start,end;

int main(){

	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}

	for (i=1;i<=n;i++){
		total[i]=total[i-1]+a[i];
	}
	int m;
	scanf("%d",&m);
	while(m--){
			int q;
		scanf("%d",&q);
		start=1;
		end=n;
		//printf("%d %d\n",start,end);
		printf("%d\n",ans(q));


	}
    return 0;
}
int ans(int q)
{
	if (start>end) return 0;
	int now=(start+end)/2;
	//printf("now=%d",now);
	if (total[now]==q) return now;
	else if (total[now-1]<q && q<total[now])return now;
	else if(q>total[now]) start=now+1;
	else end=now;
	ans(q);
}
