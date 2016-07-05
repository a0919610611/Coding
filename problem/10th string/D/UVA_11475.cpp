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
        if((j==-1)|| s[i]==p[j])
        {
            i++;
            j++;
        }else
        {
            j=next[j];
        }
    }
    return j;
}
int main()
{
        string s;
        while(cin>>s)
    {
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        string reverse_s=tmp;
        vector<int>next =pre(reverse_s);
        int t=KMP(s,reverse_s,next);
        string ans=s;
        for(int i=s.size()-1-t;i>=0;i--) ans+=s[i];
        cout<<ans<<endl;
    }
    return 0;
}
