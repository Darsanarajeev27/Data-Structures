#include <stdio.h>
#include<stdlib.h>
int stack[100],choice=0,n,top,val;
void push();
void pop();
void peek();
void display();
void isFull();
void isEmpty();

int main(){
    top = -1;
    printf("Enter the size of the stack:");
    scanf("%d",&n);
    printf("\n1.push\n2.pop\n3.peek\n4.display\n5.isFull\n6.isEmpty\n7.exit\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                isFull();
                break;
            case 6:
                isEmpty();
                break;
            case 7:
                exit(0);
            default:
               printf("Invalid choice!");
            
        }
    }
    return 0;
}
        void push()
        {
            if(top == n-1)
            {
                printf("Stack overflow\n");
            }
            else
            {
                printf("Enter value to be pushed: ");
                scanf("%d",&val);
                top++;
                stack[top]=val;
            }
        }
        void pop()
        {
            if(top == -1)
            {
                printf("Stack underflow\n");
            }
            else
            {
                printf("Popped element is %d\n",stack[top]);
                top--;
            }
        }
        void peek()
        {
            if(top ==-1)
            {
                printf("Stack underflow\n");
            }
            else
            {
                printf("%d\n",stack[top]);
            }
        }
        void display()
        {
            if(top==-1)
            {
                printf("Stack is empty\n");
            }
            else
            {
                for(int i=top;i>=0;i--)
                {
                    printf("%d\t",stack[i]);
                }
                printf("\n");
            }
        }
            void isFull()
            {
                if(top==n-1)
                {
                    printf("Stack is full\n");
                }
                else
                {
                    printf("Stack is not full\n");
                }
            }
            void isEmpty()
            {
                if(top==-1)
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("Stack is not empty\n");
                }
            }
        
        
