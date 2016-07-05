#include<iostream>
#include<stdio.h>
int f91(int a){
    if (a<=100){
        return f91(f91(a+11));
    }else{
        return a-10;
    }
}
int main(){
    int input;
    while(scanf("%d",&input)!=0){
    int ans;
    ans=f91(input);
    printf("f91(%d) = %d\n",input,ans);
    }

}
