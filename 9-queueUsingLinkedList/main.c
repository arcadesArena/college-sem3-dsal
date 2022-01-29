/*
Develop and implement linear QUEUE of integers using singly linked list and perform the following operations:
(a) insertion,
(b) deletion and
(c) display
*/
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define QUEUE_SIZE 5
struct node{
    char data[QUEUE_SIZE][30];
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
            printf("%s\n",tmp->data);
            tmp=tmp->next;
        }
    }
}
void insertFirst(){
    NODE tmp;
    char item[30];
    printf("Enter string data member: ");
    scanf("%s",item);
    tmp=getNode();
    strcpy(tmp->data,item);
    tmp->next=first;
    first=tmp;
    printf("Pushed: %s",item);
}
void deleteLast()
{
    NODE ptr,temp;
    if(first==NULL)
        printf("List is empty");
    else if(first->next==NULL)
    {
        printf("deleted: %s",first->data);
        freeNode(first);
        first=NULL;
        //printf("Only remaining node id deleted");
    }
    else
    {
        ptr=first;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        printf("deleted: %s",ptr->data);
        temp->next=NULL;
        freeNode(ptr);
        //printf("Deleted node from last");
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n==========CHOICE===========\n\t1-insert\n\t2-delete\n\t3-display\n\t4-exit\nchoice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertFirst();
            break;
        case 2:
            deleteLast();
            break;
        case 3:
            printList();
            break;
        case 4:
            exit(0);
        default:
            printf("Error: invalid choice");
            break;
        }
    }
    return 0;
}
