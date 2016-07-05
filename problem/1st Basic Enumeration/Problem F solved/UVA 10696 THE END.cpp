#include<iostream>
#include<stdio.h>
int main(){
    int input;
    while(scanf("%d",&input)!=EOF){
    int ans;
    if (input==0) break;
    if (input<=101){
            ans=91;
        printf("f91(%d) = %d\n",input,ans);
    }else {
        ans=input-10;
        printf("f91(%d) = %d\n",input,ans);
    }

    }

}
