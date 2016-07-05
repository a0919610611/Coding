#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct Leg{
	int l;
	int d;
};
bool cmp(Leg l1,Leg l2){
	return l1.l<l2.l;
}
int main(){
	int n;
	Leg leg[100000+1];
	int i;
	scanf("%d",&n);
	int total=0;
	for (i=1;i<=n;i++) scanf("%d",&leg[i].l);
	for (i=1;i<=n;i++) {scanf("%d",&leg[i].d);total+=leg[i].d;}
	//printf("hi");
	int ans=total;
	int cost;
	int cnt[201];
	int j;
	int num;
	sort(leg+1,leg+n+1,cmp);

	//printf("yo");
	i=1;
	int temp;
	//printf("ans=%d\n",ans);
	memset(cnt,0,sizeof(cnt));
	while(i<=n){
		cost=total;
		//printf("%d\n",cost);
			num=0;
		for (temp=i;leg[temp].l==leg[i].l;temp++)
		{
			cost-=leg[temp].d;
			num++;
		}
		num--;
		for (j=200;j>=1 && num>0;j--){
			cost-=min(num,cnt[j])*j;
			num-=cnt[j];
		}
		ans=min(cost,ans);
		//printf("ans=%d\n",ans);
		for (temp=i;leg[temp].l==leg[i].l;temp++)
			cnt[leg[temp].d]++;
			i=temp;
	}
	printf("%d\n",ans);
    return 0;
}
