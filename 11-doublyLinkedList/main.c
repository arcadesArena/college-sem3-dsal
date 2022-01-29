/*
Develop and implement doubly linked list with header node with the following operations: (Header node should maintain the count of number of nodes in the list after each operation).
a) Insert a node at the end of the list.
b) Insert a new node next to a node whose information field is specified.
c) To delete first node if pointer to the last node is given.
d) To delete a node whose information is given.
e) To display the contents of the list.
f) To swap nth and mth nodes in the list.
[NOTE: either of the operations a, b, d & e or operations a, c, e & f must be specified in the examination]
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *llink,*rlink;
};
typedef struct node* NODE;
NODE getNode()
{
    NODE x;
    x = (NODE) malloc (sizeof(struct node));
    if(x == NULL)
    {
        printf("\nOut of Memory");
        exit(0);
    }
    return x;
}
void fnFreeNode(NODE x)
{
    free(x);
}
NODE pushAtEnd(NODE head,int val)
{
    NODE temp,cur;
    temp = getNode();
    temp->info = val;
    temp->rlink=NULL;
    temp->llink=NULL;
    cur = head;
    if (head->rlink == NULL)
    {
        head->rlink = temp;
        temp->llink = head;
        printf("Element inserted successfully\n");
        head->info++;
        return head;
    }
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;
    printf("Element inserted successfully\n");
    head->info++;
    return head;
}
NODE InsertFront(NODE head, int iItem)
{
    NODE temp;
    temp = getNode();
    temp->info = iItem;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (head->rlink == NULL)
    {
        head->rlink = temp;
        temp->llink = head;
        printf("Element inserted successfully\n");
        head->info++;
        return head;
    }
    temp->rlink = head->rlink;
    head->rlink = temp;
    temp->llink = head;
    printf("Element inserted successfully\n");
    head->info++;
    return head;
}
NODE DelFirst(NODE last)
{
    NODE second, first, head;
    if(last->llink == NULL)
    {
        printf("\nList is Empty");
        return last;
    }
    head = last->rlink;
    first = head->rlink;
    second = first->rlink;
    head->rlink = second;
    second->llink = head;
    printf("\nElement deleted is %d\n", first->info);
    fnFreeNode(first);
    head->info -= 1;
    return head;
}
NODE InsertNext(NODE head, int iItem)
{
    NODE temp,cur,next;
    if(head->rlink == NULL)
    {
        printf("\nList is Empty\n");
        return head;
    }
    cur = head->rlink;
    while(cur != NULL && iItem != cur->info)
    {
        cur = cur->rlink;
    }
    if(cur == NULL)
    {
        printf("\nSpecified Node not found\n");
        return head;
    }
    next = cur->rlink;
    printf("\nEnter the item to be inserted to the next of %d\n",iItem);
    temp = getNode();
    scanf("%d",&temp->info);
    cur->rlink = temp;
    temp->llink = cur;
    next->llink = temp;
    temp->rlink = next;
    head->info += 1;
    return head;
}
NODE DelElePos(NODE head, int iPos)
{
    NODE prev,cur,next;
    int count = 1;
    if(head->rlink == NULL)
    {
        printf("\nList is Empty\n");
        return head;
    }
    cur = head->rlink;
    while(cur != NULL && count != iPos)
    {
        cur = cur->rlink;
        count++;
    }
    if(count == iPos)
    {
        prev = cur->llink;
        next = cur->rlink;
        prev->rlink = next;
        next->llink = prev;
        head->info -= 1;

        printf("\nElement deleted is %d\n", cur->info);
        fnFreeNode(cur);
    }
    if(cur == NULL)
    {
        printf("\nItem not found\n");
        return head;
    }
    return head;
}
void display(NODE head)
{
    NODE temp;
    if(head->rlink == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    printf("\n##Contents of the List##\n");
    printf("\n%d<-", head->info);
    for(temp = head->rlink; temp != NULL; temp = temp->rlink)
        printf("%d ",temp->info);
    printf("\n");
}
NODE SwapNodes(NODE head, int m, int n)
{
    int temp, count = 1;
    NODE cur, mpos, npos;
    cur = head->rlink;
    while(cur != NULL && count != m)
    {
        cur = cur->rlink;
        count++;
    }
    if(cur != NULL)
    {
        mpos = cur;
    }
    else
    {
        printf("\nNode %d does not exist\n", m);
        return head;
    }
    while(cur != NULL && count != n)
    {
        cur = cur->rlink;
        count++;
    }
    if(cur != NULL)
    {
        npos = cur;
    }
    else
    {
        printf("\nNode %d does not exist\n", n);
        return head;
    }
    temp = mpos->info;
    mpos->info = npos->info;
    npos->info = temp;
    return head;
}
int main()
{
    NODE head,last;
    int Choice,val,iItem, iKey, iPos, iM, iN;

    head = getNode();
    head->rlink = NULL;
    head->llink = NULL;
    head->info = 0;
    while(1)
    {
        printf("\n1.Insert Front\n2.Insert at end\n3.Insert to the next of a given Node");
        printf("\n4.Delete First Node");
        printf("\n5.Delete a Node whose position is specified");
        printf("\n6.Display\n7.Swap Nodes\n8.Exit\n");
        printf("\nEnter your Choice:");
        scanf("%d",&Choice);
        switch(Choice)
        {
        case 1:
            printf("\nEnter the Item to be inserted:");
            scanf("%d",&iItem);
            head = InsertFront(head, iItem);
            break;
        case 2:
            printf("\nEnter the Item to be inserted:");
            scanf("%d",&val);
            head = pushAtEnd(head, val);
            break;
        case 3:
            printf("\nEnter the key value of the node:");
            scanf("%d", &iKey);
            head = InsertNext(head, iKey);
            break;
        case 4:
            last = head->llink;
            head = DelFirst(last);
            break;
        case 5:
            printf("\nEnter the position of the element to be deleted:");
            scanf("%d",&iPos);
            head = DelElePos(head, iPos);
            break;
        case 6:
            display(head);
            break;
        case 7:
            printf("\nEnter the positions m and n of the nodes to be swapped(such that m < n):");
            scanf("%d%d",&iM, &iN);
            if(iM > iN)
            {
                printf("\nInvalid input\n");
            }
            else
            {
                head = SwapNodes(head, iM, iN);
            }
            break;
        case 8:
            exit(0);
        }
    }
    return 0;
}
