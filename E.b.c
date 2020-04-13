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
void Inorder(struct Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%c ",p->data);
 Inorder(p->rchild);
 }
}
void Preorder(struct Node *p)
{
 if(p)
 {
 printf("%c ",p->data);
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}
void Postorder(struct Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
 printf("%c ",p->data);

 }
}
int main()
{
 int i;
 char ch=65;
 for(i=0;i<26;i++)
    Insert(ch+i);
 printf("\nInorder display is:\n");
 Inorder(root);
 printf("\nPreorder display is:\n");
 Preorder(root);
 printf("\nPostorder display is:\n");
 Postorder(root);
 return 0;
}

