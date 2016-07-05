#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int N,n_ap,m;
    scanf("%d",&N);//輸入有幾筆測資
    while(N--){
        scanf("%d %d",&n_ap,&m);//輸入ap數量  住戶數量
        int a[m],lower,upper,k,start,need;//將住戶存入array a[]
        //double b[m-1];

        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);//將住戶address依遠近排列

        lower = 0;//預設lower_bound為0
        upper = (a[m-1]-a[0]+1)*2;//預設uppwe_bound為最遠距離之兩倍(可以隨便設  但太小不行)
        //開始binary search->從upper bound 和lower bound中間值開始找
        //ps.k為ap直徑!!

        while(upper>lower){
            k = (upper+lower)/2;
            start = a[0];
            need = 1;
            for(int i=1;i<m;i++)
                if(a[i]>start+k){
                    start = a[i];
                    need++;
                }
            if(need>n_ap)
                lower = k+1;
            else
                upper = k;
        }
        printf("%.1f\n",(double)upper/(double)2);

    }
}
