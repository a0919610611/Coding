#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int N,n_ap,m;
    scanf("%d",&N);//��J���X������
    while(N--){
        scanf("%d %d",&n_ap,&m);//��Jap�ƶq  ���ƶq
        int a[m],lower,upper,k,start,need;//�N���s�Jarray a[]
        //double b[m-1];

        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);//�N���address�̻���ƦC

        lower = 0;//�w�]lower_bound��0
        upper = (a[m-1]-a[0]+1)*2;//�w�]uppwe_bound���̻��Z�����⭿(�i�H�H�K�]  ���Ӥp����)
        //�}�lbinary search->�qupper bound �Mlower bound�����ȶ}�l��
        //ps.k��ap���|!!

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
