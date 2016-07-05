/*************************************************************************
	> File Name: uva_10104.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 廿十六年五月三日 (週二) 十九時十九分十一秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b,long long &i,long long &j)
{
    if(b==0)
    {
        i=1;
        j=0;
        return a;
    }else
    {
     long long g=   gcd(b,a%b,j,i);
        j=j-(a/b)*i;
        return g;
    }
}
int main()
{
    op_io;
    long long a,b,i,j;
    while(cin>>a>>b)
    {
        long long g=gcd(a,b,i,j);
        cout<<i<<" "<<j<<" "<<g<<endl;
    }
    return 0;
}
