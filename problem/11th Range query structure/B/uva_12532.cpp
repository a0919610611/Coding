/*************************************************************************
	> File Name: uva_12532.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月24日 (週日) 16時13分53秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
int num[400000+1];
int m;
int n,k;
void update(int a, int b)
{
    a=a+m-1;
    num[a]=b;
    while(a>1)
    {
        int parent=a>>1;
       
         num[parent]=num[(parent<<1) |1]*num[parent<<1];   
 
        a>>=1;
    }
}
int  query(int node,int l ,int r,int ql,int qr)
{
    if(ql<=l && r<=qr) return num[node];
    if(r<ql || l>qr) return 1;
    int mid=(l+r)>>1;
    int L_seg=query(node<<1,l,mid,ql,qr);
    int R_seg=query((node<<1)|1,mid+1,r,ql,qr);
    return L_seg*R_seg;
}
int main()
{
    op_io;
    while(cin>>n>>k)
    {
        m=1;
        while(m<n) m<<=1;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a>0) num[m+i]=1;
            else if (a<0) num[m+i]=-1;
            else num[m+i]=0;
        }
        for(int i=m-1;i>=1;i--)
        {
            num[i]=num[2*i] * num[2*i+1];
        }
        for(int q=1;q<=k;q++)
        {
            string in;
            cin>>in;
            int a,b;
            cin>>a>>b;
            if(in[0]=='C')
            {   
                if(b>0) b=1;
                else if(b<0) b=-1;
                else b=0;
                update(a,b);               
            }else
            {	
		
                int ans=query(1,1,m,a,b);
                if(ans>0) cout<<'+';
                else if(ans==0)cout<<0;
                else cout<<'-';
            }
        }
        cout<<endl;

    }
    return 0;
}
