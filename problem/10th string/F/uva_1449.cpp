/*************************************************************************
	> File Name: uva_1449.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016年04月23日 (週六) 16時16分36秒
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
class ac
{
    public:
        class Node
        {
            public:
            int cnt,depth,no;
            Node *child[26],*fail;
            Node(int _depth=0)
            {
                cnt=0;
                depth=_depth;
                no=-1;
                fail=0;
                memset(child,0,sizeof(child));
            } 
        };
        Node *root ,* pool;
        int pp;
        ac()
        {
            pool =new Node[1000000];
            pp=0;
            root=&pool[pp++];
        }
        ~ac()
        {
            delete pool;
        }
        void insert(const string &s ,int no,Node* nd=NULL,int pos=0)
        {
            if(nd==NULL) nd=root;
            if(pos>=(int) s.size())
            {
                nd->cnt++;
                nd->no=no;
                return ;
            }
            int c=s[pos]-'a';
            if(!nd->child[c])
            {
                pool[pp]=Node(nd->depth+1);
                nd->child[c]=&pool[pp++];
            }
            insert(s,no,nd->child[c],pos+1);
        }
        void bulid_fail()
        {
            queue<Node*> q;
            q.push(root);
            while(!q.empty())
            {
                Node *nd=q.front();
                q.pop();
                for(int i=0;i<26;i++)
                {
                    if(nd->child[i])
                    {
                        Node *pt =nd->fail;
                        while(pt && pt->child[i]==NULL) pt=pt->fail;
                        nd->child[i]->fail=pt?pt->child[i]:root;
                       // nd->child[i]->cnt+=nd->child[i]->fail->cnt;
                        q.push(nd->child[i]);
                    }
                }
            }
        }
        void match(const string & s,pair<int,int> occur[])
        {
            Node *nd=root;
            for(int i=0;i<(int)s.size();i++)
            {
                int c=s[i]-'a';
                while(nd && !nd->child[c]) nd=nd->fail;
                if(nd)
                {
                    nd=nd->child[c];
                    Node *p=nd;
                    while(p && p->cnt)
                    {
                        if(p->no>=0) occur[p->no].first++;
                        p=p->fail;
                    }
                }else nd=root;
            }
        }

};
bool cmp(pair<int,int> a ,pair<int,int> b)
{
    if(a.first!=b.first) return a.first>b.first;
    else return a.second < b.second;
}
int main()
{
//    op_io;
    int N;
    while(cin>>N && N)
    {
        vector<string> s;
        ac  AC_auto;
        s.push_back("");
        pair<int,int> occur[200]={};
        for(int i=1;i<=N;i++)
        {
            occur[i].second=i;
            string in;
            cin>>in;
            s.push_back(in);
            AC_auto.insert(in,i);
            
        }
        AC_auto.bulid_fail();
        string text;
        cin>>text;
        AC_auto.match(text,occur);
        sort(occur+1,occur+1+N,cmp);
        int max_num=occur[1].first;
        cout<<max_num<<endl;
        for(int i=1;i<=N;i++)
        {
            if(occur[i].first==max_num) cout<<s[occur[i].second]<<endl;
        }
    }
    return 0;
}
