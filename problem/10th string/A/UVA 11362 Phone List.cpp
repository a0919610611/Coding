/****************************************************************************/
/*                  code by a0919610611/fuyu0425                            */
/****************************************************************************/
//#define txt     //use freopen
//#pragma comment(linker, "/STACK:1024000000,1024000000")  //op
#ifdef LOCAL
#ifdef txt
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
#endif
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define op_io
#else
#define op_io ios_base::sync_with_stdio(0);cin.tie(0);
#endif
#define endl "\n"
#define F first
#define S second
#define MAXN 200005

typedef long long LL;
typedef pair<int,int> pii;
bool flag=0;
bool flag2=0;
class Trie
{
    public:
        class Node
        {
            public:
            int cnt,depth;
            Node *child[10];
            Node (int _depth=0)
            {
                cnt=0;
                depth=_depth;
                memset(child,0,sizeof(child));
            }
        };
        Node *root ,*pool;
        int pp;
        Trie()
        {
            pool=new Node[1000000];
            pp=0;
            root=&pool[pp++];
        }
        ~Trie()
        {
            delete pool;
        }
        void insert(const string &s ,Node * nd=NULL ,int pos=0)
        {
            if(nd==NULL)
                nd=root;
            if(pos>=s.size())
            {
                nd->cnt++;
                return ;
            }
            int c=s[pos]-'0';

            if(nd->child[c]==NULL)
            {
                pool[pp]=Node(nd->depth+1);
                nd->child[c]=&pool[pp++];
               flag=0;
            }
            if(nd->cnt>=1) flag2=1;
            insert(s,nd->child[c],pos+1);
        }
};
int main()
{
	op_io;
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int i;
        Trie *Tr=new Trie;
      int ans=0;
      string s[10000+1];
      for(i=1;i<=n;i++)
      {
          cin>>s[i];
          flag=1;
            flag2=0;
            if(ans) continue;
           Tr->insert(s[i]);


            if(flag||flag2){ans=1;}
      }

        if(ans) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        delete Tr;
    }

	return 0;
}
