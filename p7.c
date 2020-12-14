#include<stdio.h>
#include<string.h>

void main()
{
	FILE *file;
	file=fopen("7.txt","r");
	char string[50];
	int i=0,len=0;
	fgets(string,50,file);
	printf("The input string is:%s\n",string);
	for (int i = 0; string[i]!='\0';i++)
	{
		len++;
	}
	printf("Length of the string is %d\n",len);
}
