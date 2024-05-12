#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node* newnode(int value){
    struct node* temp = (struct node*) malloc(sizeof(struct node*));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node*insert(struct node*root, int key){
    if(root == NULL)
        return newnode(key);
    else if(key < root->data) 
        root->left = insert(root->left, key);
    else if(key > root->data) 
        root->right = insert(root->right, key);
    return root;          
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);    
}

int main(){
    struct node *root = NULL;
    int data, choice, i=0;
    printf("Enter 5 elements:\n");
    while(i<5){
        printf("Enter element %d: ",i+1);
        scanf("%d",&data);
        root = insert(root,data);
        i++;
    }
    printf("Elements entered are:\n");
    preorder(root);
    printf("\nAfter sorting:\n");
    inorder(root);
    

}