#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create(int data)
{
  struct node* key= (struct node*)malloc(sizeof(struct node));
  key->data = data;
  key->left = NULL;
  key->right = NULL;
  return(key);
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
  struct node *root = create(10);
  root->left = create(20);
  root->right = create(30);
  root->left->left  = create(40);
  root->right->left=create(50);
  root->right->right=create(60);
  inorder(root);
  getchar();
  return 0;
}
