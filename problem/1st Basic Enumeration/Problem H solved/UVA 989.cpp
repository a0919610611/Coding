#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
int box[10][10]={0,0};
int visit[10][10][10]={0};
 int n;
 int Case=0;
int exist;
using namespace std;
void backtracking(int currentstep,int a, int b);
int main(){
        int i,j,k,l,m;

        while(scanf("%d",&n)!=EOF){

        exist=0;
        for (i=1;i<=n*n;i++){
                for (j=1;j<=n*n;j++){
                       scanf("%d",&box[i][j]);
                }
        }
        if (Case++) putchar('\n');
        //if (!visit[1][1][3]) printf("hi");
        //printf("hi");
       // printf("%d",visit[2][5][8]);
        for (i=1;i<=n*n;i++){
                for (j=1;j<=n*n;j++){
                        if (box[i][j]){
                                for (l=1;l<=n*n;l++){
                                        visit[i][l][box[i][j]]=1;
                                        visit[l][j][box[i][j]]=1;
                                }
                               int a;
                               int b;
                               a=(i-1)/n;
                               b=(j-1)/n;
                               //printf("a=%d b=%d",a,b);
                               for (l=(a*n+1);l<=((a+1)*n);l++){
                                for (m=(b*n+1);m<=((b+1)*n);m++){
                                        visit[l][m][box[i][j]]=1;
                                }
                               }
                        }
                }
        }

        //printf("hi");
        //if (visit[1][1][3]) printf("hi");
        //printf("%d",visit[2][5][8]);
        backtracking(1,1,1);
        if (exist==0){
                printf( "NO SOLUTION\n" );
        }
        //printf("%d",box[1][1]);
        }
        //printf("hi");
    return 0;
}
void backtracking(int currentstep, int a,int b){
        int i,j,k,l,m,num;

        if (box[a][b]!=0){
                        if (currentstep==n*n*n*n && exist==0){
                                for (i=1;i<=n*n;i++){
                                        for (j=1;j<=n*n;j++){
                                        if(j!=n*n){
                                        printf("%d ",box[i][j]);
                                        }
                                        else{
                                                printf("%d\n",box[i][j]);
                                        }
                                }


                                }
                                 exist++;
                                 return;
                                }
                if (!exist){
                if ((b+1)<=n*n){
                backtracking(currentstep+1,a,b+1);
                }else {
                backtracking(currentstep+1,a+1,1);
                }
                }
        }else if (exist==0){

                num=0;
             for (i=1;i<=n*n;i++){


                               for (l=1;l<=n*n;l++){
                        for (j=1;j<=n*n;j++){
                                for (k=1;k<=n*n;k++){
                                        visit[l][j][k]=0;
                                }
                        }
                }
                 for (k=1;k<=n*n;k++){
                for (j=1;j<=n*n;j++){
                        if (box[k][j]){
                                for (l=1;l<=n*n;l++){
                                        visit[k][l][box[k][j]]=1;
                                        visit[l][j][box[k][j]]=1;
                                }
                               int c;
                               int d;
                               c=(k-1)/n;
                               d=(j-1)/n;

                               for (l=(c*n+1);l<=((c+1)*n);l++){
                                for (m=(d*n+1);m<=((d+1)*n);m++){
                                        visit[l][m][box[k][j]]=1;
                                }
                               }
                        }
                }
                 }
                if (!visit[a][b][i]){
                               num++;
                                box[a][b]=i;

                        visit[a][b][i]=1;

                        if (currentstep<n*n*n*n){
                        if ((b+1)<=n*n){
                        backtracking(currentstep+1,a,b+1);
                        if (exist==0){
                         box[a][b]=0;
                        visit[a][b][i]=0;
                        }
                        }else {
                        backtracking(currentstep+1,a+1,1);
                        if (exist==0){
                         box[a][b]=0;
                        visit[a][b][i]=0;
                        }
                        }

                        }else{    if (exist==0){
                                  for (k=1;k<=n*n;k++){
                                        for (j=1;j<=n*n;j++){
                                        if(j!=n*n){
                                        printf("%d ",box[k][j]);
                                        }
                                        else{
                                                printf("%d\n",box[k][j]);
                                        }
                                }
                                }
                                exist++;

                        }
                        }
                }

             }
                if (num==0){
                        return;
                }
        }

}
