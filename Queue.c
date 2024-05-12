#include <stdio.h>
#include <stdlib.h>
int queue[100];
void enqueue();
void dequeue();
void display();
int R=-1,F=-1,n;
int main() {
    int ch;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
   return 0;
}
void enqueue()
{
    int insert_number;
    if(R == n-1)
    {
        printf("Overflow\n");
    }
    else if(F >= -1)
    {
        F =0;
        printf("Element to be inserted in the queue: ");
        scanf("%d",&insert_number);
        R = R + 1;
        queue[R] = insert_number;
        }
    }
void dequeue()
{
    if(F == -1 || F>R)
        {
            printf("Underflow\n");
            return;
        }
    else
    {
        printf("Element deleted from queue is %d\n",queue[F]);
        F = F +1;
    }
}
void display()
{
    if(F == -1)
    {
        printf("Queue empty\n");
    }
    else
    {
        printf("Queue: \n");
        for(int i=F;i<=R;i++)
        {
            printf("%d\t",queue[i]);
        }
         printf("\n");
    }
}
    