#include<cstdio>
int c[30001];
int l[30001];
int d[30001];
int find(int a)
{
	if (c[a]==a) return a;
	int tmp;
	tmp=c[a];
	c[a]=find(tmp);
	d[a]+=d[tmp];
	return c[a];
}
void Union(int a, int b)
{
	int pa=find(a);
	int pb=find (b);
	if(pa==pb) return ;
	c[pb]=pa;
	d[pb]=l[pa];
	l[pa]+=l[pb];

}
int main()
{
	int i;
	for(i=1;i<=30000;i++)
	{
		c[i]=i;
		l[i]=1;
	}
	int T;
	scanf("%d",&T);
	getchar();
	for(i=1;i<=T;i++)
	{

		char ch;
		scanf("%c",&ch);
		if(ch=='M')
		{
			//printf("hi");
			int a,b;
			scanf("%d%d%*c",&a,&b);
			Union(a,b);
		}else
		{
			int q;
			scanf("%d%*c",&q);
			int qq=find(q);
			printf("%d\n",l[qq]-d[q]-1);
		}
	}
	return 0;
}
