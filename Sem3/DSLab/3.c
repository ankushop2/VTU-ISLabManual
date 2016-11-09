#include<stdio.h>
#include<stdlib.h>
#define m 5
int stack[m];
int top=-1;
void push(int);
int pop(int []);
void pali();
void display();

int main()
{
	int n,ch,p;
	while(1)
	{
  		printf("\nStack Functions\n1.Push\n2. Pop\n3. Check Palindrome\n4. Display\n5. Exit\nEnter your Choice:");
  		scanf("%d",&ch);
  		switch (ch)
  		{
    			case 1:printf("\nEnter the value to be pushed:");
           		       scanf("%d",&n);
           			push(n);
           			break;
    			case 2:if(top!=-1)
           			{
					p=pop(stack);
           				printf("\nPopped element:%d",p);
				}
           			else
          			printf("\nUnderflow");
           			break;
    			case 3:pali();
           			break;
    			case 4:display();
           			break;
    			case 5:exit (0);
  		}

	}	
  return 0;
}
void push(int num)
 {
	if (top==m-1)
 	printf("\nOverflow");
	else
 	{
     		stack[++top]=num;
 	}
} 
int pop(int stack[])
{
    return(stack[top--]);
}
void pali()
 { 
 	 int x,temp[50],i,flag=0; 
  	if (top==-1)
   	printf("\nUnderflow");
  	else
    	{
      		for(i=0;i<=top;i++)
       		{
         		temp[i]=stack[i];
       		}	   
      		for(i=0;i<=top;i++)
       		{  
         		x=pop(temp);
         		if(x!=stack[i])
           		{
            			flag=0;
           			 break;
           		}flag=1;
       		}	
	} 	
     	if(flag==1)
     	{
		 printf("\nIt is palindrome");
     	}
   	else
     	{
		 printf("\nIt is not a palindrome");
 	}
}
void display()
{
 	 int j=0,i=0;
  	if(top==-1)
   	printf("\nNo elements present"); 
 	else
	{
  		printf("\nElements in the stack");
  		 for(j=top;j>=0;j--,i--)
     		printf("\n %d ",stack[j]);
	}

}	


