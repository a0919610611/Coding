/*************************************************************************
	> File Name: uva_11235.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月25日 (週一) 14時38分55秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
struct t
{
    int m;
    int mtimes;
    int lmost;
    int ltimes;
    int rmost;
    int rtimes;
    bool same;
};
t tree[400000];
void pushup(int root)
{
    int lchild=root<<1;
    int rchild=root<<1|1;
    int midtimes=0;
    if(tree[lchild].rmost==tree[rchild].lmost)
{
        midtimes=tree[lchild].rtimes+tree[rchild].ltimes;
    
    if(midtimes> tree[lchild].mtimes && midtimes > tree[rchild].mtimes)
    {
        tree[root].mtimes=midtimes;
        tree[root].m=tree[lchild].rmost;
    }else
    {

        if(tree[lchild].mtimes>tree[rchild].mtimes)
        {
            tree[root].mtimes=tree[lchild].mtimes;
            tree[root].m=tree[lchild].m;
        }else 
        {
            tree[root].mtimes=tree[rchild].mtimes;
            tree[root].m=tree[rchild].m;
        }
    }
    if(tree[rchild].same==true)
    {
        tree[root].rmost=tree[rchild].lmost;
        tree[root].rtimes=tree[lchild].rtimes+tree[rchild].ltimes;
    }else
    {
        tree[root].rmost=tree[rchild].rmost;
        tree[root].rtimes=tree[rchild].rtimes;
    }
    if(tree[lchild].same==true)
    {
        tree[root].lmost=tree[lchild].rmost;
        tree[root].ltimes=tree[rchild].ltimes+tree[lchild].rtimes;
    }else
    {
        tree[root].ltimes=tree[lchild].ltimes;
        tree[root].lmost=tree[lchild].lmost;
    }
}else
{
        if(tree[lchild].mtimes>tree[rchild].mtimes)
        {
            tree[root].mtimes=tree[lchild].mtimes;
            tree[root].m=tree[lchild].m;
        }else 
        {
            tree[root].mtimes=tree[rchild].mtimes;
            tree[root].m=tree[rchild].m;
        }
        tree[root].ltimes=tree[lchild].ltimes;
        tree[root].lmost=tree[lchild].lmost;
        tree[root].rtimes=tree[rchild].rtimes;
        tree[root].rmost=tree[rchild].rmost;
}
if(tree[lchild].lmost==tree[rchild].rmost) 
{
    tree[root].same=true;
}else
{
    tree[root].same=false;
}

}
void build(int root,int l,int r)
{
    if(l==r)
    {	
        int in;
        cin>>in;
        tree[root].m=in;
        tree[root].lmost=in;
        tree[root].rmost=in;
        tree[root].mtimes=1;
        tree[root].ltimes=1;
        tree[root].rtimes=1;
        tree[root].same=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    pushup(root);
}
int query(int root,int L,int R,int l,int r)
{   
    //cout<<"L="<<L<<"R="<<R<<endl;
    if(l<=L && r>=R)
    {
        return tree[root].mtimes;
    }
    int maxx=INT_MIN;
    int mid=(L+R)>>1;
    if(r<=mid) return query(root<<1,L,mid,l,r);
    else  if(l>mid) return query(root<<1|1,mid+1,R,l,r);
    else 
    {
        int temp=max(query(root<<1,L,mid,l,r),query(root<<1|1,mid+1,R,l,r));
    int lchild=root<<1;
    int rchild=root<<1|1;
//	cout<<lchild<<" "<<rchild<<endl;
    int midtimes=0;
    if(tree[lchild].rmost==tree[rchild].lmost)
    {	
        midtimes=tree[lchild].rtimes+tree[rchild].ltimes;
    	temp=max(temp,min(tree[lchild].rtimes,mid-l+1)+min(tree[rchild].ltimes,r-mid));
    
    }
    return temp;
    }

}
int main()
{
    op_io;
    int n,q;
    while(cin>>n>>q && n)
    {
        build(1,1,n);
      /*  for(int i=1;i<=n;i++)
        { 
            cout<<"i="<<i<<endl;
            cout<<"m= "<<tree[i].m<<endl;
            cout<<"mtimes= "<<tree[i].mtimes<<endl;
            cout<<"lmost= "<<tree[i].lmost<<endl;
            cout<<"rmost= "<<tree[i].rmost<<endl;
            cout<<"ltimes= "<<tree[i].ltimes<<endl;
            cout<<"rtimes= "<<tree[i].rtimes<<endl;
        }*/
        for(int i=1;i<=q;i++)
        {
            int a,b;
            cin>>a>>b;
            cout<<query(1,1,n,a,b)<<endl;
        }
    }
    return 0;
}
