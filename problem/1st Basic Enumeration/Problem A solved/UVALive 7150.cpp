#include <bits/stdc++.h>
using namespace std;
stack <int> a;
int main(){
    int p,a,b,c,d,n;

   while(scanf("%d %d %d %d %d %d",&p,&a,&b,&c,&d,&n)!=EOF){
        double max_price=0;
        double decline=0;
        for (int i=1;i<=n;i++){
            double  now_price=0;
            now_price=p*(sin(a*i+b)+cos(c*i+d)+2);
            if (now_price>=max_price) max_price=now_price;
            else if ((max_price-now_price)>decline)decline=(max_price-now_price);
        }
        printf("%lf\n",decline);
   }

    return 0;
}
