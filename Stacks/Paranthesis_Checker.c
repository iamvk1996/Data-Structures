#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int top;
    int size;
    char *array;
};

struct node *createStack(int size)
{
    struct node *S=(struct node *)malloc(sizeof(struct node));
    S->top=-1;
    S->size=size;
    S->array=(char *)malloc(S->size*sizeof(char));
    return S;
}

void push(struct node *S,char data)
{
    if(S->top==(S->size-1))
        return;
    S->array[++S->top]=data;
}

char pop(struct node *S)
{
    if(S->top==-1)
        return -1;
    return S->array[S->top--];
}

int isbalanced(char *exp)
{
    int len=strlen(exp);
    struct node *s=createStack(len);
    int i=0;
    while(exp[i])
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(s,exp[i]);
        else if(exp[i]==')')
            {
                if(s->array[s->top]=='(')
                    pop(s);
                else
                    return 0;
            }
        else if(exp[i]==']')    
            {
            if(s->array[s->top]=='[')
                pop(s);
            else
                return 0;
            }
        else
        {
            if(s->array[s->top]=='{')
                pop(s);
            else
                return 0;
        }
        i++;
    }
    if(s->top==-1)
        return 1;
    else
        return 0;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char exp[100];
        scanf("%s",exp);
        if(isbalanced(exp))
            printf("balanced\n");
        else
            printf("not balanced\n");
    }
	return 0;
}
