#include<cstdio>
#include <iostream>

typedef long long LL;
using namespace std;

int c[200050];

int find(int a)
{
	if(c[a]==a) return a;
	return  c[a]=find(c[a]);
}
void unit(int a,int b)
{
	int pa=find(a);
	int pb=find(b);
	if(pa==pb) return ;
	if (pa <pb)
	{
		c[pa] = pb;
	}
else
	{
		c[pb] = pa;

	}
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
		for(i=1;i<=2*N;i++)
		{
			c[i]=i;

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
				if(find(a)==find(b))
				{
					printf("In the same gang.\n");
				}
				else if(find(a)==find(b+N))
				{
					printf("In different gangs.\n");
				}else
				{
					printf("Not sure yet.\n");
				}
			}else if(q=='D')
			{
				//printf("hi");
				unit(a+N,b);
				unit(a,b+N);
			}
		}
	}

	return 0;
}


