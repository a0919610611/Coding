#include<cstdio>
#include<cstring>

const int N = 30;
char preOrder[N];
char midOrder[N];
char S[N];
int top;
void solve(char *pre,char *mid,int len)//len>=1
{
   S[++top] = *pre;
   char *p = mid;
   while(*p != *pre) p++;
   p++;
   int tmp = p - mid;
   if(tmp < len)
      solve(pre + tmp, p ,len - tmp);
   if(tmp > 1)
      solve(pre + 1,mid,tmp - 1);
   return ;
}


int main()
{
   int len;
   while(~scanf("%s",preOrder)){
      scanf("%s",midOrder);
      top = 0;
      len = strlen(preOrder);
      solve(preOrder,midOrder,len);
      while(top) putchar(S[top--]);
      putchar('\n');
   }
}
