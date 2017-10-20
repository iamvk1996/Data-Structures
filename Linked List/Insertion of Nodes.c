Structure of the linked list node is as
struct node
{
    int data;
    struct node *next;
};
*/
// function inserts the data in front of the list
void insertAtBegining(struct node** headRef, int newData)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=newData;
    new_node->next=*headRef;
    *headRef=new_node;
}
// function appends the data at the end of the list
void insertAtEnd(struct node** headRef, int newData)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=newData;
    new_node->next=NULL;
    
    if(*headRef==NULL)
    {
        *headRef=new_node;
        return;
    }
    
    struct node *temp=*headRef;
    while(temp->next)
        temp=temp->next;
    temp->next=new_node;
    
    
}
