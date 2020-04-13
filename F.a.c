#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int Count(struct node* node)
{
  if(node == NULL)
    return 0;
  if(node->left == NULL && node->right==NULL)
    return 1;
  else
    return Count(node->left)+Count(node->right);
}
struct node* create(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
int main()
{
  /*create a tree*/
  struct node *root = create(10);
  root->left= create(20);
  root->right= create(30);
  root->left->left= create(40);
  root->left->right= create(50);
  root->left->left->left=create(60);
  printf("Node count is %d",Count(root));
  return 0;
}
