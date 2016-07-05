#include<iostream>
#include<stdio.h>
#include<math.h>
int i,number;
int j,k,l,m,answer,location[3],answer2,location2[3];
int box[20][20];
    int line[20][20][5]={0};
bool found(int a,int b);
bool foundw(int a,int b);
int main(){

    scanf("%d",&number);
    for (i=1;i<=number;i++){
        for (j=1;j<=4;j++){
        for (k=1;k<=19;k++){
        for (l=1;l<=19;l++){
    line[k][l][j]=0;
        }
        }
        }
    answer=0;
answer2=0;
        for (j=1;j<=19;j++){
            for (k=1;k<=19;k++){
                        int input;
                scanf("%d",&input);
                box[j][k]=input;
            }
        }
        for (j=1;j<=19;j++){
                for (k=1;k<=19;k++){
                        if (box[j][k]==1){

                                if (found(j,k)){

                                        answer=1;
                                        break;
                                }
                        }
                }
        }
         for (j=1;j<=19;j++){
                for (k=1;k<=19;k++){
                        if (box[j][k]==2){
                                if (foundw(j,k)){
                                        answer2=1;
                                        break;
                                }
                        }
                }
        }
        //printf("%d %d",answer,answer2);
        if ((answer==1) && (answer2==0)){
                printf("1\n");
                printf("%d %d\n",location[1],location[2]);
        }else if ((answer==0) && (answer2==1)){
                 printf("2\n");
                printf("%d %d\n",location2[1],location2[2]);
        }else {
                //printf("%d %d",answer,answer2);
                printf("0\n");
        }
    }
    return 0;
}
bool found(int a,int b){
        int color=1;

        int num=0;
        int found_what;
        int found_what2=0;
        found_what=b;
        while((box[a][found_what]==1) && found_what<=19 &&(!line[a][found_what][1])){

                line[a][found_what][1]=1;
                num++;
                found_what++;
        }
        if (num==5){
                location[1]=a;
                location[2]=b;
                return true;
        }
        num=0;
        found_what=a;
        while((box[found_what][b]==1) && found_what<=19 && (!line[found_what][b][2]) ){

                line[found_what][b][2]=1;
                num++;
                found_what++;
        }
        if (num==5){
                location[1]=a;
                location[2]=b;
                return true;
        }
        num=0;
        found_what=a;
        found_what2=b;
        while((box[found_what][found_what2]==1) && found_what<=19 && found_what2<=19&& (!line[found_what][found_what2][3])){

                line[found_what][found_what2][3]=1;
                num++;
                found_what++;
                found_what2++;
        }
        if (num==5){
                location[1]=a;
                location[2]=b;
                return true;
        }
        num=0;
        found_what=a;
        found_what2=b;
        while((box[found_what][found_what2]==1) && found_what>=1 && found_what<=19  && found_what2>=1&& found_what2<=19&& (!line[found_what][found_what2][4])){

                line[found_what][found_what2][4]=1;
                 num++;
                found_what++;
                found_what2--;
        }
         if (num==5){
                location[1]=found_what-1;
                location[2]=found_what2+1;
                return true;
        }else{
                return false;
        }

}
bool foundw(int a,int b){

        int color=box[a][b];

        int num=0;
        int found_what=0;
        int found_what2=0;
        found_what=b;
        while((box[a][found_what]==color) && found_what<=19 &&(!line[a][found_what][1])){

                line[a][found_what][1]=1;
                num++;
                found_what++;
        }
        if (num==5){
                location2[1]=a;
                location2[2]=b;
                return true;
        }
        num=0;
        found_what=a;
        while((box[found_what][b]==color) && found_what<=19 && (!line[found_what][b][2])){

                line[found_what][b][2]=1;
                 num++;
                found_what++;
        }
        if (num==5){
                location2[1]=a;
                location2[2]=b;
                return true;
        }
        num=0;
        found_what=a;
        found_what2=b;
        while((box[found_what][found_what2]==color) && found_what<=19 && found_what2<=19 && (!line[found_what][found_what2][3])){

                line[found_what][found_what2][3]=1;
                num++;
                found_what++;
                found_what2++;
        }
        if (num==5){
               location2[1]=a;
                location2[2]=b;
                return true;
        }
        num=0;
        found_what=a;
        found_what2=b;
        while((box[found_what][found_what2]==color) && found_what>=1 && found_what<=19 && found_what2>=1 && found_what2<=19&& (!line[found_what][found_what2][4])){

                line[found_what][found_what2][4]=1;
                num++;
                found_what++;
                found_what2--;
        }
         if (num==5){
                location2[1]=found_what-1;
                location2[2]=found_what2+1;
                return true;
        }else{
                return false;
        }

}
