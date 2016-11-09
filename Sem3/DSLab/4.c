#include<stdio.h>
char infix[20];
int top = -1;
void push(char x)
{
	top++;
        infix[top] = x;
}

char pop()
{
        if(top == -1)
                return -1;
        else
        	return infix[top--];
}

int prior(char x)
{
	if(x == '(')
		return 0;
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/')
		return 2;
	if(x == '^')
		return 3; 
	if(x == '%')
		return 4;
}

void main()
{
        char exp[20];
        char *ptr, x;
        printf("Enter the infix expression: ");
        scanf("%s",exp);
        ptr = exp;
        while(*ptr != '\0')
        {
                if(isalnum(*ptr))
                        printf("%c",*ptr);
                else if(*ptr == '(')
			push(*ptr);
		else if(*ptr == ')')
                {
                        while((x = pop()) != '(')
				printf("%c", x);
                }
		else
		{
			while(prior(infix[top]) >= prior(*ptr))
				printf("%c",pop());
			push(*ptr);
		}
                ptr++;
        }
	while(top != -1)
	{
		printf("%c",pop());
	}
	printf("\n");
}

