#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<deque>
using namespace std;

int main(){
        int n;
        while(scanf("%d",&n) && n!=0){
                        int i,j,k;
                deque<int> c;
                for (i=1;i<=n;i++){
                        c.push_back(i);
                }

                printf("Discarded cards:");
                if (c.size()==1) printf("\n");
                while (c.size()>1){
                        if (c.size()>2){
                        printf(" %d,",c.front());
                        c.pop_front();
                        int top=c.front();

                        c.pop_front();


                        c.push_back(top);
                        }else{
                           printf(" %d\n",c.front());
                           c.pop_front();
                        }
                }
                  printf("Remaining card: %d\n",c.front());

        }
    return 0;
}
