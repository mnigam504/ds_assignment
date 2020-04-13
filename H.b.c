#include<stdio.h>
#include<stdlib.h>
struct Node
{
 struct Node *lchild;
 int data;
 struct Node *rchild;
}*root=NULL;
void Insert(int key)
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
void printLevelOrder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(struct Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ",root->data);
    else if (level > 1)
    {
        printGivenLevel(root->lchild, level-1);
        printGivenLevel(root->rchild, level-1);
    }
}
int height(struct Node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->lchild);
        int rheight = height(node->rchild);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
int main()
{
 int i;
 for(i=0;i<26;i++)
    Insert(i);
 printLevelOrder(root);

 return 0;
}

