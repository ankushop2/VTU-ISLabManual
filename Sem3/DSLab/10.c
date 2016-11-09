#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree node;
node *root = NULL;
node *getnode()
{
	node *t;
	t = (node*)malloc(sizeof(node));
	t->left = NULL;
	t->right = NULL;
	return t;
}
void create(int key)
{
	node *p,*temp,*prev;
	if(root == NULL)
	{
		p=getnode();
		p->data=key;
		root = p;
	}
	else
	{
		temp = root; prev = NULL;
		while(temp!=NULL)
		{
			if(temp->data == key)
			{
				printf("Duplicate Node\n");break;
			}			
			else if(temp->data < key)
			{

				prev = temp;
				temp = temp->right;				
			}
			else
			{
				prev = temp;
				temp = temp->left;
			}
		}
		p = getnode();
		p->data = key;
		if(prev->data < key)
			prev->right = p;
		else
			prev->left= p;
	}
}
void inorder(node *r)
{
	if(r != NULL)
	{
		inorder(r->left);
		printf("%d\t",r->data);
		inorder(r->right);
	}
}
void preorder(node *r)
{
	if(r != NULL)
	{
		printf("%d\t",r->data);
		preorder(r->left);
		preorder(r->right);

	}
}
void postorder(node *r)
{
	if(r != NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%d\t",r->data);
	}
}
node *search(int key,node *leaf)
{
  if( leaf != 0 )
  {
      if(key == leaf->data)
      {
          return leaf;
      }
      else if(key < leaf->data)
      {
          return search(key, leaf->left);
      }
      else
      {
          return search(key, leaf->right);
      }
  }
  else return 0;
}
node* delete(node *r,int key)
{
	node *temp;	
	if(r == NULL)
	{
		return r;
	}
	else if (key < r->data)
        	r->left = delete(r->left, key);
     else if (key > r->data)
        	r->right = delete(r->right, key);
    else
    {	
    	if (r->left == NULL && r->right == NULL)
    	{
    		free(r);
    		r = NULL;
    		return r;
    	}
  		if (r->left == NULL)
        {
		    struct node *temp = r->right;
		    free(r);
		    return temp;
		}
        else if (r->right == NULL)
        {
		    struct node *temp = r->left;
		    free(r);
		    return temp;
		}
		node* temp = r->right;
		while(temp->left != NULL)
			temp = temp->left; 
		r->data = temp->data;
	    r->right = delete(r->right, temp->data);
	}
	 
}
void main()
{
	int ch,n;
	printf("1. Create a Binary Tree\n");
		printf("2. Transverse through the tree\n");
		printf("3. Search for a node\n");
		printf("4. Delete a node\n");
		printf("5. Create\n");
		
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&ch);		
		switch(ch)
		{
			case 1: printf("Enter the element: ");
				scanf("%d",&n);				
				create(n);
				break;
			case 2: printf("\t1. Inorder\n");
				printf("\t2. Preorder\n");
				printf("\t3. Postorder\n");
				printf("Enter your choice: ");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1: inorder(root);printf("\n");
						break;
					case 2: preorder(root);printf("\n");
						break;
					case 3: postorder(root);printf("\n");
						break;
					default: printf("Wrong Choice");
				}
				break;
			case 3: printf("Enter the element to search: ");
				scanf("%d",&n);				
				if(search(n,root))
					printf("Element Found\n");
				else
					printf("Element Not Found\n");
				break;
			case 4: printf("Enter the element to be deleted: ");
				scanf("%d",&n);				
				delete(root,n);
				break;
			case 5: exit(1);
		}
	}
}

