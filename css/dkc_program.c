
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
void con(char *);
void push(char);
char pop();
int pri(char);
#define size 25
int top=-1;
char stack[size];
int main() {
    char exp[20],*e;
    printf("Enter ");
    scanf(" %s",exp);
    e=exp;
    con(e);
    return 0;
}
void push(char x)
{
    top++;
    stack[top]=x;
}
char pop()
{
    if(top==-1)
    return -1;
    else
    {
    return stack[top--];
    }
}
int pri(char x)
{
    if(x=='+'|| x=='-')
    return 1;
    else if(x=='*'||x=='/'||x=='%')
    return 2;
    else if(x=='('||x==')')
    return 0;
    else;
}
void con(char *e)
{
    char s;
    while(*e!='\0')
    {
    if(isalpha(*e))
    printf(" %c",*e);
    else if(*e=='(')
    {
        push(*e);
    }
    else if(*e==')')
    {
        while((s=pop())!='(')
        {
            printf(" %c",s);
        }
    }
    else
    {
        while(pri(stack[top])>=pri(*e))
        {
            printf(" %c",pop());
        }
        push(*e);
    }
    e++;
    }
    while(top!=-1)
    {
        printf(" %c",pop());
    }
}