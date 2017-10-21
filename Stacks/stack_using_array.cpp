 //The structure of the class is

class Stack
{
private:
    int arr[1000];
    int top;
public:
    Stack(){top=-1;}
    int pop();
    void push(int);
};
/* The method push to push element into the stack */
void Stack :: push(int x)
{
        if(top==999)
            return;
        arr[++top]=x;
}
/*The method pop which return the element poped out of the stack*/
int Stack :: pop()
{
        if(top==-1)
            return -1;
        return arr[top--];
}
