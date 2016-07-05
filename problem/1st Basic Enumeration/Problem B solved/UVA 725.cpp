#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int main(){
    int N;
    int first=1;
    while(scanf("%d",&N)==1 && N){
                if(!first)
                printf("\n");
                first=0;
        int exist=0;
        for (int i=1234;i<=99999;i++){
                int j;
            bool ans=false;
            int used[10]={0};
        char str[10];
            if ((i*N)>99999)break;
            sprintf(str,"%05d",i);
            for (j=0;str[j];j++){
                used[str[j]-'0']++;
            }
            sprintf(str,"%05d",i*N);
             for (j=0;str[j];j++){
                used[str[j]-'0']++;
            }

            ans=true;
            for (j=0;j<10;j++){
                if (used[j]==1){



                }else{
                    ans=false;

                }
            }
            if (ans){
                printf("%05d / %05d = %d\n",i*N,i,N);
                exist++;

            }

        }
        if (exist==0){
                printf("There are no solutions for %d.\n",N);
        }

    }
    return 0;
}
