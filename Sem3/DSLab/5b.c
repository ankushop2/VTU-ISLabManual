#include <stdio.h>
#include <stdlib.h> 
void hanoi(int n, char from, char to, char aux)
{
    	if (n == 1)
    	{
        	printf("\n Move disk 1 from rod %c to rod %c", from, to);
        	return;
    	}
    	hanoi(n-1, from, aux, to);
    	printf("\n Move disk %d from rod %c to rod %c", n, from, to);
    	hanoi(n-1, aux, to, from);

}
 
void main()
{
    	int n;
	printf("Enter Number of disks:");
	scanf("%d", &n);
	if(n==0)
	{
		printf("No disk transferred!");
		exit(1);
	}
	else hanoi(n, 'A', 'C', 'B');
	printf("\n"); 
}	


