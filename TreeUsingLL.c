#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node*root=NULL, *temp=NULL;

struct Node* newnode(int key){
    struct Node*node = (struct Node*)malloc(sizeof(struct Node*));
    node->data = key;
    node->left = node->right = NULL;
    return (node);
}

void inorder(struct Node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node*root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

struct Node*insert(struct Node*node, int key){
    if(node==NULL)
        return newnode(key);
    if(key<node->key)
        node->left = insert(node->left, key);    
}