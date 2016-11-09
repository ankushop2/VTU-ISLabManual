#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<math.h>

struct node
{
	int co;
	int exp[3];
	struct node *next;
};

typedef struct node node;

int IsPresent(node **t, int arr[3])
{
	int pos = 0;
	node **first = t;

	if (*first == NULL)
	{
		return -1;
	}

	node **temp = &((*first)->next);
	do
	{
		int i, isPresent = 1;
		for (i = 0; i < 3; i++)
		{
			if ((*temp)->exp[i] != arr[i])
			{
				isPresent = 0;
				break;
			}
		}
		if (isPresent)
		{
			return pos;
		}
		pos++;
		temp = &((*temp)->next);
	} while (*temp != (*first)->next);
	return -1;
}

int Insert(node **t, int co, int arr[3])
{
	int i;
	node **first = t;
	node *new = (node *)malloc(sizeof(node));

	new->next = NULL;
	if (*first == NULL)
	{
		new->co = co;
		for (i = 0; i < 3; i++)
		{
			new->exp[i] = arr[i];
		}
		*first = new;
		(*first)->next = *first;
	}
	else
	{
		if (IsPresent(t, arr) == -1)
		{
			new->co = co;
			for (i = 0; i < 3; i++)
			{
				new->exp[i] = arr[i];
			}
			new->next = (*first)->next;
			(*first)->next = new;
			*first = new;
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void Display(node **t)
{
	node **first = t;
	node **temp = &((*first)->next);

	if ((*first) == NULL)
	{
		printf("Empty\n");
		return;
	}
	do
	{
		printf("+(%d x^%d y^%d z^%d) ", (*temp)->co, (*temp)->exp[0], (*temp)->exp[1], (*temp)->exp[2]);
		temp = &((*temp)->next);
	} while (*temp != (*first)->next);
	printf("\n");
}

int CheckExp(int arr1[], int arr2[])
{
	int isEqual = 1;
	int i;
	for (i = 0; i < 3; i++)
	{
		if (arr1[i] != arr2[i])
		{
			isEqual = 0;
			break;
		}
	}
	return isEqual;
}

void PolySum(node **p1, node **p2, node **p3)
{

	if (*p1 == NULL  && *p2 == NULL)
	{
		return;
	}
	else if (*p1 == NULL)
	{
		node **t = &((*p2)->next);
		do
		{
			Insert(p3, (*t)->co, (*t)->exp);
			t = &((*t)->next);
		} while (*t != (*p2)->next);
		return;
	}
	else if (*p2 == NULL)
	{
		node **t = &((*p1)->next);
		do
		{
			Insert(p3, (*t)->co, (*t)->exp);
			t = &((*t)->next);
		} while (*t != (*p1)->next);
		return;
		return;
	}
	node **t1 = &((*p1)->next);
	do
	{
		int done = 0;
		node **t2 = &((*p2)->next);

		do
		{
			if (CheckExp((*t1)->exp, (*t2)->exp))
			{
				done = 1;
				Insert(p3, ((*t1)->co + (*t2)->co), (*t1)->exp);
			}
			t2 = &((*t2)->next);
		} while (*t2 != (*p2)->next);

		if (!done)
		{
			Insert(p3, (*t1)->co, (*t1)->exp);
		}
		t1 = &((*t1)->next);
	} while (*t1 != (*p1)->next);

	node **t2 = &((*p2)->next);

	do
	{
		Insert(p3, (*t2)->co, (*t2)->exp);
		t2 = &((*t2)->next);
	} while (*t2 != (*p2)->next);

}

void Eval(node **t, float val[])
{
		double result = 0;
		node **temp = t;
		do
		{
			result += ((*temp)->co)*pow(val[0],(*temp)->exp[0])*pow(val[1],(*temp)->exp[1])*pow(val[2],(*temp)->exp[2]);
			temp = &((*temp)->next);
		}while(*temp != *t);
		printf("Result = %lf\n",result);
}


int main()
{
	node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL, *p = NULL;
	int ch, co, exp[3];
	float val[3];
	printf("1. Polynomial 1\n");
	printf("2. Polynomial 2\n");
	printf("3. Display Polynomials\n");
	printf("4. Add Polynomials 1 and 2 to 3\n");
	printf("5. Polynomial P Evaluation\n");
	printf("6. Exit\n");
	while (1)
	{
		
		printf("Enter choice : ");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:
				printf("Enter Co-eff and Powers of x,y,z : ");
				scanf("%d %d %d %d", &co, exp, exp + 1, exp + 2);
				if (!Insert(&poly1, co, exp))
				{
					printf("Element is already present.\n");
				}
				break;

			case 2:
				printf("Enter Co-eff and Powers of x,y,z : ");
				scanf("%d %d %d %d", &co, exp, exp + 1, exp + 2);
				if (!Insert(&poly2, co, exp))
				{
					printf("Element already present.\n");
				}
				break;

			case 3:
				printf("Polynomial 1 : ");
				Display(&poly1);
				printf("Polynomial 2 : ");
				Display(&poly2);
				printf("Polynomial 3 : ");
				Display(&poly3);
				break;
			case 4:
				poly3 = NULL;
				PolySum(&poly1, &poly2, &poly3);
				break;

			case 5:
				printf("\t1. Polynomial P.\n");
				printf("\t2. Display\n");
				printf("\t3. Evaluate\n");
				printf("\tEnter choice : ");
				scanf("%d", &ch);

				switch(ch)
				{
					case 1 :
						printf("Enter Co efficient and Powers of x,y,z : ");
						scanf("%d %d %d %d", &co, exp, exp + 1, exp + 2);
						if (!Insert(&p, co, exp))
						{
							printf("Element already present.\n");
						}
						break;
					case 2 :
						printf("Polynomial P : ");
						Display(&p);
						break;
					case 3 :
						printf("Enter values of x, y, z : ");
						scanf("%f %f %f", val, val + 1, val + 2);
						Eval(&p, val);
						break;
					default :
						printf("Wrong choice.\n");
						break;
				}
				break;
			case 6:
				exit(1);

			default:
				printf("Wrong Choice.\n");
				break;

		}
	}
}

