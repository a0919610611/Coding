#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
int main(){

        char a[100000+1],b[100000+1],c[1000000+1];
        int a2[26]={0},b2[26]={0},c2[26]={0},d2[26]={0};
        scanf("%s%s%s",a,b,c);
        int ln_a,ln_b,ln_c,i,j,k;

        int min_c,min_b;
         int flagc,flagb;
        char ans[100000+1];
        ln_a=strlen(a);
        ln_b=strlen(b);
        ln_c=strlen(c);

        for (i=0;i<ln_a;i++) a2[a[i]-'a']++;
        for (i=0;i<ln_b;i++) b2[b[i]-'a']++;
        for (i=0;i<ln_c;i++) c2[c[i]-'a']++;
         for (i=0;i<26;i++){
        d2[i]=a2[i];
       }
          min_b=100000+1;
         flagb=1;
        for (i=0;i<26;i++){
               if((b2[i])&& ((a2[i]/b2[i])<min_b)){

                  min_b=(a2[i]/b2[i]);
                  flagb=0;

        }
        }


        if (flagb) min_b=0;

        for (i=0;i<26;i++){
             if (b2[i]>0){
                a2[i]=a2[i]-b2[i]*min_b;
             }
        }
         //min_c=100000+1;
         //flagc=1;
       // for (i=0;i<26;i++){
               //if(c2[i]&& ((a2[i]/c2[i]))<min_c)

                 // min_c=(a2[i]/c2[i]);
                 // flagc=0;

        //}

        //if(flagc) min_c=0;
        //for (i=0;i<26;i++){
            // if (c2[i]>0){
               // a2[i]=a2[i]-c2[i]*min_c;
             //}
        //}

        int min_sum,bb,fff;

        min_sum=0;



        bb=min_b;

        for (i=min_b;i>=0;i--){

             for (j=0;j<26;j++){
               if(b2[j]>0 && i!=min_b){
                  a2[j]=a2[j]+b2[j];

                }
        }

         min_c=100000+1;
         flagc=1;
        for (k=0;k<26;k++){
               if(c2[k]>0 && ((a2[k]/c2[k]))<min_c)
                  min_c=(a2[k]/c2[k]);
                  flagc=0;
        }

        if(flagc) min_c=0;

        if ((i+min_c)>min_sum) {
            min_sum=i+min_c;

            bb=i;
        }

                }


min_b=bb;

        min_c=min_sum-min_b;




        //printf("%d %d\n",min_b,min_c);
        //printf("%d\n",a2[1]);
        //printf("%d\n",d2[1]);
        //printf("%d %d\n",b2[1],c2[1]);
         for (j=0;j<26;j++){
               if(c2[j]>0){

                  d2[j]=d2[j]-c2[j]*min_c;
        }
        }
        for (k=0;k<26;k++){
             if (b2[k]>0){
                d2[k]=d2[k]-b2[k]*min_b;
             }
        }

       for (i=0;i<min_b;i++){
        strcat(ans,b);
       }
       for (i=0;i<min_c;i++){
        strcat(ans,c);
       }
printf("%s",ans);

for (i=0;i<26;i++){
        if (d2[i]){
        for (j=0;j<d2[i];j++)
        printf("%c",i+'a');

}
}

printf("\n");
    return 0;
}

