#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
} * s;

int isFull()
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (s->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void push(int val)
{
    if (isFull())
    {
        puts("StackOverflow cannot push\n");
    }
    else
    {
      s->top++;
      s->arr[s->top]=val;
      puts("Value pushed successfully\n");
    }
}
int pop()
{
    int val;
    if (isEmpty())
    {
          return -1;   
    }
    else
    {
        val=s->arr[s->top];
      s->top--;

      return val;   
    }
}
int peek(int i){
    if(s->top-i+1<0){
        return -1;
    }
    else{
        return s->arr[s->top-i+1];
    }
}
int main()
{
    int choice,val,a;
    char cont[10];
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 2;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    do
    {
        printf("\nPRESS 1 TO PUSH\nPRESS 2 TO POP\nPRESS 3 TO EXIT\nPRESS 4 To PEEK\n->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter a value to push:");
            scanf("%d",&val);
            push(val);
            break;
        }
        case 2:
        {
            a=pop();
            if(a==-1){
                printf("\nStackUnderflow cannot pop\n");
            }
            else{
            printf("%d Popped successfully\n",a);
            break;
            }
        }
        case 3:
        { 
            exit(0);
            break;
                    }
        case 4:
        {
        for(int i=1;i<=s->top+1;i++){
           printf("%d\n",peek(i));
           }
            break;
        }           
        default:printf("Please select a valid number.\n");
        }
     printf("Do you want to continue?\nType yes to continue:");
     scanf("%s",&cont);
    } while (cont[0]=='y' && cont[1]=='e' && cont[2]=='s');
    return 0;
}

