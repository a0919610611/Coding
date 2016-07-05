#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int main(){
    int ans[51];
    long long int n,k;
    scanf("%I64d %I64d",&n,&k);
    long long int m;
    m=pow(2,n-1);
   int bot_now=1;
   int top_now=n;
   int i;
   long long int a;

   a=m/2;
   for (i=1;i<=n;i++){
        m=m/2;
    if(k>a){
        ans[top_now]=i;
        top_now--;
        a=a+m/2;
    }else{
        ans[bot_now]=i;
        bot_now++;
        a=a-m/2;
    }

   }
   for (i=1;i<=n;i++){
        if (i<n)printf("%d ",ans[i]);
        else printf("%d",ans[i]);
   }
    return 0;
}
