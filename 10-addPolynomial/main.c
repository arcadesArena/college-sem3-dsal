/*
Develop and implement addition of two polynomials with two coefficients using singly linked lists
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coeff;
    float powx;
    float powy;
    int flag;
    struct node * next;
};
typedef struct node * NODE;
NODE getNode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("WARN: could not allot memory");
        return;
    }
    return x;
}
NODE insAtLast(NODE first, float cf, float px, float py)
{
    NODE newnode,temp;
    newnode =getNode();
    newnode->coeff = cf;
    newnode->powx = px;
    newnode->powy = py;
    newnode->flag = 0;
    newnode->next = NULL;
    if (first == NULL)
        first = newnode;
    else
    {
        temp = first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return first;
}
NODE readPoly(NODE first)
{
    float cf, px, py;
    printf("Enter number of terms:");
    int term;
    scanf("%d",&term);
    while (term--)
    {
        printf("\nEnter the coefficient of x and y: ");
        scanf("%f", &cf);
        printf("\nEnter power of x: ");
        scanf("%f", &px);
        printf("\nEnter power of y: ");
        scanf("%f", &py);
        first=insAtLast(first, cf, px, py);

    }
    return first;
}
void display(NODE first)
{
    if (first == NULL)
    {
        printf("\nEmpty list");
        return;
    }
    while (first->next!= NULL)
    {
        printf("%.0fx^(%0.f)y^(%0.f) + ", first->coeff, first->powx, first->powy);
        first = first->next;
    }
    printf("%.0fx^(%0.f)y^(%0.f) ", first->coeff, first->powx, first->powy);
}
NODE addPoly(NODE p1, NODE p2, NODE p3)
{
    NODE temp;
    float cf;
    temp = p2;
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            if ((p1->powx == p2->powx) && (p1->powy == p2->powy))
                break;
            p2 = p2->next;
        }
        if (p2 == NULL)
            p3 = insAtLast(p3, p1->coeff, p1->powx, p1->powy);
        else
        {
            cf = p1->coeff + p2->coeff;
            if (cf != 0)
            {
                p3 = insAtLast(p3, cf, p1->powx, p1->powy);
                p2->flag = 1;
            }
        }
        p2 = temp;
        p1 = p1->next;
    }
    p2 = temp;
    while (p2 != NULL)
    {
        if (p2->flag == 0)
            p3 = insAtLast(p3, p2->coeff, p2->powx, p2->powy);
        p2 = p2->next;
    }
    return p3;
}
int main()
{
    NODE p1=NULL,p2=NULL,p3=NULL;
    printf("\nEnter the first polynomial:\n");
    p1=readPoly(p1);
    printf("\nEnter the second polynomial:\n");
    p2=readPoly(p2);
    p3=addPoly(p1, p2, p3);
    printf("\nOur first polynomial is:    ");
    display(p1);
    printf("\nOur second polynomial is:   ");
    display(p2);
    printf("\n\nThe final resultant polynomial is:\n");
    display(p3);
    return 0;
}
