#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<cstdlib>
using namespace std;
int k[10000001]={0};
int cnt,ans;
int i,j;
struct toy{
        int val;
        int rest;
};
stack<toy> s;

void solve(){
        while (!s.empty()) s.pop();


       toy temp;
       temp.val=abs(k[1]);
       temp.rest=abs(k[1]);
       s.push(temp);
       for (i=2;i<=cnt;i++){
                if (s.empty()) return;
                if (k[i]<0){
                        if (abs(k[i])<s.top().rest){
                                temp.val=abs(k[i]);
       temp.rest=abs(k[i]);
       s.push(temp);
                        }else return;
                }
                if (k[i]>0){
                      if (k[i]==s.top().val){
                        if (i!=cnt){
                        s.pop();
                        s.top().rest=s.top().rest-k[i];
                        }else s.pop();
                      }else return;

                }
       }
       if (s.empty()) ans=1;

}
int main(){
        int input;
        char inputt;
        while(~scanf("%d%c",&input,&inputt)){
                k[1]=input;
                cnt=1;
                ans=0;
                if (inputt!='\n'){
                        while(scanf("%d%c",&k[++cnt],&inputt)){
                                if (inputt=='\n') break;
                        }
                }
               // printf("%d",cnt);
                if ((cnt)%2==0) solve();
                if (ans) printf(":-) Matrioshka!\n");
                else printf(":-( Try again.\n");
        }
    return 0;
}
