#include <bits/stdc++.h>
using namespace std;
int solve(const string & in)
{
    string  s="$";
    for(int i=0;i<in.size();i++)
    {
        s.push_back('#');
        s.push_back(in[i]);   
    }
    s.push_back('#');
    int mx=0,id=0,ans=1;
    vector <int> len(s.size()+1);
    for(int i=0;i<s.size();i++)
    {
        if(mx>i) len[i]=min(len[id*2-i],mx-i);
        else len[i]=1;
        while(s[i-len[i]]==s[i+len[i]]) len[i]++;
        if(i+len[i]>mx) mx=i+len[i],id=i;
        ans=max(ans,len[i]);
    }
    return ans-1;
}
int main()
{
    string in;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>in)
    {
        int ans=solve(in);
        cout<<ans<<endl;
    }
    return 0;
}
