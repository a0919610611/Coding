/*************************************************************************
	> File Name: uva_12886.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月26日 (週二) 16時56分20秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int h1,w1,h2,w2;
const int b1=17,b2=23;
const long long int mod1=1000000000+7;
const long long int mod2=1000000000+9;
string g1[2000],g2[2000];
long long int hash1,hash2;
void get_hash1()
{
    int i,j;
    hash1=0;
    for(i=0;i<h1;i++)
    {
        long long int sum=0;
        for(j=0;j<w1;j++)
        {
            sum=sum*b1%mod1;
            sum=(sum+g1[i][j])%mod1;

        }
        hash1=hash1*b2%mod2;
        hash1=(hash1+sum)%mod2;
    }
}
long long int table1[2001][2001];
long long int table2[2001][2001];
int main()
{
    op_io;
    while(cin>>h1>>w1>>h2>>w2)
    {
	memset(table1,0,sizeof(table1));
    	memset(table2,0,sizeof(table2));
    int i,j,k,l;
    for(i=0;i<h1;i++) cin>>g1[i];
    for(i=0;i<h2;i++) cin>>g2[i];
    get_hash1();
/*    for(i=0;i<h1;i++)
    {
        cout<<g1[i]<<endl;
    }
    for(i=0;i<h2;i++)
    {
        cout<<g2[i]<<endl;
    }
*/
    long long int hh=1,ww=1;
    int ans=0;
    for(i=1;i<=w1;i++) ww=ww*b1%mod1;
    for(i=1;i<=h1;i++) hh=hh*b2%mod2;
    long long int hash_goal=0;
    for(i=0;i<h2;i++)
    {
        long long int sum=0;
        for(j=0;j<w1;j++)
        {
            sum=sum*b1%mod1;
            sum=(sum+g2[i][j])%mod1;
        }
        table1[i][w1-1]=sum;
        for(j=w1;j<w2;j++)
        {
            table1[i][j]=table1[i][j-1]*b1%mod1;
            table1[i][j]=(table1[i][j]+g2[i][j])%mod1;
            table1[i][j]=(((table1[i][j]-g2[i][j-w1]*ww+mod1)%mod1)+mod1)%mod1;
        }
    }
    for(i=w1-1;i<w2;i++)
    {
        long long int sum=0;
        for(j=0;j<h1;j++)
        {
            sum=sum*b2%mod2;
            sum=(sum+table1[j][i])%mod2;
        }
        table2[h1-1][i]=sum;
      //  cout<<"sum="<<sum<<endl;
        if(sum==hash1) ans++;
        for(j=h1;j<h2;j++)
        {
            table2[j][i]=table2[j-1][i]*b2%mod2;
            table2[j][i]=(table2[j][i]+table1[j][i])%mod2;
            table2[j][i]=(((table2[j][i]-table1[j-h1][i]*hh)%mod2)+mod2)%mod2;
         //   cout<<table2[j][i]<<" "<<hash1<<endl;
        if(table2[j][i]==hash1) ans++;
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}
