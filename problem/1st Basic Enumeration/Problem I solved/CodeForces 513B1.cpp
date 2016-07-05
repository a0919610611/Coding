#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
void permunation(int a);
int funp(int a,int b);
int p[9]={0};
int n,m;
int p_ans[9][40321]={0};
int ppp[40321]={0};
int num=1;
int to[9];
int main()
{

        int i,j,k;
        scanf("%d %d",&n,&m);


        for (int i=1;i<=8;i++){
                to[i]=1;
        }

        for (i=1;i<=n;i++){
          p[1]=i;
        to[i]=0;
       permunation(1);
       to[i]=1;
        }
        //printf("%d",num);
        //printf("%d %d",p_ans[1][2],p_ans[2][2]);
        int anss;
       anss=funp(n,m);
       //printf("%d",anss);
       for (i=1;i<=n;i++){
        printf("%d\n",p_ans[i][anss]);
       }
    return 0;
}

void permunation(int a){


        int i;

if (a==n) {

        for (i=1;i<=n;i++){
        p_ans[i][num]=p[i];
       }
                num++;
                return;
        }

        for (i=1;i<=n;i++){

                if (to[i]){
                        to[i]=0;
                        p[a+1]=i;

                        //permunation(i,b+1);
permunation(a+1);
                        to[i]=1;
                }

        }


}
int funp(int a,int b)
{
    int i,j,k,max_f,min_p,anum,l,minn,now;
    anum=1;
 min_p=1000000;
max_f=0;
    for (i=1;i<=a;i++) anum*=i;
    for (l=1;l<=anum;l++){
            now=0;


                 for (i=1;i<=a;i++){
                for (j=i;j<=a;j++){
                        minn=8;
                        for(k=i;k<=j;k++){
                              if(p_ans[k][l]<=minn) minn=p_ans[k][l];
                        }
                       now+=minn;
                }



    }
    if (now>=max_f) {
                        //printf ("yyyy\n");
                        max_f=now;

        }
        ppp[l]=now;
}
//printf("%d %d",p_ans[1][2],p_ans[2][2]);
//printf("%d",ppp[2]);
int m=0;
//printf("%d\n",max_f);
for (i=1;i<=anum;i++){
        //printf("%d\n",ppp[i]);
//printf("%d\n",i);
//printf("%d\n",max_f);
                //printf("%d\n",max_f);
        if (ppp[i]==max_f){
                m++;
                if (m==b) {
                        //printf("%d",i);
                return i;
        }
}
}
//printf ("answer\n");
//printf ("%d\n",min_p);
//return min_p;
}
