/*
Develop and implement a STACK of integers using array and perform the following operations:
(a) PUSH
(b) POP
(c) DISPLAY and
(d)check whether the contents of stack form a palindrome
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef struct{
    int top;
    char data[SIZE];
}stack;
int push(stack *st,int element){
    if(st->top>=SIZE-1)
    {
        printf("Overflow");
        return -1;
    }
    else
    {
        st->data[++st->top]=element;
        printf("Entry successful\n");
        return 0;
    }
}
int pop(stack *st){
    if(st->top==-1)
    {
        printf("Underflow");
        return -2;
    }
    else
    {
        return st->data[st->top--];
    }
}
void display(stack *st){
    if(st->top==-1)
        printf("Stack is empty");
    else
    {
        printf("Stack:\n");
        for(int i=st->top;i>=0;i--)
            printf("%d\n",st->data[i]);
    }
}
void palindrome(stack *st){
    int p=st->top;
    for(int i=0;i<=p;i++)
    {
        if(st->data[i]!=st->data[p-i])
        {
            printf("Stack is not palindrome");
            return;
        }
    }
    printf("Stack is palindrome");
}
int main(){
    stack s;
    s.top=-1;
    int ch,n;
    printf("Enter your choice:\n1-push\n2-pop\n3-display\n4-palindrome\n5-exit\nchoice:");
    scanf("%d",&ch);
    while(1)
    {
        switch(ch)
        {
        case 1:
            printf("Enter the the value to push: ");
            scanf("%d",&n);
            push(&s,n);
            break;
        case 2:
            printf("popped value is %d",pop(&s));
            break;
        case 3:
            display(&s);
            break;
        case 4:
            palindrome(&s);
            break;
        case 5:
            exit(0);
        }
        printf("\nchoice:");
        scanf("%d",&ch);
    }
    return 0;
}
