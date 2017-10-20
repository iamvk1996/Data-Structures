//Using two pointers
struct Node{
int data;
struct Node *next;
};

int getMiddle(Node *head)
{
   struct Node *fast=head,*slow=head;
   if(head==NULL)
    return -1;
   while(fast && fast->next)
   {
       fast=fast->next->next;
       slow=slow->next;
   }
   return slow->data;
}
