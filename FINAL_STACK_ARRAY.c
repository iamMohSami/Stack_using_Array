
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack_arr[MAX];
int top = -1;

void push(int item);
int pop();
int stackTop();  
int stackbottom () ;
int isEmpty();
int isFull();
void display();
void peek_at_index();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Push\n");
                printf("2.Pop\n");
                printf("3.Display the top element\n");
                printf("4.Display the Bottom element\n");
                printf("5.Display all stack elements\n");
                printf("6.Check whether is Empty\n");
                printf("7.Check whether is Full\n");
                printf("8.Peek/Display any Element by Index\n");
                printf("9.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                 case 1 :
                        printf("\nEnter the item to be pushed : ");
                        scanf("%d",&item);
                        push(item);
                        break;
                 case 2:
                        item = pop();
                        printf("\nPopped item is : %d\n",item );
                        break;
                 case 3:
                        printf("\nItem at the top is : %d\n", stackTop() );
                        break;
                 case 4:
                         printf("\nItem at the Bottom is : %d\n", stackbottom() );
                        break;
                 case 5:
                        display() ;
                        break;
                case 6 :
                        isEmpty() ;
                        if(isEmpty()) {
                            printf("Stack is Empty\n") ;
                        }
                        else{
                            printf("Stack is Not Empty\n") ;
                        }
                        break; 
                case 7 : 
                        isFull() ;
                        if(isFull()) {
                            printf("Stack is Full\n") ;
                        }
                        else {
                            printf("Stack is Not Full\n") ;
                        }
                        break;
                case 8 :
                        peek_at_index() ;
                        break;
                case 9 :
                        exit(1) ;
                 default:
                        printf("\nWrong choice\n");
                }
        }

        return 0;

}
int isEmpty()
{
        if( top == -1 )
                return 1;
        else
                return 0;
}

int isFull()
{
        if( top == MAX-1 )
                return 1;
        else
                return 0;
}


void push(int item)
{
        if( isFull() )
        {
                printf("\nStack Overflow\n");
                return;
        }
        top++;
        stack_arr[top] = item;
}

int pop()
{
        int item;
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                return;
        }
        item = stack_arr[top];
        top--;
        return item;
}

int stackTop()
{
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                return;
        }
        return stack_arr[top];
}


void display()
{
        int i;
        if( isEmpty() )
        {
                printf("\nStack is empty\n");
                return;
        }
    printf("\nStack elements :\n\n");
        for(i=top;i>=0;i--)
                printf(" %d\n", stack_arr[i] );
        printf("\n");
}

int stackbottom () {
      if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                return;
        }
        return stack_arr[0];
}

void peek_at_index() {
        int index ;
        printf("The Index starts from Top i.e Top Index=1 and so on....\n" ) ;
        printf("Enter The Index Value :") ;
        scanf("%d",&index) ;
        int xyz = top-index+1 ;
        if(xyz<0) {
                printf("Not an Valid Index \n") ;
        }
        printf("The Element at %d index[From Top]is : %d",index,stack_arr[xyz]) ;
}