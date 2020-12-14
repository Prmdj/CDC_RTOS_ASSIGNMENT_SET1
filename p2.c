#include<stdio.h>

void main()
{
	int input=0,sum=0,product=1,average=0,count=0;
	while(1)
	{
		printf("Enter input\n");
		scanf("%d",&input);
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
