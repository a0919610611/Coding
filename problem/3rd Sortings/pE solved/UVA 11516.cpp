#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include <algorithm>
using namespace std;
int num,n,m;
void solve(int h[]);
int main(){

        scanf("%d",&num);
        int i,j,k;
        while(num--){
               static int house[100000+1];
               scanf("%d %d",&n,&m);
               for (i=1;i<=m;i++) {
                int housee;
                scanf("%d",&housee);
                house[i]=housee;
               }
               //printf("hi\n");
               //int size=sizeof(house);
              //printf("hi\n");
               sort(house,house+m+1);
               for (i=1;i<=m;i++){

               }
               int lower=0;
               //int toper=(house[m]-house[1]+1)*2;
               int toper=(house[m]-house[1]); //直徑的最大值
               int k,start,need;
               while(lower<toper){
                k=(lower+toper)/2;
                need=1;
                 start=house[1];
                for (i=2;i<=m;i++){

                        if (house[i]>start+k){
                               start=house[i];
                               need++;
                        }
                }

               if (need>n)
                lower=k+1;
               else{
                toper=k;
               }
        }
        //printf("hi\n");
        printf("%.1f\n",(double)toper/(double)2);
        }
    return 0;
}


