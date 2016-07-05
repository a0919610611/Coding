#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int n,l;
	int p[1000+1];
	scanf("%d %d",&n,&l);
	int i,j;
	for (i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	sort(&p[1],&p[1]+n);
	double max=0;
	for (i=1;i<n;i++){
		if (p[i+1]-p[i]>max) max=p[i+1]-p[i];
	}
	int dis_l=l-p[n];
	int dis_s=p[1];
	//printf("%d",dis_s);
	max/=2;
	if (dis_l>max) max=dis_l;
	if (dis_s>max) max=dis_s;
	printf("%f\n",max);

    return 0;
}
