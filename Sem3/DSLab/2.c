#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ans[50],str[50],pat[50], rep[50];
int patlen, len,replen,found =0;
void read();
int strleng(char [50]);
void display();
void replace(int);
void compare();
int main()
{
	read();
	compare();
	display();
}
int strleng(char s[50])
{
	return (strlen(s));
}
void read()
{
	printf("Enter the main string:");
	gets(str);
	printf("Enter the substring:");
	gets(pat);
	printf("Enter the replace string:");
	gets(rep);
	len=strleng(str); patlen= strleng(pat);replen= strleng(rep);
}
void display()
{
	printf("The original string:%s\n",str);
	printf("The string after replacement:%s",ans);
}
void compare()
{
	int i,j,k,flag=0,in=0,m,n;
	for(i=0;i<len;i++)
	{
		flag=0;
		for(j=i,k=0;k<patlen;k++,j++)
		{
			if(str[j]!=pat[k])
			{
				flag=1; break;
			}
		}
		if(flag==0)
		{
			found=1;
			replace(in);
			i=i+patlen-1;
			in=in+patlen;			
		}
		else
		{
			ans[in]=str[in];in++;
		}
	}
	ans[in]='\0';
}
void replace(int start)
{
	int i,j;
	for(j=0,i=start;i<replen;j++,i++) ans[i]=rep[j];
}

