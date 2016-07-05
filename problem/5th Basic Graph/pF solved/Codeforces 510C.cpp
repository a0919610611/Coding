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

typedef long long LL;
typedef pair<int,int> pii;
int main()
{
	op_io;
	char str[101][101];
	char ans[101]={};
	bool f[150][150]={};
	int lo[150]={};
	int n;
	//printf("%d %d",'z','a');
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		cin>>str[i];
		//cout<<str[i]<<endl;
	}
	for (i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=0;str[i][k];k++)
			{
				if(!str[j][k])
				{
					puts("Impossible");
					return 0;
				}
				if(str[j][k]!=str[i][k])
				{
				int x,y;
				x=str[i][k],y=str[j][k];
				if(!f[x][y]) lo[y]++;
				f[x][y]=true;
				break;
				}
			}
		}
	}
	int index=0;
	for (i='a';i<='z';i++)
	{
		if(!lo[i])
		{
			ans[index++]=i;
		}
	}

	for (i=0;i<index;i++)
	{
		int c=ans[i];
		for(j='a';j<='z';j++)
		{
			if(f[c][j])
			{
				lo[j]--;
				//printf("%c %d\n",j,lo[j]);
				if(lo[j]==0) ans[index++]=j;
			}
		}
	}
	//cout<<index;
	if(index<=25) {puts("Impossible");return 0;}
	ans[index]='\0';
	puts(ans);
	//for(i=0;i<=index;i++)
	//{
		//printf("%c",ans[i]);
	//}
	return 0;
}
