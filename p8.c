#include<stdio.h>

FILE *file;
int words=0,lines=0;
char ch;

int word_count(FILE *file)
{
	
	while((ch=fgetc(file))!= EOF)
	{
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
			words++;
	}
	return (words+1);
}

int line_count(FILE *file)
{
	rewind(file);
	while((ch=fgetc(file))!= EOF)
	{
		if (ch == '\n' || ch == '\0')
			lines++;
	}
	return (lines+1);

}
void main()
{
	file=fopen("8.txt","r");
	words=word_count(file);
	lines=line_count(file);
	fclose(file);
	printf("Number of words is %d\n",words);
	printf("Number of lines is %d\n",lines);
}