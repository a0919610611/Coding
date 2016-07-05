#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;

int team[1000000+1];
char com[7];

int main(){
        int n,i,j,num,cnt;
        cnt=1;
        while(scanf("%d",&n) && n!=0){
                queue<int> q[1010]; //ªì©l¤Æ
                for (i=1;i<=n;i++){
                        scanf("%d",&num);
                        for (j=1;j<=num;j++){
                                int no;
                                        scanf("%d",&no);
                                team[no]=i;
                        }
                }
                int rank[1001]={0};
                int now_rank=1;
                 printf("Scenario #%d\n",cnt);
                while (scanf("%s",com)&& strncmp(com,"STOP",4)!=0){
                        if (strncmp(com,"ENQUEUE",7)==0) {
                                       // printf("hi");

                                int what;
                                scanf("%d",&what);
                                q[team[what]].push(what);
                                if (rank[team[what]]==0){
                                        rank[team[what]]=now_rank;
                                        now_rank++;
                                }
                        }
                        if (strncmp(com,"DEQUEUE",7)==0){
                                int min=100000000;

                                for (i=1;i<=n;i++){
                                        if (rank[i]<min && rank[i]>0)
                                                min=rank[i];
                                }
                            for (i=1;i<=n;i++){
                                        if (rank[i]==min){
                                       if (!q[i].empty() ){
                                         printf("%d\n",q[i].front());
                                         q[i].pop();
                                         if (q[i].empty()) rank[i]=0;
                                         break;
                                       }
                                        }
                                }

                        }
                }
                printf("\n");
                cnt++;
        }
    return 0;
}
