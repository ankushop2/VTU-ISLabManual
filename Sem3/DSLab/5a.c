#define SIZE 50            
#include <stdio.h>
int stack[SIZE];
int top=-1;     
 
void push(int elem)
{                      
 	stack[++top]=elem;
}
 
int pop()
{                    
 	return(stack[top--]);
}
 
main()
{                        
 	char exp[50],ch;
 	int i=0,op1,op2;
 	printf("Postfix Expression: ");
 	scanf("%s",exp);
 	while( (ch=exp[i]) != '\0')
 	{
  		if(isdigit(ch)) push((int)ch- '0');
  		else
  		{        
   			op2=pop();
   			op1=pop();
   			switch(ch)
   			{
   				case '+':push(op1+op2);break;
   				case '-':push(op1-op2);break;
   				case '*':push(op1*op2);break;
   				case '/':push(op1/op2);break;
				case '%':push(op1%op2);break;
				case '^':push(pow(op1,op2));break;

   			}
  		}
		i++;
 	}
 	printf("Result after Evaluation: %d\n",stack[top]);
}

