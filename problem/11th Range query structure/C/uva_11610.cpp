/*************************************************************************
	> File Name: uva_11610.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月24日 (週日) 17時43分48秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000;
vector <int > prime;
int factor[1000000+1];
int num_fac[1000000+1];
int k;
map<int,int> no;
void init()
{   
    for(int i=2;i<MAXN;i++)
    {
        if(!factor[i]) prime.push_back(i);
        for(int j=0;i*prime[j]<MAXN;j++)
        {
            factor[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    vector<int> reverse_prime;
    for(int i=0;i<prime.size();i++)
    {   
        int bit[7]={};
        int num=prime[i];
        int index=0;
        while(num>0)
        {
            bit[++index]=num%10;
            num/=10;
        }
        int tmp=0;
        for(int j=1;j<=6;j++) 
        {
	    tmp*=10;
            tmp+=bit[j];
            
        }
        reverse_prime.push_back(tmp);
    }
        sort(reverse_prime.begin(),reverse_prime.end());
        for(int i=0;i<reverse_prime.size();i++) 
        {
            int tmp=reverse_prime[i];
        no[tmp*10]=++k;
        num_fac[k]=2;
        while(tmp>1)
        {
            if(!factor[tmp])
            {
                num_fac[k]++;
                break;
            }else
            {
                num_fac[k]++;
                tmp/=factor[tmp];
            }
            
        }

    }
  // for(int i=0;i<3;i++) cout<<reverse_prime[i]<<" "<<num_fac[i+1]<<endl;
}
int lowbit(int x)
{
    return x& (-x);
}
void update(int *s ,int x,int val)
{
    for(int i=x;i<=k;i+=lowbit(i))
        s[i]+=val;
}
int sum(int *s ,int x)
{
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i))
    {
      res+=s[i];
    }
     return res;
}
int s1[1000000];
int s2[1000000];
int main()
{
//    op_io;
    init();
    int i;
    for(i=1;i<=k;i++) update(s1,i,1);
    for(i=1;i<=k;i++) update(s2,i,num_fac[i]);
    string in;
  //  cout<<"hi"<<endl;
    while(cin>>in)
    {
        if(in[0]=='q')
        {	
            int index;
            cin>>index;
            int t=index+1;
            int left=1,right=k,mid;
            while(left<=right)
            {
              mid=(left+right)>>1;
              int tmp=sum(s1,mid);
              if(tmp==t) break;
              if(tmp<t) left=mid+1;
              else right=mid-1;
            }
            cout<<sum(s2,mid)<<endl;
        }else
        {
            int d_number;   
            cin>>d_number;
            int pos=no[d_number];
            update(s1,pos,-1);
            update(s2,pos,-num_fac[pos]);

        }
    }
    return 0;
}
