/*
Write a C program to convert
(a) the given infix expression to postfix expression.
(b) the given infix expression to prefix expression.
(c) to evaluate a given prefix/postfix expression.
[NOTE: either a, b, or c must be specified in the examination].
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 30
typedef struct
{
    int top;
    char items[MAXSIZE];
} STACK;
void push(STACK *s, char data)
{
    s->items[++s->top] = data;
}
char pop(STACK *s)
{
    return (s->items[s->top--]);
}
char peek(STACK s)
{
    return (s.items[s.top]);
}
int precedence(char symb)
{
    switch (symb)
    {
    case '#':
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '|':
    case '%':
        return 2;
    case '$':
    case '^':
        return 3;
    }
}
int main()
{
    int i, j = 0;
    char infix[20],prefix[20], ch, c;
    STACK st;
    st.top = -1;
    printf("\nEnter a valid infix expression: ");
    scanf("%s",infix);
    i = strlen(infix) - 1;
    while (i>=0)
    {
        ch = infix[i];
        if (isalpha(ch) || isdigit(ch))
            prefix[j++]=ch;
        else
        {
            switch (ch)
            {
            case ')':
                push(&st,ch);
                break;
            case '(':
                while ((c = pop(&st)) != ')')
                    prefix[j++] = c;
                break;
            default:
                while (precedence(ch) <= precedence(peek(st)))
                    prefix[j++] = pop(&st);
                push(&st,ch);
                break;
            }
        }
        i--;
    }
    while (st.top >= 0)
        prefix[j++] = pop(&st);
    prefix[j] = '\0';
    printf("\nEquivalent prefix expression : %s", strrev(prefix));
    return 0;
}

