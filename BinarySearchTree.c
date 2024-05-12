#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left, *right;
};
//Create a node
struct node*newnode(int item){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
//Insert a node
struct node*insert(struct node*node, int data){
    if(node == NULL)
        return newnode(data);
    if(data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;    
}
//inorder traversal
void inorder(struct node*root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
//preorder traversal
void preorder(struct node*node){
    if(node == NULL)
        return;
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);  
}
//postorder traversal
void postorder(struct node*node){
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);    
}
//finding inorder successor
struct node*minValueNode(struct node*node){
    struct node* current = node;
    //finding leftmost leaf
    while(current && current->left!=NULL)
        current = current->left;
    return current;    
}
//minimum value
int minimum(struct node*root){
    if(root==NULL)
        return 0;
    else{
        while(root->left!=NULL)
            root=root->left;
        return root->data;    
    }    
}
//maximum value
int maximum(struct node*root){
    if(root==NULL)
        return 0;
    else{
        while(root->right!=NULL)
            root = root->right;
        return root->data;    
    }    
}
//Deleting node
struct node *deleteNode(struct node*root, int key){
    if(root==NULL)
        return root;
    if(key<root->data)
        root->left = deleteNode(root->left, key);
    else if(key>root->data)
        root->right = deleteNode(root->right, key);        
    else{ //if node with one child or no child
        if(root->left == NULL){
            struct node*temp = root->right;
            free(root);
            return temp;   
        } else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //if node has two children
        struct node *temp = minValueNode(root->right);
        //place the inorder succesor in position of the node to be deleted
        root->data = temp->data;
        //delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }    
    return root;
}



int main(){
    struct node*root = NULL;
    int choice,data,val;
    printf("Press 0 to exit\n");
    printf("Press 1 to insert node\n");
    printf("Press 2 to delete node\n");
    printf("Press 3 for preorder traversal\n");
    printf("Press 4 for inorder traversal\n");
    printf("Press 5 for postorder traversal\n");
    printf("Press 6 for minimum value\n");
    printf("Press 7 for maximum value\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice == 0){
            printf("Inorder traversal:\n");
            inorder(root);
            return 0;
        }
        else if(choice == 1){
            printf("Enter data:");
            scanf("%d",&data);
            root = insert(root,data);
        }
        else if(choice == 2){
            printf("Enter data to be deleted: ");
            scanf("%d",&val);
            root = deleteNode(root,val);
        }
        else if(choice == 3){
            printf("Preorder traversal:\n");
            preorder(root);
            printf("\n");
        }
        else if(choice == 4){
            printf("Inorder traversal:\n");
            inorder(root);
            printf("\n");
        }
        else if(choice ==5){
            printf("Postorder traversal:\n");
            postorder(root);
            printf("\n");
        }
        else if(choice == 6){
            printf("Minimum element is:");
            int min = minimum(root);
            printf("%d",min);
        }
        else{
            printf("Maximum element is:");
            int max = maximum(root);
            printf("%d",max);
        }
    }
    printf("Inoreder traversal:\n");
    inorder(root);
    return 0;
}