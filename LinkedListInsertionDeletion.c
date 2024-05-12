#include<stdio.h>
#include<stdlib.h>

//Declaring structure
struct node{
    int data;
    struct node*next;
};
//Defining structure
struct node*head,*curent,*newnode;
//Declaration of functions for insertion,deletion and for displaying the linked list
void insert_at_front(int data);
void insert_at_end(int data);
void insert_btw_nodes(int data);
void delete_at_front();
void delete_at_end();
void display();

//Main function
int main()
{
    int n;
    struct node*current;
    printf("Enter no. of nodes:"); //Inputing size of linked list
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node)); //Memory allocation of newnode
        printf("\nEnter data: "); //Inputing elements to linked list
        scanf("%d",&newnode->data);
        newnode->next = NULL; //Setting next of input to NULL
        if(head == NULL) //Condition to check if node is empty
        {
            head = newnode; 
            current = newnode; 
        }
        else //Condition to add newnodes to existing list
        {
            current->next = newnode;
            current = newnode;
        }
    }    
        printf("Node created is:\n"); //Displaying the linked list created
        display();
        int choice,data;
        //Displaying the choice of operations to be performed 
        printf("\n1.Insert at front\n2.Insert at end\n3.Insert between given nodes\n4.Delete at front\n5.Delete at end\n6.Display\n7.Exit\n");
        while(1) //Initializing a while loop
        {
            printf("\nEnter choice: "); //Inputing choice of operation 
            scanf("%d",&choice);
            //Initializing switch case
            switch(choice) 
            {
                case 1:
                    printf("\nEnter data to be inserted: ");
                    scanf("%d",&data);
                    insert_at_front(data);
                    break;
                 case 2:
                    printf("\nEnter data to be inserted: ");
                    scanf("%d",&data);
                    insert_at_end(data);
                    break;
                 case 3:
                    printf("\nEnter data to be inserted: ");
                    scanf("%d",&data);
                    insert_btw_nodes(data);
                    break;
                case 4:
                    delete_at_front();
                    break;
                case 5:
                    delete_at_end();
                    break;
                case 6:
                    printf("The current linked list is:\n");
                    display();
                    break;
                case 7:
                    exit(0);
                default:
                    printf("\nInvalid choice\n");
            }                            

        }
}
//Definition of function to display linked list    
void display()
{
    struct node*current = head;
    if(head == NULL) //Condition to check if list is empty
    {
        printf("List empty\n");
    }
    else 
    {
        while(current!=NULL) //while loop to display linked list elements
        {
            printf("%d\t",current->data);
            current = current->next;
        }
        printf("\n");
    }
}
//Definition of function to insert new node at front
void insert_at_front(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));//Memory allocation of newnode
    newnode->data = data; //Data assigning
    newnode->next = NULL;
    if(head==NULL)//Condition to check if list is empty
    {
        head = newnode;
    }
    else
    {
        //linking the newnode to the existing linked list
        newnode->next = head;
        head = newnode;
    }
    printf("\nNew linked list is:\n");//displaying new linked list
    display();
}    
//Definition of function to insert new node at end
void insert_at_end(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));//Memory allocation of newnode
    newnode->data = data; //Data assigning
    newnode->next = NULL;
    struct node*temp = head;
    while(temp->next!=NULL) //while loop to traverse through the linked list
    {
        temp = temp->next;
    }
    temp->next = newnode;//Assigning the newnode as the last node in the list
    printf("\nNew linked list is:\n");//Displaying new linked list
    display();
}  
//Definition of function to insert new node between two nodes
void insert_btw_nodes(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));//Memory allocation of newnode
    newnode->data = data; //Data assigning
    newnode->next = NULL;
    int position;
    //Inputing the position to which the new node is to be added
    printf("Enter the position at which the new node is to be inserted: ");
    scanf("%d",&position);
    struct node*temp = head;
    for(int i=2;i<position;i++)//for loop to traverse through the list
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("\nNew linked list is:\n");//Displaying new linked list
    display();
}
//Definition of function to delete node from front
void delete_at_front()
{
    struct node*temp = head;
    if(head == NULL)//Condition to check if node is empty
    {
        printf("\nList is empty\n");
    }
    else
    {
        head = head->next;
        free(temp); //Function to free the position of last node
    }
    printf("\nNew linked list is:\n");//Displaying new linked list
    display();
}
//Definition of function to delete node from end
void delete_at_end()
{
    struct node*current = head;
    struct node*temp;
    if(head == NULL)//Condition to check if node is empty
    {
        printf("List is empty\n");
    }
    else
    {
        while(current->next!=NULL && current->next->next!=NULL)//while loop to check if there are atleast 2 nodes in the list
        {
            current = current->next; 
            temp = current->next;
        }
        current->next = NULL;
        free(temp);  //Function to free the position of last node
    } 
    printf("\nNew linked list is:\n");//Displaying new linked list
    display();   
}


