/*
Develop and implement linear QUEUE of strings using array and perform the following operations:
(a) insertion,
(b) deletion and
(c) display
*/

#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define QUEUE_SIZE 5
typedef struct
{
    char queue[QUEUE_SIZE][30];
    int front,rear;
} QUEUE;

int isFull(QUEUE q)
{
    if (q.rear == QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty(QUEUE q)
{
    if (q.rear+1 == q.front || q.front==-1)
        return 1;
    else
        return 0;
}
void insertRear(QUEUE *q,char val[])
{
    if(q->front==-1)
        q->front=0;
    strcpy(q->queue[++q->rear],val);
}
void deleteFront(QUEUE *q)
{
    printf("Deleted: %s",q->queue[q->front++]);
    if(q->front==QUEUE_SIZE)
    {
        q->front=-1;
        q->rear=-1;
    }
}
void display(QUEUE * q)
{
    for (int i = q->front; i <= q->rear; i++)
        printf("%s\n", q->queue[i]);
    printf("\n");
}
int main()
{
    QUEUE q;
    q.front=q.rear=-1;
    int choice;
    char element[30];
    while (1)
    {
        printf("\n\n==========CHOICE===========\n\t1-insert\n\t2-delete\n\t3-display\n\t4-exit\nchoice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (!isFull(q))
            {
                printf("Enter an element: ");
                scanf("%s", element);
                insertRear(&q,element);
            }
            else
                printf("Queue is full");
            break;
        case 2:
            if (!isEmpty(q))
            {
                deleteFront(&q);
            }
            else
                printf("Queue is empty");
            break;
        case 3:
            if (!isEmpty((q)))
            {
                printf("Contents of queue\n");
                display(&q);
            }
            else
                printf("Queue is empty");
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
