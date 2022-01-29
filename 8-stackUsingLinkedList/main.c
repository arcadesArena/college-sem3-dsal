/*
Develop and implement a STACK of integers using singly linked list and perform the following operations:
(a) PUSH
(b) POP
(c) DISPLAY
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};
typedef struct node * NODE;
NODE first=NULL;
NODE getNode(){
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Node could not be created");
        exit(0);
    }
    //printf("Node created");
    return x;
}
void freeNode(struct node * ptr){
    free(ptr);
}
void printList(){
    NODE tmp=first;
    if(tmp==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        printf("Stack contents:\n");
        while(tmp!=NULL)
        {
            printf("%d\n",tmp->data);
            tmp=tmp->next;
        }
    }
}
void insertFirst(){
    NODE tmp;
    int item;
    printf("Enter data member: ");
    scanf("%d",&item);
    tmp=getNode();
    tmp->data=item;
    tmp->next=first;
    first=tmp;
    printf("Pushed: %d",item);
}
void deleteFirst(){
    NODE tmp;
    if(first==NULL)
    {
        printf("Empty stack");
        return;
    }
    tmp=first;
    printf("Popped: %d",tmp->data);
    first=tmp->next;
    freeNode(tmp);
    //printf("Node deleted");
}
int main(){
    int choice;
    while(1)
    {
        printf("Enter your choice:\n1-push\n2-pop\n3-display\n4-exit\nchoice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertFirst();
            break;
        case 2:
            deleteFirst();
            break;
        case 3:
            printList();
            break;
        case 4:
            exit(0);
        default:
            printf("Error: invalid choice");
        }
        printf("\n");
    }
    return 0;
}
