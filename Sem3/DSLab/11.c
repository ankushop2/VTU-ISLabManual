#include<stdio.h>
int adarray[20][20],adarray1[20][20],queue[20],stack[20],visited[20],reach[20],answer1[20];
int front,rear,top,nodes;
int main()
{
	int n,i,j,k,top,front,rear,choice,source;	
	printf("Enter number of nodes: ");
	scanf("%d",&nodes);
	printf("Enter the adjacency matrix.\n");
	for(i=1;i<=nodes;i++)
	{
		for(j=1;j<=nodes;j++)
		{
			printf("Is there a link between %d and %d: ",i,j);
			scanf("%d",&adarray[i][j]);
			adarray1[i][j]=adarray[i][j];
		}
	}
	while(1)
	{
		printf("1. Search through Breadth First Search\n");
		printf("2. Search through Depth First Search\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		if(choice == 1)
		{
			bfs();
		}
		else if(choice == 2)
		{
			for (i=1;i<=nodes;i++)
			{
				reach[i]=0;
			}
			printf("Enter source:");
			scanf("%d", &source);
			dfs(source);
			printf("\n");
			for(i=1;i<nodes;i++)
			{
				if(!reach[i])
					printf("Node %d is not reachable",i);
			}
			printf("\n");
		}
		else exit(0);
	}
}
void bfs()
{
	int source,i,answer[20],k=0;
	front=rear=0;
	printf("Enter Source: ");
	scanf("%d",&source);
	queue[rear]=source;
	answer[k]=source;
	for(i=1; i<=nodes; i++) 
	{	
 		visited[i] = 0;
	}
	while(front <= rear)
	{	
		for(i=1;i<=nodes;i++)
		{	
			if((adarray[source][i]==1)&&(visited[i]==0))
			{
				queue[++rear]=i;
				visited[i]=1;
			}
		}	
		source=queue[++front];
		k++;
		answer[k]=source;
	}
	printf("BFS is as follows: ");
	for(i=0;i<k;i++)
	{
		printf("%d\t",answer[i]);
	}
	printf("\n");
}
void dfs(int v)
{
	int i,answer1[20];
	reach[v]=1;
 	for(i=1;i<=nodes;i++)
  		if(adarray1[v][i] && !reach[i])
  		{
  			printf("\n %d->%d",v,i);
  			answer1[i]=v;
   			dfs(i);
  		}  	
}

