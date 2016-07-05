#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int road[6][6]={0};
int out[10]={0};
int times;


void ans(int a,int b){

        if (b==9){
                for (int k=1;k<=9;k++){
                                int outt;
                outt=out[k]+'0';
                printf("%c",(char)outt);

                }

                printf("\n");


        }
        // if (many(a)){
                //return false;
         //}


        for (int i=1;i<=5;i++){
                if (road[a][i]){
                        out[b+1]=i;
                road[a][i]=road[i][a]=0;
                    ans(i,b+1);
                road[a][i]=road[i][a]=1; // 還原 重要!!


                }
        }

}

int main(){
         road[1][2]=1;
       road[2][1]=1;
        road[2][3]=1;
        road[3][2]=1;
        road[3][5]=1;
        road[5][3]=1;
        road[5][1]=1;
        road[1][5]=1;
        road[5][4]=1;
        road[4][5]=1;
        road[3][4]=1;
        road[4][3]=1;
        road[5][2]=1;
        road[2][5]=1;
        road[3][1]=1;
        road[1][3]=1;

        out[1]=1;
        ans(1,1);

    return 0;
}
