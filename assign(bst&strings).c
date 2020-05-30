#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char key[100];
    struct node *left, *right;
};

struct node *newNode(char item[])
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->key,item);
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s\n",root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, char key[])
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
      /*while (1) {
         if (strcmp(node->key,key) < 0) { // look left
            if (node->left != NULL) node=node->left;
            else { strcpy(node->key,key);node->left=node->right=NULL; break; }
         }
         else if (strcmp(node->key,key) > 0) { // look left
            if (node->right != NULL) node=node->right;
            else { strcpy(node->key,key);node->left=node->right=NULL; break; }
         }
         else break; // found! Don't insert
      }*/

    /* Otherwise, recur down the tree */
    if (strcmp(node->key,key) > 0)
        node->left = insert(node->left, key);
    else if (strcmp(node->key,key) < 0)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, "Arthi");
    insert(root, "Christy");
    insert(root, "Dorothy");
    insert(root, "Fraser");
    insert(root, "Eliza");
    insert(root, "David");
    // print inoder traversal of the BST
    inorder(root);

    return 0;
}

