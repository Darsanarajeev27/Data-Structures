#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left, *right;
};
struct node*create();

void main(){
    struct node*root;
    root = create();
}
struct node*create(){
    int choice;
    struct node*temp;
    int data;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Press 0 to exit\n");
    printf("Press 1 to add new node\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    if(choice == 0){
        return 0;
    }
    else{
        printf("Enter data:");
        scanf("%d",&data);
        temp->data = data;
        printf("Enter the left child of %d\n",data);
        temp->left = create();
    printf("Enter the right child of %d\n",data);
    temp->right = create();
    return temp;
    }
}   