#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node*head,*current,*newnode;
void display();
int main()
{
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            current = newnode;
        }
        else 
        {
            current->next = newnode;
            current = newnode;
        }
    }
    printf("\nNode created is:\n");
    display();
}
void display()
{
    struct node*current = head;
    if(head = NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("Nodes of linked list are:\n");
        while(current!=NULL)
        {
            printf("%d\t",current->data);
            current = current->next;
        }
        printf("\n");
    }
}