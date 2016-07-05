/*************************************************************************
	> File Name: POJ_3461_KMP.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月26日 (週二) 20時05分25秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include<string>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int fail[1000000+10]={};
void build_fail(const string &s)
{   
    fail[0]=-1;
    int i,j;
    j=-1;
    for(i=1;i<(int)s.size();i++)
    {
        while(j!=-1 && s[j+1]!=s[i]) j=fail[j];
        if(s[j+1]==s[i])
            j++;
        fail[i]=j;
    }
}
int kmp(const string &t,const string & w)
{
    int ln_t=t.size();
    int ln_w=w.size();
    int j=-1;
    int i=0;
    int ans=0;
    for(i=0;i<ln_t;i++)
    {
        while(j!=-1 && t[i]!=w[j+1]) j=fail[j];
        if(t[i]==w[j+1])j++;
        if(j==ln_w-1) 
        {
            ans++;
            j=fail[j];
        }
    }
    return ans;
    
}
int main()
{
    op_io;
    string w,t;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>w>>t;
        memset(fail,0,sizeof(fail));
        build_fail(w);
        cout<<kmp(t,w)<<endl;
    }
    return 0;
}
