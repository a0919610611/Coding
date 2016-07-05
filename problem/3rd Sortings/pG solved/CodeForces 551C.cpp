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
using namespace std;
typedef long long lld;
int main()
{	int n,num_s,i;
	scanf("%d %d",&n,&num_s);
	lld p[100000+1];
	lld max_sec=0;
	lld end_s;
	for (i=1;i<=n;i++){
		scanf("%I64d",&p[i]);
		max_sec+=p[i];
		if (p[i]) end_s=i;
	}
	lld ans=max_sec;
	max_sec+=end_s;

	lld min_sec=end_s+1;
//printf("%d %d",max_sec,min_sec);
	lld mid_sec;
	lld flag;
	while(min_sec<=max_sec )
	{
		//printf("hi\n");
		mid_sec=(max_sec+min_sec)/2;
		lld s=1;
		lld remain=mid_sec;
		lld temp;
		lld total=0;
		flag=0;
		for (i=1;i<=end_s;i++)
		{	remain--;
			temp=p[i];
			while(temp!=0)
			{
			if(remain>=temp){
				remain-=temp;
				total+=temp;
				temp=0;
			}else{
				total+=remain;
				temp=temp-remain;

				remain=mid_sec-i;
				if (remain==0) {flag=1;break;}
				s++;
			}
			//printf("remain is %d temp is %d i is %d mid_sec is %d\n",remain,temp,i,mid_sec);
			}
			//printf("%d\n",flag);
			if (flag) break;
		}
		//printf("%d %d %d %d\n",s,flag,min_sec,max_sec);
		if (max_sec==min_sec) break;
		if (s>num_s||flag==1) min_sec=mid_sec+1;
		else if (s<=num_s) max_sec=mid_sec;


	}
printf("%I64d\n",mid_sec);
	return 0;
}
