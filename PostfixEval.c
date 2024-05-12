#include<stdio.h>
#include<stdlib.h>
int stack[100];
int top = -1;
int max;

void push(int item)
{
    if(top>=max-1)
    {
        printf("/nStack full");
        return;
    }
    top++;
    stack[top]=item;
}
int pop()
{
    if(top == -1)
    {
        printf("/nStack empty");
        return -1;
    }
    int item = stack[top];
    top--;
    return item;
}
int is_operator(char symbol)
{
    if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
        return 1;
    return 0;    
}
int evaluate(char*expression)
{
    int i=0;
    char symbol = expression[i];
    int operand1,operand2,result;
    while(symbol != '\0')
    {
        if(symbol>='0' && symbol<='9')
        {
            int num = symbol - '0';
            push(num);
        }
        else if(is_operator(symbol))
        {
            operand2 = pop();
            operand1 = pop();
            switch(symbol)
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;    
            }
            push(result);
        }
        i++;
        symbol = expression[i];
    }
    result = pop();
    return result;
}
int main()
{
    printf("\nEnter array limit: ");
    scanf("%d",&max);
    char expression[] = "567+*8-";
    int result = evaluate(expression);
    printf("Result = %d\n",result);
    return 0;
}


//Enter array limit: 5
//Result = 57