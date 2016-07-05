#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int step;
int box[11][11];
int num[11];
int findans();
bool light(int a);
int main(){
        int i,j,k;
    char input[1];
    char name[100];
    while(1)
{
        scanf("%s",name);
        //printf("%s",name);
        //printf("%d",strncmp(name,"end",3));
if (strncmp(name,"end",3)==0) return 0;
scanf("\n");
    for (i=1;i<=10;i++){
        for (j=1;j<=10;j++){
                if (scanf("%c",input)){
                        if (input[0]=='#'){
                    box[i][j]=1;
                        }
                    else{
                box[i][j]=0;
                }
                }
        }
        if (i!=10)
         scanf("\n");
    }
    // for (i=1;i<=10;i++){
       //for (j=1;j<=10;j++){

                   // printf("%d",box[i][j]);

                //}
        //printf("\n");
    //}
    //}
    int output;
    output=findans();
    printf("%s %d\n",name,output);

}
return 0;
}
int findans(){
        int i,j,k,l,m,n;
        int box2[11][11];
        int min_step=1000000;

        for (k=0;k<=1024;k++){
                        step=0;
                for (i=1;i<=10;i++){
                for (j=1;j<=10;j++)
                box2[i][j]=box[i][j];
        }
               for (i=0;i<10;i++) {
                num[i+1]=((k>>i) & 1);
               }
                if (light(1)){
                                //printf("hi");
                       if (step<min_step) min_step=step;
                }
                  for (i=1;i<=10;i++){
                for (j=1;j<=10;j++)
                box[i][j]=box2[i][j];
        }
        }
        return min_step;
}
bool light(int a){
        int i,j,k,l,m,n;

        if (a==1){
                for (i=1;i<=10;i++){
                                if (num[i]){
                        if (i==1){
                                box[1][1]=(box[1][1]^1);
                                box[1][2]=(box[1][2]^1);
                                box[2][1]=(box[2][1]^1);
                        }else if (i==10){
                                box[1][10]=(box[1][10]^1);
                                box[1][9]=(box[1][9]^1);
                                box[2][10]=(box[2][10]^1);
                                }else{
                                        box[1][i]=(box[1][i]^1);
                                        box[1][i-1]=(box[1][i-1]^1);
                                        box[1][i+1]=(box[1][i+1]^1);
                                        box[2][i]=(box[2][i]^1);
                                }
                                step++;
                                }

                }
                light(a+1);
        }
        if (a>1 && a<10){
        for (i=1;i<=10;i++){
                if (box[a-1][i]==0){
                        box[a-1][i]=1;
                        if (i==1){

                                box[a][i]=(box[a][i]^1);
                                box[a][i+1]=(box[a][i+1]^1);
                                box[a+1][i]=(box[a+1][i]^1);
                        }else if (i==10){
                                box[a][i]=(box[a][i]^1);
                                box[a][i-1]=(box[a][i-1]^1);
                                box[a+1][i]=(box[a+1][i]^1);
                        }else {
                                box[a][i]=(box[a][i]^1);
                                box[a][i-1]=(box[a][i-1]^1);
                                box[a][i+1]=(box[a][i+1]^1);
                                box[a+1][i]=(box[a+1][i]^1);
                        }
                        step++;
                        //printf("hi\n");
               }
        }
        light(a+1);
        }
         if (a==10) {
                            for (i=1;i<=10;i++){
                if (box[a-1][i]==0){
                        box[a-1][i]=1;
                        if (i==1){

                                box[a][i]=(box[a][i]^1);
                                box[a][i+1]=(box[a][i+1]^1);

                        }else if (i==10){
                                box[a][i]=(box[a][i]^1);
                                box[a][i-1]=(box[a][i-1]^1);

                        }else {
                                box[a][i]=(box[a][i]^1);
                                box[a][i-1]=(box[a][i-1]^1);
                                box[a][i+1]=(box[a][i+1]^1);

                        }
                        step++;
                        //printf("hi\n");
               }
        }
                n=0;
                        for (i=1;i<=10;i++){
                                if (box[10][i]==1) n++;
                        }
                        if (n==10){
                       // printf("hi\n");
                        return true;
                        }else{
                               // printf("%d",step);
                        return false;
                        }
        }
}
