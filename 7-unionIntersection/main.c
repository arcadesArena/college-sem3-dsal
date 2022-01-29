/*
Develop and implement two ordered singly linked lists with the following operations:
a) insert into list1.
b) insert into list2.
c) to perform UNION of list1 and list2
d) to perform INTERSECTION of list1 and list2
e) display the contents of all three lists.
[NOTE: either of the operations a, b, c & e or operations a, b, d & e must be specified in the examination]
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};
typedef struct node * NODE;
NODE getNode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Node could not be allocated");
        exit(0);
    }
    return x;
}
NODE insertInOrder(NODE start,int val)
{
    NODE newl,temp,previous;
    newl=getNode();
    newl->data = val;
    newl->next = NULL;
    if (start == NULL)
        start = newl;
    else if(val < start->data)
    {
        newl->next = start;
        start = newl;
    }
    else
    {
        previous = start;
        temp = start->next;
        while(temp != NULL && val > temp->data)
        {
            previous = temp;
            temp = temp->next;
        }
        if(temp == NULL)
        {
            previous->next = newl;
        }
        else
        {
            newl->next = temp;
            previous->next = newl;
        }
    }
    return start;
}
int searchKey(NODE first,int k)
{
    NODE temp;
    int flag=0;
    temp=first;
    while(temp!=NULL)
    {
        if(temp->data==k)
            flag=1;
        temp=temp->next;
    }
    return flag;
}
NODE unionList(NODE list1,NODE list2)
{
    NODE list3=NULL;
    int e;
    if(list1==NULL && list2==NULL)
    {
        printf("Both list are empty");
        return;
    }
    while(list1!=NULL)
    {
        e=list1->data;
        if(!searchKey(list3,e))
            list3=insertInOrder(list3,e);
        list1=list1->next;
    }
    while(list2!=NULL)
    {
        e=list2->data;
        if(!searchKey(list3,e))
            list3=insertInOrder(list3,e);
        list2=list2->next;
    }
    return list3;
}
NODE intersectionList(NODE list1,NODE list2)
{
    NODE list3=NULL;
    int e;
    if(list1==NULL && list2==NULL)
    {
        printf("Both list are empty");
        return;
    }
    while(list1!=NULL)
    {
        e=list1->data;
        if(searchKey(list2,e))
        {
            if(!searchKey(list3,e))
                list3=insertInOrder(list3,e);
        }
        list1=list1->next;
    }
    return list3;
}
void display(NODE list)
{
    NODE temp=list;
    if(temp==NULL)
        printf("List is empty");
    else
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    NODE list1=NULL,list2=NULL,list3=NULL;
    int n,c;
    while(1)
    {
        printf("\n1-to insert in list1\n2-to insert in list2\n3-perform union of list1 and list2\n4-perform intersection of list1 and list2\n5-display all lists\n6-exit\nchoice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter a number:");
            scanf("%d",&n);
            list1=insertInOrder(list1,n);
            break;
        case 2:
            printf("Enter a number:");
            scanf("%d",&n);
            list2=insertInOrder(list2,n);
            break;
        case 3:
            list3=unionList(list1,list2);
            printf("\nUNION:\n");
            display(list3);
            break;
        case 4:
            list3=intersectionList(list1,list2);
            printf("\nINTERSECTION:\n");
            display(list3);
            break;
        case 5:
            printf("\nLIST 1: ");
            display(list1);
            printf("\nLIST 2: ");
            display(list2);
            printf("\nLIST 3: ");
            display(list3);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
    return 0;
}
