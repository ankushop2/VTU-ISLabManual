#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct
{
	char usn[11];
	char name[20];
	char branch[25];
	int sem;
	char phNo[11];
}student;

struct node
{
	student s;
	struct node *next;
}*first;
typedef struct node node;
void Insert_Beg(student s, int *count)
{
	*count += 1;
	fflush(stdin);
	node *new = (node *)malloc(sizeof(node));
	if(new == NULL)
	{
		printf("Memory allocation failed.");
	}
	new->s=s;
	new->next = NULL;

	if(first == NULL)
	{
		first = new;
	}
	else
	{
		new->next = first;
		first = new;
	}
}
void Insert_End(student s,int *count)
{
	*count += 1;
	fflush(stdin);
	node *new =(node *) malloc(sizeof(node));

	if(new == NULL)
	{
		printf("Memory allocation failed.");
	}
	new->next = NULL;
	new->s = s;

	if(first == NULL)
	{
		first = new;
	}
	else
	{
		node *temp = first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}
void Delete_Beg(int *count)
{
	if(first == NULL)
	{
		printf("Underflow.\n");
		return;
	}
	*count -= 1;
	node *temp = first;
	first = first->next;
	free(temp);
}
void Delete_End(int *count)
{
	if(first == NULL)
	{
		printf("Underflow.\n");
		return;
	}
	*count -= 1;
	node *temp1 = first;
	node *temp2 = first->next;
	while(temp2->next != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp1->next = NULL;
	free(temp2);
}
void GetNode(student *s)
{
	getchar();
	fflush(stdin);
	printf("Enter USN : ");
	fgets(s->usn,11,stdin);
	printf("Enter Name : ");
	fgets(s->name,20,stdin);
	printf("Enter Branch : ");
	fgets(s->branch,25,stdin);
	printf("Enter Sem : ");
	scanf("%d",&s->sem);
	fflush(stdin);
	getchar();
	printf("Enter Phone Number : ");
	fgets(s->phNo,11,stdin); 

}
void Display(int count)
{
	printf("Count : %d\n",count);
	node *temp = first;
	while(temp != NULL)
	{
		PrintStud(temp->s);
		temp = temp->next;
	}
}
void PrintStud(student s)
{
	printf("USN : ");
	printf("%s",s.usn);
	printf("Name : ");
	printf("%s",s.name);
	printf("Branch : ");
	printf("%s",s.branch);
	printf("Sem : ");
	printf("%d",s.sem);
	printf("\nPhone Number : ");
	printf("%s",s.phNo);
	printf("*****************\n"); 
}
int main()
{
	int n,ch,i;
	student s;
	first = NULL;	
	int count = 0;		
	while(1)
	{
		printf("1. Insert N Students\n");
		printf("2. Insert At Beginning\n");
		printf("3. Insert At End\n");
		printf("4. Delete At Beginning\n");
		printf("5. Delete At End\n");
		printf("6. Display\n");
		printf("7. Use As Stack\n");
		printf("8. Use As Queue\n");
		printf("9. Exit\n");
		student s;
		printf("Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 :
				printf("Enter number of students : ");
				scanf("%d",&n);
				for(i = 0; i < n;i++)
				{		
					student s;
					GetNode(&s);
					Insert_Beg(s,&count);		
				}
				break;
			case 2 :
				GetNode(&s);
				Insert_Beg(s,&count);
				break;		
			case 3 :		
				GetNode(&s);
				Insert_End(s,&count);
				break;
			case 4 :
				Delete_Beg(&count);
				break;
			case 5 :
				Delete_End(&count);
				break;		
			case 6 :
				printf("The Students are as follows : \n");
				Display(count);
				break;
			case 7 :
				printf("\t1. Push\n\t2. Pop\n\tEnter : ");
				scanf("%d",&n);
				if(n == 1)
				{
					GetNode(&s);
					Insert_Beg(s,&count);
				}
				else if(n == 2)
				{
					Delete_Beg(&count);
				}
				else
				{
					printf("Wrong Option.\n");
				}
				break;
			case 8 :
				printf("\t1. Enqueue\n\t2. Dequeue\n\tEnter : ");
				scanf("%d",&n);
				if(n == 1)
				{
					GetNode(&s);
					Insert_End(s,&count);
				}
				else if(n == 2)
				{
					Delete_Beg(&count);
				}
				else
				{
					printf("Wrong Option.\n");
				}
				break;
			case 9 :
				exit(0);
			default :
				printf("Wrong choice.\n");
				break;
				
		}	
		
	}
}

