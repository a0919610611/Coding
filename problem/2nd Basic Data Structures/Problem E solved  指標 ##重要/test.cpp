#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
char a[27],b[27],c[27];
void solve(){
}
int main(){
    int i,j,k,left,right,root,length;
        while(scanf("%s %s",a,b)!=EOF){
        int lr[27],rank[27];

                         length=strlen(a);
                for (i=length;i>=1;i--){
                        a[i]=a[i-1]-64;

                        b[i]=b[i-1]-64;
                        rank[b[i]]=i;
                }
                for (i=1;i<=length;i++){
                        if (b[i]==a[i]) root=i;
                }

        for (i=1;i<=length;i++){
                if (i<root) lr[i]=1;
                else if (i>root) lr[i]=2;
                else lr[i]=0;
        }
        c[length]=root;
        }
    return 0;
}
