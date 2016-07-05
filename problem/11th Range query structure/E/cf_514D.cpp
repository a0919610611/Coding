/*************************************************************************
	> File Name: cf_514D.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月25日 (週一) 22時31分17秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int f[6][100000+10][100];
int num[6][100000+10];
vector<int>anss(6);
int ans=INT_MIN;
void RMQ_init()
{
    int i,j;
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
        {
            f[j][i][0]=num[j][i];
        }
    }
  
    int l;
    for(l=1;l<=m;l++)
    {
        for(j=1;(1<<j)<=n;j++)
        {
            for(i=1;(i+(1<<j)-1)<=n;i++)
            {
                f[l][i][j]=max(f[l][i][j-1],f[l][i+(1<<(j-1))][j-1]);
            }
        }
    }
}
int query(int num,int l ,int r)
{   
   // cout<<"query"<<endl;
    int t=0;
   while((1<<(t+1))<=r-l+1)t++;
   // cout<<f[num][l][t]<<" "<<f[num][r-(1<<t)+1][t]<<endl;
    return max(f[num][l][t],f[num][r-(1<<t)+1][t]);
}
int check(int mid)
{
    int i;
    vector<int> tmp(6);
    for(i=1;i+mid-1<=n;i++)
    {
        int used=0;
        for(int j=1;j<=m;j++)
        {
            int tmpp=query(j,i,i+mid-1);
            used+=tmpp;
            tmp[j]=tmpp;
        }
        if(used<=k) 
        {
            if(mid>=ans)
            {
                ans=mid;
                anss=tmp;
            }
            return true;
        }
    }
    return false;
}
int main()
{
    op_io;
    cin>>n>>m>>k;
    int i;
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>num[j][i];
    }
    RMQ_init();
    int ans =INT_MIN;
    int l=0;
    int r=n;
    int len=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
        }else
        {
            r=mid-1;
        }
    }
    for(i=1;i<=m;i++)
    {
        if(i>1) cout<<" ";
        cout<<anss[i];
    }
    return 0;
}
