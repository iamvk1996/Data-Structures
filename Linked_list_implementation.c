struct node{
int data;
struct node *next;
};

struct node *createNode(int new_data)
{
struct node *s=(struct node *)malloc(sizeof(struct node));
s->data=new_data;
s->next=NULL;
return s;
}

void push(struct node **root_ref,int new_data)
{
struct node *s=createNode(new_data);
s->next=*root_ref;
*root_ref=s;
}

int pop(struct node **root_ref)
{
if(*root_ref==NULL)
  return -1;
struct node *temp=*root_ref;
int x=temp->data;
*root_ref=temp->next;
free(temp);
return x;
}

