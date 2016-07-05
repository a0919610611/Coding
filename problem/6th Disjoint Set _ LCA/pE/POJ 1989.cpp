//#define txt     //use freopen
//#pragma comment(linker, "/STACK:1024000000,1024000000")  //op
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
#ifdef LOCAL
#define op_io ios_base::sync_with_stdio(0);
#else
#define op_io ios_base::sync_with_stdio(0);cin.tie(0);
#endif
#define endl "\n"
#define F first
#define S second
#define MAXN 200005

typedef long long LL;
typedef pair<int,int> pii;
int main()
{
	op_io;
	int N,K;
	cin>>N>>K;
	int i;
	int* cow=new int [N+1];
	bool used[10000+1]={};
	for(i=1;i<=N;i++)
	{
		cin>>cow[i];
	}
	int j;
	int ans=1;
	int count=0;
	for(i=1;i<=N;i++)
	{
		if(!used[cow[i]])
		{
			count++;
			used[cow[i]]=1;
		}
		if(count==K)
		{
			ans++;
			memset(used,0,sizeof(used));
			count=0;
		}

	}
	cout<<ans<<endl;
	return 0;
}
