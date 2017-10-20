Node* deleteNode(Node *head,int x)
{
    if(head==NULL)
        return head;
        
    Node *temp=head;
    if(x==1)
    {
        head=temp->next;
        free(temp);
        return head;
    }
    
    for(int i=1;i<(x-1) && temp;i++)
    {
        temp=temp->next;
    }
    
    if(!temp && !temp->next)
        return head;
    Node *next=temp->next;
    temp->next=temp->next->next;
    free(next);
    return head;
}
