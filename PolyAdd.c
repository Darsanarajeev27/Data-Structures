/*#include <stdio.h>

void main() {
   int a,b,max;
   
   struct poly{
       int coeff;
       int exp;
   };
   struct poly p1[20], p2[20], p3[20];
   printf("Enter degree of first polynomial: ");
   scanf("%d",&a);
   for(int i=a;i>=0;i--){
       printf("Enter coeff of x^%d: ",i);
       scanf("%d",&p1[i].coeff);
       p1[i].exp=1;
   }
   printf("Enter degree of second polynomial: ");
   scanf("%d",&b);
   for(int i=b;i>=0;i--){
       printf("Enter coeff of x^%d: ",i);
       scanf("%d",&p2[i].coeff);
       p2[i].exp=i;
   }
   if(a>b){
       max = a;
   }
   else{
       max = b;
   }
   for(int i= max;i<=0;i--){
       if(p1[i].exp==p2[i].exp){
           printf("%d(x^%d) +", p1[i].coeff + p2[i].coeff, p1[i].exp);
       }
       else{
           if(max<=a)
           printf("%d(x^%d");
       }   
   }
   
}*/


#include <stdio.h>

int main() {
    int a,b,max;
    struct poly{
        int coeff;
        int expo;
    };
    struct poly p1[20], p2[20], p3[20];
    
    printf("Enter degree of 1st polynomial: ");
    scanf("%d",&a);
    for(int i=a;i>=0;i--)
    {
        printf("Enter coefficient of x^%d: ",i);
        scanf("%d",&p1[i].coeff);
        p1[i].expo=i;
    }
    
    printf("Enter degree of 2nd polynomial: ");
    scanf("%d",&b);
    for(int i=b;i>=0;i--)
    {
        printf("Enter coefficient of x^%d: ",i);
        scanf("%d",&p2[i].coeff);
        p2[i].expo=i;
        
    }
    if(a==b)
    {
        max = a;
    }
    else if(a>b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    
    for(int i=max;i>=0;i--)
    {
        if(p1[i].expo == p2[i].expo)
        {
            p3[i].coeff = p1[i].coeff+p2[i].coeff;
            //printf("%d(x^%d)+",p3[i].coeff,i);
        }
        else if(p1[i].expo>p2[i].expo)
        {
            p3[i].coeff=p1[i].coeff;
        }
        else
        {
            p3[i].coeff=p2[i].coeff;
        }
    }
    printf("Sum of polynomial:");
    for(int i=max;i>=1;i--)
    {
       printf("%d(x^%d)+",p3[i].coeff,i);
    }
    printf("%d(x^%d)",p3[0].coeff,0);

    return 0;
}