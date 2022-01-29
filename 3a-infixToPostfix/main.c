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
    STACK s;
    char infix[30], postfix[30], symbo, ch;
    int i, j = 0;
    s.top = -1;
    printf("\nEnter a valid infix expression:");
    scanf("%s", infix);
    push(&s, '#');
    for (i = 0; infix[i] != '\0'; i++)
    {
        symbo = infix[i];
        if (isalnum(symbo))
            postfix[j++] = symbo;
        else
        {
            switch (symbo)
            {
            case '(':
                push(&s, '(');
                break;
            case ')':
                while ((ch = pop(&s)) != '(')
                    postfix[j++] = ch;
                break;
            default:
                while (precedence(symbo) <= precedence(peek(s)))
                {
                    if (symbo == peek(s) && precedence(symbo) == 3)
                        break;
                    postfix[j++] = pop(&s);
                }
                push(&s, symbo);
            }
        }
    }
    while (peek(s) != '#')
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
    printf("\nResultant postfix expression:");
    printf("%s\n", postfix);
    return 0;
}
