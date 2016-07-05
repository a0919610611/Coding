#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
int n,w;
int cup[200000+1];
int main(){
	scanf("%d %d",&n,&w);
	int i;
	for (i=1;i<=n*2;i++){
		scanf("%d",&cup[i]);
	}
	sort(cup+1,cup+2*n+1);
	double val;
	if(cup[1]*2>cup[n+1]) val=(double)cup[n+1]*n+(double)cup[n+1]*n/2;
	else if(cup[1]*2<=cup[n+1]) val=(double)cup[1]*n+(double)cup[1]*n*2;
	if (val>w) val=w;
	printf("%f\n",val);
    return 0;
}
