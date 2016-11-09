#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct
{
	char ssn[20];
	char name[20];
	char dept[20];
	char desg[20];
	int sal;
	char phNo[20];
}Employee;

struct node
{
	Employee e;
	struct node *right;
	struct node *left;	
}*first = NULL,*last = NULL;

typedef struct node node;

void Insert_Beg(Employee e, int *count)
{
	node *new = (node *)malloc(sizeof(node));
	if(new == NULL)
	{
		printf("Memory Allocation Fail\n");
		return;
	}
	*count += 1;
	new->e = e;
	new->right = NULL;
	new->left = NULL;
	
	if(first == NULL)
	{
		first = last = new;
	}
	else
	{
		new->right = first;
		first->left = new;
		first = new;
	}
} 

void Insert_End(Employee e, int *count)
{
	
	node *new = (node *)malloc(sizeof(node));
	if(new == NULL)
	{
		printf("Memory Allocation Fail\n");
		return;
	}
	*count += 1;
	new->e = e;
	new->right = NULL;
	new->left = NULL;
	
	if(first == NULL)
	{
		first = last = new;
	}
	else
	{
		new->left = last;
		last->right = new;
		last = new;
	}
}

void Delete_Beg(int *count)
{
	if(first != NULL)
	{
		*count -= 1;
		node *temp = first;
		if(NULL == first->right)
		{
			first = last = NULL;
			temp->right = NULL;
			temp->left = NULL;
			free(temp);
		}
		else
		{
			first = first->right;
			first->left = NULL;
			temp->right = NULL;
			free(temp);
		}
	}
}


void Delete_End(int *count)
{
	if(NULL != last)
	{
		*count -= 1;
		node *temp = last;
		if(last->left == NULL)
		{
			first = last = NULL;
			temp->left = NULL;
			temp->right = NULL;
			free(temp);
		}
		else
		{
			last = last->left;
			last->right = NULL;
			temp->left = NULL;
			free(temp);
		}
	}
}
void GetNode(Employee *e)
{
	getchar();
	fflush(stdin);
	printf("Enter SSN : ");
	fgets(e->ssn,20,stdin);
	printf("Enter Name : ");
	fgets(e->name,20,stdin);
	printf("Enter Department : ");
	fgets(e->dept,20,stdin);
	printf("Enter Designation: ");
	fgets(e->desg,20,stdin);
	printf("Enter Salary : ");
	scanf("%d",&e->sal);
	fflush(stdin);
	getchar();
	printf("Enter Phone Number : ");
	fgets(e->phNo,20,stdin); 
}

void PrintEmpDetails(Employee e)
{
	printf("SSN : ");
	printf("%s",e.ssn);
	printf("Name : ");
	printf("%s",e.name);
	printf("Department : ");
	printf("%s",e.dept);
	printf("Designation: ");
	printf("%s",e.desg);
	printf("Salary : %d\n",e.sal);
	printf("Enter Phone Number : ");
	printf("%s",e.phNo); 
}

void DispRight(int count)
{
	printf("Count : %d\n",count);
	printf("##################\n"); 
	node *temp = first;
	while(temp != NULL)
	{
		PrintEmpDetails(temp->e);
		temp = temp->right;
        	printf("########################\n");
	}
}

void DispLeft(int count)
{
        printf("Count : %d\n",count);
        printf("##############\n");
        node *temp = last;
        while(temp != NULL)
        {
                PrintEmpDetails(temp->e);
                temp = temp->left;
        	printf("###################\n");
        }
}

int main()
{
	int n,i,ch;
	Employee e;
	first = NULL;
	last = NULL;
	printf("1. Insert N Employees\n");
		printf("2. Insert At Beginning\n");
		printf("3. Insert At End\n");
		printf("4. Delete At Beginning\n");
		printf("5. Delete At End\n");
		printf("6. Display\n");
		printf("7. Use As Double Ended Queue\n");
		printf("8. Exit\n");
	int count = 0;		
	while(1)
	{		
		printf("Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 :
				printf("Enter number of Employees : ");
				scanf("%d",&n);
				for(i = 0; i < n;i++)
				{		
					Employee e;
					GetNode(&e);
					Insert_End(e,&count);		
				}
				break;
			case 2 :
				GetNode(&e);
				Insert_Beg(e,&count);
				break;		
			case 3 :		
				GetNode(&e);
				Insert_End(e,&count);
				break;
			case 4 :
				Delete_Beg(&count);
				break;
			case 5 :
				Delete_End(&count);
				break;		
			case 6 :
				printf("\t1. Display From Right\n\t2. Display From Left\n\tEnter :");
				scanf("%d",&n);
				if(n == 1)
				{
					printf("The Employees are as follows(Left to Right) : \n");
					DispRight(count);
				}
				else if(n == 2)
				{
					printf("The Employees are as follows(Right to Left) : \n");
					DispLeft(count);
				}
				else
				{
					printf("Wrong Choice\n");
					break;
				}
				break;
			case 7 :
				printf("\t1. Enqueue Front\n\t2. Dequeue End\n\t");
				printf("3. Enqueue End\n\t4. Dequeue Front\n\tEnter :");
				scanf("%d",&n);
				if(n == 1)
				{
					GetNode(&e);
                    Insert_Beg(e,&count);                              
				}
				else if(n == 2)
				{
			 		Delete_End(&count);		
				}
				else if(n == 3)
				{
					GetNode(&e);
                    Insert_End(e,&count);
				}
				else if(n == 4)
				{
					Delete_Beg(&count);
				}
				else
				{
					printf("Wrong Choice\n");
					break;
				}
				break;				
			case 8 :
				exit(0);
			default :
				printf("Wrong choice.\n");
			break;
				
		}	
		
	}
}

