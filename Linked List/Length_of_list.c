//Recursive Solution

int getCount(struct node* head){
    if(!head)
        return 0;
    else
            return 1+getCount(head->next);
}

//Iterative Solution
int getCount(struct node* head){
    int count=0;
    struct node *temp=head;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
