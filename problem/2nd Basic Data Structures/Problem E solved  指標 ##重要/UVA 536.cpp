#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
char a[30],b[30];
using namespace std;


struct Node
{
	char c;
	Node* left;
	Node* right;
	Node()
	{
		c=NULL;
		left=0;
		right=0;
	}
};
Node* root;
Node* creat(char* pre,char*mid, int len)
{
	if(len==0) return NULL;
	char * p=mid;
	while(*p!=*pre) p++;
	int tmp=p-mid;
	//Node *root=new Node(*pre);
	Node* root =new Node;
	root->c=pre[0];
	root->left=creat(pre+1,mid,tmp);
	root->right=creat(pre+tmp+1,mid+tmp+1,len-tmp-1);
	return root;
}
void postorder(Node* tree)
{
	if(tree !=NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%c",tree->c);
	}
}

int main(){
int length;
        while(scanf("%s",a)!=EOF){
                scanf("%s",b);

                length=strlen(a);
                creat(a,b,length);
               root=creat(a,b,length);
		postorder(root);
		putchar('\n');
        }
    return 0;
}
