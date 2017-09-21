#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *array;
};

struct stack *createStack(int size)
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=size;
    s->array=(char*)malloc(s->size*sizeof(char));
    return s;
}

void push(struct stack *s,char data)
{
    if(s->top==(s->size-1))
        return;
    s->array[++s->top]=data;
}

char pop(struct stack *s)
{
    if(s->top==-1)
        return -1;
    return s->array[s->top--];
}

int prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 3;
    }
    return -1;
}

void infixtopost(char *exp)
{
    int len=strlen(exp);
    char post[len];
    struct stack *s=createStack(len);
    int k=0;
    for(int i=0;exp[i];i++)
    {
        if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
            post[k++]=exp[i];
        else if(exp[i]=='(')
            push(s,exp[i]);
        else if(exp[i]==')')
            {
                while(s->top!=-1 && s->array[s->top]!='(')
                    post[k++]=pop(s);
                pop(s);
            }
        else
            {
                while(s->top!=-1 && prec(exp[i])<=prec(s->array[s->top]))
                    post[k++]=pop(s);
                push(s,exp[i]);
            }
    }
    
    while(s->top!=-1)
        post[k++]=pop(s);
    post[k]='\0';
    printf("%s\n",post);
    
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    char exp[30];
	    scanf("%s",exp);
	    infixtopost(exp);
	}
	return 0;
}
