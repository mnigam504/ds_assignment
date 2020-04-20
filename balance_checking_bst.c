#include<stdio.h>
#include<stdlib.h>
struct Node* insert(struct Node* node, int link)
{
    if (node == NULL)
        return(newNode(link));

    if (link < node->link)                   //creating bst
        node->left  = insert(node->left, link);
    else if (link > node->link)
        node->right = insert(node->right, link);
    else
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && link < node->left->link)
        return rightRotate(node);
    if (balance < -1 && link > node->right->link)
        return leftRotate(node);
    if (balance > 1 && link > node->left->link)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && link < node->right->link)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
