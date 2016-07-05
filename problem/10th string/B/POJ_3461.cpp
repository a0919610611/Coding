/*************************************************************************
	> File Name: POJ_3461.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 西元2016年04月19日 (週二) 10時32分01秒
 ************************************************************************/
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
unsigned long long B=100000000+7;
int match(char * w,char *t)
{	
	int ans=0;
	unsigned long long tt=1,w_hash=0,t_hash=0;
	int ln_w=strlen(w),ln_t=strlen(t);
	for(int i=0;i<ln_w;i++)
	{	
		tt*=B;
		w_hash=w_hash*B+w[i];
		t_hash=t_hash*B+t[i];
	}
	for(int i=0;i+ln_w<=ln_t;i++)
	{
		if(w_hash==t_hash) ans++;
		if(i+ln_w<ln_t) t_hash=t_hash*B+t[i+ln_w]-t[i]*tt; 
	}
	return ans;
}
int main()
{
	int times;
	scanf("%d",&times);
	while(times--)
	{	
		char  w[10000+1],t[1000000+1];
		scanf("%s %s",w,t);


		int ans=match(w,t);
		printf("%d\n",ans);
		
	}
    return 0;
}
