struct node
{
int data;
struct node *next;
};

int detectloop(struct node *head)
{
   if(head==NULL)
    return 0;
   struct node *fast=head,*slow=head;
   while(fast && fast->next)
   {
       fast=fast->next->next;
       slow=slow->next;
       if(slow==fast)
        return 1;
   }
   return 0;
}
