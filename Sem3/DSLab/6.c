#include<stdlib.h>
#include<stdio.h>
#define max 10
char queue[max];
int front=-1,rear=-1;
void main()
{
	int ch;
	char p;
  	while(1)
	{
		printf("\nCircular Queue Functions(Assuming size of queue is 10)\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
  		scanf("%d",&ch);
		switch(ch)
  		{
    			case 1:printf("\nEnter the value to be enqueued:");
				scanf("%s",&p);
				enqueue(p);
           			break;
    			case 2:dequeue();
				break;
    			case 3:display();
           			break;
    			case 4:exit (0);
  		}

	}	
  
}
 
void enqueue(char elem)
{                       
    if((front==rear+1)||(front==0 && rear==max-1)) printf("Overflow!\n\n");
    else

    {
        if(front==-1)front=0;
        rear=(rear+1) % max;
        queue[rear]=elem;
    }
}
int dequeue()
{                 
    char elem;
    if(front==-1)
    {
	printf("Underflow!\n\n");return;
    }		
    else
    {
        elem=queue[front];
	printf("The dequeued value:%c",elem);
        if(front==rear){ front=-1; rear=-1;}
        else
            front=(front+1)%max;
    }
}

display()
{     
    int i;
    if(front==-1) printf("Empty Queue\n");
    else
    {
        printf("Front[%d]->",front);
        for(i=front;i!=rear;i=(i+1)%max)
            printf("%c ",queue[i]);
        printf("%c ",queue[i]);
        printf("<-[%d]Rear",rear);
    }
}

