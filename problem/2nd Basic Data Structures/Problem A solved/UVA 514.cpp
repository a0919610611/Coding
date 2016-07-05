#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stack>
using namespace std;
stack <int> train;
int p[1001];
int main(){
        int num,i,j,k,size_train;
        while (scanf("%d",&num)!=EOF && num){

                int n;
                while (1){
                for (i=1;i<=num;i++){
                        scanf("%d",&n);
                        if (n==0)
                        {

                          break;
                        }

                        p[i]=n;
                }
                if (n==0) break;
                       if(!train.empty()){                             //²MªÅ
                                size_train=train.size();
                                for (i=1;i<=size_train;i++){
                                        train.pop();

                                }
                        }
                        int now;
                        int exist=0;
                        i=1;
                        now=1;
                        train.push(i);
                        while(1){

                                if ((i==num))
                                if (train.empty()){
                                        break;
                                }
                              if ((!train.empty())&&(train.top())==(p[now])){
                                        //printf("%d",train.top());
                                        train.pop();

                                        //printf("%d",train.top());

                                        exist++;

                                now++;

                              } else{
                                      if (i<num) {
                                                i++;
                                      train.push(i);

                                      }else{
                                                break;
                                      }
                              }
                             //printf("%d",now);
                        }
                      //  printf("%d",exist);
                        if (exist==num) printf("Yes\n");
                                else printf("No\n");

        }

         printf("\n");
        }
    return 0;
}
