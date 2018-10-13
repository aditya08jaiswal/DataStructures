#include <stdio.h>
#define size 5
int rear = -1, front = -1;

struct Queue
{
    int id;
}Queue[size];

void enqueue()
{
    if (rear==front-1)
        printf("\nQueue is full\n");
    else{
        if(front==-1)
            front=0;
        rear++;
        printf("Enter Queue id\n");
        scanf("%d", &Queue[rear].id);
    }
}
void dequeue()
{
    if(rear==-1)
        printf("UNDERFLOW!");
    else{
        front = front+1;
        printf("Deleted");
        if(front>rear)
            front = rear = -1;
    }
}

void display()
{
    if(rear==-1)
        printf("\nQUEUE IS EMPTY\n");
    else
    {
        int i;
        for(i=front;i<=rear;i++)
        {
            printf("\n%d", Queue[i].id);
        }
    }
}

int main()
{
    int n;
    char k;
    do{
        printf("\nChoose one option\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: return 0;
        }
        printf("Do you wish to continue(y/n)?");
        scanf("%c", &k);
    }while(k=='y' || k=='Y');
    return 0;
    
}


