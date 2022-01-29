/*
Develop and implement singly linked list with integer data and perform the following operations:
a) to insert a node at the end of the list.
b) to delete the first node in the list.
c) to insert a node at the specified position in the list (1<=pos<=n where ‘n’ is the total number of nodes in the list & ‘pos’ is the position where data is to be inserted).
d) to display the contents of the list.
e) to reverse a given list.
[NOTE: either of the operations a, b, d & e or operations a, b, c & d must be specified in the examination].
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
void insertLast(int item){
    NODE ptr,temp;
    temp=getNode();
    temp->data=item;
    temp->next=NULL;
    if(first==NULL)
        first=temp;
    else
    {
        ptr=first;
        while(1)
        {
            if(ptr==NULL)
            {
                ptr=temp;
                break;
            }
            ptr=ptr->next;
        }
    }
    printf("Node inserted at the end");
}
void insertLastHack(NODE pt,int item){
    NODE ptr,temp;
    temp=getNode();
    temp->data=item;
    if(pt==NULL)
    {
        temp->next=NULL;
        pt=temp;
        printf("Node inserted at the end of array list");
    }
    else
    {
        ptr=pt;
        while(ptr!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
        temp->next=NULL;
        printf("Node inserted at the end");
    }
}
int deleteFirst(){
    NODE tmp;
    int n;
    if(first==NULL)
    {
        printf("Empty");
        return 0;
    }
    tmp=first;
    n=tmp->data;
    first=tmp->next;
    freeNode(tmp);
    //printf("Node deleted");
    return n;
}
void printList(){
    NODE p=first;
    if(p==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}
void insertAtPosition(int item,int pos){
    NODE newNode,cur,prev;
    int count=0;
    newNode=getNode();
    newNode->next=NULL;
    if(first==NULL && pos==1)
        first=newNode;
    if(first==NULL)
    {
        printf("Invalid position list does not exist");
        return;
    }
    count=1;
    prev=NULL;
    cur=first;
    while(cur!=NULL && count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=newNode;
        newNode->next=cur;
        printf("Node inserted\n");
        return;
    }
    printf("Invalid position");
}
/*NODE reverseList(NODE alpha){
    NODE temp;
    temp=alpha;
    if(temp!=NULL)
    {
        reverseList(temp->next);

    }
    else
    {
        s
    }
}*/
NODE reverseListHack(NODE ogList){
    NODE temp,second=NULL;
    temp=ogList;
    while(temp!=NULL)
    {
        insertLastHack(second,temp->data);
        temp=temp->next;
    }
    return second;
}
int main(){
    int choice,n,p;
    while(1)
    {
        printf("\n\n1. enter at the end\n2.delete from front\n3.display the list\n4.insert node at a position\n5.reverse the list\n6.exit\nchoice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number to be inserted at last:");
            scanf("%d",&n);
            insertLast(n);
            break;
        case 2:
            printf("Deleted the first node: %d",deleteFirst());
            break;
        case 3:
            printf("Contents of the list:\n");
            printList();
            break;
        case 4:
            printf("Enter the data to insert:");
            scanf("%d",&n);
            printf("Enter the position at which to insert it:");
            scanf("%d",&p);
            insertAtPosition(n,p);
            break;
        case 5:
            printf("The original list is:");
            printList();
            first=reverseListHack(first);
            printf("The reversed list is:");
            printList();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("WARN: invalid choice");
        }
    }
    return 0;
}
