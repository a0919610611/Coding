#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main(){
int n,l,r,x;
        int i,j,k,m,answer,now,maxc,minc,num;
        int c[15+1];
        int d[15+1];
        scanf("%d %d %d %d",&n,&l,&r,&x);
      for (i=1;i<=n;i++) scanf("%d",&c[i]);
      //for (i=1;i<=n;i++) printf("%d",c[i]);
     answer=0;
     int a;
     a=pow(2,n);
     //printf("%d",a);
        for (j=1;j<=a;j++){
                //printf("%d",i);
                i=j;
                now=0;
                k=n;
        while(i>0){
                d[k]=i%2;
                i=i/2;
                k--;
        }
        if (i==1){
        d[k]=1;
        k--;}
        else {
                d[k]=0;
                k--;
        }
        for (;k>=1;k--){
                d[k]=0;
        }
        maxc=0;
        minc=1000000+1;
        num=0;
        for (m=1;m<=n;m++){

        if (d[m]){
                now=now+(c[m]*d[m]);
                if (c[m]>maxc) maxc=c[m];
                if (c[m]<minc) minc=c[m];
                num++;
        }
       }
       if ((now>=l)&&(now<=r) && ((maxc-minc)>=x) && (num>=2)){

        answer++;
       }
       }
      printf("%d",answer);
    return 0;
}

