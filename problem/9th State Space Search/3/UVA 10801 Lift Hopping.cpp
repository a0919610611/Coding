//#define txt     //use freopen
//#pragma comment(linker, "/STACK:1024000000,1024000000")  //op
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif
#include<bits/stdc++.h>
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
#define INF 100000000
typedef long long LL;
typedef pair<int,int> pii;
int main()
{
	op_io;
	int n,k;
	int T[6]={};
	int dis[100]={};
	int w[100][100]={};
	while(cin>>n>>k)
	{
		int i,j,h;
		for(i=0;i<100;i++) dis[i]=INF;
		for(i=0;i<100;i++)
			for(j=0;j<100;j++) w[i][j]=INF;
		for(i=1;i<=n;i++) cin>>T[i];
			cin.ignore();
		for(h=1;h<=n;h++)
		{


		char input[200];
		cin.getline(input,200);

		stringstream ss;
		ss.str(input);
		int in;
		vector<int> e;
		while(ss>>in)
		{
			e.push_back(in);
		}
		for(i=0;i<e.size();i++)
		{
			for(j=i+1;j<e.size();j++)
			{
				w[e[i]][e[j]]=min(w[e[i]][e[j]],(e[j]-e[i])*T[h]);
				w[e[j]][e[i]]=w[e[i]][e[j]];
			}
		}
		}
		queue<int> q;
		dis[0]=0;
		q.push(0);
		bool inq[101]={};
		inq[0]=true;
		while(!q.empty())
		{

			int t=q.front();
		//	cout<<"t= "<<t<<endl;
			q.pop();
			inq[t]=false;
			for(i=0;i<100;i++)
			{
				if(dis[t]+w[t][i]+60<dis[i])
				{
					dis[i]=dis[t]+w[t][i]+60;
					//cout<<t<<" "<<i<<" "<<dis[i]<<endl;
					if(inq[i]==false)
					{
						q.push(i);
						inq[i]=true;
					}
				}
			}
		}
		if(k==0) cout<<0<<endl;
		else if(dis[k]==INF)cout<<"IMPOSSIBLE"<<endl;
		else cout<<dis[k]-60<<endl;
	}

	return 0;
}
