/*
Develop and implement CIRCULAR QUEUE of integers using array and perform the following operations:
(a) insertion,
(b) deletion and
(c) display.
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE first=NULL;
NODE getnode(){
    NODE x;
    x=(NODE *)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("node is not created...");
        exit(0);
    }
    return x;
}
void freenode(struct node *ptr){
    free(ptr);
}
void InsertLast(){
    NODE ptr,temp;
    temp=getnode();
    int item;
    printf("Enter the item to be inserted: ");
    scanf("%d",&item);
    temp->data=item;
    if(first==NULL)
    {
        first=temp;
        temp->next=NULL;
    }
    else
    {
        ptr=first;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
        printf("Inserted: %d",item);
    }
}
void DeleteFirst()
{
    NODE temp;
    if(first==NULL)
    {
        printf("\nlist is empty...");
        return;
    }
    temp=first;
    first=temp->next;
    freenode(temp);
    printf("\nDeleted");
}
void printList(struct node *p)
{
    printf("Queue contents:\n");
    while(p!=NULL)
    {
        printf("%d - ",p->data);
        p=p->next;
    }
}
void main()
{
    int choice;
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:InsertLast();
                   break;
            case 2:DeleteFirst();
                   break;
            case 3:printList(first);
                   break;
            case 4:exit(0);
            default:printf("\n Invalid input.");
        }
    }
}
