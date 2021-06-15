#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top;
// traversal of the stack
void traversal(){
    struct node *i=top;
    int a=1;
    do{
     printf("element %d=%d\n",a++,i->data);
     i=i->next;
    }while(i!=NULL);
}
// to check if the stack is full
int isfull(){
    // creating a new node to check if it is NULL or not(null means no memory to make another node)
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        return 1;
    }
return 0;
}
// to check if the stack is empty
int isempty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}
// push in stack
void push(int val){
    if(isfull()){
        printf("Stack overflow\n");
    }
    else{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=top;
    newnode->data=val;
    top=newnode;
    }
}
// pop from stack
int pop(){
    if(isempty()){
        printf("stack underflow");
        return -1;
    }
    else{
        int val;
        struct node *temp=top;
        top=top->next;
        val=temp->data;
        free(temp);
        return val;
    }
}
//to get the top of the stack
int stack_top(){
    return top->data;
}
//to create stack with a limit of a user
void create_stack(int limit){
int i=0,val;
while(i<limit){
    printf("Enter the element %d=",++i);
    scanf("%d",&val);
push(val);
}
}
// to get the bottom of the stack
int stack_bottom(){
    struct node *temp=top;
    do{
        temp=temp->next;
    }while(temp->next!=NULL);
    return temp->data;
    }

int main(){
   top=NULL; 
int limit,choice,val;
char cont;
printf("Enter the limit of your stack:");
scanf("%d",&limit);
create_stack(limit);
do{
    printf("\n\nWhat do you want to do?\nPress 1 to push a new element\nPress 2 to pop an element\nPress 3 to see the top of the stack\nPress 4 to see the bottom of the stack\n-->");
    scanf("%d",&choice);
    switch(choice){
        case 1:{
                 printf("Enter a value to push:");
                 scanf("%d",&val);
                 push(val);
                 traversal();
                 break;
        }
        case 2:{
            int check;
            //checking if the values is not -1
                 check=pop();
                 if(check==-1){
                     printf("%d \n",check);
                 }
                 traversal();
                 break;
        }
        case 3:{
            // to check top of the stack
            printf("Top of stack is: %d\n",stack_top());
            break;
        }
        case 4:{
        // to check bottom of the stack
        printf("Bottom of the stack is %d\n",stack_bottom());
        break;
        }
        default: printf("Choose between 1-4 only\n");  
    }
     printf("\nDo you want to do anything else?");
        scanf("%s",&cont);
}while(cont=='y');

    return 0;
}