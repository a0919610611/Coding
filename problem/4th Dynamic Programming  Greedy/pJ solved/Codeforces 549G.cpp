#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
struct man{
        int money,num;
};
int compare (man l,man r){
        return l.money<r.money;
}

int main(){
        man a[200000+1];
        int n;
        scanf("%d",&n);
        int i,j,k;
        for (i=0;i<n;i++){
                if (i!=n-1){
                        scanf("%d ",&a[i].money);
                }else scanf("%d",&a[i].money);
                a[i].money+=i;
                
        }
        sort(a,a+n,compare);
        for (i=0;i<n;i++){
        	a[i].num=i;
               a[i].money-=(a[i].num);
               
        }
        
        int flag=0;
        
        for (i=0;i<n-1;i++){
                if (a[i].money>a[i+1].money) flag=1;
        }
        if (flag) printf(":(\n");
        else{
        	for (i=0;i<n;i++){
        		if (i!=n-1) printf("%d ",a[i].money);
        		else printf("%d",a[i].money);
			}
		}
    return 0;
}
