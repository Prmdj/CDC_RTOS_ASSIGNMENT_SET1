#include<stdio.h>
void main(int argc, char const *argv[])
{
	
	int i=1,sum=0,product=1,average=0,value=0;
	for(i=1;i<argc;i++)
	{
		value=atoi(argv[i]);
		sum+=value;
		product*=value;
	}
	average=sum/(argc-1);
	printf("Sum is %d\nProduct is %d\nAverage is %d\n",sum,product,average);
	return 0;
}
