#include<stdio.h>
#include<stdlib.h>
int array[100];
int n=0;
void main()
{
	int counter,pos1,pos2,elem,x,i;
	for(i=0;i<100;i++)
	{
		array[i]= -1;
	}
	while(1){
		 printf("ARRAYS FUNCTIONS\n1. Create\n2. Display\n3. Insert into Position\n4. Delete from position\n5. Exit\n");
		scanf("%d",&counter);
		switch(counter)
		{
			case 1:
			{
				create();break;
			}
			case 2:
			{
				display();break;
			}
			case 3:
			{
				printf("Enter the position where the element has to be entered:");
				scanf("%d", &pos1);
				printf("Enter the element:");
				scanf("%d", &elem);
				insert(pos1,elem);
				printf("%d was inserted to postion %d\n",elem,pos1);
				break;
			}
			case 4:
			{
				printf("Enter the position where the element has to be deleted from:");
				scanf("%d",&pos2);
				x = del(pos2);
				printf("The element %d was deleted from %d\n",x,pos2);
				break;
			}
			case 5:
			{
				exit(1);
			}
		}
		
	}
}	
void create()
{
	int i;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for( i=0; i<n; i++)
	{
		scanf("%d",&array[i]);
	}
	printf("\n");
}
void display()
{	
	int i;
	printf("The elements of the array are:\n");
	for( i=0; i<n; i++)
	{
		printf("Array[%d]=%d\t",i,array[i]);
	}
	printf("\n");
}
void insert(int position, int element)
{
	int i;
	n=n+1;
	array[n]=0;
	if(position>n)
	{
		printf("Position cannot exceed size!, Exiting...\n");exit(1);
	}
	else
	{
		for(i=n ; i>position; i--)
		{
			array[i]=array[i-1];
		}
		array[position]=element;
	}				
}
int del(int position1)
{	
	int ret,i;
	if(array[position1]==-1)
	{
		printf("Position is already empty!, Exiting...");exit(1);
	}
	else
	{
		ret=array[position1];
		for(i=position1;i<n;i++)
		{
			array[i]=array[i+1];
		}
		n=n-1;
	}
	return ret;
}		

