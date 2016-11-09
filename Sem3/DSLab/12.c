#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define max 50

typedef struct Node
{
	int key;
	char name[20];
	char dept[20];
}Node;

Node *hashTable[100];

void Display()
{
	int i;
	printf("HASHTABLE : \n");
	for(i = 0; i < max; i++)
	{
		if(hashTable[i] != NULL)
		{
			printf("Index Stored : %d\n\tKey : %d\n\tName : %s\n\tDepartment : %s\n\n", i, hashTable[i]->key, hashTable[i]->name,hashTable[i]->dept);	
		}
	}
}

Node * Search(int key)
{
	int index = key % max;
	int end = index;
	while(hashTable[index] != NULL)
	{
		if(hashTable[index]->key == key)
		{
			return hashTable[index];
		}
		index = (index + 1) % max;
		if(index == end)
		{
			return NULL;
		}
	}
	return NULL;
}

void Insert(int key, char name[20],char dept[20])
{
	if(Search(key) != NULL)
	{
		printf("Key isn't unique.\n");
		return;
	}
	Node *n = (Node *)malloc(sizeof(Node));
	n->key = key;
	strcpy(n->name, name);
	strcpy(n->dept,dept);
	int index = key % max;
	while(1)
	{
		if(hashTable[index] == NULL)
		{
			hashTable[index] = n;
			printf("Element inserted at %d.\n", index);
			break;
		}
		printf("Collision occured at %d. Using Linear Probing.\n", index);
		index = (index+1)%max;
	}
}
int main()
{
	Node *n;
	int ch, key;
	char name[20],dept[20];	
	printf("1. Insert an Element into Hash Table\n");
	printf("2. Search for an Element in Hash Table\n");
	printf("3. Display HashTable\n");
	printf("4. Exit\n");	
	while(1)
	{
		printf("Enter choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :
				printf("Enter Key: ");
				scanf("%d", &key);
				printf("Enter Name: ");
				scanf("%s", name);
				printf("Enter Department: ");
				scanf("%s", dept);
				Insert(key,name,dept);	
				break;
			case 2 :
				printf("\tEnter Key : ");
				scanf("%d", &key);
				n = Search(key);
				if(n==NULL)
				{
					printf("Employee Not found.\n");	
				}
				else
				{
					printf("Employee found.\n");
					printf("Key : %d\n", n->key);
					printf("Name : %s\n", n->name);
					printf("Department : %s\n", n->dept);
				}
				break;
			case 3 :
				Display();
				break;
			case 4 :
				exit(1);	
				break;
			default:
				printf("Wrong choice.\n");
				break;
		}
	}
}

