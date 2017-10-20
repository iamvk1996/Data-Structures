//Iterative Solution

void reverse(struct node **head_ref)
{
  if(*head_ref==NULL || *head_ref->next==NULL)
    return;
  struct Node *cur=*head_ref,*next,*prev=NULL;
  while(cur!=NULL)
  {
      next=cur->next;
      cur->next=prev;
      prev=cur;
      cur=next;
  }
  *head_ref=prev;
}
