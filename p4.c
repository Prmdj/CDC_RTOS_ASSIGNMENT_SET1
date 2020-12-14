#include<stdio.h>

void main()
{
	int input=0,sum=0,product=1,average=0,count=0;
	char str[100];
	FILE *file;
	file=fopen("p4.txt","r");
	while(fgets(str,100,file)!=NULL)
	{
		input=atoi(str);
		if(input==999)
			break;
		else
		{
			sum+=input;
			product*=input;
			count++;
		}
	}
	average=sum/count;
	printf("Sum is %d\nProduct is %d\nAverage is %d\n",sum,product,average);
}
