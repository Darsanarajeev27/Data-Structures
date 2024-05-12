#include<stdio.h>
#include<stdlib.h>
 
 int PQ[100];
 int F=-1,R=-1,i;
 int data,max,x;
 void enqueue(int data);
 void dequeue();
 void priorityCheck(int data);
 void display();

 int main()
 {
    int choice;
    printf("Enter no. of elements in queue: " );
    scanf("%d",&max);
    printf("\n1.Insert element\n2.Delete element\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be added:");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("The priority queue is:\n");
                display(); 
                break;   
            case 4:
                exit(0);    
            default:
                printf("Enter valid choice!\n");
                break;    
        }
    }
 }
 void enqueue(int data)
 {
    if(R==max-1)
    {
        printf("Overflow");
    }
    else if(F==-1 && R==-1)
    {
        F =0;
        R=0;
        PQ[R] = data;
    }
    else
    {
        priorityCheck(data);
        R++;
    }
 }
 void priorityCheck(int data)
 {
    int i,j;
    for(i=0;i<=R;i++)
    {
        if(data>PQ[i])
        {
            for(j=R+1;j>i;j--)
            {
                PQ[j] = PQ[j-1];
            }
            PQ[i] = data;
            return;
        }
    }
    PQ[i] = data;
 }
 void dequeue()
 {
    if(F==-1 && R==-1)
    {
        printf("Underflow\n");
    }
    else if(F==R)
    {
        printf("%d is deleted\n",PQ[F]);
        F = -1;
        R = -1;
    }
    else
    {
        printf("%d is deleted\n",PQ[F]);
        F++;
    }
 }
 void display()
 {
    if(F == -1 && R ==-1)
    {
        printf("Queue underflow\n");
    }
    else{
        for(i=F;i<=R;i++)
        {
            printf("%d\t",PQ[i]);
        }
        printf("\n");
    }
 }