#include <stdio.h>
#include<stdlib.h>
int CQ[100];
void enqueue();
void dequeue();
void display();
int max,i,choice;
int F =-1;
int R= -1;

void main() {
   
    printf("Enter array elements: ");
    scanf("%d",&max);
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
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
            printf("Enter valid choice: \n");
        }
    }
}
void enqueue()
{
    int data;
    /*if(F==0 && R==max-1)
    {
        printf("Overload\n");
    }*/
    if((R+1)%max == F){
        printf("Overflow\n");
    }
    else{
     if(F==-1 && R==-1)
    {
        F=0;
        R=0;
        //CQ[R] = data;
    }
    else if(F!=0 && R==max-1)
    {
        R = (R+1)%max;
    }
    /*printf("Enter element to be added: ");
    scanf("%d",&data);*/
    //R = (R+1)%max;
    CQ[R] = data;
   // printf("CQ[R]=%d, R=%d\n",CQ[R],R);
    R = (R+1)%max;
    }
}    
 
    

void dequeue()
{
    if(F == -1)
    {
        printf("Underflow");
    }
    if(F == R)
    {
        F= (F+1)%max;
    }
    printf("Element deleted from queue is: %d\n",CQ[F]);
}
void display()
{
    int i=F;
    if(F == -1)
    {
        printf("Empty\n");
    }
    while(i!=R)
    {
        printf("%d\t",CQ[i]);
        i = (i+1)%max;
    }    
    printf("%d\t",CQ[R]);
}    
    

    
    
    
