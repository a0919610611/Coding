#include<cstdio>
#include <iostream>

typedef long long LL;
using namespace std;

int c[100050];
int grp[100050];
int find(int a)
{
	if(c[a]==a) return a;
	else
	{
		int tmp=c[a];
		c[a]=find(c[a]);
		grp[a]=(grp[a]==grp[tmp])?0:1;
		return c[a];
	}
}
void unit(int a,int b)
{
	int pa=find(a);
	int pb=find(b);
	if(pa==pb) return ;

		c[pa]=pb;
		grp[pa]=(grp[a]==grp[b])?1:0;

}
int main()
{

	int T;
	cin>>T;
	while(T--)
	{
		int N,M;

		cin>>N>>M;
		//printf("%d%d")
		getchar();
		int i;
		for(i=1;i<=N;i++)
		{
			c[i]=i;
			grp[i]=0;

		}
		for(i=1;i<=M;i++)
		{

			char q;
			int a,b;
			scanf("%c%d%d%*c",&q,&a,&b);
			//printf("i=%d",i);
			//printf("hi%c",q);
			if(q=='A')
			{
				//printf("a=%d b=%d",a,b);
				//printf("hi");
				//printf("%d %d %d %d\n",grp[1],grp[2],grp[3],grp[4]);
				if(find(a)==find(b))
				{

					//printf("%d %d %d %d\n",grp[1],grp[2],grp[3],grp[4]);
					if(grp[a]==grp[b])
					printf("In the same gang.\n");
					else
					printf("In different gangs.\n");
				}
				else
				{
					printf("Not sure yet.\n");
				}
			}else if(q=='D')
			{
				//printf("hi");
				unit(a,b);
			}
		}
	}

	return 0;
}


