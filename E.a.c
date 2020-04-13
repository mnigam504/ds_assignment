#include <stdio.h>
#include <stdlib.h>
struct Node
{
 struct Node *lchild;
 char data;
 struct Node *rchild;
}*root=NULL;
void Insert(char key)
{
 struct Node *t=root;
 struct Node *r=NULL,*p;

 if(root==NULL)
 {
 p=(struct Node *)malloc(sizeof(struct Node));
 p->data=key;
 p->lchild=p->rchild=NULL;
 root=p;
 return;
 }
 while(t!=NULL)
 {
 r=t;
 if(key<t->data)
 t=t->lchild;
 else if(key>t->data)
 t=t->rchild;
 else
 return;
 }
 p=(struct Node *)malloc(sizeof(struct Node));
 p->data=key;
 p->lchild=p->rchild=NULL;

 if(key<r->data) r->lchild=p;
 else r->rchild=p;
}

int main()
{
 int i;
 char ch=65;
 for(i=0;i<26;i++)
    Insert(ch+i);

 return 0;
}
