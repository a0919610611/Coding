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
	const int limit=40000000;
	int n;
	cin>>n;
	int a_num,b_num;

	queue<int> a_card;

	queue<int> b_card;
	cin>>a_num;
	int i;
	int in;
	for(i=1;i<=a_num;i++ )
	{
		cin>>in;
		a_card.push(in);
	}
	cin>>b_num;
	for(i=1;i<=b_num;i++)
	{
		cin>>in;
		b_card.push(in);
	}
 int turn;
 int winner=0;
 for(turn=1;turn<=limit;turn++)
 {
 	if(a_card.empty()){winner=2; break;}
 	else if(b_card.empty()) {winner=1; break;}
 	else
	{
		int top_a=a_card.front();
		a_card.pop();
		int top_b=b_card.front();
		b_card.pop();
		if (top_a>top_b)
		{
			a_card.push(top_b);
			a_card.push(top_a);
		}else
		{
			b_card.push(top_a);
			b_card.push(top_b);
		}
	}

 }
	if(!winner) cout<<"-1";
	else cout<<turn-1<<" "<<winner<<endl;
	return 0;
}
