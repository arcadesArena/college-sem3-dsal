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
typedef struct{
    int top;
    float data[MAXSIZE];
} STACK;
int precedence(char op){
    switch (op)
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

float eval(char * postfix)
{
    STACK stack;
    float x1, x2, sym[26];
    char ch;
    int i;
    stack.top = -1;
    for (i = 0; i < 26; i++)
        sym[i] = -1;
    i = 0;
    while ((ch = postfix[i++]) != '\0')
    {
        if (isdigit(ch))
            stack.data[++stack.top] = ch - '0';
        else if (isalpha(ch))
        {
            if (ch >= 'a' || ch <= 'z')
                ch -= 32;
            if (sym[ch - 'A'] == -1)
            {
                printf("Enter the value of %c: ", ch);
                scanf("%f", &sym[ch - 'A']);
                stack.data[++stack.top] = sym[ch - 'A'];
            }
            else
                stack.data[++stack.top] = sym[ch - 'A'];
        }
        else
        {
            x2 = stack.data[stack.top--];
            x1 = stack.data[stack.top--];
            switch (ch)
            {
            case '+':
                stack.data[++stack.top] = x1 + x2;
                break;
            case '-':
                stack.data[++stack.top] = x1 - x2;
                break;
            case '*':
                stack.data[++stack.top] = x1 * x2;
                break;
            case '/':
                stack.data[++stack.top] = x1 / x2;
                break;
            default:
                printf("Invalid operation");
                exit(0);
            }
        }
    }
    if(stack.top==0)
        return stack.data[stack.top];
    else
    {
        printf("\nInvalid expression");
        exit(1);
    }
}
int main()
{
    int n;
    printf("Enter\n1-to evaluate postfix\n2-to evaluate prefix\nchoice-");
    scanf("%d",&n);
    char expression[30];
    printf("Enter a valid expression: ");
    scanf("%s", expression);
    switch(n)
    {
    case 1:
        printf("Result of evaluation is %0.2f\n\n", eval(expression));
        break;
    case 2:
        strrev(expression);
        printf("Result of evaluation is %0.2f\n\n", eval(expression));
        break;
    default:
        printf("Error: invalid choice");
    }
    return 0;
}
