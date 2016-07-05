/*************************************************************************
	> File Name: cf_456B.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 廿十六年五月三日 (週二) 十七時38分九秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    op_io;
    LL ans=0;
    int d;
    long long table[5][10]={};
    for(int i=0;i<=3;i++) table[1][i]=1;
    table[2][1]=2;table[2][2]=4;table[2][3]=3;table[2][0]=1;
    table[3][1]=3;table[3][2]=4;table[3][3]=2;table[3][0]=1;
    table[4][1]=4;table[4][2]=1;table[4][3]=4;table[4][0]=1;
    int index=0;
    int in;
    while(scanf("%1d",&in)!=EOF)
    {
        index=index*10%4;
        index=(index+in)%4;
    }
    ans=table[1][index]+table[2][index]+table[3][index]+table[4][index];
    cout<<ans%5<<endl;
    return 0;
}
