/*************************************************************************
	> File Name: uva_12086.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月23日 (週六) 21時59分41秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int n;
inline int lowbit(int x)
{
    return x&(-x);
}
void update(vector<int>& num,int location,int value,vector<int>& sum)
{   
    int res=value-num[location];
    num[location]=value;
    while(location<= n)
    {
        sum[location]=sum[location]+res;
        location+=lowbit(location);
    }
}
int getsum(vector<int> & num ,vector<int>& sum, int r )
{
        int ans=0;
        while(r>0)
        {
            ans+=sum[r];
            r-=lowbit(r);
        }
        return ans;
        
}
int main()
{
    op_io;
    int kase=0;
    while(cin>>n && n)
    {
        if(kase++) cout<<endl;
        cout<<"Case "<<kase<<":"<<endl;
        vector<int>num(n+1,0);
        for(int i=1;i<=n;i++) cin>>num[i];
        int m=1;
        while(m<n+2) m<<=1;
        vector<int>sum(m);
        for(int i=1;i<=n;i++)
        {
            int t=i;
            while(t<=n)
            {
                sum[t]+=num[i];
                t+=lowbit(t);
            }
        }
        string in;
        while(cin>>in && in!="END")
        {   
            int a,b;
            cin>>a>>b;
            if(in[0]=='M')
            {
                cout<<getsum(num,sum,b)-getsum(num,sum,a-1)<<endl;
            }else
            {
                update(num,a,b,sum);   
            }
        }
    }
    return 0;
}
