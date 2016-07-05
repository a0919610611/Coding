/*************************************************************************
	> File Name: UVA_11576.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月19日 (週二) 20時02分53秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
vector<int> pre(const string & str)
{
    vector<int>next(str.size()+1);
    next[0]=-1;
    int i=0,k=-1;
    while(i<str.size()-1)
    {
        if(k==-1 || str[i]==str[k])
        {
            next[++i]=++k;
        }else
        {
            k=next[k];
        }
    
    }
    return next;
}
int KMP(const string & s,const string &p,vector<int>&next)
{
    int i=0,j=0;
    int s_size=s.size();
    int p_size=p.size();
    while(i<s_size && j<p_size)
    {
//        cout<<"1"<<"i="<<i<<" j="<<j<<endl;
        if((j==-1)|| s[i]==p[j])
        {
            i++;
            j++;
        }else
        {
            j=next[j];
        }
 //       cout<<"2"<<"i="<<i<<" j="<<j<<endl;
    }
    return j;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {   
        int ln,n;
        cin>>ln>>n;
        vector<string> s;
        for(int i=0;i<n;i++)
        {
            string in;
            cin>>in;
            if(s.size() &&s.back()==in) continue;
            else s.push_back(in);
        }
        int ans=s[0].size();
        for(int i=1;i<s.size();i++)
        {
        vector<int> next=pre(s[i]);
        int t=KMP(s[i-1],s[i],next);
        ans+=ln-t;
        }  
        cout<<ans<<endl;
    }
    return 0;
}
