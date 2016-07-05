#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
   char str[100000+1];
   bool AB=false;
   bool BA=false;
   int i=0;
   int length;
   scanf("%s",str);
   length=strlen(str);

   int strr[100000+1]={0};

  int strr2[100000+1]={0};
    for (i=0;i<length;i++){  //¥ý§äAB
            if (AB==false){
        if (str[i]=='A' && str[i+1]=='B'&& strr[i]==0){
            AB=true;
            strr[i+1]=1;

        }
        }
        if (BA==false && AB==true){
        if (str[i]=='B' && str[i+1]=='A'&& strr[i]==0){
            BA=true;
            strr[i+1]=1;

        }
        }
        if (AB&&BA){break;}

   }
   if (AB&&BA){
    printf("YES");
   }else{
       AB=false;
       BA=false;
        for (i=0;i<length;i++){ //¥ý§äBA
            if (AB==false && BA==true){
        if (str[i]=='A' && str[i+1]=='B'&& strr2[i]==0){
            AB=true;
            strr2[i+1]=1;

        }
        }
        if (BA==false){
        if (str[i]=='B' && str[i+1]=='A'&& strr2[i]==0){
            BA=true;
            strr2[i+1]=1;

        }
        }
        if (AB&&BA){break;}
        }
         if (AB&&BA){
    printf("YES");
   }else{
   printf("NO");
   }
   }





   return 0;
}
