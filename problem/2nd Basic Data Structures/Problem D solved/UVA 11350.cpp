#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
struct node{
        int left;
        int right;
};
void solve(){

}
int main(){
       int n;
       scanf("%d",&n);
       while(n--){
        char input[90];
        scanf("%s",input);
        int length;
        length=strlen(input);

        int i;
        long long int ma=1,mb=1,la=0,lb=1,ra=1,rb=0,x=1,y=1;
       for (i=0;input[i];i++){
        if (input[i]=='L'){
                x=la+ma;
                y=lb+mb;
                ra=ma;
                rb=mb;
                ma=x;
                mb=y;
                //printf("hi");
        }else{
                x=ra+ma;
                y=rb+mb;
                la=ma;
                lb=mb;
                ma=x;
                mb=y;
                //printf("YO");
        }
       }
       printf("%lld/%lld\n",x,y);
       }
    return 0;
}
